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

typedef long long ll;

const int MAXN = 100005;
const ll INF = 4e18;

struct Node
{
	int ch[2];
	int size;
	ll val,laz;
	
	Node(ll v = 0)
	{
		ch[0] = ch[1] = laz = 0;
		size = 1;
		val = v;
	}
}node[MAXN];

int n,rt;

ll sum,ans;

void add(int u,ll v)
{
	node[u].val += v;
	node[u].laz += v;
}

void pushdown(int u)
{
	if (node[u].laz)
	{
		add(node[u].ch[0],node[u].laz);
		add(node[u].ch[1],node[u].laz);
		node[u].laz = 0;
	}
}

void update(int u)
{
	node[u].size = node[node[u].ch[0]].size + 1 + node[node[u].ch[1]].size;
}

void link(int u,int v,bool dir)
{
	node[u].ch[dir] = v;
	update(u);
}

pair<int,int> split(int u,ll v,int sz)
{
	if (!u)
		return make_pair(0,0);
	pushdown(u);
	if (node[u].val < (node[node[u].ch[0]].size + sz + 1) * v)
	{
		pair<int,int> res = split(node[u].ch[0],v,sz);
		link(u,res.second,0);
		return make_pair(res.first,u);
	}
	pair<int,int> res = split(node[u].ch[1],v,sz + node[node[u].ch[0]].size + 1);
	link(u,res.first,1);
	return make_pair(u,res.second);
}

int merge(int u,int v)
{
	if (!u || !v)
		return u | v;
	pushdown(u);
	pushdown(v);
	if (rand() % (node[u].size + node[v].size) + 1 <= node[u].size)
	{
		link(u,merge(node[u].ch[1],v),1);
		return u;
	}
	link(v,merge(u,node[v].ch[0]),0);
	return v;
}

void getans(int u)
{
	if (!u)
		return;
	pushdown(u);
	getans(node[u].ch[0]);
	sum += node[u].val;
	ans = max(ans,sum);
	getans(node[u].ch[1]);
}

int main()
{
	node[0].size = 0;
	scanf("%d",&n);
	node[rt = 1] = Node(-INF);
	for (int i = 1;i <= n;i++)
	{
		ll a;
		scanf("%lld",&a);
		pair<int,int> res = split(rt,a,0);
		node[i + 1] = Node((node[res.first].size + 1) * a);
		add(res.second,a);
		rt = merge(merge(res.first,i + 1),res.second);
	}
	getans(rt);
	printf("%lld\n",ans);
	return 0;
}