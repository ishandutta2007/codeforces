#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int T,n,m;
int col[MAXN];
int A[MAXN];
int B[MAXN];

bool vis[MAXN][2];
bool mark[MAXN];

vector<int> ans;
vector<int> e[MAXN];

void work()
{
	for (int i = 1;i <= n;i++)
	{
		vis[i][0] = vis[i][1] = mark[i] = 0;
		col[i] = -1;
	}
	for (int i = 1;i <= n;i++)
	{
		if (mark[i])
			continue;
		bool must[2] = {0};
		for (int j = 0;j < e[i].size();j++)
		{
			if (mark[e[i][j]])
				continue;
			vis[i][col[e[i][j]]] = 1;
			if (vis[e[i][j]][0] && col[e[i][j]] == 0)
				must[1] = 1;
			if (vis[e[i][j]][1] && col[e[i][j]] == 1)
				must[0] = 1;
		}
		if (must[0] && must[1])
			mark[i] = 1;
		else if (must[0])
			col[i] = 0;
		else if (must[1])
			col[i] = 1;
		else
		{
			if (!vis[i][0] && vis[i][1])
				col[i] = 0;
			else if (vis[i][0] && !vis[i][1])
				col[i] = 1;
			else
				col[i] = rand() % 2;
		}
	}
	int cnt[2] = {0};
	for (int i = 1;i <= n;i++)
		if (!mark[i])
			cnt[col[i]]++;
	int flag = (cnt[0] >= cnt[1]);
	for (int i = 1;i <= n;i++)
		if (!mark[i] && col[i] == flag)
			mark[i] = 1;
	ans.clear();
	for (int i = 1;i <= n;i++)
		if (mark[i])
			ans.push_back(i);
}

int main()
{
	srand(20030506);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++)
			e[i].clear();
		for (int i = 1;i <= m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			e[v].push_back(u);
		}
		work();
		while (ans.size() > 4. / 7 * n)
			work();
		printf("%d\n",(int)ans.size());
		for (int i = 0;i < ans.size();i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}