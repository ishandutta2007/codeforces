#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool is_win(vector<ll>& arr1, vector<ll>& arr2) {
	ll cnt = 0;
	for (ll i = 0; i < 5; i++) {
		cnt += arr1[i] < arr2[i];
	}
	return cnt > 2;
}

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
			for (ll j = 0; j < 5; j++) {
				cin >> arr[i][j];
			}
		}
		ll now = 0;
		for (ll i = 1; i < n; i++) {
			if (!is_win(arr[now], arr[i])) {
				now = i;
			}
		}
		bool f = false;
		for (ll i = 0; i < n; i++) {
			if (i != now) {
				if (!is_win(arr[now], arr[i])) {
					f = true;
					cout << -1 << '\n';
					break;
				}
			}
		}
		if (!f) {
			cout << now+1 << '\n';
		}
	}
}