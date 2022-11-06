#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<vector<ll>> ans(n+1, vector<ll>(n+1, 0));
	for (ll i = 1; i < n+1; i++) {
		ll x = i, y = i, now = arr[i-1];
		ans[y][x] = now;
		now--;
		while (now > 0) {
			if (x > 1 && ans[y][x-1] == 0) {
				x--;
			} else {
				y++;
			}
			now--;
			ans[y][x] = arr[i-1];
		}
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j <= i; j++) {
			cout << ans[i+1][j+1] << ' ';
		}
		cout << '\n';
	}
}