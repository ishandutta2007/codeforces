#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n,tot,ans;
int a[MAXN];
int sum[MAXN][105];
int st[MAXN << 1];
int ed[MAXN << 1];
int c[MAXN];
int p[MAXN];

vector<int> pos[105];

bool ok(int l,int r,int lim)
{
	for (int i = 1;i <= 100;i++)
		if (sum[r][i] - sum[l - 1][i] > lim)
			return 0;
	return 1;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		for (int j = 1;j <= 100;j++)
			sum[i][j] = sum[i - 1][j] + (a[i] == j);
		pos[a[i]].push_back(i);
	}
	for (int i = 1;i <= 100;i++)
		for (int j = i + 1;j <= 100;j++)
		{
			tot = 0;
			int k = 0,l = 0;
			while (k < pos[i].size() && l < pos[j].size())
			{
				if (pos[i][k] < pos[j][l])
					p[++tot] = pos[i][k++];
				else
					p[++tot] = pos[j][l++];
			}
			while (k < pos[i].size())
				p[++tot] = pos[i][k++];
			while (l < pos[j].size())
				p[++tot] = pos[j][l++];
			p[tot + 1] = n + 1;
			for (int k = -tot;k <= tot;k++)
			{
				st[k + tot] = -1;
				ed[k + tot] = 0;
			}
			st[tot] = 0;
			for (int k = 1;k <= tot;k++)
			{
				c[k] = c[k - 1] + (a[p[k]] == i ? 1 : -1);
				if (st[c[k] + tot] == -1)
					st[c[k] + tot] = k;
				ed[c[k] + tot] = k;
			}
			for (int k = -tot;k <= tot;k++)
				if (~st[k + tot])
				{
					int l = p[st[k + tot]] + 1,r = p[ed[k + tot] + 1] - 1;
					if (ans < r - l + 1 && ok(l,r,(ed[k + tot] - st[k + tot]) / 2))
						ans = r - l + 1;
				}
		}
	printf("%d\n",ans);
	return 0;
}