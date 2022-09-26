#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAXN = 505;
const int MAXM = 15;
const int INF = (1 << 30) - 1;

int n,m,id,cur;
int fa[MAXN];
int cnt[MAXN];
int ch[MAXN][MAXM];
int f[MAXN][MAXN][MAXM];
int g[MAXN][MAXN][MAXM];

string s;

void dfs(int now)
{
	for (int i = 1;i <= 10;i++)
		if (ch[now][i])
			dfs(ch[now][i]);
	int last = 0;
	for (int len = 0,i = now;i;i = fa[i],len++)
		for (int j = 0;j <= m;j++)
			g[0][i][j] = len * cnt[now];
	for (int i = 1;i <= 10;i++)
	{
		int to = ch[now][i];
		if (!to)
			continue;
		for (int len = 0,j = now;j;j = fa[j],len++)
			for (int k = 0;k <= m;k++)
			{
				g[i][j][k] = INF;
				for (int l = 0;l <= k;l++)
					g[i][j][k] = min(g[i][j][k],g[last][j][k - l] + min(f[to][j][l],l > 0 ? f[to][to][l - 1] : INF));
			}
		last = i;
	}
	for (int len = 0,i = now;i;i = fa[i],len++)
		for (int j = 0;j <= m;j++)
			f[now][i][j] = g[last][i][j];
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	id = 1;
	for (int v,i = 1;i <= n;i++)
	{
		cin >> s >> v;
		cur = 1;
		for (int j = 0;j < s.size();j++)
		{
			if (!ch[cur][s[j] == '0' ? 10 : s[j] - '0'])
				fa[ch[cur][s[j] == '0' ? 10 : s[j] - '0'] = ++id] = cur;
			cur = ch[cur][s[j] == '0' ? 10 : s[j] - '0'];
		}
		cnt[cur] += v;
	}
	dfs(1);
	cout << f[1][1][m] << endl;
	return 0;
}