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
#define taskname "task_b"

const double pi = acos(-1.0);
const int size = 1000 * 1000 + 100;
const int mdl = 1000 * 1000 * 1000 + 7;

char s[size], t[size], buf[size];
int z[size];
int finishhere[size];
int n, m, tot;
int ans[size];
int sumans[size];
int sumsumans[size];

void calcz(int len) {
	int b = 0;
	z[0] = 0;
	for (int i = 1; i < len; i++) {
		z[i] = max(0, min(b + z[b] - i, z[i - b]) - 2);
		while (i + z[i] < len && buf[i + z[i]] == buf[z[i]])
			z[i]++;
		if (i + z[i] > b + z[b])
			b = i;
	}
}

int main() {
	/*
	freopen("input.txt", "w", stdout);
	int n = 100 * 1000;
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < n / (j * 1000 + 1); i++)
			cout << 'a';
		cout << endl;
	}
	return 0;
	*/
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%s", s);
	scanf("%s", t);
	n = strlen(s);
	m = strlen(t);

	tot = n + m + 1;
	for (int i = 0; i < m; i++)
		buf[i] = t[i];
	buf[m] = '#';
	for (int i = 0; i < n; i++)
		buf[m + 1 + i] = s[i];
	calcz(tot);

	ans[0] = 1;
	sumans[0] = 1;
	sumsumans[0] = 1;

	int lst = -1;
	int total = 0;

	for (int i = 1; i <= n; i++) {
		if (i >= m && z[i + 1] >= m) {
			lst = i - m;
		}
		if (lst != -1) {
			ans[i] = sumsumans[lst];
		} else {
			ans[i] = 0;
		}

		sumans[i] = sumans[i - 1] + ans[i];
		if (sumans[i] >= mdl)
			sumans[i] -= mdl;
		sumsumans[i] = sumsumans[i - 1] + sumans[i];
		if (sumsumans[i] >= mdl)
			sumsumans[i] -= mdl;
	}

	total = sumans[n] + mdl - 1;
	if (total >= mdl)
		total -= mdl;

	cout << total << endl;

	return 0;
}