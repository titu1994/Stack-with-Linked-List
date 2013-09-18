/*
 ============================================================================
 Name        : Stack.c
 Author      : Somshubra Majumdar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct Stack{
	Node *top;
}Stack;

//Linear Linked List Stack
void push(Stack *p, int v);
int pop(Stack *p);
int peek(Stack *p);
int isEmpty(Stack *p);
void display(Stack t);

int main(void) {
	//Linear Stack
	Stack s;
	int choice, ele;
	s.top = NULL;


	setbuf(stdout, NULL);

	printf("Enter choice :\n1 for push\n2 for pop\n3 for display\n");

	do{
		printf("Enter choice : ");
		scanf("%d", &choice);

		switch(choice){
		case 1:{
			//Add element

			printf("Enter an element\n");
			scanf("%d",&ele);
			push(&s, ele);

			break;
		}
		case 2:{
			//Remove element

			ele = pop(&s);
			break;
		}
		case 3:{
			//Display

			display(s);
			break;
		}
		default:{
			choice = -1;
		}

		}

	}while(choice != -1);

	return EXIT_SUCCESS;
}

void push(Stack *p, int v){

	Node *newNode = NULL;
	newNode = (Node*) calloc(1, sizeof(Node));

	if(newNode == NULL){
		printf("Stack is full\n");
	}
	else{
		newNode->data = v;
		newNode->next = p->top;
		p->top = newNode;
	}

}

int pop(Stack *p){

	Node *temp;

	if(p->top == NULL){
		return -1;
	}
	else{
		temp = p->top;
		int v = p->top->data;
		p->top = p->top->next;

		free(temp);
		return v;
	}

}

int peek(Stack *p){
	if(p->top == NULL){
		return -1;
	}
	else{
		return p->top->data;
	}
}

int isEmpty(Stack *p){
	return (p->top == NULL);
}

void display(Stack t){

	while(!isEmpty(&t))
	{
		printf("%d\t", t.top->data);
	}

	printf("\n");

}
