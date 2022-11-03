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
	ll r1, c1, r2, c2, r3, c3;
	cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
	ll x, y;
	cin >> x >> y;
	if (((x == r1) + (x == r2) + (x == r3)) == 2 || ((y == c1) + (y == c2) + (y == c3)) == 2) {
		cout << "YES\n";
		return;
	}
	if (abs(r1 - r2) + abs(c1 - c2) == 2) {
		ll x1 = r2 - (r1 - r2), y1 = c2 - (c1 - c2), x2 = r1 - (r2 - r1), y2 = c1 - (c2 - c1);
		if ((x1 <= 0 || x1 > n || y1 <= 0 || y1 > n) && (x2 <= 0 || x2 > n || y2 <= 0 || y2 > n) && (r3 == 1 || r3 == n) && (c3 == 1 || c3 == n)) {
			cout << "NO\n";
			return;
		}
	}
	if (abs(r1 - r3) + abs(c1 - c3) == 2) {
		ll x1 = r3 - (r1 - r3), y1 = c3 - (c1 - c3), x2 = r1 - (r3 - r1), y2 = c1 - (c3 - c1);
		if ((x1 <= 0 || x1 > n || y1 <= 0 || y1 > n) && (x2 <= 0 || x2 > n || y2 <= 0 || y2 > n) && (r2 == 1 || r2 == n) && (c2 == 1 || c2 == n)) {
			cout << "NO\n";
			return;
		}
	}
	if (abs(r3 - r2) + abs(c3 - c2) == 2) {
		ll x1 = r2 - (r3 - r2), y1 = c2 - (c3 - c2), x2 = r3 - (r2 - r3), y2 = c3 - (c2 - c3);
		if ((x1 <= 0 || x1 > n || y1 <= 0 || y1 > n) && (x2 <= 0 || x2 > n || y2 <= 0 || y2 > n) && (r1 == 1 || r1 == n) && (c1 == 1 || c1 == n)) {
			cout << "NO\n";
			return;
		}
	}
	if (x % 2 == r1 % 2 && y % 2 == c1 % 2) {
		cout << "YES\n";
		return;
	}
	if (x % 2 == r2 % 2 && y % 2 == c2 % 2) {
		cout << "YES\n";
		return;
	}
	if (x % 2 == r3 % 2 && y % 2 == c3 % 2) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
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