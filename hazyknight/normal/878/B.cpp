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

ll n,k,m;
ll sz[35];

vector<pair<int,int> > v[35];

vector<pair<int,int> > merge(vector<pair<int,int> > a,vector<pair<int,int> > b)
{
	for (int i = 0;i < b.size();i++)
	{
		if (!a.size() || b[i].first != a.back().first)
			a.push_back(b[i]);
		else
		{
			(a.back().second += b[i].second) %= k;
			if (!a.back().second)
				a.pop_back();
		}
	}
	return a;
}

int main()
{
	scanf("%lld%lld%lld",&n,&k,&m);
	for (int a,i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		if (!v[0].size() || v[0].back().first != a)
			v[0].push_back(make_pair(a,1));
		else if (++v[0].back().second == k)
			v[0].pop_back();
	}
	if (k > 2 * (n - 1))
	{
		if (v[0].size() == 1)
			printf("%lld\n",n * m % k);
		else
			printf("%lld\n",n * m);
		return 0;
	}
	for (int i = 0;i < v[0].size();i++)
		sz[0] += v[0][i].second;
	for (int i = 1;(1 << i) <= m;i++)
	{
		v[i] = merge(v[i - 1],v[i - 1]);
		for (int j = 0;j < v[i].size();j++)
			sz[i] += v[i][j].second;
		if (sz[i] > 2 * sz[0] || (1 << (i + 1)) > m)
		{
			ll ans = (m / (1 << i) - 1) * sz[i] - (sz[i - 1] * 2 - sz[i]) * (m / (1 << i) - 1);
			vector<pair<int,int> > cur = v[i];
			for (int j = i - 1;j >= 0;j--)
				if (m >> j & 1)
					cur = merge(cur,v[j]);
			for (int j = 0;j < cur.size();j++)
				ans += cur[j].second;
			printf("%lld\n",ans);
			return 0;
		}
	}
	return 0;
}