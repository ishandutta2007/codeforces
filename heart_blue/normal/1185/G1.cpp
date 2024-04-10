#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e5 + 10;
const int M = 51;
int dp1[4][2510][51];
int dp2[M][M][M][4];
vector<int> v[4];
LL fact[M];
LL f[M][M][M];
int dfs(int x, int y, int z, int o)
{
	if (x == 0 && y == 0 && z == 0)
	{
		return 1;
	}
	if (x < 0 || y < 0 || z < 0) return 0;
	if (dp2[x][y][z][o] != -1)
		return dp2[x][y][z][o];
	int a[] = { 0,x,y,z };
	LL ret = 0;
	for (int i = 1; i <= 3; i++)
	{
		if (i == o) continue;
		a[i]--;
		ret += dfs(a[1], a[2], a[3], i);
		a[i]++;
	}
	return dp2[x][y][z][o] = ret % INF;
}
void init()
{
	fact[0] = 1;
	for (int i = 1; i < M; i++)
		fact[i] = fact[i - 1] * i % INF;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < M; k++)
				f[i][j][k] = fact[i] * fact[j] % INF * fact[k] % INF;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	MEM(dp2, -1);
	int n, T;
	scanf("%d%d", &n, &T);
	for (int i = 1; i <= n; i++)
	{
		int t, g;
		scanf("%d%d", &t, &g);
		v[g].push_back(t);
	}
	for (int o = 1; o <= 3; o++)
	{
		int tot = 0;
		int sz = 0;
		sort(v[o].begin(), v[o].end());
		dp1[o][0][0] = 1;
		for (auto& x : v[o])
		{
			tot += x;
			sz++;
			for (int i = tot; i >= x; i--)
			{
				for (int j = sz; j >= 1; j--)
				{
					dp1[o][i][j] += dp1[o][i - x][j - 1];
					if (dp1[o][i][j] >= INF)
						dp1[o][i][j] -= INF;
				}
			}
		}
	}
	LL ans = 0;
	for (int i = 0; i <= T; i++)
	{
		for (int s1 = 0; s1 <= v[1].size(); s1++)
		{
			if (dp1[1][i][s1] == 0) continue;
			for (int j = 0; j <= T - i; j++)
			{
				for (int s2 = 0; s2 <= v[2].size(); s2++)
				{
					if (dp1[2][j][s2] == 0) continue;
					int k = T - i - j;
					for (int s3 = 0; s3 <= v[3].size(); s3++)
					{
						if (dp1[3][k][s3] == 0) continue;
						LL tot = 1LL * dp1[1][i][s1] * dp1[2][j][s2] % INF * dp1[3][k][s3] % INF;
						ans += f[s1][s2][s3] * dfs(s1, s2, s3, 0) % INF * tot % INF;
					}
				}
			}
		}
	}
	printf("%lld\n", ans % INF);
	return 0;
}