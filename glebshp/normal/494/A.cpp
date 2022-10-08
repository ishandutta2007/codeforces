#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "task_a"

const double pi = acos(-1.0);
const int size = 1000 * 1000 + 100;

char buf[size];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%s", buf);
	int len = strlen(buf);

	int lst = 0;
	for (int i = 0; i < len; i++)
		if (buf[i] == '#')
			lst = i;

	int pot = 0;
	for (int i = 0; i < len; i++) {
		if (buf[i] == '(')
			pot++;
		else 
			pot--;
	}

	int ans = max(0, pot);
	bool flag = true;

	pot = 0;
	for (int i = 0; i < len; i++) {
		if (buf[i] == '(')
			pot++;
		else
			pot--;
		if (i == lst)
			pot -= ans;
		flag = flag && (pot >= 0);
	}

	if (flag) {
		for (int i = 0; i < len; i++) {
			if (buf[i] == '#') {
				if (i == lst)
					printf("%d\n", ans + 1);
				else
					printf("1\n");
			}
		}
	} else {
		printf("-1\n");
	}

	return 0;
}