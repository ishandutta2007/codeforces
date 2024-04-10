#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double db;

const int MAXN = 4000005;

int n,MOD;
int f[MAXN];
int dif[MAXN];

int main()
{
	scanf("%d%d",&n,&MOD);
	f[1] = 1;
	int sum = 1;
	int sum2 = 0;
	for (int i = 2;i <= n;i++)
		dif[i] = 1;
	for (int i = 2;i <= n;i++)
	{
		(f[i] += sum) %= MOD;
		(sum2 += dif[i]) %= MOD;
		(f[i] += sum2) %= MOD;
		(sum += f[i]) %= MOD;
		for (int j = 1;i * j <= n;j++)
			dif[i * j] = ((ll)dif[i * j] + f[i] - f[i - 1]) % MOD;
	}
	printf("%d\n",(f[n] + MOD) % MOD);
	return 0;
}