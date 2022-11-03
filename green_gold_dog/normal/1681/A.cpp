#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
T square(T a) {
	return a * a;
}

template<>
struct std::hash<pair<ll, ll>> {
	ll operator() (pair<ll, ll> p) {
		return ((__int128)p.first * MOD + p.second) % INF64;
	}
};

void solve() {
	ll n, m;
	cin >> n;
	ll m1 = 0;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		assign_max(m1, x);
	}
	cin >> m;
	ll m2 = 0;
	for (ll i = 0; i < m; i++) {
		ll x;
		cin >> x;
		assign_max(m2, x);
	}
	if (m1 > m2) {
		cout << "Alice" << '\n' << "Alice" << '\n';
	}
	if (m1 == m2) {
		cout << "Alice" << '\n' << "Bob" << '\n';
	}
	if (m1 < m2) {
		cout << "Bob" << '\n' << "Bob" << '\n';
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}