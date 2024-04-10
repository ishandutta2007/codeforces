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
typedef double db;

const int MAXN = 1005;
const int MAXT = 1605;
const ll CONS = 1000000;

struct Task
{
	int ss,sl,ts,tl;
	
	db pos;
	
	bool operator < (const Task &p)const
	{
		if (!pos)
			return 0;
		if (!p.pos)
			return 1;
		return tl / pos - tl < p.tl / p.pos - p.tl;
	}
}p[MAXN];

int n,t;

ll f[MAXN][MAXT];
ll h[MAXN][MAXT];

db g[MAXN][MAXT];

int main()
{
	scanf("%d%d",&n,&t);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d%d%d%lf",&p[i].ss,&p[i].sl,&p[i].ts,&p[i].tl,&p[i].pos);
		p[i].pos = 1 - p[i].pos;
	}
	sort(p + 1,p + n + 1);
	for (int i = n;i >= 1;i--)
		for (int j = 0;j <= t;j++)
		{
			f[i][j] = f[i + 1][j];
			if (j >= p[i].ts)
				f[i][j] = max(f[i][j],f[i + 1][j - p[i].ts] + p[i].ss * CONS);
			if (j >= p[i].ts + p[i].tl)
				f[i][j] = max(f[i][j],f[i + 1][j - p[i].ts - p[i].tl] + p[i].ss * CONS + p[i].sl * (ll)(CONS * p[i].pos + 0.5));
		}
	ll glo = 0;
	for (int i = 0;i <= t;i++)
		glo = max(glo,f[1][i]);
	for (int i = 1;i <= t;i++)
		g[0][i] = 4e18;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j <= t;j++)
		{
			g[i][j] = 4e18;
			if (f[i + 1][t - j] + h[i - 1][j] == glo)
			{
				g[i][j] = g[i - 1][j];
				h[i][j] = h[i - 1][j];
			}
			if (j >= p[i].ts)
			{
				ll u = h[i - 1][j - p[i].ts] + p[i].ss * CONS;
				if (f[i + 1][t - j] + u == glo)
				{
					db v = g[i - 1][j - p[i].ts] + p[i].ts;
					if (v < g[i][j])
					{
						g[i][j] = v;
						h[i][j] = u;
					}
				}
			}
			if (j >= p[i].ts + p[i].tl)
			{
				ll u = h[i - 1][j - p[i].ts - p[i].tl] + p[i].ss * CONS + p[i].sl * (ll)(CONS * p[i].pos + 0.5);
				if (f[i + 1][t - j] + u == glo && g[i - 1][j - p[i].ts - p[i].tl] != 4e18)
				{
					db v = (1 - p[i].pos) * (g[i - 1][j - p[i].ts - p[i].tl] + p[i].ts) + p[i].pos * j;
					if (v < g[i][j])
					{
						g[i][j] = v;
						h[i][j] = u;
					}
				}
			}
		}
	db ans = 4e18;
	for (int i = 0;i <= t;i++)
		if (h[n][i] == glo)
			ans = min(ans,g[n][i]);
	printf("%.10lf %.10lf\n",(db)glo / CONS,ans);
	return 0;
}