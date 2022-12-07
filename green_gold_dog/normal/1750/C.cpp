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
	string s1, s2;
	cin >> s1 >> s2;
	deque<pair<ll, ll>> ans;
	if (s1 != s2) {
		ans.push_back(make_pair(1, n));
		for (auto& i : s1) {
			if (i == '0') {
				i = '1';
			} else {
				i = '0';
			}
		}
	}
	if (s1 != s2) {
		cout << "NO\n";
		return;
	}
	deque<ll> e;
	for (ll i = 0; i < n; i++) {
		if (s1[i] == '1') {
			e.push_back(i + 1);
		}
	}
	while (e.size() > 1) {
		ans.emplace_back(e[0], e[0]);
		ans.emplace_back(e[1], e[1]);
		e.pop_front();
		e.pop_front();
	}
	if (!e.empty()) {
		if (e.back() == 1) {
			ans.emplace_back(1, n);
			ans.emplace_back(2, n);
		} else {
			if (e.back() == n) {
				ans.emplace_back(1, n);
				ans.emplace_back(1, n - 1);
			} else {
				ans.emplace_back(e[0], e[0]);
				ans.emplace_back(1, 1);
				ans.emplace_back(2, n);
				ans.emplace_back(1, n);
			}
		}
	}
	cout << "YES\n" << ans.size() << '\n';
	for (auto[x, y] : ans) {
		cout << x << ' ' << y << '\n';
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