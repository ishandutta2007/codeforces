#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int MAXN = 305;
const int MAXM = 50005;

struct Edge
{
	int to;
	int next;
}edge[MAXM << 1];

int n,V,m,p,id;
int first[MAXN];
int a[MAXN];
int b[MAXN];
int u[MAXM];
int v[MAXM];
int seq[MAXN];
int pre[MAXN];

long long SumA,SumB;

bool mark[MAXN];

vector<pair<pair<int,int>,int> > ans;

void move(int u,int v,int c)
{
	if (!c)
		return;
	ans.push_back(make_pair(make_pair(u,v),c));
	a[u] -= c;
	a[v] += c;
}

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int now)
{
	mark[now] = true;
	SumA += a[now];
	SumB += b[now];
	for (int i = first[now];i;i = edge[i].next)
		if (!mark[edge[i].to])
		{
			m++;
			u[m] = now;
			v[m] = edge[i].to;
			dfs(edge[i].to);
		}
}

void Sort(int now,int fa)
{
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa)
		{
			pre[edge[i].to] = now;
			Sort(edge[i].to,now);
		}
	seq[++p] = now;
}

void suck(int now,int fa)
{
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa && !mark[edge[i].to])
		{
			suck(edge[i].to,now);
			if (a[edge[i].to] <= V - a[now])
				move(edge[i].to,now,a[edge[i].to]);
			else
				move(edge[i].to,now,V - a[now]);
		}
}

void drain(int now,int fa)
{
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa && !mark[edge[i].to])
		{
			drain(edge[i].to,now);
			if (a[now] <= V - a[edge[i].to])
				move(now,edge[i].to,a[now]);
			else
				move(now,edge[i].to,V - a[edge[i].to]);
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> V >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
		cin >> b[i];
	for (int i = 1;i <= m;i++)
	{
		cin >> u[i] >> v[i];
		addE(u[i],v[i]);
		addE(v[i],u[i]);
	}
	m = 0;
	for (int i = 1;i <= n;i++)
		if (!mark[i])
		{
			SumA = SumB = 0;
			dfs(i);
			if (SumA != SumB)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	memset(first,0,sizeof(first));
	memset(mark,0,sizeof(mark));
	id = 0;
	for (int i = 1;i <= m;i++)
	{
		addE(u[i],v[i]);
		addE(v[i],u[i]);
	}
	for (int i = 1;i <= n;i++)
		if (!mark[i])
		{
			p = 0;
			Sort(i,0);
			for (int j = 1;j <= p;j++)
			{
				int cur = seq[j];
				if (a[cur] < b[cur])
				{
					suck(pre[cur],cur);
					move(pre[cur],cur,b[cur] - a[cur]);
				}
				if (a[cur] > b[cur])
				{
					drain(pre[cur],cur);
					move(cur,pre[cur],a[cur] - b[cur]);
				}
				mark[cur] = true;
			}
		}
	cout << ans.size() << endl;
	for (int i = 0;i < ans.size();i++)
		cout << ans[i].first.first << ' ' << ans[i].first.second << ' ' << ans[i].second << endl;
	return 0;
}