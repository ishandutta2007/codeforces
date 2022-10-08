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
#define taskname "task_c"

const double pi = acos(-1.0);
const int size = 60;
const int ssize = 20;
const int lsize = 20 * 1000;

char field[size][size];
int n, m;
int cnt[1 << ssize];
double ans[1 << ssize];
int clr[size][size];
int hmas[lsize];

int bc(int msk) {
	int c = 0;
	while (msk > 0) {
		c += msk & 1;
		msk /= 2;
	}

	return c;
}

int h[size];
int ch[size];

void rec(int ps, int msk) {
	if (ps == m) {
		cnt[msk] = 0;
		for (int i = 0; i < n; i++)
			ch[i] = 0;
		for (int i = 0; i < n; i++) {
			if (ch[clr[ps][i]] > 0) {
				cnt[msk]++;
			}
			ch[clr[ps][i]]++;
			if (ch[clr[ps][i]] == 2)
				cnt[msk]++;
		}

		return;
	}

	for (int i = 0; i < n; i++)
		clr[ps + 1][i] = clr[ps][i];
	rec(ps + 1, msk);
	
	for (int i = 0; i < n; i++) {
		clr[ps + 1][i] = clr[ps][i] * 200 + (int) field[i][ps];
		hmas[clr[ps + 1][i]] = -1;
		//h[i] = clr[ps + 1][i];
	}
	//sort(h, h + n);
	int cc = 0;
	for (int i = 0; i < n; i++) {
		if (hmas[clr[ps + 1][i]] == -1) {
			hmas[clr[ps + 1][i]] = cc++;
		}
		clr[ps + 1][i] = hmas[clr[ps + 1][i]];
		//clr[ps + 1][i] = lower_bound(h, h + n, clr[ps + 1][i]) - h;
	}

	rec(ps + 1, msk | (1 << ps));
}

int main() {
	/*
	freopen("input.txt", "w", stdout);
	cout << "50" << endl;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 20; j++)
			printf("%c", char('a' + rand() % 2));
		printf("\n");
	}
	return 0;
	*/
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", field[i]);
	}
	m = strlen(field[0]);

	for (int i = 0; i < n; i++)
		clr[0][i] = 0;
	rec(0, 0);

	for (int i = (1 << m) - 1; i >= 0; i--) {
		if (cnt[i] == 0)
			ans[i] = 0.0;
		else {
			ans[i] = 0.0;
			double p = 1.0 / (m - bc(i));
			for (int j = 0; j < m; j++)
				if (!((i >> j) & 1)) {
					int tg = i | (1 << j);
					double g = (cnt[i] - cnt[tg] + 0.0) / cnt[i];
					ans[i] += p * (g + (1 - g) * (ans[tg] + 1));
				}
		}

		//cout << i << ' ' << ans[i] << endl;
	}

	cout.precision(20);
	cout << ans[0] << endl;

	//cout << (clock() + 0.0) / CLOCKS_PER_SEC << endl;

	return 0;
}