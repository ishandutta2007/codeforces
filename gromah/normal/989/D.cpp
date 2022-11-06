#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, l, w, A[2][N];
LL ans, W[N];

LL Calc(int id)
{
	LL res = 0;
	for (int i = 1; i <= A[id ^ 1][0]; i ++)
		W[i] = 1LL * A[id ^ 1][i] * (w - 1);
	sort(W + 1, W + A[id ^ 1][0] + 1);
	for (int i = 1; i <= A[id][0]; i ++)
		if (A[id][i] >= 0)
		{
			LL tmp = 1LL * A[id][i] * (w + 1);
			int t = upper_bound(W + 1, W + A[id ^ 1][0] + 1, tmp) - W;
			res += A[id ^ 1][0] + 1 - t;
		}
	return res;
}

int main()
{
	scanf("%d%d%d", &n, &l, &w);
	for (int i = 1, p, v; i <= n; i ++)
	{
		scanf("%d%d", &p, &v);
		if (v == -1) p += l;
		v = max(v, 0);
		A[v][++ A[v][0]] = p;
	}
	sort(A[0] + 1, A[0] + A[0][0] + 1);
	sort(A[1] + 1, A[1] + A[1][0] + 1);
	int c_0 = 0, c_1 = 0;
	for (int i = 1; i <= A[0][0]; i ++)
		if (A[0][i] > 0) c_0 ++;
	for (int i = 1; i <= A[1][0]; i ++)
		if (A[1][i] < 0) c_1 ++;
	ans = 1LL * c_0 * c_1;
	ans += Calc(1);
	for (int i = 1; i <= n; i ++)
		A[0][i] = -A[0][i], A[1][i] = -A[1][i];
	reverse(A[0] + 1, A[0] + A[0][0] + 1);
	reverse(A[1] + 1, A[1] + A[1][0] + 1);
	ans += Calc(0);
	printf("%lld\n", ans);
	return 0;
}