#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll iii = 0; iii < t; iii++) {
		ll n;
		cin >> n;
		vector<ll> arr(n, 0);
		pair<ll, ll> minn = {100000000000, 0}, maxx = {0, 0};
		for (ll i = 0; i < n; i++) {
			cin >> arr[i];
			minn = min(minn, {arr[i], i});
			maxx = max(maxx, {arr[i], i});
		}
		if (maxx.second >= minn.second) {
			cout << min(n - minn.second, min(maxx.second + 1, n - maxx.second + minn.second + 1)) << endl;
		} else {
			cout << min(n - maxx.second, min(minn.second + 1, n - minn.second + maxx.second + 1)) << endl;
		}
	}
}