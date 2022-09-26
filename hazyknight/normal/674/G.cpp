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
	static char buf[524288],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,524288,stdin),p1 == p2) ? EOF : *p1++;
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

const int MAXN = 150005;

struct Node
{
	int lch,rch,sum,tag;
}node[MAXN * 80];

int n,m,p,id,LIM;
int a[MAXN];
int rt[MAXN];
int L[MAXN << 2];
int R[MAXN << 2];
int tag[MAXN << 2];
int mark[MAXN];

bool vis[MAXN];

queue<int> Q;
vector<int> ans,checked;
vector<int> cdt[MAXN << 2];

inline void opr1(int o,int l,int r)
{
	L[o] = l;
	R[o] = r;
}

inline void opr2(int o,int l,int r,int v)
{
	node[o].sum = v ? r - l + 1 : 0;
	node[o].tag = v;
}

inline void opr3(int o,int v)
{
	tag[o] = v;
	cdt[o].clear();
	cdt[o].push_back(v);
}

inline void pushdown1(int o)
{
	if (L[o])
	{
		opr1(o << 1,L[o],R[o]);
		opr1(o << 1 | 1,L[o],R[o]);
		L[o] = R[o] = 0;
	}
}

inline void pushdown2(int o,int l,int r)
{
	if (~node[o].tag)
	{
		int mid = l + r >> 1;
		if (!node[o].lch)
			node[o].lch = ++id;
		opr2(node[o].lch,l,mid,node[o].tag);
		if (!node[o].rch)
			node[o].rch = ++id;
		opr2(node[o].rch,mid + 1,r,node[o].tag);
		node[o].tag = -1;
	}
}

inline void pushdown3(int o)
{
	if (tag[o])
	{
		opr3(o << 1,tag[o]);
		opr3(o << 1 | 1,tag[o]);
		tag[o] = 0;
	}
}

pair<int,int> query1(int o,int l,int r,int p)
{
	if (l == r)
		return make_pair(L[o],R[o]);
	pushdown1(o);
	int mid = l + r >> 1;
	if (mid >= p)
		return query1(o << 1,l,mid,p);
	return query1(o << 1 | 1,mid + 1,r,p);
}

int query2(int o,int l,int r,int x,int y)
{
	if (!o || !node[o].tag)
		return 0;
	if (node[o].tag == 1)
		return min(r,y) - max(l,x) + 1;
	if (l >= x && r <= y)
		return node[o].sum;
	pushdown2(o,l,r);
	int mid = l + r >> 1;
	if (mid + 1 > y)
		return query2(node[o].lch,l,mid,x,y);
	if (mid < x)
		return query2(node[o].rch,mid + 1,r,x,y);
	return query2(node[o].lch,l,mid,x,y) + query2(node[o].rch,mid + 1,r,x,y);
}

int query3(int o,int l,int r,int p)
{
	if (tag[o])
		return tag[o];
	if (l == r)
		return 0;
	pushdown3(o);
	int mid = l + r >> 1;
	if (mid >= p)
		return query3(o << 1,l,mid,p);
	return query3(o << 1 | 1,mid + 1,r,p);
}

void modify1(int o,int l,int r,int x,int y)
{
	if (l >= x && r <= y)
	{
		opr1(o,x,y);
		return;
	}
	pushdown1(o);
	int mid = l + r >> 1;
	if (mid >= x)
		modify1(o << 1,l,mid,x,y);
	if (mid + 1 <= y)
		modify1(o << 1 | 1,mid + 1,r,x,y);
}

inline int modify2(int o,int l,int r,int x,int y,bool v)
{
	if (!o)
	{
		o = ++id;
		node[o].tag = -1;
	}
	if (l >= x && r <= y)
	{
		opr2(o,l,r,v);
		return o;
	}
	pushdown2(o,l,r);
	int mid = l + r >> 1;
	if (mid >= x)
		node[o].lch = modify2(node[o].lch,l,mid,x,y,v);
	if (mid + 1 <= y)
		node[o].rch = modify2(node[o].rch,mid + 1,r,x,y,v);
	node[o].sum = node[node[o].lch].sum + node[node[o].rch].sum;
	return o;
}

void modify3(int l,int r,int v)
{
	int cur = l;
	pair<int,int> sp1,sp2,sp3;
	while (cur <= r)
	{
		int col = query3(1,1,n,cur);
		pair<int,int> t = query1(1,1,n,cur);
		cur = t.second + 1;
		if (v == col)
			continue;
		rt[col] = modify2(rt[col],1,n,max(l,t.first),min(r,t.second),0);
	}
	rt[v] = modify2(rt[v],1,n,l,r,1);
	if (l > 1)
	{
		int tmp = query1(1,1,n,l - 1).first;
		if (query3(1,1,n,l - 1) == v)
			l = tmp;
		else
			modify1(1,1,n,tmp,l - 1);
	}
	if (r < n)
	{
		int tmp = query1(1,1,n,r + 1).second;
		if (query3(1,1,n,r + 1) == v)
			r = tmp;
		else
			modify1(1,1,n,r + 1,tmp);
	}
	modify1(1,1,n,l,r);
}

void update2(vector<int> &res,vector<int> &u,vector<int> &v,int l,int r)
{
	res.clear();
	int lim = (p * (r - l + 1) - 1) / 100 + 1;
	for (int i = 0;i < v.size();i++)
		mark[v[i]]++;
	for (int i = 0;i < u.size();i++)
		if (mark[u[i]] || query2(rt[u[i]],1,n,l,r) >= lim)
		{
			res.push_back(u[i]);
			mark[u[i]]++;
		}
	for (int i = 0;i < v.size();i++)
		if (!--mark[v[i]] && query2(rt[v[i]],1,n,l,r) >= lim)
			res.push_back(v[i]);
	for (int i = 0;i < res.size();i++)
		mark[res[i]] = 0;
}

void modify4(int o,int l,int r,int x,int y,int v)
{
	if (o == 1)
		modify3(x,y,v);
	if (l >= x && r <= y)
	{
		opr3(o,v);
		return;
	}
	pushdown3(o);
	int mid = l + r >> 1;
	if (mid >= x)
		modify4(o << 1,l,mid,x,y,v);
	if (mid + 1 <= y)
		modify4(o << 1 | 1,mid + 1,r,x,y,v);
	update2(cdt[o],cdt[o << 1],cdt[o << 1 | 1],l,r);
}

void query4(int o,int l,int r,int x,int y)
{
	if (l >= x && r <= y)
	{
		if (ans.size() == 100 / p)
			return;
		for (int i = 0;i < cdt[o].size();i++)
			if (!vis[cdt[o][i]])
			{
				vis[cdt[o][i]] = 1;
				checked.push_back(cdt[o][i]);
				if (query2(rt[cdt[o][i]],1,n,x,y) >= LIM)
					ans.push_back(cdt[o][i]);
			}
		return;
	}
	pushdown3(o);
	int mid = l + r >> 1;
	if (mid >= x)
		query4(o << 1,l,mid,x,y);
	if (mid + 1 <= y)
		query4(o << 1 | 1,mid + 1,r,x,y);
}

int main()
{
	read(n),read(m),read(p);
	modify1(1,1,n,1,n);
	for (int i = 1;i <= n;i++)
	{
		read(a[i]);
		modify4(1,1,n,i,i,a[i]);
	}
	while (m--)
	{
		int tp,l,r,id;
		read(tp),read(l),read(r);
		if (tp == 1)
		{
			read(id);
			modify4(1,1,n,l,r,id);
		}
		else
		{
			LIM = (p * (r - l + 1) - 1) / 100 + 1;
			for (int i = 0;i < checked.size();i++)
				vis[checked[i]] = 0;
			checked.clear();
			ans.clear();
			query4(1,1,n,l,r);
			printf("%d ",(int)ans.size());
			for (int i = 0;i < ans.size();i++)
				printf("%d ",ans[i]);
			printf("\n");
		}
	}
	return 0;
}