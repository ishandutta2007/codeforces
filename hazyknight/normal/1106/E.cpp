#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

typedef long long ll;

const int MAXN = 100005;
const int MAXM = 205;
const ll INF = (1ll << 60) - 1;

int n,m,k;

ll ans;
ll f[MAXN][MAXM];

vector<pair<int,int> > add[MAXN];
vector<pair<int,int> > rmv[MAXN];

priority_queue<pair<int,int> > Q1,Q2;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int s,t,d,w,i = 1;i <= k;i++)
	{
		cin >> s >> t >> d >> w;
		add[s].push_back(make_pair(w,d));
		rmv[t + 1].push_back(make_pair(w,d));
	}
	for (int i = 0;i <= n + 1;i++)
		for (int j = 0;j <= m;j++)
			f[i][j] = INF;
	f[0][0] = 0;
	for (int i = 0;i <= n;i++)
	{
		for (int j = 0;j < add[i].size();j++)
			Q1.push(add[i][j]);
		for (int j = 0;j < rmv[i].size();j++)
			Q2.push(rmv[i][j]);
		while (!Q2.empty() && Q1.top() == Q2.top())
		{
			Q1.pop();
			Q2.pop();
		}
		int to = 0,val = 0;
		if (Q1.empty())
			to = i + 1;
		else
		{
			val = Q1.top().first;
			to = Q1.top().second + 1;
		}
		for (int j = 0;j <= m;j++)
		{
			f[to][j] = min(f[to][j],f[i][j] + val);
			if (j != m)
				f[i + 1][j + 1] = min(f[i + 1][j + 1],f[i][j]);
		}
	}
	ans = INF;
	for (int j = 0;j <= m;j++)
		ans = min(ans,f[n + 1][j]);
	cout << ans << endl;
	return 0;
}