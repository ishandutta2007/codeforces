#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, s, ans, X[N];

inline int Solve(int *p, int cnt, int st)
{
	if (st <= p[1]) return p[cnt] - st;
	if (st >= p[cnt]) return st - p[1];
	int len = p[cnt] - p[1];
	int extra = min(p[cnt] - st, st - p[1]);
	return len + extra;
}

int main()
{
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i ++)
		scanf("%d", X + i);
	sort(X + 1, X + n + 1);
	ans = min(Solve(X, n - 1, s), Solve(X + 1, n - 1, s));
	if (n == 1) ans = 0;
	printf("%d\n", ans);
	return 0;
}