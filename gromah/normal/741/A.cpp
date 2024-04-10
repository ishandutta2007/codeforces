#include <cstdio>
typedef long long LL;
#define N 100 + 5

int n, A[N];
bool ok = 1, Flag[N];
LL ans = 1;

inline LL gcd(LL x, LL y)
{
	return !y ? x : gcd(y, x % y);
}

inline bool Solve()
{
	for (int i = 1; i <= n; i ++)
	{
		if (!Flag[i]) continue ;
		int cnt = 1;
		for (int j = A[i]; j != i; j = A[j]) cnt ++;
		if (cnt + 1 & 1) cnt >>= 1;
		LL d = gcd(cnt, ans);
		ans = ans * cnt / d;
	}
	printf("%I64d\n", ans);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		if (Flag[A[i]]) ok = 0;
		Flag[A[i]] = 1;
	}
	if (!ok) puts("-1");
	else Solve();
	return 0;
}