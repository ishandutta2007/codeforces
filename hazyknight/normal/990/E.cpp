#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using namespace std;

const int MAXN = 1000005;

int n,m,k;
int c[MAXN];
int l[MAXN];

long long ans = (1ll << 60) - 1;

bool mark[MAXN];

int solve(int len)
{
	int bound = 0,ret = 0;
	if (mark[0])
		return -1;
	while (bound < n)
	{
		if (l[bound] + len <= bound)
			return -1;
		bound = l[bound] + len;
		ret++;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int b,i = 1;i <= m;i++)
	{
		cin >> b;
		mark[b] = true;
	}
	int cur = -1;
	for (int i = 0;i <= n;i++)
	{
		if (!mark[i])
			cur = i;
		l[i] = cur;
	}
	for (int i = 1;i <= k;i++)
		cin >> c[i];
	for (int i = 1;i <= k;i++)
	{
		int ret = solve(i);
		if (ret == -1)
			continue;
		ans = min(ans,(long long)ret * c[i]);
	}
	if (ans == (1ll << 60) - 1)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}