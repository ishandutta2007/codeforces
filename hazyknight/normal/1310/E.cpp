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

const int MAXN = 2025;
const int MOD = 998244353;

int n,k;

namespace Task1
{

int ans;
int f[MAXN][MAXN];
int sum[MAXN][MAXN];

void solve()
{
	f[0][n] = 1;
	for (int i = n;i >= 1;i--)
		sum[0][i] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = i;j >= 1;j--)
		{
			f[i][j] = sum[i - j][j];
			(ans += f[i][j]) %= MOD;
			sum[i][j] = (sum[i][j + 1] + f[i][j]) % MOD;
		}
	printf("%d\n",ans);
}

}

namespace Task2
{

int ans,N;

vector<int> f[MAXN][70];
vector<int> sum[MAXN][70];

void solve()
{
	N = min(n,65);
	for (int i = 0;i <= n;i++)
	{
		f[i][0].resize(MAXN);
		sum[i][0].resize(MAXN);
		for (int j = 1;j <= N;j++)
		{
			f[i][j].resize(i / j + 2);
			sum[i][j].resize(i / j + 2);
		}
	}
	f[0][0][n] = 1;
	for (int i = n;i >= 1;i--)
		sum[0][0][i] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= N;j++)
			for (int k = i / j;k >= 1;k--)
			{
				if (sum[i - j * k][j - 1].size() > k)
					f[i][j][k] = sum[i - j * k][j - 1][k];
				(ans += f[i][j][k]) %= MOD;
				sum[i][j][k] = (sum[i][j][k + 1] + f[i][j][k]) % MOD;
			}
	printf("%d\n",ans);
}

}

namespace Task3
{

int ans;

vector<int> a;

bool chk(vector<int> t)
{
	int K = k;
	while (K--)
	{
		vector<int> tt;
		int sum = 0;
		for (int i = 0;i < t.size();i++)
			sum += t[i];
		if (sum > n)
			return 0;
		tt.resize(sum);
		int tot = 0;
		for (int i = t.size() - 1;i >= 0;i--)
			for (int j = 1;j <= t[i];j++)
				tt[tot++] = i + 1;
		swap(tt,t);
	}
	return 1;
}

void dfs(int d)
{
	if (d > 1 && !chk(a))
		return;
	if (d > 1)
		ans++;
	int t = d > 1 ? a.back() : n;
	for (int i = 1;i <= t;i++)
	{
		a.push_back(i);
		int tmp = ans;
		dfs(d + 1);
		a.pop_back();
		if (ans == tmp)
			return;
	}
}

void solve()
{
	dfs(1);
	printf("%d\n",ans);
}

}

int main()
{
	scanf("%d%d",&n,&k);
	if (k == 1)
		Task1::solve();
	if (k == 2)
		Task2::solve();
	if (k >= 3)
		Task3::solve();
	return 0;
}