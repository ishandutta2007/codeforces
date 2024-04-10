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
#define taskname "problem_a"

const double pi = acos(-1.0);
const int size = 2000 * 1000;

bool isfree[10];
char buf[size];
int cnt[10];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%s", buf);
	int n = strlen(buf);
	for (int i = 0; i < n; i++) 
		cnt[buf[i] - '0']++;
	cnt[1]--;
	cnt[6]--;
	cnt[8]--;
	cnt[9]--;
	int cur = 0;
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < cnt[i]; j++)
			cur = (cur * 10 + i) % 7;
	}

	vector <int> p;
	p.pb(1);
	p.pb(6);
	p.pb(8);
	p.pb(9);
	do {
		int res = cur;
		for (int i = 0; i < 4; i++) {
			res = (res * 10 + p[i]) % 7;
		}

		if (res == 0) {
			for (int i = 1; i < 10; i++)
				for (int j = 0; j < cnt[i]; j++)
					printf("%d", i);
			for (int i = 0; i < 4; i++)
				printf("%d", p[i]);
			for (int i = 0; i < cnt[0]; i++)
				printf("0");

			return 0;
		}
	} while (next_permutation(p.begin(), p.end()));

	printf("0\n");

	return 0;
}