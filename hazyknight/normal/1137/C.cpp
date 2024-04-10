#pragma GCC optimize(0)
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

inline char gc()
{
	static char buf[1048576],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,1048576,stdin),p1 == p2) ? EOF : *p1++;
}

inline void read(int &v)
{
	v = 0;
	char c = gc();
	while (c < '0' || c > '9')
		c = gc();
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
}

const int MAXN = 5000005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN];

int T,n,m,cc,d,id,tot,t;
int f[MAXN];
int u[100005];
int v[100005];
int deg[MAXN];
int l[MAXN];
int first[MAXN];
int dfn[MAXN];
int low[MAXN];
int bel[MAXN];
int cnt[MAXN];
int tag[MAXN];

bool vis[MAXN];

char s[MAXN];

stack<int> S;
queue<int> Q;

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void tarjan(int u)
{
	dfn[u] = low[u] = ++id;
	vis[u] = 1;
	S.push(u);
	for (int i = first[u];i;i = edge[i].nxt)
	{
		if (!dfn[edge[i].to])
		{
			tarjan(edge[i].to);
			low[u] = min(low[u],low[edge[i].to]);
		}
		else if (vis[edge[i].to])
			low[u] = min(low[u],dfn[edge[i].to]);
	}
	T++;
	if (dfn[u] == low[u])
	{
		cc++;
		while (S.top() != u)
		{
			vis[S.top()] = 0;
			bel[S.top()] = cc;
			t = S.top() / d;
			if (s[S.top()] - '0' && tag[t] != T)
			{
				cnt[cc]++;
				tag[t] = T;
			}
			S.pop();
		}
		vis[u] = 0;
		bel[u] = cc;
		t = u / d;
		if (s[u] - '0' && tag[t] != T)
		{
			cnt[cc] += s[u] - '0';
			tag[t] = T;
		}
		S.pop();
	}
}

int main()
{
	read(n),read(m),read(d);
	for (int i = 1;i <= m;i++)
	{
		read(u[i]),read(v[i]);
		u[i]--;
		v[i]--;
		for (int j = 0;j < d;j++)
			addE(u[i] * d + j,v[i] * d + (j + 1) % d);
	}
	for (int i = 0;i < n;i++)
	{
		char c = gc();
		while (c < '0' || c > '1')
			c = gc();
		for (int j = i * d;j < i * d + d;j++,c = gc())
			s[j] = c;
	}
	id = 0;
	for (int i = 0;i < n * d;i++)
		if (!dfn[i])
			tarjan(i);
	memset(first,0,sizeof(first));
	id = 0;
	for (int i = 1;i <= m;i++)
		for (int j = 0;j < d;j++)
			if (bel[u[i] * d + j] != bel[v[i] * d + (j + 1) % d])
			{
				addE(bel[u[i] * d + j],bel[v[i] * d + (j + 1) % d]);
				deg[bel[v[i] * d + (j + 1) % d]]++;
			}
	for (int i = 1;i <= cc;i++)
		if (!deg[i])
			Q.push(i);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		l[++tot] = u;
		for (int i = first[u];i;i = edge[i].nxt)
			if (!--deg[edge[i].to])
				Q.push(edge[i].to);
	}
	for (int i = tot;i >= 1;i--)
	{
		for (int j = first[l[i]];j;j = edge[j].nxt)
			f[l[i]] = max(f[l[i]],f[edge[j].to]);
		f[l[i]] += cnt[l[i]];
		if (l[i] == bel[0])
			break;
	}
	printf("%d\n",f[bel[0]]);
	return 0;
}