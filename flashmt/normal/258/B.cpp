#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
const int base = 1000000007;

int d[11], c[11][11], isLucky[10], fact[11];
long long f[7][11];

long long power(int x, int y)
{
	if (!y) return 1;
	long long res = power(x, y / 2);
	res *= res; res %= base;
	if (y % 2) res *= x, res %= base;
	return res;
}

long long C(int n, int k)
{
	if (!k) return 1;
	return C(n, k - 1) * (n - k + 1) % base * power(k, base - 2) % base;
}

void calc(int n)
{
	int a[11], l = 0, tmp = n, sofar = 0;
	while (tmp) a[l++] = tmp % 10, tmp /= 10;
	for (int i = l - 1; i >= 0; i--)
	{
		for (int j = 0; j < a[i]; j++) 
			for (int k = 0; k <= i; k++)
				d[sofar + k + isLucky[j]] += (c[i][k] << k << (3 * (i - k)));
		sofar += isLucky[a[i]];
	}
	d[sofar]++;
}

int main()
{
	isLucky[4] = isLucky[7] = 1;
	for (int i = 0; i < 11; i++) fact[i] = i ? fact[i - 1] * i : 1;
	for (int i = 0; i < 11; i++)
		for (int j = 0; j <= i; j++)
			c[i][j] = j ? c[i - 1][j] + c[i - 1][j - 1] : 1;
		
	int n;
	cin >> n;
	calc(n);
	d[0]--;
	
	f[0][0] = 1;
	for (int i = 0; i < 10; i++)
		for (int j = 5; j >= 0; j--)
			for (int k = 8; k >= 0; k--)
				for (int p = 1; p <= d[i]; p++)
					if (p * i + k < 10 && p + j <= 6)
					{
						long long u = f[j][k] * C(d[i], p) % base * fact[p] % base * c[6 - j][p] % base;
						f[j + p][k + p * i] += u;
						f[j + p][k + p * i] %= base;
					}		
					else break;
			
	long long ans = 0;
	for (int k = 0; k < 9; k++)
		for (int kk = k + 1; kk < 10; kk++)
		{
			ans += f[6][k] * d[kk];
			ans %= base;
		}
	
	cout << ans << endl;
}