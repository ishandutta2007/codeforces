#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1000005;
const ll MOD = 998244353;

int n;
int cnt[MAXN];

ll f[MAXN];

int main()
{
	scanf("%d",&n);
	ll sum = 0;
	f[1] = 1;
	sum++;
	for (int i = 1;i <= n;i++)
		for (int j = i;j <= n;j += i)
			cnt[j]++;
	for (int i = 2;i <= n;i++)
	{
		f[i] = (sum + cnt[i]) % MOD;
		(sum += f[i]) %= MOD;
	}
	printf("%lld\n",f[n]);
	return 0;
}