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
	vector<ll> h;
	ll log = 20;
	LCA(vector<vector<ll>> arr) {
		binup.resize(arr.size(), vector<ll>(20, 0));
		h.resize(arr.size(), -1);
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
		return h[a] + h[b] - h[get_LCA(a, b)] * 2 + 1;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> arr(n);
	for (ll i = 0; i < n - 1; i++) {
		ll a;
		cin >> a;
		a--;
		arr[i + 1].push_back(a);
		arr[a].push_back(i + 1);
	}
	LCA l(arr);
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		c--;
		ll ab = l.get_dist(a, b), ac = l.get_dist(a, c), bc = l.get_dist(b, c);
		cout << (ab + ac + bc - min(ab, min(ac, bc)) * 2 + 1) / 2 << '\n';
	}
}