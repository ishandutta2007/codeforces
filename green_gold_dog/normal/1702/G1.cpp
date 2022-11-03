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

struct LCA {
	ll log = 20;
	vector<vector<ll>> binup;
	vector<ll> h;
	LCA(vector<vector<ll>> arr = vector<vector<ll>>(1, vector<ll>(0, 0))) {
		binup.resize(log, vector<ll>(arr.size(), 0));
		h.resize(arr.size(), -1);
		dfs(0, 0, arr);
	}
	void dfs(ll v, ll p, vector<vector<ll>>& arr) {
		binup[0][v] = p;
		for (ll i = 1; i < log; i++) {
			binup[i][v] = binup[i - 1][binup[i - 1][v]];
		}
		h[v] = h[p] + 1;
		for (auto i : arr[v]) {
			if (i != p) {
				dfs(i, v, arr);
			}
		}
	}
	ll get_LA(ll a, ll x) {
		for (ll i = log - 1; i >= 0; i--) {
			if (x >= (1 << i)) {
				x -= 1 << i;
				a = binup[i][a];
			}
		}
		return a;
	}
	ll get_LCA(ll a, ll b) {
		if (h[a] < h[b]) {
			swap(a, b);
		}
		a = get_LA(a, h[a] - h[b]);
		if (a == b) {
			return a;
		}
		for (ll i = log - 1; i >= 0; i--) {
			if (binup[i][a] != binup[i][b]) {
				a = binup[i][a];
				b = binup[i][b];
			}
		}
		return binup[0][a];
	}
};

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& tin, vector<ll>& tout, ll& t) {
	tin[v] = t;
	t++;
	for (auto i : arr[v]) {
		if (i != p) {
			dfs(i, v, arr, tin, tout, t);
		}
	}
	tout[v] = t;
	t++;
}

void solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n);
	for (ll i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	LCA l(arr);
	vector<ll> tin(n), tout(n);
	ll t = 0;
	dfs(0, 0, arr, tin, tout, t);
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll k;
		cin >> k;
		vector<tuple<ll, ll, ll>> all;
		for (ll j = 0; j < k; j++) {
			ll x;
			cin >> x;
			x--;
			all.push_back(make_tuple(tin[x], tout[x], x));
		}
		sort(all.begin(), all.end());
		ll col = 0;
		tuple<ll, ll, ll> vt, ft = all.back();
		for (ll j = 0; j < k - 1; j++) {
			if (get<1>(all[j]) < get<1>(all[j + 1])) {
				col++;
				vt = all[j];
			}
		}
		if (col > 1) {
			cout << "NO" << '\n';
			continue;
		}
		if (col == 0) {
			cout << "YES\n";
			continue;
		}
		ll lca = l.get_LCA(get<2>(vt), get<2>(ft));
		ll co = 0;
		for (auto[a, b, c] : all) {
			if (a < get<0>(vt) && get<1>(vt) < b && a < get<0>(ft) && get<1>(ft) < b) {
				if (c == lca) {
					co++;
				} else {
					co += 2;
				}
			}
		}
		cout << (co <= 1 ? "YES\n" : "NO\n");
	}
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