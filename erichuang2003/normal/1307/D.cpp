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

const int MAXN = 200005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,m,k,id;
int a[MAXN];
int MAX[MAXN];
int MAX2[MAXN];
int first[MAXN];
int disS[MAXN];
int disT[MAXN];

queue<int> Q;

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void bfs(int cur,int *dis)
{
	for (int i = 1;i <= n;i++)
		dis[i] = 1e9;
	dis[cur] = 0;
	Q.push(cur);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = first[u];i;i = edge[i].nxt)
			if (dis[edge[i].to] == 1e9)
			{
				dis[edge[i].to] = dis[u] + 1;
				Q.push(edge[i].to);
			}
	}
}

void update(int &mx,int &mx2,int v)
{
	if (v >= mx)
	{
		mx2 = mx;
		mx = v;
	}
	else if (v > mx2)
		mx2 = v;
}

void modify(int p,int v)
{
	p = n - p + 1;
	while (p <= n)
	{
		update(MAX[p],MAX2[p],v);
		p += p & -p;
	}
}

pair<int,int> query(int p)
{
	if (p < 1)
		p = 1;
	p = n - p + 1;
	int res = -1e9,res2 = -1e9;
	while (p >= 1)
	{
		update(res,res2,MAX[p]);
		update(res,res2,MAX2[p]);
		p -= p & -p;
	}
	return make_pair(res,res2);
}

bool ok(int lim)
{
	for (int i = 1;i <= k;i++)
	{
		pair<int,int> r = query(lim - disT[a[i]] - 1);
		int len = (r.first == disT[a[i]] ? r.second : r.first);
		if (len + 1 + disS[a[i]] >= lim)
			return 1;
	}
	return 0;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= k;i++)
		scanf("%d",&a[i]);
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	bfs(1,disS);
	bfs(n,disT);
	for (int i = 1;i <= n;i++)
		MAX[i] = MAX2[i] = -1e9;
	for (int i = 1;i <= k;i++)
		modify(disS[a[i]],disT[a[i]]);
	int low = 1,high = disS[n];
	while (low < high)
	{
		int mid = low + high + 1 >> 1;
		if (ok(mid))
			low = mid;
		else
			high = mid - 1;
	}
	printf("%d\n",low);
	return 0;
}