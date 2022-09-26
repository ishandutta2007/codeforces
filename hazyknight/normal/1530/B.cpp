#include <bits/stdc++.h>

using namespace std;

const int MAXN = 25;

int T,n,m;

bool vis[MAXN][MAXN];
bool finl[MAXN][MAXN];

bool ok(int x,int y)
{
	for (int i = -1;i <= 1;i++)
		for (int j = -1;j <= 1;j++)
			if (x + i <= n && y + j <= m && x + i >= 1 && y + j >= 1 && vis[x + i][y + j])
				return 0;
	return 1;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		vector<pair<int,int> > v;
		int ans = 0;
		for (int i = 1;i <= n;i++)
			v.push_back(make_pair(i,1));
		for (int i = 2;i <= m;i++)
			v.push_back(make_pair(n,i));
		for (int i = n - 1;i >= 1;i--)
			v.push_back(make_pair(i,m));
		for (int i = m - 1;i >= 2;i--)
			v.push_back(make_pair(1,i));
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				vis[i][j] = 0;
		int cnt = 1;
		vis[1][1] = 1;
		for (int i = 0;i < v.size();i++)
			if (ok(v[i].first,v[i].second))
				vis[v[i].first][v[i].second] = 1,cnt++;
		if (cnt > ans)
		{
			ans = cnt;
			memcpy(finl,vis,sizeof(vis));
		}
		
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				vis[i][j] = 0;
		cnt = 1;
		vis[2][1] = 1;
		for (int i = 0;i < v.size();i++)
			if (ok(v[i].first,v[i].second))
				vis[v[i].first][v[i].second] = 1,cnt++;
		if (cnt > ans)
		{
			ans = cnt;
			memcpy(finl,vis,sizeof(vis));
		}
		
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				vis[i][j] = 0;
		cnt = 1;
		vis[3][1] = 1;
		for (int i = 0;i < v.size();i++)
			if (ok(v[i].first,v[i].second))
				vis[v[i].first][v[i].second] = 1,cnt++;
		if (cnt > ans)
		{
			ans = cnt;
			memcpy(finl,vis,sizeof(vis));
		}
		
		for (int i = 1;i <= n;i++,printf("\n"))
			for (int j = 1;j <= m;j++)
				printf("%d",(int)finl[i][j]);
	}
	return 0;
}