#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5
#define M 5000 + 5 

int n, m, k, p, H[N], A[N], T[M];
LL l, r, Final[N];

inline bool Check(LL lim)
{
	LL tot = 0;
	for (int i = 1; i <= n; i ++)
		tot += max(0LL, (Final[i] - lim + p - 1) / p);
	if (tot > m * k) return 0;
	memset(T, 0, sizeof(T));
	for (int i = 1; i <= n; i ++)
	{
		if (Final[i] <= lim) continue ;
		for (LL t = (Final[i] - lim - 1) % p + 1; t <= Final[i] - lim; t += p)
		{
			if (t <= H[i]) T[0] ++;
			else if (t > Final[i] - A[i]) return 0;
			else T[(t - H[i] + A[i] - 1) / A[i]] ++;
		}
	}
	int ret = 0;
	for (int i = 0; i < m; i ++)
	{
		ret += T[i];
		ret = max(0, ret - k);
	}
	return ret == 0;
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &p);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d%d", H + i, A + i);
		l = max(l, (LL) A[i]);
		r = max(r, Final[i] = 1LL * m * A[i] + H[i]);
	}
	while (l < r)
	{
		LL mid = l + r >> 1;
		if (Check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%I64d\n", l);
	return 0;
}