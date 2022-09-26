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

const int MAXN = 100005;
const int MAXM = 300005;

struct Node
{
	int ch[2],fa;
	int size,sz,MAX;
	bool rev;
}node[MAXN + MAXM];

int n,m,odd;
int u[MAXM];
int v[MAXM];
int w[MAXM];
int ans[MAXM];

bool mark[MAXM];

stack<int> S;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;

void rev(int u)
{
	if (!u)
		return;
	swap(node[u].ch[0],node[u].ch[1]);
	node[u].rev ^= 1;
}

void update(int u)
{
	node[u].size = node[node[u].ch[0]].size + node[u].sz + (u <= n) + node[node[u].ch[1]].size;
	node[u].MAX = max(node[node[u].ch[0]].MAX,node[node[u].ch[1]].MAX);
	if (u > n)
		node[u].MAX = max(node[u].MAX,u);
}

void link(int u,int v,bool dir)
{
	node[u].ch[dir] = v;
	if (v)
		node[v].fa = u;
	update(u);
}

bool isroot(int u)
{
	return !node[u].fa || (node[node[u].fa].ch[0] != u && node[node[u].fa].ch[1] != u);
}

void pushdown(int u)
{
	if (node[u].rev)
	{
		rev(node[u].ch[0]);
		rev(node[u].ch[1]);
		node[u].rev = 0;
	}
}

void rotate(int u,bool dir)
{
	int ch = node[u].ch[dir],fa = node[u].fa;
	bool ok = isroot(u);
	link(u,node[ch].ch[!dir],dir);
	link(ch,u,!dir);
	node[ch].fa = fa;
	if (!ok)
		node[fa].ch[node[fa].ch[1] == u] = ch;
}

void splay(int u)
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

void access(int u)
{
	int tmp = 0,st = u;
	while (u)
	{
		splay(u);
		node[u].sz += node[node[u].ch[1]].size - node[tmp].size;
		link(u,tmp,1);
		tmp = u;
		u = node[u].fa;
	}
	splay(st);
}

void setroot(int u)
{
	access(u);
	rev(u);
}

void extract(int u,int v)
{
	setroot(u);
	access(v);
}

void link(int u,int v)
{
	setroot(u);
	setroot(v);
	if ((node[u].size & 1) && (node[v].size & 1))
		odd -= 2;
	node[v].sz += node[u].size;
	update(v);
	node[u].fa = v;
}

bool connected(int u,int v)
{
	extract(u,v);
	int st = u;
	while (node[u].fa)
		u = node[u].fa;
	return u == v;
}

void cut(int u,int v)
{
	extract(u,v);
	if ((~node[v].size & 1) && (node[u].size & 1))
		odd += 2;
	node[u].fa = node[v].ch[0] = 0;
	update(v);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		node[i].size = 1;
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		Q.push(make_pair(w[i],i));
	}
	odd = n;
	for (int i = m;i >= 1;i--)
	{
		ans[i] = ans[i + 1];
		while (!Q.empty() && odd)
		{
			int cur = Q.top().second;
			Q.pop();
			if (cur > i)
				continue;
			if (connected(u[cur],v[cur]))
			{
				int MAX = node[v[cur]].MAX - n;
				if (MAX < cur)
					continue;
				mark[MAX] = 0;
				cut(u[MAX],MAX + n);
				cut(MAX + n,v[MAX]);
			}
			ans[i] = w[cur];
			mark[cur] = 1;
			link(u[cur],cur + n);
			link(cur + n,v[cur]);
		}
		if (odd)
			ans[i] = -1;
		if (mark[i])
		{
			cut(u[i],i + n);
			cut(i + n,v[i]);
		}
	}
	for (int i = 1;i <= m;i++)
		printf("%d\n",ans[i]);
	return 0;
}