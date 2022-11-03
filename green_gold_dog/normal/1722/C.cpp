#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);
const bool IS_FILE = false, IS_TEST_CASES = true;

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

void solve() {
	ll n;
	cin >> n;
	map<string, ll> m;
	vector<string> a1(n), a2(n), a3(n);
	for (ll i = 0; i < n; i++) {
		cin >> a1[i];
		m[a1[i]]++;
	}
	for (ll i = 0; i < n; i++) {
		cin >> a2[i];
		m[a2[i]]++;
	}
	for (ll i = 0; i < n; i++) {
		cin >> a3[i];
		m[a3[i]]++;
	}
	ll c1 = 0, c2 = 0, c3 = 0;
	for (ll i = 0; i < n; i++) {
		if (m[a1[i]] == 1) {
			c1 += 3;
		}
		if (m[a1[i]] == 2) {
			c1++;
		}
		if (m[a2[i]] == 1) {
			c2 += 3;
		}
		if (m[a2[i]] == 2) {
			c2++;
		}
		if (m[a3[i]] == 1) {
			c3 += 3;
		}
		if (m[a3[i]] == 2) {
			c3++;
		}
	}
	cout << c1 << ' ' << c2 << ' ' << c3 << '\n';
}

int main() {
	if (IS_FILE) {
		freopen("", "r", stdin);
		freopen("", "w", stdout);
	}
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	if (IS_TEST_CASES) {
		cin >> t;
	}
	for (ll i = 0; i < t; i++) {
		solve();
	}
}