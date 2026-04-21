#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* next;
};

Node* createList(int n) {
  Node* head = new Node;
  head->value = 0;
  head->next = nullptr;

  Node* current = head;

  for (int i = 1; i < n; i++) {
    current->next = new Node;
    current = current->next;
    current->value = i;
    current->next = nullptr;
  }

  return head;
}

void printList(Node* head) {
  Node* temp = head;

  while (temp != nullptr) {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
}

void freeList(Node* head) {
  Node* temp = head;

  while (temp != nullptr) {
    Node* next = temp->next;
    delete temp;
    temp = next;
  }
}

int main() {
  Node* list = createList(5);

  printList(list);
  cout << list->value << endl;

  freeList(list);

  Node* leakNode = new Node;
  leakNode->value = 99;
  leakNode->next = nullptr;

  cout << leakNode->value << endl;

  int* arr = new int[3];
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;

  delete[] arr;
  delete leakNode;
  return 0;
}
