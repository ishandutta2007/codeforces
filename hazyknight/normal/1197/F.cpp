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
 
const int MAXN = 1005;
const int MAXL = 65;
const ll MOD = 998244353;

int tot;

bool vis[MAXL];
 
struct Matrix
{
	int r,c;
	int a[MAXL][MAXL];
	
	Matrix (int R = 0,int C = 0)
	{
		r = R;
		c = C;
		memset(a,0,sizeof(a));
	}
	
	Matrix operator * (const Matrix &p)const
	{
		Matrix res(r,p.c);
		for (int k = 0;k < c;k++)
			for (int i = 0;i < res.r;i++)
			{
				int r = a[i][k];
				if (!r)
					continue;
				for (int j = 0;j < res.c;j++)
					res.a[i][j] = ((ll)r * p.a[k][j] + res.a[i][j]) % MOD;
			}
		return res;
	}
}unit,trans[4][3][1024];
 
int n,m;
int a[MAXN];
int G[4][4];
int match[MAXL];
 
ll f[MAXN][4];

vector<int> e[MAXL];
vector<pair<int,int> > tag[MAXN];
 
Matrix power(int b)
{
	Matrix res = unit;
	int t = 0;
	while (b)
	{
		if (b & 1023)
			res = res * trans[0][t][b & 1023];
		t++;
		b >>= 10;
	}
	return res;
}

void dfs(int u)
{
	if (vis[u])
		return;
	vis[u] = 1;
	for (int i = 0;i < e[u].size();i++)
		dfs(e[u][i]);
}

void init()
{
	for (int l1 = 0;l1 < 4;l1++)
		for (int l2 = 0;l2 < 4;l2++)
			for (int l3 = 0;l3 < 4;l3++)
			{
				int id = (l1 << 4) | (l2 << 2) | l3;
				for (int i = 1;i <= 3;i++)
				{
					bool mark[4] = {0};
					if (G[i][1])
						mark[l1] = 1;
					if (G[i][2])
						mark[l2] = 1;
					if (G[i][3])
						mark[l3] = 1;
					int SG = 0;
					for (int j = 0;j < 4;j++)
						if (!mark[j])
						{
							SG = j;
							break;
						}
					int to = (SG << 4) | (l1 << 2) | l2;
					e[id].push_back(to);
				}
			}
	dfs(63);
	memset(match,-1,sizeof(match));
	for (int i = 0;i < 64;i++)
		if (vis[i] || !i)
			match[i] = tot++;
	unit = Matrix(tot,tot);
	for (int i = 0;i < tot;i++)
		unit.a[i][i] = 1;
	for (int i = 0;i <= 3;i++)
		trans[i][0][1] = Matrix(tot,tot);
	for (int l1 = 0;l1 < 4;l1++)
		for (int l2 = 0;l2 < 4;l2++)
			for (int l3 = 0;l3 < 4;l3++)
			{
				int id = match[(l1 << 4) | (l2 << 2) | l3];
				if (id == -1)
					continue;
				for (int i = 1;i <= 3;i++)
				{
					bool mark[4] = {0};
					if (G[i][1])
						mark[l1] = 1;
					if (G[i][2])
						mark[l2] = 1;
					if (G[i][3])
						mark[l3] = 1;
					int SG = 0;
					for (int j = 0;j < 4;j++)
						if (!mark[j])
						{
							SG = j;
							break;
						}
					int to = match[(SG << 4) | (l1 << 2) | l2];
					if (to == -1)
						continue;
					trans[i][0][1].a[id][to]++;
					trans[0][0][1].a[id][to]++;
				}
			}
	for (int i = 0;i < 3;i++)
	{
		if (i)
			trans[0][i][1] = trans[0][i - 1][1023] * trans[0][i - 1][1];
		for (int j = 2;j < 1024;j++)
			trans[0][i][j] = trans[0][i][j - 1] * trans[0][i][1];
	}
}

Matrix solve(int l,vector<pair<int,int> > &cur)
{
	Matrix st(1,tot);
	st.a[0][tot - 1] = 1;
	int now = 0;
	for (int i = 0;i < cur.size();i++)
	{
		st = st * power(cur[i].first - now - 1) * trans[cur[i].second][0][1];
		now = cur[i].first;
	}
	st = st * power(l - now);
	return st;
}
 
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for (int u,v,c,i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&u,&v,&c);
		tag[u].push_back(make_pair(v,c));
	}
	for (int i = 1;i <= 3;i++)
		for (int j = 1;j <= 3;j++)
			scanf("%d",&G[i][j]);
	init();
	f[0][0] = 1;
	for (int i = 1;i <= n;i++)
	{
		sort(tag[i].begin(),tag[i].end());
		Matrix res = solve(a[i],tag[i]);
		ll a[4] = {0};
		for (int l1 = 0;l1 < 4;l1++)
			for (int l2 = 0;l2 < 4;l2++)
				for (int l3 = 0;l3 < 4;l3++)
					if (~match[(l1 << 4) | (l2 << 2) | l3])
						(a[l1] += res.a[0][match[(l1 << 4) | (l2 << 2) | l3]]) %= MOD;
		for (int j = 0;j < 4;j++)
			for (int k = 0;k < 4;k++)
				(f[i][j ^ k] += f[i - 1][j] * a[k]) %= MOD;
	}
	printf("%lld\n",f[n][0]);
	return 0;
}