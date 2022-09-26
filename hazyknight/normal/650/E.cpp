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

const int MAXN = 1000005;

struct Node
{
	int ch[2],fa;
	int sz,sum;
	bool vis,rev;
}node[MAXN];

int n;
int u[MAXN];
int v[MAXN];
int U[MAXN];
int V[MAXN];

bool ok[MAXN];

stack<int> S;
vector<pair<int,int> > ans;

inline void rev(int u)
{
	if (!u)
		return;
	node[u].rev ^= 1;
}

inline int sum(int u)
{
	return u ? node[u].sum : 0;
}

inline int sz(int u)
{
	return u ? node[u].sz : 0;
}

inline void pushdown(int u)
{
	if (node[u].rev)
	{
		rev(node[u].ch[0]);
		rev(node[u].ch[1]);
		swap(node[u].ch[0],node[u].ch[1]);
		node[u].rev = 0;
	}
}

inline bool isroot(int u)
{
	return !node[u].fa || node[node[u].fa].ch[0] != u && node[node[u].fa].ch[1] != u;
}

inline void update(int u)
{
	node[u].sz = sz(node[u].ch[0]) + 1 + sz(node[u].ch[1]);
	node[u].sum = sum(node[u].ch[0]) + node[u].vis + sum(node[u].ch[1]);
}

inline void link(int u,int v,bool dir)
{
	node[u].ch[dir] = v;
	if (v)
		node[v].fa = u;
	update(u);
}

inline void rotate(int u,bool dir)
{
	int ch = node[u].ch[dir],fa = node[u].fa;
	bool ok = isroot(u);
	link(u,node[ch].ch[!dir],dir);
	link(ch,u,!dir);
	node[ch].fa = fa;
	if (!ok)
		node[fa].ch[node[fa].ch[1] == u] = ch;
}

inline void splay(int u)
{
	S.push(u);
	for (int i = u;!isroot(i);i = node[i].fa)
		S.push(node[i].fa);
	while (!S.empty())
	{
		pushdown(S.top());
		S.pop();
	}
	while (!isroot(u))
	{
		int fa = node[u].fa;
		bool dir1 = (node[fa].ch[1] == u);
		if (isroot(fa))
		{
			rotate(fa,dir1);
			return;
		}
		int ffa = node[fa].fa;
		bool dir2 = (node[ffa].ch[1] == fa);
		if (dir1 ^ dir2)
		{
			rotate(fa,dir1);
			rotate(ffa,dir2);
		}
		else
		{
			rotate(ffa,dir2);
			rotate(fa,dir1);
		}
	}
}

inline void access(int u)
{
	int st = u,tmp = 0;
	while (u)
	{
		splay(u);
		link(u,tmp,1);
		tmp = u;
		u = node[u].fa;
	}
	splay(st);
}

inline void setroot(int u)
{
	access(u);
	rev(u);
}

inline void extract(int u,int v)
{
	setroot(u);
	access(v);
}

inline void link(int u,int v)
{
	setroot(u);
	node[u].fa = v;
}

inline void cut(int u,int v)
{
	extract(u,v);
	node[u].fa = node[v].ch[0] = 0;
	update(v);
}

int getvac(int u)
{
	if (!node[u].vis)
		return u;
	if (sz(node[u].ch[0]) != sum(node[u].ch[0]))
		return getvac(node[u].ch[0]);
	return getvac(node[u].ch[1]);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		node[i].vis = 1;
		update(i);
	}
	for (int i = 1;i < n;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		if (u[i] > v[i])
			swap(u[i],v[i]);
		link(u[i],i + n);
		link(v[i],i + n);
	}
	for (int i = 1;i < n;i++)
	{
		scanf("%d%d",&U[i],&V[i]);
		if (U[i] > V[i])
			swap(U[i],V[i]);
		extract(U[i],V[i]);
		int t = getvac(V[i]) - n;
		splay(t + n);
		if (U[i] == u[t] && V[i] == v[t])
		{
			ok[i] = 1;
			node[t + n].vis = 1;
			update(t + n);
		}
	}
	for (int i = 1;i < n;i++)
	{
		if (ok[i])
			continue;
		extract(U[i],V[i]);
		int t = getvac(V[i]) - n;
		cut(u[t],t + n);
		cut(v[t],t + n);
		link(U[i],V[i]);
		ans.push_back(make_pair(t,i));
	}
	printf("%d\n",(int)ans.size());
	for (int i = 0;i < ans.size();i++)
		printf("%d %d %d %d\n",u[ans[i].first],v[ans[i].first],U[ans[i].second],V[ans[i].second]);
	return 0;
}