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

typedef long long ll;

const int MAXN = 1000005;
const int MOD = 1000000007;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN];

int n,id,ans;
int first[MAXN];
int a[MAXN];
int f[MAXN];
int proc[MAXN];

ll tot;
ll sum[MAXN];

bool ok[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs1(int u)
{
	for (int i = first[u];i;i = edge[i].nxt)
		dfs1(edge[i].to);
	proc[++id] = u;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		tot += a[i];
	}
	for (int fa,i = 2;i <= n;i++)
	{
		scanf("%d",&fa);
		addE(fa,i);
	}
	id = 0;
	dfs1(1);
	int cnt = 0;
	for (int i = 1;i <= n;i++)
		if (tot % i == 0)
		{
			ll val = tot / i;
			bool flag = 1;
			for (int j = 1;j <= n;j++)
			{
				int u = proc[j];
				sum[u] = a[u];
				for (int k = first[u];k;k = edge[k].nxt)
					sum[u] += sum[edge[k].to];
				if (sum[u] > val)
				{
					flag = 0;
					break;
				}
				if (sum[u] == val)
					sum[u] = 0;
			}
			if (flag)
			{
				cnt++;
				ok[i] = 1;
			}
		}
	f[1] = 1;
	for (int i = 1;i <= n;i++)
		if (f[i])
		{
			(ans += f[i]) %= MOD;
			for (int j = i + i;j <= n;j += i)
				if (ok[j])
					(f[j] += f[i]) %= MOD;
		}
	printf("%d\n",ans);
	return 0;
}