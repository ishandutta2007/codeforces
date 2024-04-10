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
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> st(k);
	for (ll i = 0; i < k; i++) {
		cin >> st[i];
		st[i]--;
	}
	reverse(st.begin(), st.end());
	ll last = k - 1;
	vector<bool> be(k, false);
	ll np = n * m - 4;
	while (!st.empty()) {
		if (st.back() == last) {
			last--;
			st.pop_back();
			while (last >= 0 && be[last]) {
				last--;
				np++;
			}
		} else {
			be[st.back()] = true;
			st.pop_back();
			np--;
			if (np < 0) {
				cout << "TIDAK\n";
				return;
			}
		}
	}
	cout << "YA\n";
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