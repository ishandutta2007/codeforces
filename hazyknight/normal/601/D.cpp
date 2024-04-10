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

typedef unsigned long long ull;

const int MAXN = 300005;
const ull BASE = 29;
const ull MOD = 1000000007ll * 1000000009ll;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,id,MAX,cnt;
int c[MAXN];
int first[MAXN];

ull h[MAXN];

char s[MAXN];

set<ull> S[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u,int fa)
{
	h[u] = (h[fa] * BASE + s[u] - 'a' + 1) % MOD;
	int hson = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			dfs(edge[i].to,u);
			if (S[edge[i].to].size() > S[hson].size())
				hson = edge[i].to;
		}
	swap(S[u],S[hson]);
	S[u].insert(h[u]);
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && edge[i].to != hson)
			S[u].insert(S[edge[i].to].begin(),S[edge[i].to].end());
	if (S[u].size() + c[u] > MAX)
	{
		MAX = S[u].size() + c[u];
		cnt = 0;
	}
	if (S[u].size() + c[u] == MAX)
		cnt++;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&c[i]);
	scanf("%s",s + 1);
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	dfs(1,0);
	printf("%d\n%d\n",MAX,cnt);
	return 0;
}