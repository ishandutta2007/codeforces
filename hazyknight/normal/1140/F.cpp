#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

const int MAXN = 600005;
const int BASE = 300000;
const int INF = (1 << 30) - 1;

struct Node
{
	int ch[2],fa;
	int f[2],g[2];
	int val,MIN;
	bool rev;
}node[MAXN << 1];

int n;
int u[MAXN];
int v[MAXN];
int w[MAXN];
int ptr[MAXN];

ll ans;

bool tp[MAXN];

unordered_set<int> S;
unordered_map<ll,int> match;

inline void rev(int u)
{
	if (!u)
		return;
	node[u].rev ^= 1;
}

inline void update(int u)
{
	node[u].MIN = u;
	if (node[u].ch[0] && node[node[node[u].ch[0]].MIN].val < node[node[u].MIN].val)
		node[u].MIN = node[node[u].ch[0]].MIN;
	if (node[u].ch[1] && node[node[node[u].ch[1]].MIN].val < node[node[u].MIN].val)
		node[u].MIN = node[node[u].ch[1]].MIN;
	node[u].f[0] = node[node[u].ch[0]].f[0] + node[u].g[0] + (u <= BASE) + node[node[u].ch[1]].f[0];
	node[u].f[1] = node[node[u].ch[0]].f[1] + node[u].g[1] + (u > BASE && u <= BASE * 2) + node[node[u].ch[1]].f[1];
}

inline void push_down(int u)
{
	if (node[u].rev)
	{
		swap(node[u].ch[0],node[u].ch[1]);
		rev(node[u].ch[0]);
		rev(node[u].ch[1]);
		node[u].rev = 0;
	}
}

inline bool is_root(int u)
{
	return !node[u].fa || (node[node[u].fa].ch[0] != u && node[node[u].fa].ch[1] != u);
}

inline void link(int fa,int ch,bool dir)
{
	node[fa].ch[dir] = ch;
	if (ch)
		node[ch].fa = fa;
	update(fa);
}

inline void rotate(int u,bool dir)
{
	int ch = node[u].ch[dir],fa = node[u].fa;
	bool ok = is_root(u);
	link(u,node[ch].ch[!dir],dir);
	link(ch,u,!dir);
	node[ch].fa = fa;
	if (!ok)
		node[fa].ch[node[fa].ch[1] == u] = ch;
}

inline void splay(int u)
{
	stack<int> S;
	S.push(u);
	for (int i = u;!is_root(i);i = node[i].fa)
		S.push(node[i].fa);
	while (!S.empty())
	{
		push_down(S.top());
		S.pop();
	}
	while (!is_root(u))
	{
		int fa = node[u].fa;
		bool dir1 = (node[fa].ch[1] == u);
		if (is_root(fa))
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
		node[u].g[0] += node[node[u].ch[1]].f[0] - node[tmp].f[0];
		node[u].g[1] += node[node[u].ch[1]].f[1] - node[tmp].f[1];
		update(u);
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
//	cout << "link:" << u << ',' << v << endl;
	setroot(u);
	node[v].g[0] += node[u].f[0];
	node[v].g[1] += node[u].f[1];
	update(v);
	node[u].fa = v;
}

inline void cut(int u,int v)
{
//	cout << "cut:" << u << ',' << v << endl;
	extract(u,v);
	node[v].ch[0] = node[u].fa = 0;
	update(v);
}

inline int getroot(int u)
{
	int tmp = u;
	while (node[u].fa)
		u = node[u].fa;
	return u;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		v[i] += BASE;
	}
	for (int i = 1;i <= n;i++)
	{
		ll H = (ll)u[i] * (BASE << 1) + v[i];
		if (match[H])
		{
			w[ptr[i] = match[H]] = i;
			match[H] = 0;
			tp[i] = 1;
		}
		else
		{
			w[i] = INF;
			match[H] = i;
			tp[i] = 0;
		}
	}
	for (int i = 1;i <= BASE * 2;i++)
	{
		node[i].val = INF;
		update(i);
	}
	for (int i = 1;i <= n;i++)
	{
		if (!tp[i])
		{
			node[i + BASE * 2].val = w[i];
			int tu = getroot(u[i]),tv = getroot(v[i]);
			splay(u[i]);
			splay(v[i]);
			if (tu != tv)
			{
				setroot(u[i]);
				setroot(v[i]);
				ans -= (ll)node[u[i]].f[0] * node[u[i]].f[1];
				ans -= (ll)node[v[i]].f[0] * node[v[i]].f[1];
				S.insert(i + BASE * 2);
				link(u[i],i + BASE * 2);
				link(v[i],i + BASE * 2);
				ans += (ll)node[i + BASE * 2].f[0] * node[i + BASE * 2].f[1];
			}
			else
			{
				extract(u[i],v[i]);
				int ID = node[v[i]].MIN;
				if (node[ID].val < w[i])
				{
					S.erase(ID);
					cut(u[ID - BASE * 2],ID);
					cut(v[ID - BASE * 2],ID);
					S.insert(i + BASE * 2);
					link(u[i],i + BASE * 2);
					link(v[i],i + BASE * 2);
				}
			}
		}
		else if (S.find(ptr[i] + BASE * 2) != S.end())
		{
			setroot(ptr[i] + BASE * 2);
			ans -= (ll)node[ptr[i] + BASE * 2].f[0] * node[ptr[i] + BASE * 2].f[1];
			S.erase(ptr[i] + BASE * 2);
			cut(u[ptr[i]],ptr[i] + BASE * 2);
			cut(v[ptr[i]],ptr[i] + BASE * 2);
			ans += (ll)node[u[ptr[i]]].f[0] * node[u[ptr[i]]].f[1];
			ans += (ll)node[v[ptr[i]]].f[0] * node[v[ptr[i]]].f[1];
		}
		printf("%lld ",ans);
	}
	printf("\n");
	return 0;
}