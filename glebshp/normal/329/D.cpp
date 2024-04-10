#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);

int n, k;

void printftype() {
	printf("v");
	for (int i = 0; i < 66; i++)
		if (i % 2 == 0)
			printf(".");
		else
			printf("<");
	for (int i = 0; i < 33; i++)
		printf("<");
	printf("\n");
}

void printstype() {
	for (int i = 0; i < 33; i++)
		printf(">");
	for (int i = 0; i < 66; i++)
		if (i % 2 == 0)
			printf(".");
		else
			printf(">");
	printf("^");
	printf("\n");
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	if (n == 5) {
		printf(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1\n");
	}
	if (n == 3) {
		printf(">vv\n^<.\n^.<\n1 3\n");
	}
	if (n == 100) {
		for (int i = 0; i < 50; i++) {
			printftype();
			printstype();
		}
		printf("1 1\n");
	}

    return 0;
}