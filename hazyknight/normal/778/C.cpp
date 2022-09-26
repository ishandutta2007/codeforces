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

typedef unsigned long long ll;

const int MAXN = 300005;
const ll MUL = 29;
const ll MOD = 1000000007;

struct Set
{
	multiset<ll> S;
	ll var;
	
	void add(ll v)
	{
		var += v;
	}
	
	void insert(ll v)
	{
		S.insert(v - var);
	}
	
	void erase(ll v)
	{
		S.erase(S.find(v - var));
	}
	
	bool find(ll v)
	{
		return S.find(v - var) != S.end();
	}
	
	int size()
	{
		return S.size();
	}
}S[MAXN];

struct Edge
{
	int to;
	int c;
	int nxt;
}edge[MAXN << 1];

int n,p,id;
int first[MAXN];
int ans[MAXN];

ll pw[MAXN];

void addE(int u,int v,int c)
{
	edge[++id] = (Edge){v,c,first[u]};
	first[u] = id;
}

void dfs(int u,int fa,int depth)
{
	int MAX = 0,c = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			ans[depth]++;
			dfs(edge[i].to,u,depth + 1);
			if (!MAX || S[MAX].size() < S[edge[i].to].size())
			{
				MAX = edge[i].to;
				c = edge[i].c;
			}
		}
	if (!MAX)
		return;
	swap(S[u],S[MAX]);
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && edge[i].to != MAX)
			for (multiset<ll>::iterator j = S[edge[i].to].S.begin();j != S[edge[i].to].S.end();j++)
			{
				ans[depth] += S[u].find(*j + S[edge[i].to].var);
				S[u].insert(*j + S[edge[i].to].var);
			}
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && edge[i].to != MAX)
			for (multiset<ll>::iterator j = S[edge[i].to].S.begin();j != S[edge[i].to].S.end();j++)
				S[u].erase(*j + S[edge[i].to].var);
	S[u].insert(0);
	S[u].add(pw[depth] * c);
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && edge[i].to != MAX)
		{
			S[edge[i].to].insert(0);
			S[edge[i].to].add(pw[depth] * edge[i].c);
			for (multiset<ll>::iterator j = S[edge[i].to].S.begin();j != S[edge[i].to].S.end();j++)
				S[u].insert(*j + S[edge[i].to].var);
		}
}

int main()
{
	scanf("%d",&n);
	pw[0] = 1;
	for (int i = 1;i <= n;i++)
		pw[i] = pw[i - 1] * MUL % MOD;
	char c;
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d %c",&u,&v,&c);
		addE(u,v,c - 'a' + 1);
		addE(v,u,c - 'a' + 1);
	}
	dfs(1,0,1);
	p = 1;
	for (int i = 2;i <= n;i++)
		if (ans[i] > ans[p])
			p = i;
	printf("%d\n%d\n",n - ans[p],p);
	return 0;
}