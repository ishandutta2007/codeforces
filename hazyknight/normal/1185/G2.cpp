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

const int MAXN = 55;
const int MAXT = 2505;
const ll MOD = 1000000007;

int n,T;

ll ans;
ll fac[MAXN];
ll f[MAXT][MAXN][MAXN];
ll g[MAXT][MAXN];
ll F[MAXN][MAXN][MAXN];
ll G[MAXN][MAXN][MAXN][3];

vector<int> s[3];

int main()
{
	cin >> n >> T;
	for (int a,b,i = 1;i <= n;i++)
	{
		cin >> a >> b;
		s[b - 1].push_back(a);
	}
	if (s[0].size() > s[1].size())
		swap(s[0],s[1]);
	if (s[0].size() > s[2].size())
		swap(s[0],s[2]);
	if (s[1].size() > s[2].size())
		swap(s[1],s[2]);
	f[0][0][0] = 1;
	for (int i = 0;i < s[0].size();i++)
		for (int j = T - 1;j >= 0;j--)
			for (int k = 0;k <= i;k++)
				if (f[j][k][0] && j + s[0][i] <= T)
					(f[j + s[0][i]][k + 1][0] += f[j][k][0]) %= MOD;
	for (int i = 0;i < s[1].size();i++)
		for (int j = T - 1;j >= 0;j--)
			for (int k = 0;k <= s[0].size();k++)
				for (int l = 0;l <= i;l++)
					if (f[j][k][l] && j + s[1][i] <= T)
						(f[j + s[1][i]][k][l + 1] += f[j][k][l]) %= MOD;
	g[0][0] = 1;
	for (int i = 0;i < s[2].size();i++)
		for (int j = T - 1;j >= 0;j--)
			for (int k = 0;k <= i;k++)
				if (g[j][k] && j + s[2][i] <= T)
					(g[j + s[2][i]][k + 1] += g[j][k]) %= MOD;
	for (int i = 0;i <= T;i++)
		for (int j = 0;j <= s[0].size();j++)
			for (int k = 0;k <= s[1].size();k++)
				if (f[i][j][k])
					for (int l = 0;l <= s[2].size();l++)
						if (g[T - i][l])
							(F[j][k][l] += f[i][j][k] * g[T - i][l]) %= MOD;
	G[1][0][0][0] = G[0][1][0][1] = G[0][0][1][2] = 1;
	for (int i = 0;i <= s[0].size();i++)
		for (int j = 0;j <= s[1].size();j++)
			for (int k = 0;k <= s[2].size();k++)
			{
				if (G[i][j][k][0])
				{
					if (j < s[1].size())
						(G[i][j + 1][k][1] += G[i][j][k][0]) %= MOD;
					if (k < s[2].size())
						(G[i][j][k + 1][2] += G[i][j][k][0]) %= MOD;
				}
				if (G[i][j][k][1])
				{
					if (i < s[0].size())
						(G[i + 1][j][k][0] += G[i][j][k][1]) %= MOD;
					if (k < s[2].size())
						(G[i][j][k + 1][2] += G[i][j][k][1]) %= MOD;
				}
				if (G[i][j][k][2])
				{
					if (i < s[0].size())
						(G[i + 1][j][k][0] += G[i][j][k][2]) %= MOD;
					if (j < s[1].size())
						(G[i][j + 1][k][1] += G[i][j][k][2]) %= MOD;
				}
			}
	fac[0] = 1;
	for (int i = 1;i <= n;i++)
		fac[i] = fac[i - 1] * i % MOD;
	for (int i = 0;i <= s[0].size();i++)
		for (int j = 0;j <= s[1].size();j++)
			for (int k = 0;k <= s[2].size();k++)
				(ans += fac[i] * fac[j] % MOD * fac[k] % MOD * (G[i][j][k][0] + G[i][j][k][1] + G[i][j][k][2]) % MOD * F[i][j][k]) %= MOD;
	cout << ans << endl;
	return 0;
}