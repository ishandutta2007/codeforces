#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

const int MAXN = 200005;
const long long MOD = 1000000007;

int n;
long long a[MAXN];
long long tmp[MAXN];
long long C[MAXN]; 

long long mod(long long a,long long m)
{
	a += (-a / m + 1) * m;
	return a % m;
}

long long exp(long long a,long long b)
{
	if (b == 1)
		return a;
	long long tmp = exp(a,b >> 1);
	tmp = mod(tmp * tmp,MOD);
	if (b & 1)
		return mod(tmp * a,MOD);
	return tmp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	if (n == 1)
	{
		cout << mod(a[1],MOD) << endl;
		return 0;
	}
	long long mul = 1;
	if (n % 4 == 1)
	{
		int lim = (n >> 1) + 1;
		C[0] = 1;
		for (int i = 1;i < lim;i++)
			C[i] = (C[i - 1] * (lim - i)) % MOD * exp(i,MOD - 2) % MOD;
		long long ans = 0;
		for (int i = 0;i < n;i++)
		{
			if (!(i & 1))
				ans = mod(ans + mod(a[i + 1] * C[i >> 1],MOD),MOD);
		}
		cout << ans << endl;
		return 0;
	}
	while (n >= 2 && !(n % 2 != 1 && mul == 1))
	{
		for (int i = 1;i <= n;i++)
			tmp[i] = a[i];
		n--;
		for (int i = 1;i <= n;i++)
			a[i] = mod(tmp[i] + mul * tmp[i + 1],MOD),mul *= -1;
	}
	int lim = (n >> 1);
	C[0] = 1;
	for (int i = 1;i < lim;i++)
		C[i] = (C[i - 1] * (lim - i)) % MOD * exp(i,MOD - 2) % MOD;
	long long ans = 0;
	for (int i = 0;i < n;i++)
	{
		if (n % 4 == 0 && (i & 1))
			ans = mod(ans + mod(a[i + 1] * -C[i >> 1],MOD),MOD);
		else
			ans = mod(ans + mod(a[i + 1] * C[i >> 1],MOD),MOD);
	}
	cout << ans << endl;
	return 0;
}