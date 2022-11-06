#include <cstdio>
#include <algorithm>
using namespace std;
#define N 10000 + 5

int Case, n, A[N];

int Query(int st, int l, int r)
{
	int sz = 0, res;
	for (int i = l; i <= r; i ++)
		if (i != st)
			A[++ sz] = i;
	printf("1 %d %d", sz, st);
	for (int i = 1; i <= sz; i ++)
		printf(" %d", A[i]);
	printf("\n");
	fflush(stdout);
	scanf("%d", &res);
	return res;
}

int Get(int l, int r, int lim)
{
	if (l == r) return l;
	int mid = l + r >> 1;
	int lhs = Query(n, l, mid);
	if (lhs == lim)
		return Get(l, mid, lim);
	else return Get(mid + 1, r, lim);
}

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		int x = Get(1, n - 1, Query(n, 1, n - 1));
		int res = Query(x, 1, n);
		printf("-1 %d\n", res);
		fflush(stdout);
	}
	return 0;
}