#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, k, x, ans = 0;
	cin >> n >> k >> x;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	vector<ll> p;
	for (ll i = 1; i < n; i++) {
		p.push_back(max((abs(arr[i]-arr[i-1])-1)/x, 0ll));
	}
	sort(p.begin(), p.end());
	for (ll i = 0; i < n-1; i++) {
		if (p[i] <= k) {
			k -= p[i];
		} else {
			ans++;
		}
	}
	cout << ans+1;
}