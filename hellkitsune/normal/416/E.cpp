#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a[500][500], f[500][500];
int cnt[500][500] = {}, ans[500][500] = {};
int INF = 1e9;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, n) REP(j, n) {
		if (i == j)
			a[i][j] = 0;
		else
			a[i][j] = INF;
	}
	REP(i, m) {
		int p, q, c;
		scanf("%d%d%d", &p, &q, &c);
		--p; --q;
		a[p][q] = a[q][p] = c;
	}
	REP(i, n) REP(j, n)
		f[i][j] = a[i][j];
	REP(k, n) REP(i, n) REP(j, n)
		if (f[i][k] + f[k][j] < f[i][j])
			f[i][j] = f[i][k] + f[k][j];
	REP(i, n) REP(j, n) REP(k, n) if (k != i)
		if (a[i][k] != INF && f[k][j] != INF && a[i][k] + f[k][j] == f[i][j])
			++cnt[i][j];
	REP(i, n - 1) for (int j = i + 1; j < n; ++j) REP(k, n) if (k != j)
		if (f[i][k] != INF && f[k][j] != INF && f[i][k] + f[k][j] == f[i][j])
			ans[i][j] += cnt[k][j];
	REP(i, n - 1) for (int j = i + 1; j < n; ++j)
		printf("%d ", ans[i][j]);
	printf("\n");
	return 0;
}