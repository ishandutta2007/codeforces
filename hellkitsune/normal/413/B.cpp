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

int n, m, k;
int a[20000][10];
int cnt1[10] = {};
LL cnt2[20000] = {};

int main() {
	scanf("%d%d%d", &n, &m, &k);
	REP(i, n) REP(j, m)
		scanf("%d", a[i] + j);
	REP(i, k) {
		int x, y;
		scanf("%d%d", &x, &y);
		++cnt1[y - 1];
		--cnt2[x - 1];
	}
	REP(i, n) REP(j, m)
		cnt2[i] += cnt1[j] * a[i][j];
	REP(i, n)
		printf("%I64d ", cnt2[i]);
	return 0;
}