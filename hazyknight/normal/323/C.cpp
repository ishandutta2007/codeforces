#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector> 
#include <map>
#include <iomanip>

using namespace std;

inline char gc()
{
	static char buf[262144],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,262144,stdin),p1 == p2) ? EOF : *p1++;
}

void read(int &v)
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

const int MAXN = 1000005;
const int MAXM = 200005;

struct Node
{
	int ch[2];
	int sum;
}node[MAXN << 5];

int n,m,id,last_ans;
int pos[MAXN];
int root[MAXN];

inline int f(int x)
{
	return (x + last_ans) % n + 1;
}

inline int sum(int o)
{
	return o ? node[o].sum : 0;
}

void pushup(int o)
{
	node[o].sum = sum(node[o].ch[0]) + sum(node[o].ch[1]);
}

int buildtree(int l,int r)
{
	int o = ++id;
	if (l == r)
		return o;
	int mid = (l + r) >> 1;
	node[o].ch[0] = buildtree(l,mid);
	node[o].ch[1] = buildtree(mid + 1,r);
	pushup(o);
}

int update(int o,int l,int r,int p)
{
	node[++id] = node[o];
	o = id;
	if (l == r)
	{
		node[o].sum = 1;
		return o;
	}
	int mid = (l + r) >> 1;
	if (mid >= p)
		node[o].ch[0] = update(node[o].ch[0],l,mid,p);
	else
		node[o].ch[1] = update(node[o].ch[1],mid + 1,r,p);
	pushup(o);
	return o;
}

int query(int o,int l,int r,int x,int y)
{
	if (l >= x && r <= y)
		return node[o].sum;
	int mid = (l + r) >> 1;
	if (mid < x)
		return query(node[o].ch[1],mid + 1,r,x,y);
	if (mid + 1 > y)
		return query(node[o].ch[0],l,mid,x,y);
	return query(node[o].ch[0],l,mid,x,y) + query(node[o].ch[1],mid + 1,r,x,y);
}

int main()
{
	read(n);
	for (int a,i = 1;i <= n;i++)
	{
		read(a);
		pos[a] = i;
	}
	root[0] = buildtree(1,n);
	for (int a,i = 1;i <= n;i++)
	{
		read(a);
		root[i] = update(root[i - 1],1,n,pos[a]);
	}
	read(m);
	last_ans = -1;
	for (int a,b,c,d,l1,r1,l2,r2,i = 1;i <= m;i++)
	{
		read(a),read(b),read(c),read(d);
		l1 = f(a);
		r1 = f(b);
		l2 = f(c);
		r2 = f(d);
		if (l1 > r1)
			swap(l1,r1);
		if (l2 > r2)
			swap(l2,r2);
		printf("%d\n",last_ans = query(root[r2],1,n,l1,r1) - query(root[l2 - 1],1,n,l1,r1));
	}
	return 0;
}