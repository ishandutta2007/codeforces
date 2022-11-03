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

struct BIT {
	vector<ll> tree;
	vector<ll> arr;
	ll size;
	BIT(ll n) {
		arr.resize(n + 1, 0);
		tree.resize(n + 1, 0);
		size = n;
	}
	void change(ll x, ll y) {
		x++;
		y -= arr[x];
		arr[x] += y;
		for (; x <= size; x += x & -x) {
			tree[x] += y;
		}
	}
	ll get(ll x) {
		x++;
		return arr[x];
	}
	ll get_pref(ll x) {
		ll ans = 0;
		for (; x > 0; x -= x & -x) {
			ans += tree[x];
		}
		return ans;
	}
	ll get(ll l, ll r) {
		return get_pref(r) - get_pref(l);
	}
};

struct DSU {
	vector<ll> p;
	DSU(ll n) {
		p.resize(n, 0);
		for (ll i = 0; i < n; i++) {
			p[i] = i;
		}
	}
	ll get(ll x) {
		return (p[x] == x ? x : p[x] = get(p[x]));
	}
	bool unite(ll a, ll b) {
		a = get(a);
		b = get(b);
		if (a == b) {
			return false;
		}
		p[b] = a;
		return true;
	}
};

void solve() {
	ll n, m, q;
	cin >> n >> m >> q;
	vector<pair<ll, ll>> arr(m);
	for (ll i = 0; i < m; i++) {
		cin >> arr[i].first >> arr[i].second;
		arr[i].first--;
		arr[i].second--;
	}
	if (n <= 10) {
		vector<tuple<ll, ll, ll>> na;
		DSU d(n);
		for (ll i = 0; i < m; i++) {
			if (d.unite(arr[i].first, arr[i].second)) {
				na.emplace_back(arr[i].first, arr[i].second, i + 1);
			}
		}
		for (ll i = 0; i < q; i++) {
			ll l, r;
			cin >> l >> r;
			l--;
			DSU d(n);
			for (ll i = 0; i <= na.size(); i++) {
				ll c1 = d.get(l);
				bool b = true;
				for (ll j = l + 1; j < r; j++) {
					if (c1 != d.get(j)) {
					b = false;
						break;
					}
				}
				if (b) {
					if (i == 0) {
						cout << 0 << ' ';
						break;
					}
					cout << get<2>(na[i - 1]) << ' ';
					break;
				}
				d.unite(get<0>(na[i]), get<1>(na[i]));
			}
		}
		cout << '\n';
		return;
	}
	vector<ll> ql(q), qr(q), l(q), r(q);
	vector<vector<ll>> mid(m + 1);
	for (ll i = 0; i < q; i++) {
		cin >> ql[i] >> qr[i];
		ql[i]--;
		l[i] = -1;
		r[i] = m;
		mid[(l[i] + r[i]) / 2].push_back(i);
	}
	ll LOG = 20;
	vector<ll> p(n);
	for (ll i = 0; i < n; i++) {
		p[i] = rnd64() % INF32 + 1;
	}
	for (ll _ = 0; _ < LOG; _++) {
		BIT bit(n);
		vector<vector<ll>> pr(n);
		DSU d(n);
		for (ll j = 0; j < n; j++) {
			pr[j].push_back(j);
			bit.change(j, p[j]);
		}
		for (ll i = 0; i < m; i++) {
			 for (auto j : mid[i]) {
				ll x = bit.get(ql[j], qr[j]), y = bit.get(ql[j]);
				if (x % y == 0 && x / y == qr[j] - ql[j]) {
					r[j] = i;
				} else {
					l[j] = i;
				}
				if (r[j] - l[j] > 1) {
					mid[(r[j] + l[j]) / 2].push_back(j);
				}
			}
			mid[i].clear();
			ll a = arr[i].first, b = arr[i].second;
			a = d.get(a);
			b = d.get(b);
			if (a != b) {
				if (pr[a].size() < pr[b].size()) {
					swap(a, b);
				}
				d.unite(a, b);
				for (auto j : pr[b]) {
					pr[a].push_back(j);
					bit.change(j, p[a]);
				}
				pr[b].clear();
			}
		}
	}
	for (ll i = 0; i < q; i++) {
		cout << r[i] << ' ';
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