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

void dfs(ll v, vector<vector<ll>>& arr, vector<ll>& tin, vector<ll>& tout, ll& t) {
	tin[v] = t;
	t++;
	for (auto i : arr[v]) {
		dfs(i, arr, tin, tout, t);
	}
	tout[v] = t;
	t++;
}

ll dfs2(ll v, vector<vector<ll>>& arr, vector<ll>& tin, vector<ll>& tout, set<pair<ll, ll>>& s) {
	s.insert(make_pair(tin[v], tout[v]));
	pair<ll, ll> d(0, 0), a(0, 0);
	auto it = s.upper_bound(make_pair(tin[v], tout[v]));
	if (it != s.end()) {
		if (it->second < tout[v]) {
			s.erase(make_pair(tin[v], tout[v]));
		}
	}
	it = s.lower_bound(make_pair(tin[v], tout[v]));
	if (it != s.end() && it != s.begin()) {
		it--;
		if (it->second > tout[v]) {
			d = *it;
			a = make_pair(tin[v], tout[v]);
			s.erase(it);
		}
	}
	ll ans = s.size();
	for (auto i : arr[v]) {
		assign_max(ans, dfs2(i, arr, tin, tout, s));
	}
	s.insert(d);
	s.erase(a);
	s.erase(make_pair(tin[v], tout[v]));
	return ans;
}

void solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> arr1(n), arr2(n);
	for (ll i = 1; i < n; i++) {
		ll x;
		cin >> x;
		x--;
		arr1[x].push_back(i);
	}
	for (ll i = 1; i < n; i++) {
		ll x;
		cin >> x;
		x--;
		arr2[x].push_back(i);
	}
	ll t = 0;
	vector<ll> tin(n), tout(n);
	dfs(0, arr2, tin, tout, t);
	set<pair<ll, ll>> s;
	cout << dfs2(0, arr1, tin, tout, s) << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}