#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1000000000000000;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

struct LCA {
	vector<vector<ll>> binup;
	vector<ll> h, size;
	ll log = 20;
	LCA(vector<vector<ll>> arr) {
		binup.resize(arr.size(), vector<ll>(20, 0));
		h.resize(arr.size(), -1);
		size.resize(arr.size(), 1);
		dfs(0, 0, arr);
	}
	void dfs(ll v, ll p, vector<vector<ll>>& arr) {
		binup[v][0] = p;
		h[v] = h[p] + 1;
		for (ll i = 1; i < log; i++) {
			binup[v][i] = binup[binup[v][i - 1]][i - 1];
		}
		for (auto i : arr[v]) {
			if (i != p) {
				dfs(i, v, arr);
				size[v] += size[i];
			}
		}
	}
	ll get_LA(ll a, ll x) {
		for (ll i = log - 1; i >= 0; i--) {
			if (x >= h[a] - h[binup[a][i]]) {
				x -= h[a] - h[binup[a][i]];
				a = binup[a][i];
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
			if (binup[a][i] != binup[b][i]) {
				a = binup[a][i];
				b = binup[b][i];
			}
		}
		return binup[a][0];
	}
	bool is_p(ll a, ll b) {
		a = get_LA(a, h[a] - h[b]);
		return a == b;
	}
	ll get_h(ll v) {
		return h[v];
	}
	ll get_dist(ll a, ll b) {
		return h[a] + h[b] - h[get_LCA(a, b)] * 2;
	}
	ll get_size(ll a) {
		return size[a];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n;
	vector<vector<ll>> arr(n);
	for (ll i = 0; i < n - 1; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[b].push_back(a);
		arr[a].push_back(b);
	}
	LCA l(arr);
	cin >> m;
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		if (a == b) {
			cout << n << '\n';
			continue;
		}
		if (l.get_h(a) < l.get_h(b)) {
			swap(a, b);
		}
		if (l.get_h(a) == l.get_h(b)) {
			cout << n - l.get_size(l.get_LA(a, l.get_dist(a, b) / 2 - 1)) - l.get_size(l.get_LA(b, l.get_dist(a, b) / 2 - 1)) << '\n';
		} else {
			if (l.get_dist(a, b) % 2 != 0) {
				cout << 0 << '\n';
			} else {
				ll lc = l.get_LA(a, l.get_dist(a, b) / 2);
				ll lc2 = l.get_LA(a, l.get_dist(a, b) / 2 - 1);
				cout << l.get_size(lc) - l.get_size(lc2) << '\n';
			}
		}
	}
}