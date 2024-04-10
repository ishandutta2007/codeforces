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

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	vector<ll> mi(n), ma(n);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		ll l = 0, r = n;
		while (r - l > 1) {
			ll mid = (l + r) / 2;
			if ((i + 1) / mid > arr[i]) {
				l = mid;
			} else {
				r = mid;
			}
		}
		mi[i] = r;
		l = 1;
		r = n + 1;
		while (r - l > 1) {
			ll mid = (l + r) / 2;
			if ((i + 1) / mid >= arr[i]) {
				l = mid;
			} else {
				r = mid;
			}
		}
		ma[i] = r - 1;
	}
	set<pair<ll, ll>> s;
	vector<vector<pair<ll, ll>>> st(n + 1);
	for (ll i = 0; i < n; i++) {
		st[mi[i]].push_back(make_pair(ma[i], i));
	}
	vector<ll> ans(n);
	for (ll i = 1; i <= n; i++) {
		for (auto j : st[i]) {
			s.insert(j);
		}
		ans[s.begin()->second] = i;
		s.erase(s.begin());
	}
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
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