#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5

int Case, n, sz, A[N], T[N];
deque<int> Q;

int Calc(int x)
{
	int ret = 0;
	for (; x; x -= x & -x)
		ret += T[x];
	return ret;
}

void Add(int x, int k)
{
	for (; x <= sz; x += x & -x)
		T[x] += k;
}

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
		{
			scanf("%d", A + i);
			T[i] = A[i];
		}
		sort(T + 1, T + n + 1);
		sz = unique(T + 1, T + n + 1) - T - 1;
		for (int i = 1; i <= n; i ++)
			A[i] = lower_bound(T + 1, T + sz + 1, A[i]) - T;
		for (int i = 1; i <= sz; i ++)
			T[i] = 0;
		Q.clear();
		LL ans = 0;
		for (int i = 1; i <= n; i ++)
		{
			int x = Calc(A[i] - 1);
			int y = i - 1 - Calc(A[i]);
			if (x < y)
				Q.push_front(A[i]);
			else Q.push_back(A[i]);
			Add(A[i], 1);
			ans += min(x, y);
		}
		printf("%lld\n", ans);
	}
	return 0;
}