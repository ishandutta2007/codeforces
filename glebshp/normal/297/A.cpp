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
const int size = 10 * 1000;

char buf1[size], buf2[size];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%s%s", buf1, buf2);

	int n = strlen(buf1);
	int m = strlen(buf2);

	int c1 = 0;
	int c2 = 0;

	for (int i = 0; i < n; i++) {
		c1 += buf1[i] == '1';
	}
	for (int i = 0; i < m; i++) {
		c2 += buf2[i] == '1';
	}
	c1 += c1 & 1;
	if (c1 >= c2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	/*
	int c = 0;
	for (int i = 0; i < n; i++)
		c ^= (buf1[i] == '1');
	int mx = 0;
	for (int i = n - 1; i >= max(0, n - m); i--) {
		bool flag = true;
		for (int j = 0; j < min(m, n - i); j++)
			flag = flag && buf1[i + j] == buf2[j];
		if (flag)
			mx = n - i;
	}

	int p = 0;
	int lm = n - mx;
	while (p <= lm) {
		if (mx == m)
			p++;
		else {
			if (c == (buf2[mx] == '1')) {
				mx++;
				if (mx == m)
					break;
			} else {
				c ^= (buf1[p] == '1');
				p++;
			}
		}
	}
	if (mx == m)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	*/

	return 0;
}