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

template<typename T>
T square(T& a) {
	return a * a;
}

ll gcd(ll a, ll b) {
	if (min(a, b) == 0) {
		return max(a, b);
	}
	return gcd(max(a, b) % min(a, b), min(a, b));
}

bool is_sorted(vector<ll>& arr) {
	for (ll i = 1; i < arr.size(); i++) {
		if (arr[i] < arr[i - 1]) {
			return false;
		}
	}
	return true;
}

ll sum(ll x) {
	ll ans = 0;
	while (x > 0) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

bool is_gcdsum(ll x) {
	return gcd(x, sum(x)) > 1;
}

bool is_prime(ll x) {
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

ll col_add(ll a, ll b) {
	ll ans = 0;
	while (a * 2 < b) {
		a *= 2;
		ans++;
	}
	return ans;
}

struct segment_tree {
	vector<ll> tree;
	ll size;
	segment_tree(vector<ll> arr) {
		ll p = 1;
		while (arr.size() > p) {
			p *= 2;
		}
		arr.resize(p, 0);
		tree.resize(p * 2, 0);
		size = p;
		build(1, 0, size, arr);
	}
	void build(ll v, ll l, ll r, vector<ll>& arr) {
		if (r - l == 1) {
			tree[v] = arr[l];
			return;
		}
		ll mid = (l + r) / 2;
		build(v * 2, l, mid, arr);
		build(v * 2 + 1, mid, r, arr);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
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
		ll mid = (l + r) / 2;
		return get(v * 2, l, mid, ql, qr) + get(v * 2 + 1, mid, r, ql, qr);
	}
	void change(ll n, ll x) {
		change(1, 0, size, n, x);
	}
	void change(ll v, ll l, ll r, ll n, ll x) {
		if (n < l || r <= n) {
			return;
		}
		if (r - l == 1) {
			tree[v] = x;
			return;
		}
		ll mid = (l + r) / 2;
		change(v * 2, l, mid, n, x);
		change(v * 2 + 1, mid, r, n, x);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll a, b, n;
	cin >> a >> b >> n;
	bool now = false;
	while (n > 0) {
		n -= gcd(a * (1 - now) + b * now, n);
		now = !now;
	}
	cout << !now;
}