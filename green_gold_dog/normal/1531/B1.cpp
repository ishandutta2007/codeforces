#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct mon {
	ll x;
	ll y;
	mon(ll x = 0, ll y = 0): x(x), y(y) {}
	bool pod(mon m) {
		return ((x == m.x) || (y == m.y) || (y == m.x) || (x == m.y));
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<mon> arr(n, mon(0ll, 0ll));
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = i+1; j < n; j++) {
			if (arr[i].pod(arr[j])) {
				ans++;
			}
		}
	}
	cout << ans;
}