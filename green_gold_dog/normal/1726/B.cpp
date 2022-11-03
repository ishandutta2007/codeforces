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
	ll n, m;
	cin >> n >> m;
	if (m < n) {
		cout << "No" << '\n';
		return;
	}
	if (n % 2 == 1) {
		cout << "Yes\n";
		for (ll i = 0; i < n - 1; i++) {
			cout << 1 << ' ';
		}
		cout << m - n + 1 << '\n';
		return;
	}
	if (n % 2 == 0) {
		if (m % 2 == 1) {
			cout << "No" << '\n';
			return;
		}
		cout << "Yes\n";
		for (ll i = 0; i < n - 2; i++) {
			cout << 1 << ' ';
		}
		cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << '\n';
		return;
	}
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