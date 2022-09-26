#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int T,n,m;
int dis[MAXN];

bool mark[MAXN];

vector<int> e[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++)
			e[i].clear();
		for (int u,v,i = 1;i <= m;i++)
		{
			scanf("%d%d",&u,&v);
			e[v].push_back(u);
		}
		for (int i = 1;i <= n;i++)
			mark[i] = 0;
		int tot = 0; 
		for (int i = 1;i <= n;i++)
		{
			int MAX = -1;
			for (int j = 0;j < e[i].size();j++) 
				if (!mark[e[i][j]])
					MAX = max(MAX,dis[e[i][j]]);
			if (MAX == 1)
				mark[i] = 1,tot++;
			else
				dis[i] = MAX + 1;
		}
		printf("%d\n",tot);
		for (int i = 1;i <= n;i++)
			if (mark[i])
				printf("%d ",i);
		printf("\n");
	} 
	return 0;
}