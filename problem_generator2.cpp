// problem_generator2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include	<time.h>
int p[27] = {0,1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
time_t t;
int test(int x) {

	for (int i = 0; i<27; i++) {

		if (x == p[i]) {
	/*		printf("ne moze\n");
			printf("%d\n", x);*/
			x= rand() % 101;
			x = test(x);
		}
	}
	//printf("kada moze %d\n", x);
	return x;
}
void program() {
	srand((unsigned)time(&t));
	int x = rand() % 101;
	int y = rand() % 11;

	if (y == 0) {

		y++;
	}
	

	x = test(11);
	do {
		if (x % y == 0) {

	//		printf("dobar broj %d \n", y);
			break;
		}
		srand((unsigned)time(&t));
		y = rand() % 11;
		if (y == 0) {

			y++;
		}
	} while (x % y != 0);

	printf("%d : %d	= ? \n", x, y);

	char s[10];
	scanf_s("%s", s, 10);
	printf("skenirali %s\n", s);
	x = x / y;

	int c=0;
	c = atoi(s);
	if (c == x) {
		printf("tacno \n");
		printf("opet ? \n");
		c = 0;
		getchar();
		c = getchar();
	//	printf("%d", c);
		if (c == 10) {
			program();
		}
		
	}
	else {
		printf("netacno\n");
		c = 0;
		printf("opet ? \n");
	
		getchar();
		c = getchar();
		if (c == 10) {
			program();
		}
	}

}
int main()
{
	
	

	program();
	
    return 0;
}

