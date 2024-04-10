#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

long long ways[50][1010], fact[3333] , invFact[3333];
long long ans[1010][1010];

long long power(long long x, int y)
{
	if (!y) return 1;
	long long res = power(x, y / 2);
	res = res * res % BASE;
	if (y % 2) res = res * x % BASE;
	return res;
}

long long p(int n, int k)
{
	return fact[n] * invFact[n - k] % BASE;
}

int main()
{
	ways[0][0] = 1;
	for (int i = 0; i <= 1000; i++)
		for (int numGroup = 45; numGroup; numGroup--)
			for (int sum = 1000; sum >= i; sum--)
			{
				ways[numGroup][sum] += ways[numGroup - 1][sum - i];
				ways[numGroup][sum] %= BASE;
			}
			
	fact[0] = 1;
	for (int i = 1; i <= 3000; i++) fact[i] = fact[i - 1] * i % BASE;
	for (int i = 0; i <= 3000; i++) invFact[i] = power(fact[i], BASE - 2);
	
	for (int n = 0; n <= 1000; n++)
		for (int k = 1; k <= 1000; k++)
			if (k * (k - 1) / 2 + k - 1 <= n)
				for (int sum = 0; sum + k - 1 <= n; sum++)
				{
					ans[n][k] += p(n + 1 - sum, k) * ways[k][sum];
					ans[n][k] %= BASE;
				}
	
	int test;
	cin >> test;
	while (test--)
	{
		int n, k;
		cin >> n >> k;
		cout << ans[n - 1][k] << endl;
	}
}