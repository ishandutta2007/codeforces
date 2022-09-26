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

const ll MOD = 1000000007;
const int INF = (1 << 30) - 1;

int n,addone;
int a[2000005];
int cnt[2000005];
int cntp[2000005];

ll ans;

vector<pair<int,int> > fac[2000005];
vector<vector<pair<int,int> > > Q;

void add(int v)
{
	Q.push_back(fac[v]);
	for (int i = 0;i < fac[v].size();i++)
		cntp[fac[v][i].first] = max(cntp[fac[v][i].first],fac[v][i].second);
}

int main()
{
	for (int i = 1;i <= 2000000;i++)
		a[i] = i;
	for (int i = 2;i <= 2000000;i++)
	{
		if (a[i] == 1)
			continue;
		for (int j = i;j <= 2000000;j += i)
		{
			while (a[j] % i == 0)
			{
				if (fac[j].size() && fac[j].back().first == i)
					fac[j].back().second++;
				else
					fac[j].push_back(make_pair(i,1));
				a[j] /= i;
			}
		}
	}
	scanf("%d",&n);
	for (int b,i = 1;i <= n;i++)
	{
		scanf("%d",&b);
		cnt[b]++;
	}
	for (int i = 2000000;i >= 1;i--)
		if (cnt[i])
		{
			if (cnt[i] >= 3)
				addone = 1;
			if (cnt[i] >= 2)
			{
				add(i);
				add(i - 1);
				continue;
			}
			if (!cntp[i])
				add(i);
			else
				add(i - 1);
		}
	ans = 1;
	for (int i = 1;i <= 2000000;i++)
		while (cntp[i])
		{
			(ans *= i) %= MOD;
			cntp[i]--;
		}
	memset(cntp,0,sizeof(cntp));
	for (int i = 0;i < Q.size();i++)
	{
		for (int j = 0;j < Q[i].size();j++)
		{
			if (Q[i][j].second <= cntp[Q[i][j].first])
				Q[i][j].second += INF;
			else
				cntp[Q[i][j].first] = Q[i][j].second;
		}
	}
	memset(cntp,0,sizeof(cntp));
	for (int i = Q.size() - 1;i >= 0;i--)
	{
		for (int j = 0;j < Q[i].size();j++)
		{
			int real = (Q[i][j].second > INF ? Q[i][j].second - INF : Q[i][j].second);
			if (real <= cntp[Q[i][j].first])
				Q[i][j].second = real + INF;
			else
				cntp[Q[i][j].first] = real;
		}
	}
	for (int i = 0;i < Q.size();i++)
	{
		bool all = 1;
		for (int j = 0;j < Q[i].size();j++)
			if (Q[i][j].second <= INF)
			{
				all = 0;
				break;
			}
		if (all)
			addone = 1;
	}
	printf("%lld\n",(ans + addone) % MOD);
	return 0;
}