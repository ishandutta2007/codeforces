#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);

random_device rd;
mt19937 rnd32(rd());
mt19937_64 rnd64(rd());

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

bool check(ll x, ll n, ll k) {
	if (x > n) {
		return false;
	}
	ll nl = x, nr = min(n, x + 1);
	if (x % 2 == 1) {
		nr = x;
	}
	ll now = nr - nl + 1;
	while (nr < n) {
		nl *= 2;
		nr *= 2;
		nr++;
		assign_min(nr, n);
		now += max(0ll, nr - nl + 1);
	}
	return now >= k;
}

void solve() {
	ll k, n;
	cin >> n >> k;
	ll l = 0, r = n + 1;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		if (check(mid * 2, n, k)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	l *= 2;
	if (check(l + 1, n, k)) {
		l++;
	}
	cout << l << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}