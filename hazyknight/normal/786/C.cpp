#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const int MAXN = 100005;

struct Node
{
	int lch,rch;
	int sum;
}node[MAXN << 6];

int n,id;
int a[MAXN];
int last[MAXN];
int root[MAXN];

int duplicate(int o)
{
	id++;
	node[id].lch = node[o].lch;
	node[id].rch = node[o].rch;
	node[id].sum = node[o].sum;
	return id;
}

void update(int o)
{
	node[o].sum = node[node[o].lch].sum + node[node[o].rch].sum;
}

int buildtree(int o,int l,int r)
{
	o = ++id;
	if (l == r)
		return o;
	int mid = l + r >> 1;
	node[o].lch = buildtree(node[o].lch,l,mid);
	node[o].rch = buildtree(node[o].rch,mid + 1,r);
	update(o);
	return o;
}

int modify(int o,int l,int r,int p,int v)
{
	o = duplicate(o);
	if (l == r)
	{
		node[o].sum += v;
		return o;
	}
	int mid = l + r >> 1;
	if (mid >= p)
		node[o].lch = modify(node[o].lch,l,mid,p,v);
	else
		node[o].rch = modify(node[o].rch,mid + 1,r,p,v);
	update(o);
	return o;
}

int query(int o,int l,int r,int K)
{
	if (l == r)
		return l;
	int mid = l + r >> 1;
	if (K < node[node[o].lch].sum)
		return query(node[o].lch,l,mid,K);
	return query(node[o].rch,mid + 1,r,K - node[node[o].lch].sum);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	a[n + 1] = a[n];
	n++;
	root[n + 1] = buildtree(root[n + 1],1,n);
	for (int i = n;i >= 1;i--)
	{
		root[i] = root[i + 1];
		if (last[a[i]])
			root[i] = modify(root[i],1,n,last[a[i]],-1);
		root[i] = modify(root[i],1,n,last[a[i]] = i,1);
	}
	for (int K = 1;K < n;K++)
	{
		int cur = 1,ans = 0;
		while (cur < n)
		{
			cur = query(root[cur],1,n,K);
			ans++;
		}
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}