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

const int MAXN = 55;

int T;
int fa[MAXN];

ll f[MAXN];
ll fac[MAXN];

bool vis[MAXN];

vector<int> empty;

ll add(ll a,ll b)
{
	return a + b > 1e18 ? 1e18 + 1 : a + b;
}

ll mul(ll a,ll b)
{
	if (!b)
		return 0;
	if (a > 1e18 / b)
		return 1e18 + 1;
	return a * b;
}

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

vector<int> solve2(int n,ll k)
{
	vector<int> res;
	res.resize(n);
	memset(vis,0,sizeof(vis));
	for (int i = 1;i <= n;i++)
		fa[i] = i;
	fa[n] = vis[n] = 1;
	res[0] = n;
	int cnt = 1;
	for (int i = 2;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
			if (!vis[j] && (i == n || j != getroot(i)))
			{
				ll tot = fac[n - i];
				if (tot < k)
				{
					k -= tot;
					continue;
				}
				fa[j] = i;
				vis[j] = 1;
				res[i - 1] = j;
				cnt += (j > i) - vis[i];
				break;
			}
	}
	return res;
}

vector<int> solve1(int n,ll k)
{
	if (!n)
		return empty;
	for (int i = 1;i <= n;i++)
	{
		ll tot = mul(fac[i - 1],f[n - i]);
		if (tot < k)
		{
			k -= tot;
			continue;
		}
		ll tota = k / f[n - i] + 1,totb = k % f[n - i];
		if (!totb)
		{
			tota--;
			totb = f[n - i];
		}
		vector<int> res1 = solve2(i,tota),res2 = solve1(n - i,totb);
		for (int j = 0;j < n - i;j++)
			res1.push_back(res2[j] + i);
		return res1;
	}
}

int main()
{
	fac[0] = fac[1] = 1;
	for (int i = 2;i <= 50;i++)
		fac[i] = mul(fac[i - 1],i - 1);
	f[0] = 1;
	for (int i = 1;i <= 50;i++)
		for (int j = 0;j < i;j++)
			f[i] = add(f[i],mul(f[j],fac[i - j - 1]));
	scanf("%d",&T);
	while (T--)
	{
		int n;
		ll k;
		scanf("%d%lld",&n,&k);
		if (k > f[n])
		{
			puts("-1");
			continue;
		}
		vector<int> ans = solve1(n,k);
		for (int i = 0;i < n;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}