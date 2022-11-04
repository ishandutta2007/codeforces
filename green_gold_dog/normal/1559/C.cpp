#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n;
		cin >> n;
		vector<ll> arr(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
		}
		ll i = 0;
		if (arr[0] != 1) {
			i++;
			for (; i < n; i++) {
				if (!arr[i - 1] && arr[i]) {
					break;
				}
			}
		}
		if (i == n && arr[n - 1] == 1) {
			cout << -1 << '\n';
		} else {
			for (ll j = 0; j < i; j++) {
				cout << j + 1 << ' ';
			}
			cout << n + 1 << ' ';
			for (ll j = i; j < n; j++) {
				cout << j + 1 << ' ';
			}
			cout << '\n';
		}
	}
}

/*
















*/