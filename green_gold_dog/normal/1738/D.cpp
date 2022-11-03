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
	vector<ll> arr(n);
	map<ll, vector<ll>> m;
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		m[arr[i]].push_back(i + 1);
	}
	vector<ll> ans;
	ll k = 0;
	ll last = 0;
	bool b = false;
	if (m[0].size() == 0) {
		b = !b;
		last = n + 1;
	}
	while (ans.size() != n) {
		if (b) {
			for (auto i : m[last]) {
				assign_max(k, i);
			}
		}
		b = !b;
		ll x = m[last][0];
		for (auto i : m[last]) {
			if (m[i].size() != 0) {
				x = i;
			}
		}
		for (auto i : m[last]) {
			if (i != x) {
				ans.push_back(i);
			}
		}
		ans.push_back(x);
		last = x;
	}
	cout << k << '\n';
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
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