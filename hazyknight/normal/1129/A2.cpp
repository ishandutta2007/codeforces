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

const int MAXN = 5005;
const int MAXM = 20005;
const int INF = (1 << 30) - 1;

int n,m,ans;
int pos[MAXM];

vector<int> cnt[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int a,i = 1;i <= m;i++)
	{
		cin >> a >> pos[i];
		cnt[a].push_back(i);
	}
	for (int i = 1;i <= n;i++)
	{
		int ans = 0;
		for (int j = 0;j < n;j++)
		{
			int cur = (i + j - 1) % n + 1;
			if (!cnt[cur].size())
				continue;
			int MIN = INF;
			for (int k = 0;k < cnt[cur].size();k++)
				MIN = min(MIN,j + ((int)cnt[cur].size() - 1) * n + (pos[cnt[cur][k]] + n - cur) % n);
			ans = max(ans,MIN);
		}
		cout << ans << ' ';
	}
	cout << endl;
	return 0;
}