#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector> 

using namespace std;

const int MOD = 998244353;

int n,k;
int f[1005][2005][2][2];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	f[1][1][0][0] = f[1][1][1][1] = f[1][2][0][1] = f[1][2][1][0] = 1;
	for (int i = 1;i < n;i++)
		for (int j = 1;j <= k;j++)
		{
			if (f[i][j][0][0])
			{
				(f[i + 1][j][0][0] += f[i][j][0][0]) %= MOD;
				(f[i + 1][j + 1][0][1] += f[i][j][0][0]) %= MOD;
				(f[i + 1][j + 1][1][0] += f[i][j][0][0]) %= MOD;
				(f[i + 1][j + 1][1][1] += f[i][j][0][0]) %= MOD;
			}
			if (f[i][j][0][1])
			{
				(f[i + 1][j][0][0] += f[i][j][0][1]) %= MOD;
				(f[i + 1][j][0][1] += f[i][j][0][1]) %= MOD;
				(f[i + 1][j + 2][1][0] += f[i][j][0][1]) %= MOD;
				(f[i + 1][j][1][1] += f[i][j][0][1]) %= MOD;
			}
			if (f[i][j][1][0])
			{
				(f[i + 1][j][0][0] += f[i][j][1][0]) %= MOD;
				(f[i + 1][j + 2][0][1] += f[i][j][1][0]) %= MOD;
				(f[i + 1][j][1][0] += f[i][j][1][0]) %= MOD;
				(f[i + 1][j][1][1] += f[i][j][1][0]) %= MOD;
			}
			if (f[i][j][1][1])
			{
				(f[i + 1][j + 1][0][0] += f[i][j][1][1]) %= MOD;
				(f[i + 1][j + 1][0][1] += f[i][j][1][1]) %= MOD;
				(f[i + 1][j + 1][1][0] += f[i][j][1][1]) %= MOD;
				(f[i + 1][j][1][1] += f[i][j][1][1]) %= MOD;
			}
		}
	cout << ((f[n][k][0][0] + f[n][k][0][1]) % MOD + (f[n][k][1][0] + f[n][k][1][1]) % MOD) % MOD << endl; 
	return 0;
}