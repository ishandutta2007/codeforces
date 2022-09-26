#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

const long long MOD = 1000000007;

long long x[300005];
long long sum[300005];
long long bits[300005];

long long n,ans;

void init()
{
	bits[0] = 1;
	for (int i = 1;i <= n;i++)
		bits[i] = (bits[i - 1] << 1) % MOD;
	for (int i = 1;i <= n;i++)
		sum[i] = (sum[i - 1] + x[i]) % MOD;
}

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> x[i];
	sort(x + 1,x + n + 1);
	init();
	for (int len = 2;len <= n;len++)
	{
		long long ret = sum[n] - sum[len - 1] - sum[n - len + 1];
		while (ret < 0)
			ret += MOD;
		(ret *= bits[len - 2]) %= MOD;
		(ans += ret) %= MOD;
	}
	cout << ans << endl;
	return 0;
}