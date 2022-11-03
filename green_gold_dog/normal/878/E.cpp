#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007, LOGMOD = 60;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

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

ll binpow(ll x, ll y) {
	if (y == 0) {
		return 1;
	}
	if (y % 2 == 1) {
		return binpow(x, y - 1) * x % MOD;
	} else {
		ll ans = binpow(x, y / 2);
		return ans * ans % MOD;
	}
}

ll inv(ll x) {
	return binpow(x, MOD - 2);
}

struct segment_tree {
	vector<ll> tree, m;
	ll size;
	segment_tree(ll n, vector<ll> arr = vector<ll>(0, 0)) {
		size = 1;
		while (size < n) {
			size *= 2;
		}
		arr.resize(size, 1);
		tree.resize(size * 2, 1);
		m.resize(size * 2, 1);
		build(1, 0, size, arr);
	}
	void build(ll v, ll l, ll r, vector<ll>& arr) {
		if (r - l == 1) {
			tree[v] = (arr[l] + MOD * 2) % MOD;
			return;
		}
		ll mid = (l + r) / 2;
		build(v * 2, l, mid, arr);
		build(v * 2 + 1, mid, r, arr);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
	void upd(ll v, ll x) {
		m[v] *= x;
		m[v] %= MOD;
		tree[v] *= x;
		tree[v] %= MOD;
	}
	void push(ll v) {
		upd(v * 2, m[v]);
		upd(v * 2 + 1, m[v]);
		m[v] = 1;
	}
	ll get(ll l, ll r) {
		return get(1, 0, size, l, r);
	}
	ll get(ll v, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		if (qr <= l || r <= ql) {
			return 0;
		}
		push(v);
		ll mid = (l + r) / 2;
		return (get(v * 2, l, mid, ql, qr) + get(v * 2 + 1, mid, r, ql, qr)) % MOD;
	}
	void change(ll l, ll r, ll x) {
		return change(1, 0, size, l, r, x);
	}
	void change(ll v, ll l, ll r, ll ql, ll qr, ll x) {
		if (ql <= l && r <= qr) {
			upd(v, x);
			return;
		}
		if (qr <= l || r <= ql) {
			return;
		}
		push(v);
		ll mid = (l + r) / 2;
		change(v * 2, l, mid, ql, qr, x);
		change(v * 2 + 1, mid, r, ql, qr, x);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
};

vector<ll> solve(int n, int m, vector<ll> arr, vector<pair<ll, ll>> qq) {
	vector<ll> ao = arr;
	vector<ll> pow2(1, 1);
	for (ll i = 0; i < LOGMOD; i++) {
		pow2.push_back(pow2.back() * 2);
	}
	vector<ll> nv(n, 0);
	deque<pair<ll, ll>> lstp;
	vector<vector<ll>> em(n + 1);
	for (ll i = n - 1; i >= 0; i--) {
		if (arr[i] >= 0) {
			lstp.push_front(make_pair(arr[i], 1));
			nv[i] = i;
		} else {
			ll ns = 0, s2 = 1;
			while (!lstp.empty() && ns + arr[i] < 0) {
				if (lstp.front().first >= MOD * 3) {
					ns = MOD * 2;
					s2 += lstp.front().second;
					break;
				}
				ns += lstp.front().first * pow2[s2];
				s2 += lstp.front().second;
				lstp.pop_front();
			}
			if (ns + arr[i] < 0) {
				nv[i] = n;
			} else {
				nv[i] = i + s2 - 1;
				lstp.push_front(make_pair(ns + arr[i], s2));
			}
		}
	}
	multiset<ll> ms;
	for (ll i = 1; i < n; i++) {
		em[nv[i]].push_back(i);
		ms.insert(i);
	}
	ms.insert(n);
	ms.insert(0);
	vector<vector<pair<ll, ll>>> q(n);
	for (ll i = 0; i < m; i++) {
		auto[l, r] = qq[i];
		l--;
		r--;
		q[r].push_back(make_pair(l, i));
	}
	vector<ll> a2(n, 2);
	for (ll i = 0; i < n; i++) {
		arr[i] *= 2;
	}
	vector<ll> ans(m, 0);
	segment_tree st(n * 2, arr), stp2(n * 2, a2);
	for (ll i = 0; i < n; i++) {
		for (auto j : em[i]) {
			ms.erase(ms.find(j));
			ll x = stp2.get(j - 1, j);
			ll y = *ms.lower_bound(j);
			st.change(j, y, x);
			stp2.change(j, y, x);
		}
		for (auto[l, j] : q[i]) {
			auto it = ms.upper_bound(l);
			ll x = *it;
			//assign_min(x, i + 1);
			it--;
			ll y = *it;
			ans[j] += st.get(l, min(x, i + 1)) * inv(binpow(2, l - y + 1)) % MOD;
			if (x <= i) {
				ans[j] += st.get(x, i + 1);
			}
		}
	}
	for (auto& i : ans) {
		i = ((i + MOD * 100) % MOD);
	}
	return ans;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	bool b = true, b2 = true;
	if (b) {
		ll t = 1;
		//cin >> t;
		for (ll i = 0; i < t; i++) {
			int n, m;
			cin >> n >> m;
			vector<ll> arr(n);
			for (ll i = 0; i < n; i++) {
				int x;
				cin >> x;
				arr[i] = x;
			}
			vector<pair<ll, ll>> q;
			for (ll i = 0; i < m; i++) {
				int l, r;
				cin >> l >> r;
				q.push_back(make_pair(l, r));
			}
			if (b2) {
				for (auto i : solve(n, m, arr, q)) {
					cout << (int)i << '\n';
				}
			} else {
			}
		}
	} else {
	}
}