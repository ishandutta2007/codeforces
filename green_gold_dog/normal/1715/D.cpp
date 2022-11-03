#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007, ML = 30;
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

bool cmp(tuple<ll, ll, ll> a1, tuple<ll, ll, ll> a2) {
	return get<1>(a1) < get<1>(a2);
}

void solve() {
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n, (1ll << ML) - 1);
	vector<tuple<ll, ll, ll>> all(q);
	for (auto&[i, j, x] : all) {
		cin >> i >> j >> x;
		i--;
		j--;
		if (i > j) {
			swap(i, j);
		}
		a[i] &= x;
		a[j] &= x;
	}
	sort(all.begin(), all.end(), cmp);
	vector<ll> ans(n, 0);
	for (auto&[i, j, x] : all) {
		ans[i] |= a[j] ^ x;
	}
	for (auto&[i, j, x] : all) {
		ans[j] |= a[j] & (x ^ ans[i]);
	}
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