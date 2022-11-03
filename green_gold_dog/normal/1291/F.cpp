#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);
const bool IS_FILE = false, IS_TEST_CASES = false;

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
	ll n, k;
	cin >> n >> k;
	vector<bool> be(n, true);
	if (k == 1) {
		for (ll i = 0; i < n; i++) {
			for (ll j = i + 1; j < n; j++) {
				cout << "? " << i + 1 << endl;
				cout << "? " << j + 1 << endl;
				char c;
				cin >> c >> c;
				if (c == 'Y') {
					be[j] = false;
				}
			}
		}
	} else {
		k >>= 1;
		for (ll i = 0; i < n / k; i++) {
			bool b = true;
			for (ll j = i + 1; j < n / k; j++) {
				for (ll f = 0; f < k; f++) {
					cout << "? " << i * k + f + 1 << endl;
					char c;
					cin >> c;
					if (b && c == 'Y') {
						be[i * k + f] = false;
					}
				}
				b = false;
				for (ll f = 0; f < k; f++) {
					cout << "? " << j * k + f + 1 << endl;
					char c;
					cin >> c;
					if (c == 'Y') {
						be[j * k + f] = false;
					}
				}
			}
			cout << 'R' << endl;
		}
	}
	ll ans = 0;
	for (auto i : be) {
		ans += i;
	}
	cout << "! " << ans << endl;
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