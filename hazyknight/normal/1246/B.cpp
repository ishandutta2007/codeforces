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

int n,k,tot;
int p[MAXN];
int c[MAXN];
int match[MAXN];
int ch[MAXN * 20][20];

bool mark[MAXN];

ll ans;

vector<int> val[MAXN * 20];
vector<pair<int,int> > d[MAXN];

void init()
{
	for (int i = 2;i <= 100000;i++)
	{
		if (!mark[i])
			p[match[i] = ++tot] = i;
		for (int j = 1;j <= tot && i * p[j] <= 100000;j++)
		{
			mark[i * p[j]] = 1;
			if (i % p[j] == 0)
				break;
		}
	}
	for (int i = 1;i <= 100000;i++)
	{
		int v = i;
		for (int j = 1;j <= tot && (ll)p[j] * p[j] <= v;j++)
			if (v % p[j] == 0)
			{
				int cnt = 0;
				while (v % p[j] == 0)
				{
					cnt++;
					v /= p[j];
				}
				cnt %= k;
				if (cnt)
					d[i].push_back(make_pair(j,cnt));
			}
		if (v != 1)
			d[i].push_back(make_pair(match[v],1));
	}
}

bool check(int a,int b)
{
	if (d[a].size() != d[b].size())
		return 0;
	for (int i = 0;i < d[a].size();i++)
		if (d[a][i].first != d[b][i].first || d[a][i].second + d[b][i].second != k)
			return 0;
	return 1;
}

int main()
{
	scanf("%d%d",&n,&k);
	init();
	for (int a,i = 1;i <= n;i++)
	{
		scanf("%d",&a);
		c[a]++;
	}
	int id = 1;
	for (int i = 1;i <= 100000;i++)
	{
		if (!c[i])
			continue;
		if (check(i,i))
			ans += (ll)c[i] * (c[i] - 1) / 2;
		int cur = 1,cnt[21] = {0};
		for (int j = 0;j < d[i].size() && d[i][j].first <= 20;j++)
			cnt[d[i][j].first] += d[i][j].second;
		bool ok = 1;
		for (int j = 1;j <= 20;j++)
		{
			if ((k - cnt[j]) % k >= 20 || !ch[cur][(k - cnt[j]) % k])
			{
				ok = 0;
				break;
			}
			cur = ch[cur][(k - cnt[j]) % k];
		}
		if (ok)
		{
			for (int j = 0;j < val[cur].size();j++)
				if (check(i,val[cur][j]))
					ans += (ll)c[i] * c[val[cur][j]];
		}
		cur = 1;
		for (int j = 1;j <= 20;j++)
		{
			if (!ch[cur][cnt[j]])
				ch[cur][cnt[j]] = ++id;
			cur = ch[cur][cnt[j]];
		}
		val[cur].push_back(i);
	}
	printf("%lld\n",ans);
	return 0;
}