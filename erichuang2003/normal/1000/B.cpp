#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>

using namespace std;

int n,m,ans;
int a[100005];
int cnt[100005][2];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	bool flag = !(n & 1);
	a[0] = 0;
	a[n + 1] = m;
	for (int i = n;i >= 0;i--)
	{
		cnt[i][flag] = cnt[i + 1][flag] + a[i + 1] - a[i];
		flag ^= 1;
		cnt[i][flag] = cnt[i + 1][flag];
	}
	ans = cnt[0][1];
	for (int i = 0;i <= n;i++)
		if (a[i] < a[i + 1] - 1)
		{
			if (i & 1)
				ans = max(ans,cnt[0][1] - cnt[i + 1][1] + cnt[i + 1][0] + a[i + 1] - a[i] - 1);
			else
				ans = max(ans,cnt[0][1] - cnt[i + 1][1] + cnt[i + 1][0] - 1);
		}
	cout << ans << endl;
	return 0;
}