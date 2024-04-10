#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 2005;
const ll MOD = 1000000007;

int n,m;

ll f[MAXN][MAXN][2];

char s[MAXN];

ll power(ll a,ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			(res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}

int main()
{
	scanf("%d%d%s",&n,&m,s + 1);
	f[0][0][0] = 1;
	for (int i = 0;i < n;i++)
		for (int j = 0;j <= m;j++)
		{
			if (f[i][j][0])
			{
				(f[i + 1][j][0] += f[i][j][0] * (s[i + 1] - 'a')) %= MOD;
				(f[i + 1][j][1] += f[i][j][0]) %= MOD;
				int ed = n;
				for (int k = i + 1;k <= n;k++)
				{
					if (j + (n - k + 1) * (k - i) > m)
					{
						ed = k - 1;
						break;
					}
					(f[k][j + (n - k + 1) * (k - i)][0] += f[i][j][0] * ('z' - s[k])) %= MOD;
				}
				if (ed < n)
				{
					for (int k = n;k >= i + 1;k--)
					{
						if (j + (n - k + 1) * (k - i) > m)
						{
							ed = k - 1;
							break;
						}
						(f[k][j + (n - k + 1) * (k - i)][0] += f[i][j][0] * ('z' - s[k])) %= MOD;
					}
				}
			}
			if (f[i][j][1])
			{
				(f[i + 1][j][1] += f[i][j][1]) %= MOD;
				(f[i + 1][j][0] += f[i][j][1] * (s[i + 1] - 'a')) %= MOD;
			}
		}
	printf("%lld\n",(f[n][m][0] + f[n][m][1]) % MOD);
	return 0;
}