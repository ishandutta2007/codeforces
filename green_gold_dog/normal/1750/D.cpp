#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 998244353;
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
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	ll ans = 1;
	for (ll i = 1; i < n; i++) {
		ll x = arr[i - 1] / arr[i];
		if (arr[i - 1] % arr[i] != 0) {
			ans = 0;
			break;
		}
		ll y = m / arr[i], st = m / arr[i];
		vector<ll> all;
		for (ll j = 2; j * j <= x; j++) {
			if (x % j == 0) {
				while (x % j == 0) {
					x /= j;
				}
				all.push_back(j);
			}
		}
		if (x != 1) {
			all.push_back(x);
		}
		for (ll j = 1; j < (1 << all.size()); j++) {
			ll now = 1, col = 0;
			for (ll k = 0; k < all.size(); k++) {
				if ((j >> k) & 1) {
					now *= all[k];
					col++;
				}
			}
			if (col % 2) {
				y -= st / now;
			} else {
				y += st / now;
			}
		}
		ans *= y;
		ans %= MOD;
	}
	cout << ans << '\n';
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