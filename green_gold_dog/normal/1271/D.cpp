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
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n), b(n), c(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	vector<vector<ll>> arr(n);
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
	}
	for (ll i = 0; i < n; i++) {
		arr[i].push_back(i);
	}
	vector<ll> nb(n, 0);
	for (ll i = n - 1; i > 0; i--) {
		nb[i - 1] = max(nb[i] - b[i], a[i]);
	}
	if (k < a[0] || k + b[0] < nb[0]) {
		cout << -1 << '\n';
		return;
	}
	vector<bool> be(n, false);
	vector<ll> cs(n, 0);
	for (ll i = 0; i < n; i++) {
		k += b[i];
		cs[i] = k - nb[i];
		k -= cs[i];
	}
	multiset<ll, greater<ll>> s;
	ll ans = 0;
	for (ll i = n - 1; i >= 0; i--) {
		for (auto j : arr[i]) {
			if (!be[j]) {
				be[j] = true;
				s.insert(c[j]);
			}
		}
		while (!s.empty() && cs[i] > 0) {
			ans += *s.begin();
			s.erase(s.begin());
			cs[i]--;
		}
	}
	cout << ans << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}