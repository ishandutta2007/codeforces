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
		ll ans;
		cin >> ans;
		for (ll i = 1; i < n; i++) {
			ll x;
			cin >> x;
			ans &= x;
		}
		cout << ans << '\n';
	}
}

/*
















*/