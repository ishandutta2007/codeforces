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

const int MAXN = 100005;
const int MAXM = 5005;

int n,m,k;

ll p;
ll h[MAXN];
ll b[MAXN];
ll a[MAXN];

vector<int> evenh[MAXM];

bool check(ll v)
{
	for (int i = 1;i < m;i++)
		evenh[i].clear();
	for (int i = 1;i <= n;i++)
	{
		b[i] = v;
		if (b[i] / a[i] < m)
			evenh[b[i] / a[i]].push_back(i);
	}
	int cnt = 0;
	for (int i = 1;i < m;i++)
		for (int j = 0;j < evenh[i].size();j++)
		{
			int u = evenh[i][j];
			ll t = ((i + 1) * a[u] - b[u] - 1) / p + 1;
			if ((cnt += t) > i * k)
				return 0;
			b[u] += t * p;
			if (b[u] / a[u] < m)
				evenh[b[u] / a[u]].push_back(u);
		}
	for (int i = 1;i <= n;i++)
	{
		ll t = h[i] <= b[i] - a[i] * m ? 0 : (h[i] - b[i] + a[i] * m - 1) / p + 1;
		if ((cnt += t) > m * k)
			return 0;
	}
	return 1;
}

int main()
{
	scanf("%d%d%d%lld",&n,&m,&k,&p);
	ll low = 0,high = 1e13;
	for (int i = 1;i <= n;i++)
	{
		scanf("%lld%lld",&h[i],&a[i]);
		low = max(low,a[i]);
	}
	while (low < high)
	{
		ll mid = low + high >> 1;
		if (check(mid))
			high = mid;
		else
			low = mid + 1;
	}
	printf("%lld\n",low);
	return 0;
}