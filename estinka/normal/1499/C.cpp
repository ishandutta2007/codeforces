#include <iostream>
#include <string>
#include <set>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <queue>
typedef long long ll;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<ll> c(n);
		for (int i = 0; i < n; i++) cin >> c[i];
		ll sum = 0, ans = 1e18;
		vector<ll> mini(2, ans), cnt(2, 0); mini[0] = c[0]; cnt[0]++;
		sum += c[0];
		for (int i = 1; i < n; i++)
		{
			mini[i & 1] = min(mini[i & 1], c[i]);
			cnt[i & 1]++;
			sum += c[i];
			ll cur = sum;
			for (int j = 0; j < 2; j++)
			{
				ll need = n - cnt[j];
				cur += mini[j] * need;
			}
			ans = min(ans, cur);
		}
		cout << ans << "\n";
	}
	return 0;
}