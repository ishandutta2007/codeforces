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
		ll ans = 0;
		vector<ll> arr(n, 0);
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
			ans += arr[i];
		}
		sort(arr.begin(), arr.end());
		cout << setprecision(15) << arr.back()+((double)ans-arr.back())/(n-1) << '\n';
	}
}