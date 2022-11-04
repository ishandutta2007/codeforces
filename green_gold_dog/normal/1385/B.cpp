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

template<typename T>
T square(T& a) {
	return a * a;
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
		vector<ll> ans;
		set<ll> s;
		for (ll i = 0; i < n * 2; i++) {
			ll a;
			cin >> a;
			if (s.count(a) == 0) {
				ans.push_back(a);
				s.insert(a);
			}
		}
		for (auto i : ans) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}
/*
















*/