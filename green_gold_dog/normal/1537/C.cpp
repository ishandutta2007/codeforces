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
		ll n, maxx = 0, minn = 100000000000000;
		cin >> n;
		vector<ll> arr(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
			maxx = max(maxx, arr[i]);
			minn = min(minn, arr[i]);
		}
		sort(arr.begin(), arr.end());
		ll min = 100000000000000, col = 0, np = -1, ns = -1;
		for (ll i = 0; i < n-1; i++) {
			if (min > arr[i+1]-arr[i]) {
				if (arr[i] != minn || arr[i+1] != maxx) {
					col = n-1;
					np = i;
					ns = i+1;
				} else {
					col = n;
					np = -1;
				}
				min = arr[i+1]-arr[i];
			} else {
				if (min == arr[i+1]-arr[i]) {
					if (arr[i] == minn && arr[i+1] == maxx) {
						col = n;
						np = -1;
					}
				}
			}
		}
		if (np == -1) {
			for (auto i : arr) {
				cout << i << ' ';
			}
			cout << '\n';
		} else {
			cout << arr[np] << ' ';
			for (ll i = ns+1; i < n; i++) {
				cout << arr[i] << ' ';
			}
			for (ll i = 0; i < np; i++) {
				cout << arr[i] << ' ';
			}
			cout << arr[ns] << '\n';
		}
	}
}