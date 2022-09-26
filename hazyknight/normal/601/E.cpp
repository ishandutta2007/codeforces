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

const int MAXN = 15005;
const int MAXM = 1005;
const int MAXQ = 20005;
const ll BASE = 10000019;
const ll MOD = 1000000007;

int n,k,q,m;
int v[MAXN];
int w[MAXN];
int f[MAXN][MAXM];
int intime[MAXN];
int outtime[MAXN];

vector<int> item[MAXQ << 2];

void add(int o,int l,int r,int x,int y,int id)
{
	if (x > y)
		return;
	if (l >= x && r <= y)
	{
		item[o].push_back(id);
		return;
	}
	int mid = l + r >> 1;
	if (mid >= x)
		add(o << 1,l,mid,x,y,id);
	if (mid + 1 <= y)
		add(o << 1 | 1,mid + 1,r,x,y,id);
}

void solve(int o,int l,int r,int i)
{
	for (int j = 0;j < item[o].size();j++,i++)
	{
		memset(f[i + 1],0,sizeof(f[i + 1]));
		for (int k = 0;k <= m;k++)
		{
			f[i + 1][k] = max(f[i + 1][k],f[i][k]);
			if (k + w[item[o][j]] <= m)
				f[i + 1][k + w[item[o][j]]] = max(f[i + 1][k + w[item[o][j]]],f[i][k] + v[item[o][j]]);
		}
	}
	if (l == r)
	{
		ll ans = 0;
		for (int k = m;k >= 1;k--)
			ans = (ans * BASE + f[i][k]) % MOD;
		printf("%lld\n",ans);
		return;
	}
	int mid = l + r >> 1;
	solve(o << 1,l,mid,i);
	solve(o << 1 | 1,mid + 1,r,i);
}

int main()
{
	memset(outtime,-1,sizeof(outtime));
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d",&v[i],&w[i]);
		intime[i] = 1;
	}
	scanf("%d",&q);
	int cnt1 = 0,cnt3 = 0;
	for (int tp,id,i = 1;i <= q;i++)
	{
		scanf("%d",&tp);
		if (tp == 1)
		{
			cnt1++;
			scanf("%d%d",&v[n + cnt1],&w[n + cnt1]);
			intime[n + cnt1] = cnt3 + 1;
		}
		if (tp == 2)
		{
			scanf("%d",&id);
			outtime[id] = cnt3;
		}
		if (tp == 3)
			cnt3++;
	}
	for (int i = 1;i <= n + cnt1;i++)
		if (outtime[i] == -1)
			outtime[i] = cnt3;
	for (int i = 1;i <= n + cnt1;i++)
		add(1,1,cnt3,intime[i],outtime[i],i);
	solve(1,1,cnt3,0);
	return 0;
}