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

const int MAXN = 5005;
const ll MOD = 1000000007;

int n,m,MAX;
int a[MAXN];
int cnt[MAXN][MAXN];
int pre[MAXN];
int suf[MAXN];

ll ans;

int Count(int u,int l,int r)
{
	return cnt[u][r] - cnt[u][l - 1];
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int f,h,i = 1;i <= m;i++)
	{
		scanf("%d%d",&f,&h);
		cnt[f][h]++;
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			cnt[i][j] += cnt[i][j - 1];
	for (int i = 1;i <= n;i++)
		suf[a[i]]++;
	for (int i = 0;i <= n;i++)
	{
		if (i && !Count(a[i],pre[a[i]],pre[a[i]]))
		{
			pre[a[i + 1]]++;
			suf[a[i + 1]]--;
			continue;
		}
		int tot = 0;
		ll pro = 1;
		for (int j = 1;j <= n;j++)
		{
			if (j == a[i])
			{
				int r = Count(j,1,suf[j]);
				if (suf[j] >= pre[j])
					r--;
				if (r)
				{
					tot += 2;
					(pro *= r) %= MOD;
				}
				else
					tot++;
			}
			else
			{
				int u = pre[j],v = suf[j];
				if (u > v)
					swap(u,v);
				int r1 = Count(j,1,u),r2 = Count(j,1,v);
				if (r1)
				{
					r2--;
					if (r2)
					{
						tot += 2;
						(pro *= r1) %= MOD;
						(pro *= r2) %= MOD;
					}
					else
					{
						tot++;
						(pro *= 2 * r1) %= MOD;
					}
				}
				else if (r2)
				{
					tot++;
					(pro *= r2) %= MOD;
				}
			}
		}
		if (tot > MAX)
		{
			MAX = tot;
			ans = pro;
		}
		else if (tot == MAX)
			(ans += pro) %= MOD;
		pre[a[i + 1]]++;
		suf[a[i + 1]]--;
	}
	printf("%d %lld\n",MAX,ans);
	return 0;
}