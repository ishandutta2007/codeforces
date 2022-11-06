#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5

int n, m, A[N], B[N], T[N], Ans[N];

bool cmp(int u, int v)
{
	return B[u] < B[v];
}

bool Check(int k)
{
	int sz = 0;
	for (int i = 1; i <= n; i ++)
		if (A[i] >= k)
			T[++ sz] = i;
	if (sz < k) return 0;
	sort(T + 1, T + sz + 1, cmp);
	LL t = 0;
	for (int i = 1; i <= k; i ++)
	{
		t += B[T[i]];
		Ans[i] = T[i];
	}
	return t <= m;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%d%d", A + i, B + i);
	int l = 0, r = n;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (Check(mid)) l = mid;
		else r = mid - 1;
	}
	Check(l);
	printf("%d\n%d\n", l, l);
	if (!l) puts("");
	for (int i = 1; i <= l; i ++)
		printf("%d%c", Ans[i], i == l ? '\n' : ' ');
	return 0;
}