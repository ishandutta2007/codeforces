#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int MAXN = 2005;
const long long MOD = 998244353;

long long pow(long long a,long long b)
{
	if (!b)
		return 1;
	long long ret = pow(a,b >> 1);
	ret = (ret * ret) % MOD;
	if (b & 1)
		return ret * a % MOD;
	return ret;
}

long long n,a,b;
long long p[2005][2];
long long f[2005];
long long g[2005];
long long h[2005][2005];

int main()
{
	cin >> n >> a >> b;
	p[0][0] = p[0][1] = 1;
	p[1][0] = a * pow(b,MOD - 2) % MOD;
	p[1][1] = 1 - p[1][0];
	for (int i = 2;i <= n;i++)
		p[i][0] = (p[i - 1][0] * p[1][0]) % MOD,p[i][1] = (p[i - 1][1] * p[1][1]) % MOD;
	h[0][0] = 1;
	for (int i = 0;i < n;i++)
		for (int j = 0;j <= i;j++)
		{
			h[i + 1][j] = (h[i + 1][j] + h[i][j] * p[j][0]) % MOD;
			h[i + 1][j + 1] = (h[i + 1][j + 1] + h[i][j] * p[i - j][1]) % MOD;
		}
	for (int i = 1;i <= n;i++)
	{
		g[i] = 1;
		for (int j = 1;j < i;j++)
			g[i] = (g[i] - g[j] * h[i][j]) % MOD;
	}
	f[0] = f[1] = 0;
	for (int i = 2;i <= n;i++)
	{
		for (int j = 1;j < i;j++)
			f[i] = (f[i] + g[j] * h[i][j] % MOD * (j * (i - j) + j * (j - 1) / 2 + f[j] + f[i - j]) % MOD) % MOD;
		f[i] = (f[i] + g[i] % MOD * (i * (i - 1) / 2)) % MOD;
		f[i] = (f[i] * pow(1 - g[i],MOD - 2)) % MOD;
	}
	cout << (f[n] + MOD) % MOD << endl;
	return 0;
}