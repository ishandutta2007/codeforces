#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 9'000'000'000'000'000'000;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	set<ll> s;
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		ll a;
		cin >> a;
		sum += a;
		s.insert(a);
	}
	ll m;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		y -= sum;
		ll ans = INF;
		auto it = s.lower_bound(x);
		auto it2 = it;
		if (it != s.end()) {
			ans = max(0ll, x - *it) + max(0ll, y + *it);
		}
		if (it2 != s.begin()) {
			it2--;
			ans = min(ans, max(0ll, x - *it2) + max(0ll, y + *it2));
		}
		cout << ans << '\n';
	}
}

/*
















*/