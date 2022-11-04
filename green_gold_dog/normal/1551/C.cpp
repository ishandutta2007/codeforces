#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n;
		cin >> n;
		vector<vector<ll>> arr(n, vector<ll>(5, 0));
		for (ll i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (auto c : s) {
				arr[i][c-'a']++;
			}
		}
		ll maxn = 0;
		for (ll ns = 0; ns < 5; ns++) {
			vector<ll> colp(n);
			for (ll i = 0; i < n; i++) {
				for (ll j = 0; j < 5; j++) {
					colp[i] -= arr[i][j]*(j == ns ? -1 : 1);
				}
			}
			sort(colp.begin(), colp.end());
			reverse(colp.begin(), colp.end());
			ll now = 0;
			ll ans = 0;
			for (auto i : colp) {
				if (now + i <= 0) {
					break;
				}
				ans++;
				now += i;
			}
			maxn = max(maxn, ans);
		}
		cout << maxn << '\n';
	}
}