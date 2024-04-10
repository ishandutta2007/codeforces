#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	map<ll, int> cnt;
	vector<vector<int>> a(n, vector<int>(m));
	for (auto &v : a)
	{
		for (int &x : v)
		{
			cin >> x;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			ll tmp = 0;
			for (int k = 0; k < m; k++)
			{
				tmp = tmp * 3 + (a[i][k] + a[j][k]) % 3;
			}
			cnt[tmp]++;
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll tmp = 0;
		for (int k = 0; k < m; k++)
		{
			tmp = tmp * 3 + (a[i][k] ? 3 - a[i][k] : 0);
		}
		ans += cnt[tmp] * (cnt[tmp] - 1ll) / 2;
	}
	cout << ans << endl;
}