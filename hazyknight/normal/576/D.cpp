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

const int MAXN = 155;
const int INF = (1 << 30) - 1;

struct Matrix
{
	int r,c;
	
	bitset<MAXN> a[MAXN];
	
	Matrix (int R = 0,int C = 0)
	{
		r = R;
		c = C;
	}
	
	Matrix operator * (const Matrix &p)const
	{
		Matrix res(r,p.c);
		for (int k = 1;k <= c;k++)
			for (int i = 1;i <= r;i++)
			{
				if (!a[i][k])
					continue;
				res.a[i] |= p.a[k];
			}
		return res;
	}
}st,G,unit;

int n,m,ans = INF;
int u[MAXN];
int v[MAXN];
int d[MAXN];
int dis[MAXN];

queue<int> Q;

Matrix power(Matrix a,int b)
{
	Matrix res = unit;
	while (b)
	{
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int bfs()
{
	for (int i = 1;i <= n;i++)
	{
		if (st.a[1][i])
		{
			dis[i] = 0;
			Q.push(i);
		}
		else
			dis[i] = INF;
	}
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int i = 1;i <= n;i++)
			if (G.a[u][i] && dis[i] == INF)
			{
				dis[i] = dis[u] + 1;
				Q.push(i);
			}
	}
	return dis[n];
}

int main()
{
	scanf("%d%d",&n,&m);
	st = Matrix(1,n);
	st.a[1][1] = 1;
	G = unit = Matrix(n,n);
	for (int i = 1;i <= n;i++)
		unit.a[i][i] = 1;
	for (int i = 1;i <= m;i++)
		scanf("%d%d%d",&u[i],&v[i],&d[i]);
	for (int i = 1;i <= m;i++)
		for (int j = i + 1;j <= m;j++)
			if (d[i] > d[j])
			{
				swap(u[i],u[j]);
				swap(v[i],v[j]);
				swap(d[i],d[j]);
			}
	for (int i = 1;i <= m;i++)
	{
		st = st * power(G,d[i] - d[i - 1]);
		G.a[u[i]][v[i]] = 1;
		int res = bfs();
		if (res != INF)
			ans = min(ans,d[i] + res);
	}
	if (ans != INF)
		printf("%d\n",ans);
	else
		puts("Impossible");
	return 0;
}