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

typedef long long ll;

const int MAXN = 400005;
const int SIZE = 250;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN];

struct Line
{
	ll k,b;
	int id;
	
	ll val(ll x)
	{
		return k * x + b;
	}
}c[MAXN];

int n,q,id;
int first[MAXN];
int dfn[MAXN];
int laz[MAXN];
int endfn[MAXN];
int pos[MAXN];

vector<int> conv[MAXN];

bool cmp1(const Line &a,const Line &b)
{
	return a.id < b.id;
}

bool cmp2(const Line &a,const Line &b)
{
	return a.k < b.k;
}

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u)
{
	dfn[u] = id++;
	for (int i = first[u];i;i = edge[i].nxt)
	{
		c[edge[i].to].k += c[u].k;
		c[edge[i].to].b += c[u].b;
		dfs(edge[i].to);
	}
	endfn[u] = id - 1;
}

long double inter(const Line &a,const Line &b)
{
	return (long double)(a.b - b.b) / (b.k - a.k);
}

void build(int cur)
{
	int l = cur * SIZE,r = cur * SIZE + SIZE - 1;
	laz[cur] = 0;
	conv[cur].clear();
	pos[cur] = 0;
	for (int i = l;i <= r;i++)
	{
		while (conv[cur].size() > 1 && ((c[i].k == c[conv[cur].back()].k && c[i].b > c[conv[cur].back()].b) || (c[i].k != c[conv[cur].back()].k && inter(c[conv[cur][conv[cur].size() - 2]],c[i]) >= inter(c[conv[cur].back()],c[i]))))
			conv[cur].pop_back();
		while (conv[cur].size() >= 1 && (c[i].k == c[conv[cur].back()].k && c[i].b > c[conv[cur].back()].b))
			conv[cur].pop_back();
		if (!conv[cur].size() || c[conv[cur].back()].k != c[i].k)
			conv[cur].push_back(i);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output1.txt","w",stdout);
	scanf("%d%d",&n,&q);
	for (int fa,i = 1;i < n;i++)
	{
		scanf("%d",&fa);
		addE(fa - 1,i);
	}
	id = 0;
	for (int i = 0;i < n;i++)
		scanf("%lld",&c[i].b);
	for (int i = 0;i < n;i++)
		scanf("%lld",&c[i].k);
	dfs(0);
	for (int i = n - 1;i >= 0;i--)
	{
		c[i << 1] = c[i << 1 | 1] = c[i];
		c[i << 1].id = dfn[i] << 1;
		c[i << 1 | 1].id = dfn[i] << 1 | 1;
		c[i << 1 | 1].k *= -1;
	}
	for (int i = 0;i < n;i++)
	{
		dfn[i] = dfn[i] << 1;
		endfn[i] = endfn[i] << 1 | 1;
	}
	n <<= 1;
	for (int i = 0;i < n;i++)
		c[i].b = c[i].k * c[i].b;
	sort(c,c + n,cmp1);
	for (int i = 0,j = min(n - 1,SIZE - 1);i < n;i = j + 1,j = min(n - 1,j + SIZE))
	{
		sort(c + i,c + j + 1,cmp2);
		build(i / SIZE);
	}
	while (q--)
	{
		int tp,u,v;
		scanf("%d%d",&tp,&u);
		int l = dfn[u - 1],r = endfn[u - 1],L = l / SIZE,R = r / SIZE;
		if (tp == 1)
		{
			scanf("%d",&v);
			if (L == R)
			{
				for (int i = L * SIZE;i < min(n,L * SIZE + SIZE);i++)
					c[i].b += c[i].k * (laz[L] + (c[i].id >= l && c[i].id <= r) * v);
				build(L);
				continue;
			}
			for (int i = L * SIZE;i < min(n,L * SIZE + SIZE);i++)
				c[i].b += c[i].k * (laz[L] + (c[i].id >= l) * v);
			build(L);
			for (int i = R * SIZE;i < min(n,R * SIZE + SIZE);i++)
				c[i].b += c[i].k * (laz[R] + (c[i].id <= r) * v);
			build(R);
			for (int i = L + 1;i < R;i++)
				laz[i] += v;
		}
		else
		{
			ll ans = 0;
			if (L == R)
			{
				for (int i = L * SIZE;i < min(n,L * SIZE + SIZE);i++)
					if (c[i].id >= l && c[i].id <= r)
						ans = max(ans,c[i].val(laz[L]));
				printf("%lld\n",ans);
				continue;
			}
			for (int i = L * SIZE;i < min(n,L * SIZE + SIZE);i++)
				if (c[i].id >= l)
					ans = max(ans,c[i].val(laz[L]));
			for (int i = R * SIZE;i < min(n,R * SIZE + SIZE);i++)
				if (c[i].id <= r)
					ans = max(ans,c[i].val(laz[R]));
			for (int i = L + 1;i < R;i++)
			{
				while (pos[i] + 1 < conv[i].size() && c[conv[i][pos[i]]].val(laz[i]) < c[conv[i][pos[i] + 1]].val(laz[i]))
					pos[i]++;
				ans = max(ans,c[conv[i][pos[i]]].val(laz[i]));
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}