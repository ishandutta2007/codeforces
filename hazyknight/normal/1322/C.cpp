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

const int MAXN = 500005;

int T,n,m;
int p[MAXN];

ll c[MAXN];

vector<int> e[MAXN];

ll gcd(ll a,ll b)
{
	return b ? gcd(b,a % b) : a;
}

bool cmp(const int &a,const int &b)
{
	int l = min(e[a].size(),e[b].size());
	for (int j = 0;j < l;j++)
		if (e[a][j] != e[b][j])
			return e[a][j] < e[b][j];
	return e[a].size() < e[b].size();
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++)
		{
			scanf("%lld",&c[i]);
			e[i].clear();
		}
		for (int u,v,i = 1;i <= m;i++)
		{
			scanf("%d%d",&u,&v);
			e[v].push_back(u);
		}
		for (int i = 1;i <= n;i++)
		{
			sort(e[i].begin(),e[i].end());
			p[i] = i;
		}
		sort(p + 1,p + n + 1,cmp);
		ll g = 0,sum = c[p[1]];
		for (int i = 2;i <= n;i++)
		{
			bool ok = (e[p[i]].size() == e[p[i - 1]].size());
			if (ok)
			{
				for (int j = 0;j < e[p[i]].size();j++)
					if (e[p[i]][j] != e[p[i - 1]][j])
					{
						ok = 0;
						break;
					}
			}
			if (ok)
				sum += c[p[i]];
			else
			{
				if (e[p[i - 1]].size())
					g = gcd(g,sum);
				sum = c[p[i]];
			}
		}
		g = gcd(g,sum);
		printf("%lld\n",g);
	}
	return 0;
}