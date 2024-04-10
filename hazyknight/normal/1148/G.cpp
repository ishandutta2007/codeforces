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
const int S = 40;
const int MAXV = 10000005;

int n,m,a,id,cnt;
int crs[MAXV];
int pr[MAXV];
int MIN[MAXV];

bool mark[MAXV];

queue<int> Q;
vector<int> v[MAXV];
vector<int> fac[MAXN];
vector<int> comp[MAXN];
bitset<MAXN> mask,tot,nxt,vis;
vector<bitset<MAXN> > bitsets;

void Sieve(int N)
{
	for (int i = 2;i <= N;i++)
	{
		if (!mark[i])
		{
			pr[++cnt] = i;
			MIN[i] = i;
		}
		for (int j = 1;j <= cnt && i * pr[j] <= N;j++)
		{
			mark[i * pr[j]] = 1;
			MIN[i * pr[j]] = pr[j];
			if (i % pr[j] == 0)
				break;
		}
	}
}

void bfs(int st,int cur)
{
	Q.push(st);
	vis[st] = 1;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		comp[cur].push_back(u);
		nxt.reset();
		for (int i = 0;i < fac[u].size();i++)
		{
			if (~crs[fac[u][i]])
				nxt |= bitsets[crs[fac[u][i]]];
			else
			{
				for (int j = 0;j < v[fac[u][i]].size();j++)
					nxt[v[fac[u][i]][j]] = 1;
			}
		}
		nxt[0] = 1;
		nxt = (~vis) & (~nxt);
		for (int i = nxt._Find_first();i <= n;i = nxt._Find_next(i))
		{
			Q.push(i);
			vis[i] = 1;
		}
	}
}

int main()
{
	memset(crs,-1,sizeof(crs));
	Sieve(MAXV - 5);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		while (a > 1)
		{
			int p = MIN[a];
			fac[i].push_back(p);
			v[p].push_back(i);
			while (a % p == 0)
				a /= p;
		}
	}
	for (int i = 2;i <= MAXV - 5;i++)
	{
		if (v[i].size() <= S)
			continue;
		mask.reset();
		for (int j = 0;j < v[i].size();j++)
			mask[v[i][j]] = 1;
		crs[i] = bitsets.size();
		bitsets.push_back(mask);
	}
	for (int i = 1;i <= n;i++)
		if (!vis[i])
			bfs(i,++id);
	if (id >= m)
	{
		for (int i = 1;i <= m;i++)
			printf("%d ",comp[i][0]);
		printf("\n");
		return 0;
	}
	for (int i = 1;m && i <= id;i++)
	{
		if ((m & 1) && comp[i].size() >= 3)
		{
			for (int j = 0;j < comp[i].size() - (comp[i].size() % 2 == 0) && m;j++,m--)
				printf("%d ",comp[i][j]);
		}
		else if (comp[i].size() >= 2)
		{
			for (int j = 0;j < comp[i].size() - (comp[i].size() % 2 == 1) && m;j++,m--)
				printf("%d ",comp[i][j]);
		}
	}
	printf("\n");
	return 0;
}