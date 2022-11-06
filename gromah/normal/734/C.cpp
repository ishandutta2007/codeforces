#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define mp make_pair

int n, m, k, x, s, A[N], B[N], Ord[N], C[N], D[N], Min[N];
LL ans;

inline bool cmp(int u, int v)
{
	return mp(B[u], A[u]) < mp(B[v], A[v]);
}

inline LL Calc(int _n, int _s)
{
	if (_n <= 0) return 0;
	int t = upper_bound(B + 1, B + m + 1, _s) - B - 1;
	return 1LL * Min[t] * _n;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	scanf("%d%d", &x, &s);
	ans = 1LL * n * x;
	for (int i = 1; i <= m; i ++)
		scanf("%d", A + i);
	for (int i = 1; i <= m; i ++)
	{
		scanf("%d", B + i);
		Ord[i] = i;
	}
	sort(Ord + 1, Ord + m + 1, cmp);
	sort(B + 1, B + m + 1);
	Min[0] = x;
	for (int i = 1; i <= m; i ++)
		Min[i] = min(Min[i - 1], A[Ord[i]]);
	for (int i = 1; i <= k; i ++)
		scanf("%d", C + i);
	for (int i = 1; i <= k; i ++)
		scanf("%d", D + i);
	for (int i = 0; i <= k; i ++)
	{
		if (D[i] > s) continue ;
		LL t = Calc(n - C[i], s - D[i]);
		if (t < ans) ans = t;
	}
	printf("%I64d\n", ans);
	return 0;
}