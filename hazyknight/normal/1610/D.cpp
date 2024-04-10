#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
const int MOD = 1000000007;

int T,n,m,ans;
int a[MAXN];
int b[MAXN];
int pw[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		if (~a[i] & 1)
			b[++m] = a[i] >> 1;
	}
	pw[0] = 1;
	for (int i = 1;i <= n;i++)
		pw[i] = pw[i - 1] * 2 % MOD;
	for (int i = 0;(1 << i) <= 1e9;i++)
	{
		int S = 1 << i;
		int odd = 0,even = 0;
		for (int j = 1;j <= m;j++)
			if (b[j] % S == 0)
			{
				int t = b[j] / S;
				if (t & 1)
					odd++;
				else
					even++;
			}
		if (odd)
			(ans += pw[odd + even - 1]) %= MOD;
	}
	printf("%d\n",(pw[n] - 1 - ans + MOD) % MOD);
	return 0;
}