#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

int T,n,m;
int cnt[MAXN];
int a[MAXN];
int pos[MAXN];
int to[MAXN];

bool vis[MAXN];

vector<int> ans;

bool check(int t)
{
	int p = 0;
	for (int i = n - t + 1;i <= n;i++)
		pos[i] = ++p;
	for (int i = 1;i <= n - t;i++)
		pos[i] = ++p;
	for (int i = 1;i <= n;i++)
		to[i] = pos[a[i]];
	int tot = 0;
	for (int i = 1;i <= n;i++)
		vis[i] = 0;
	for (int i = 1;i <= n;i++)
		if (!vis[i])
		{
			int sz = 0,u = i;
			while (!vis[u])
			{
				vis[u] = 1;
				sz++;
				u = to[u];
			}
			tot += sz - 1;
		}
	return tot <= m;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 0;i < n;i++)
			cnt[i] = 0;
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			cnt[(i - a[i] + n) % n]++;
		}
		ans.clear();
		for (int i = 0;i < n;i++)
			if (cnt[i] >= n - 2 * m && check(i))
				ans.push_back(i);
		printf("%d ",(int)ans.size());
		for (int i = 0;i < ans.size();i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}