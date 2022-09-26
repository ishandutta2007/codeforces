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
#include <iomanip>

using namespace std;

const int MAXN = 100005;

int n,m,ans;

vector<int> v[MAXN];

bool cmp(const vector<int> &a,const vector<int> &b)
{
	return a.size() > b.size();
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int s,r,i = 1;i <= n;i++)
	{
		cin >> s >> r;
		v[s].push_back(r);
	}
	for (int i = 1;i <= m;i++)
	{
		sort(v[i].begin(),v[i].end());
		reverse(v[i].begin(),v[i].end());
		for (int j = 1;j < v[i].size();j++)
			v[i][j] += v[i][j - 1];
	}
	sort(v + 1,v + m + 1,cmp);
	for (int i = 1;i <= n;i++)
	{
		int cur = 0;
		for (int j = 1;j <= m;j++)
		{
			if (v[j].size() < i)
				break;
			cur += max(0,v[j][i - 1]);
		}
		ans = max(ans,cur);
	}
	cout << ans << endl;
	return 0;
}