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

const int MAXN = 505;
const int MAXM = 1000005;
const ll MOD = 998244353;

int n,m;
int a[MAXM];
int LOG2[MAXM];
int MIN[MAXN];
int MAX[MAXN];
int MN[MAXM][20];
int MX[MAXM][20];

ll F[MAXN << 1][MAXN << 1];

vector<int> pos[MAXN];

int qmin(int l,int r)
{
	int t = LOG2[r - l + 1];
	return min(MN[l][t],MN[r - (1 << t) + 1][t]);
}

int qmax(int l,int r)
{
	int t = LOG2[r - l + 1];
	return max(MX[l][t],MX[r - (1 << t) + 1][t]);
}

ll f(int l,int r)
{
	if (l > r)
		return 1;
	if (qmin(l,r) < l || qmax(l,r) > r)
		return 0;
	if (F[l][r])
		return F[l][r] - 1;
	ll &res = F[l][r];
	res = 1;
	int MN = l;
	for (int k = l + 1;k <= r;k++)
		if (a[k] < a[MN])
			MN = k;
	for (int k = 0;k + 1 < pos[a[MN]].size() && res;k++)
		(res *= f(pos[a[MN]][k] + 1,pos[a[MN]][k + 1] - 1)) %= MOD;
	if (!res)
	{
		res++;
		return 1;
	}
	ll L = 0,R = 0;
	for (int k = l;k <= MIN[a[MN]];k++)
	{
		ll tmp = f(l,k - 1);
		if (tmp)
			(L += tmp * f(k,MIN[a[MN]] - 1)) %= MOD;
	}
	for (int k = r;k >= MAX[a[MN]];k--)
	{
		ll tmp = f(k + 1,r);
		if (tmp)
			(R += tmp * f(MAX[a[MN]] + 1,k)) %= MOD;
	}
	(res *= L) %= MOD;
	(res *= R) %= MOD;
	ll tmp = res;
	res++;
	return tmp;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		MIN[i] = m + 1;
	for (int i = 1;i <= m;i++)
		scanf("%d",&a[i]);
	m = unique(a + 1,a + m + 1) - a - 1;
	for (int i = 1;i <= m;i++)
	{
		MIN[a[i]] = min(MIN[a[i]],i);
		MAX[a[i]] = max(MAX[a[i]],i);
		pos[a[i]].push_back(i);
	}
	if (m >= 2 * n)
	{
		puts("0");
		return 0;
	}
	LOG2[1] = 0;
	for (int i = 2;i <= m;i++)
		LOG2[i] = LOG2[i >> 1] + 1;
	for (int i = 1;i <= m;i++)
	{
		MN[i][0] = MIN[a[i]];
		MX[i][0] = MAX[a[i]];
	}
	for (int i = m;i >= 1;i--)
		for (int j = 1;i + (1 << j) - 1 <= m;j++)
		{
			MN[i][j] = min(MN[i][j - 1],MN[i + (1 << (j - 1))][j - 1]);
			MX[i][j] = max(MX[i][j - 1],MX[i + (1 << (j - 1))][j - 1]);
		}
	printf("%lld\n",f(1,m));
	return 0;
}