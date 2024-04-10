#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 20005;
const int MAXM = 40005;
const int INF = 1e9;

struct Stock
{
	int a,b,id;
	ll val;
}s[MAXN];

struct Edge
{
	int to;
	int cap;
	int cst;
	int nxt;
}edge[MAXM << 1];

int n,id,S,T,ans;
int first[MAXN];
int dis[MAXN];
int a[MAXN];
int b[MAXN];
int cnt[MAXN];

bool vis[MAXN];
bool inqueue[MAXN];

queue<int> Q;

bool cmp(const Stock &a,const Stock &b)
{
	return a.val == b.val ? cnt[a.id] < cnt[b.id] : a.val < b.val;
}

void addE(int u,int v,int c,int w)
{
	edge[++id] = (Edge){v,c,w,first[u]};
	first[u] = id;
	edge[++id] = (Edge){u,0,-w,first[v]};
	first[v] = id;
}

bool ok(int t)
{
	memset(cnt,0,sizeof(cnt));
	for (int i = 1;i <= 2 * n;i++)
		s[i].val = s[i].b;
	sort(s + 1,s + 2 * n + 1,cmp);
	for (int i = 1;i <= 2 * n;i++)
		s[i].val = (ll)s[i].a * t + s[i].b;
	ll MAX = 0;
	for (int i = 1,j = 0;i <= 2 * n;i++)
	{
		while (j + 1 <= 2 * n && s[i].b >= s[j + 1].b)
		{
			j++;
			if (!MAX || s[j].val >= s[MAX].val)
				MAX = j;
		}
		if (s[i].id <= n)
			cnt[s[MAX].id]++;
	}
	sort(s + 1,s + 2 * n + 1,cmp);
	int tot = 0;
	for (int i = 2 * n;i >= 1;i--)
	{
		tot += cnt[s[i].id];
		if (!tot && s[i].id > n)
			return 0;
		if (s[i].id > n)
			tot--;
	}
	return 1;
}

bool SPFA()
{
	for (int i = S;i <= T;i++)
		dis[i] = INF;
	dis[S] = 0;
	inqueue[S] = 1;
	Q.push(S);
	while (!Q.empty())
	{
		int u = Q.front();
		inqueue[u] = 0;
		Q.pop();
		for (int i = first[u];i;i = edge[i].nxt)
			if (edge[i].cap && dis[edge[i].to] > dis[u] + edge[i].cst)
			{
				dis[edge[i].to] = dis[u] + edge[i].cst;
				if (!inqueue[edge[i].to])
				{
					inqueue[edge[i].to] = 1;
					Q.push(edge[i].to);
				}
			}
	}
	return dis[T] != INF;
}

int dfs(int u,int f)
{
	if (u == T)
		return f;
	vis[u] = 1;
	int res = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (!vis[edge[i].to] && edge[i].cap && dis[edge[i].to] == dis[u] + edge[i].cst)
		{
			int ret = dfs(edge[i].to,min(f,edge[i].cap));
			ans += edge[i].cst * ret;
			edge[i].cap -= ret;
			edge[i ^ 1].cap += ret;
			f -= ret;
			res += ret;
			if (!f)
				break;
		}
	return res;
}

void build(int t)
{
	S = 0,T = 8 * n + 1;
	id = 1;
	for (int i = 1;i <= n;i++)
		addE(S,i * 4 - 2,1,0);
	for (int i = n + 1;i <= 2 * n;i++)
		addE(i * 4 - 1,T,1,0);
	for (int i = 1;i <= 2 * n;i++)
		addE(i * 4 - 2,i * 4 - 1,INF,0);
	for (int i = 1;i <= 2 * n;i++)
	{
		addE(i * 4 - 3,i * 4 - 2,INF,0);
		addE(i * 4,i * 4 - 1,INF,0);
	}
	for (int i = 1;i <= 2 * n;i++)
		s[i].val = s[i].b;
	sort(s + 1,s + 2 * n + 1,cmp);
	for (int i = 1;i < 2 * n;i++)
		addE(s[i + 1].id * 4 - 3,s[i].id * 4 - 3,INF,0);
	for (int i = 1,j = 0;i <= 2 * n;i++)
	{
		while (j + 1 <= 2 * n && s[i].val >= s[j + 1].val)
			j++;
		if (j)
			addE(s[i].id * 4 - 2,s[j].id * 4 - 3,INF,1);
	}
	for (int i = 1;i <= 2 * n;i++)
		s[i].val = (ll)s[i].a * t + s[i].b;
	sort(s + 1,s + 2 * n + 1,cmp);
	for (int i = 1;i < 2 * n;i++)
		addE(s[i + 1].id * 4,s[i].id * 4,INF,0);
	for (int i = 1,j = 0;i <= 2 * n;i++)
	{
		while (j + 1 <= 2 * n && s[i].val >= s[j + 1].val)
			j++;
		if (j)
			addE(s[i].id * 4 - 1,s[j].id * 4,INF,1);
	}
}

int mcmf()
{
	int res = 0;
	while (SPFA())
	{
		while (int tot = dfs(S,INF))
			memset(vis,0,sizeof(vis));
		memset(vis,0,sizeof(vis));
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= 2 * n;i++)
	{
		scanf("%d%d",&s[i].a,&s[i].b);
		s[i].id = i;
	}
	if (!ok(INF + 1))
	{
		puts("-1");
		return 0;
	}
	int low = 0,high = INF;
	while (low < high)
	{
		int mid = low + high >> 1;
		if (ok(mid))
			high = mid;
		else
			low = mid + 1;
	}
	build(low);
	printf("%d %d\n",low,mcmf());
	return 0;
}