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

struct DSU {
	vector<ll> p;
	DSU(ll n = 0) {
		p.resize(n, 0);
		for (ll i = 0; i < n; i++) {
			p[i] = i;
		}
	}
	ll get(ll v) {
		return (p[v] == v ? v : p[v] = get(p[v]));
	}
	void unite(ll a, ll b) {
		p[get(b)] = get(a);
	}
};

void solve() {
	ll n, m, x;
	cin >> n >> m >> x;
	ll sum = 0;
	vector<ll> a(n);
	set<pair<ll, ll>, greater<pair<ll, ll>>> s;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		s.insert(make_pair(a[i], i));
	}
	vector<pair<ll, ll>> arr;
	vector<vector<pair<ll, ll>>> go(n);
	map<pair<ll, ll>, ll> num;
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr.emplace_back(a, b);
		num[make_pair(a, b)] = i + 1;
		go[a].emplace_back(b, i + 1);
		go[b].emplace_back(a, i + 1);
	}
	if (sum < n * x - x) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	vector<ll> ans;
	DSU d(n);
	for (ll i = 1; i < n; i++) {
		if (s.begin()->first >= x) {
			ll now = s.begin()->second;
			s.erase(s.begin());
			while (d.get(go[now].back().first) == now) {
				go[now].pop_back();
			}
			ans.push_back(go[now].back().second);
			go[now].back().first = d.get(go[now].back().first);
			a[now] += a[go[now].back().first];
			a[now] -= x;
			ll g = go[now].back().first;
			go[now].pop_back();
			if (go[now].size() < go[g].size()) {
				swap(go[now], go[g]);
			}
			for (auto i : go[g]) {
				go[now].push_back(i);
			}
			go[g].clear();
			d.unite(now, g);
			s.erase(make_pair(a[g], g));
			s.insert(make_pair(a[now], now));
		} else {
			while (d.get(arr.back().first) == d.get(arr.back().second)) {
				arr.pop_back();
			}
			ans.push_back(num[make_pair(arr.back().first, arr.back().second)]);
			ll f = d.get(arr.back().first);
			ll se = d.get(arr.back().second);
			s.erase(make_pair(a[f], f));
			s.erase(make_pair(a[se], se));
			a[f] += a[se];
			a[f] -= x;
			d.unite(f, se);
			s.insert(make_pair(a[f], f));
			arr.pop_back();
		}
	}
	for (auto i : ans) {
		cout << i << '\n';
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