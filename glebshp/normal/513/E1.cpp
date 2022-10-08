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
#define taskname "task_e"

const double pi = acos(-1.0);
const int size = 30 * 1000 + 100;
const int ssize = 250;
const int inf = 1000 * 1000 * 1000;

int f[ssize][size];
int g[ssize][size];
int ans[ssize][size];
int sum[size];
int val[size];
int n, k;

int getvalue(int lb, int rb) {
	return sum[rb + 1] - sum[lb];
}


int main() {
//	assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));

	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &val[i]);
	}
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + val[i - 1];

	for (int i = 0; i <= n; i++) {
		f[0][i] = -inf;
		g[0][i] = -inf;
		ans[0][i] = 0;
	}
//	f[0][0] = -inf;
	for (int j = 0; j < n; j++)
		for (int p = j + 1; p <= n; p++) {
			int d = getvalue(j, p - 1);
//			cerr <<d << endl;
			f[0][p] = max(f[0][p], d);
			g[0][p] = max(g[0][p], -d);
		}
	for (int j = 1; j <= n; j++) {
		ans[0][j] = max(ans[0][j - 1], ans[0][j]);
		f[0][j] = max(f[0][j - 1], f[0][j]);
		g[0][j] = max(g[0][j - 1], g[0][j]);
	}

	for (int i = 1; i < k; i++) {
		for (int j = 0; j <= n; j++) {
			f[i][j] = -inf;
			g[i][j] = -inf;
			ans[i][j] = -inf;
		}
		for (int j = 0; j < n; j++)
			for (int p = j + 1; p <= n; p++) {
			    int d = getvalue(j, p - 1);
				f[i][p] = max(f[i][p], g[i - 1][j] + d * 2);
				f[i][p] = max(f[i][p], f[i - 1][j]);
				g[i][p] = max(g[i][p], g[i - 1][j]);
				g[i][p] = max(g[i][p], f[i - 1][j] - d * 2);
				ans[i][p] = max(ans[i][p], g[i - 1][j] + d);
				ans[i][p] = max(ans[i][p], f[i - 1][j] - d);
			}

		for (int j = 1; j <= n; j++) {
			f[i][j] = max(f[i][j - 1], f[i][j]);
			g[i][j] = max(g[i][j - 1], g[i][j]);
			ans[i][j] = max(ans[i][j - 1], ans[i][j]);
		}
	}

	printf("%d\n", ans[k - 1][n]);
	
	return 0;
}