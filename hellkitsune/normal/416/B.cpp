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

int a[50000][5];
int d[50000][5];

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	REP(i, m) REP(j, n)
		scanf("%d", &a[i][j]);
	d[0][0] = a[0][0];
	for (int i = 1; i < n; ++i)
		d[0][i] = d[0][i - 1] + a[0][i];
	for (int i = 1; i < m; ++i)
		REP(j, n) {
			d[i][j] = d[i - 1][j];
			if (j > 0)
				d[i][j] = max(d[i][j], d[i][j - 1]);
			d[i][j] += a[i][j];
		}
	REP(i, m)
		printf("%d ", d[i][n - 1]);
	printf("\n");
	return 0;
}