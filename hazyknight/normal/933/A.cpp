#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int n,ans;
int a[2005];
int f[2005][2005];
int g[2005][2005];
int cnt1[2005][2005];
int cnt2[2005][2005];

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
		for (int j = i;j <= n;j++)
		{
			cnt1[i][j] = cnt1[i][j - 1] + (a[j] == 1);
			cnt2[i][j] = cnt2[i][j - 1] + (a[j] == 2);
		}
	for (int i = 1;i <= n;i++)
	{
		int MAX = 0;
		for (int j = i;j <= n;j++)
		{
			if (a[j] == 1)
				MAX = max(MAX,f[i][j] = cnt1[i][j]);
			else
				MAX = f[i][j] = MAX + 1;
		}
	}
	for (int i = n;i >= 1;i--)
	{
		int MAX = 0;
		for (int j = i;j >= 1;j--)
		{
			if (a[j] == 1)
				MAX = max(MAX,g[j][i] = cnt1[j][i]);
			else
				MAX = g[j][i] = MAX + 1;
		}
	}
	for (int i = 1;i <= n;i++)
		for (int j = i;j <= n;j++)
		{
			ans = max(ans,f[1][i - 1] + cnt2[i][n]);
			ans = max(ans,cnt1[1][i - 1] + g[i][j] + cnt2[j + 1][n]);
			ans = max(ans,cnt1[1][j] + f[j + 1][n]);
		}
	cout << ans << endl;
	return 0;
}