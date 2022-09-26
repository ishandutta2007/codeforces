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

const int MAXN = 405;

int n,m,id,cc,N;
int dfn[MAXN];
int low[MAXN];
int bel[MAXN];

bool vis[MAXN];
bool T[MAXN][MAXN];
bool G[MAXN][MAXN];

char s[26];
char S[MAXN];
char ans[MAXN];

stack<int> St;

void fix(int a,int b,int v)
{
	G[a << 1 | !b][a << 1 | b] = v;
}

int spj(int l)
{
	bool ok[2] = {0};
	for (int i = l;i < N;i++)
		ok[s[i]] = 1;
	if (!ok[0])
		return 1;
	if (!ok[1])
		return 0;
	return -1;
}

void dfs(int u)
{
	dfn[u] = low[u] = ++id;
	vis[u] = 1;
	St.push(u);
	for (int i = 2;i <= (n << 1 | 1);i++)
		if (G[u][i])
		{
			if (!dfn[i])
			{
				dfs(i);
				low[u] = min(low[u],low[i]);
			}
			else if (vis[i])
				low[u] = min(low[u],dfn[i]);
		}
	if (low[u] == dfn[u])
	{
		cc++;
		while (St.top() != u)
		{
			bel[St.top()] = cc;
			vis[St.top()] = 0;
			St.pop();
		}
		bel[u] = cc;
		vis[u] = 0;
		St.pop();
	}
}

bool two_sat()
{
	memset(dfn,0,sizeof(dfn));
	id = cc = 0;
	for (int i = 2;i <= (n << 1 | 1);i++)
		if (!dfn[i])
			dfs(i);
	for (int i = 1;i <= n;i++)
		if (bel[i << 1] == bel[i << 1 | 1])
			return 0;
	return 1;
}

void check(int p)
{
	if (p <= n && S[p] == N - 1)
		return;
	memcpy(G,T,sizeof(G));
	for (int i = 1;i < p;i++)
		fix(i,s[S[i]],1);
	int t = spj(S[p] + 1);
	if (~t)
		fix(p,t,1);
	t = spj(0);
	if (~t)
	{
		for (int i = p + 1;i <= n;i++)
			fix(i,t,1);
	}
	if (!two_sat())
		return;
	fix(p,s[S[p] + 1],1);
	ans[p] = S[p] + 1;
	if (!two_sat())
	{
		fix(p,s[S[p] + 1],0);
		fix(p,!s[S[p] + 1],1);
		for (int i = S[p] + 2;i < N;i++)
			if (s[i] != s[S[p] + 1])
			{
				ans[p] = i;
				break;
			}
	}
	int alt = 0;
	for (int i = 1;i < N;i++)
		if (s[i] != s[0])
		{
			alt = i;
			break;
		}
	for (int i = p + 1;i <= n;i++)
	{
		fix(i,s[0],1);
		if (!two_sat())
		{
			fix(i,s[0],0);
			fix(i,s[alt],1);
			ans[i] = alt;
		}
	}
	for (int i = 1;i < p;i++)
		putchar(S[i] + 'a');
	for (int i = p;i <= n;i++)
		putchar(ans[i] + 'a');
	putchar('\n');
	exit(0);
}

int main()
{
	scanf("%s%d%d",s,&n,&m);
	N = strlen(s);
	for (int i = 0;i < N;i++)
		s[i] = (s[i] == 'V');
	for (int p1,p2,i = 1;i <= m;i++)
	{
		char t1,t2;
		scanf("%d %c %d %c",&p1,&t1,&p2,&t2);
		T[p1 << 1 | (t1 == 'V')][p2 << 1 | (t2 == 'V')] = 1;
		T[p2 << 1 | (t2 == 'C')][p1 << 1 | (t1 == 'C')] = 1;
	}
	scanf("%s",S + 1);
	for (int i = 1;i <= n;i++)
		S[i] -= 'a';
	check(n + 1);
	for (int i = n;i >= 1;i--)
		check(i);
	puts("-1");
	return 0;
}