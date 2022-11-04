#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

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
	ll n;
	cin >> n;
	vector<ll> t1, t2, t3;
	for (ll i = 0; i < n; i++) {
		ll a;
		cin >> a;
		if (a == 1) {
			t1.push_back(i + 1);
		}
		if (a == 2) {
			t2.push_back(i + 1);
		}
		if (a == 3) {
			t3.push_back(i + 1);
		}
	}
	ll ans = min(t1.size(), min(t2.size(), t3.size()));
	cout << ans << '\n';
	for (ll i = 0; i < ans; i++) {
		cout << t1[i] << ' ' << t2[i] << ' ' << t3[i] << '\n';
	}
}
/*
















*/