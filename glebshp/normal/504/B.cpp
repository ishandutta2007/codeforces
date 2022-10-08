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
const int size = 250 * 1000 + 100;
const int rms = (1 << 19) - 1;
const int hrms = rms / 2;

int rsq[rms + 1];
int perm[2][size];
int res[size];
int resperm[size];
int num[2][size];
int n;

int rss(int v, int lb, int rb, int i, int j) {
	if (lb >= i && rb <= j)
		return rsq[v];
	if (lb > j || rb < i)
		return 0;
	return rss(v * 2, lb, (lb + rb) / 2, i, j) + rss(v * 2 + 1, (lb + rb) / 2 + 1, rb, i, j);
}

void translate(int ps) {
	for (int i = 1; i <= n; i++)
		rsq[hrms + i] = 1;
	for (int i = hrms; i > 0; i--)
		rsq[i] = rsq[i * 2] + rsq[i * 2 + 1];

	for (int i = 0; i < n; i++) {
		num[ps][i] = rss(1, 1, hrms + 1, 1, perm[ps][i] + 1) - 1;
		int ptr = perm[ps][i] + 1 + hrms;
		while (ptr > 0) {
			rsq[ptr]--;
			ptr /= 2;
		}
	}
}

void backtranslate() {
	for (int i = 1; i <= n; i++)
		rsq[hrms + i] = 1;
	for (int i = hrms; i > 0; i--)
		rsq[i] = rsq[i * 2] + rsq[i * 2 + 1];
	
	for (int i = 0; i < n; i++) {
		int sum = 0;
		int ptr = 1;
		while (ptr <= hrms) {
			if (rsq[ptr * 2] + sum >= res[i] + 1)
				ptr = ptr * 2;
			else {
				sum += rsq[ptr * 2];
				ptr = ptr * 2 + 1;
			}
		}

		resperm[i] = ptr - hrms - 1;

		while (ptr > 0) {
			rsq[ptr]--;
			ptr /= 2;
		}
	}
}

int main() {
//	assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &perm[i][j]);
		translate(i);
	}

	int d = 0;
	for (int i = n - 1; i >= 0; i--) {
		res[i] = num[0][i] + num[1][i] + d;
		d = (res[i] >= (n - i));
		res[i] %= n - i;
	}
	
	backtranslate();
	for (int i = 0; i < n; i++)
		printf("%d%c", resperm[i], " \n"[i == n - 1]);

	return 0;
}