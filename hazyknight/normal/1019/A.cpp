#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int n,m;
int cur[3005];
int cnt[3005];
int els[3005];
int need[3005][3005];

long long ans;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	ans = (1ll << 60) - 1;
	for (int p,c,i = 1;i <= n;i++)
		cin >> p >> c,need[p][++cnt[p]] = c;
	for (int i = 1;i <= m;i++)
		sort(need[i] + 1,need[i] + cnt[i] + 1);
	for (int i = cnt[1];i <= n;i++)
	{
		for (int j = 2;j <= m;j++)
			cur[j] = 1;
		int CNT = cnt[1],tot = 0;
		long long cost = 0;
		for (int j = 2;j <= m;j++)
		{
			while (cnt[j] - cur[j] + 1 >= i)
				cost += need[j][cur[j]++],CNT++;
			for (int k = cur[j];k <= cnt[j];k++)
				els[++tot] = need[j][k];
		}
		sort(els + 1,els + tot + 1);
		reverse(els + 1,els + tot + 1);
		while (CNT < i)
		{
			CNT++;
			cost += els[tot--];
		}
		ans = min(ans,cost);
	}
	cout << ans << endl;
	return 0;
}