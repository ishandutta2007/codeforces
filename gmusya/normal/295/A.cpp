#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

struct triplet {
	ll l, r, val;
};
vector <ll> a(200001), t(800001), ans;

void build(ll v, ll tl, ll tr) {
	
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll val) {
	if (l > r)
		return;
	if (l == tl && r == tr) {
		t[v] += val;
		return;
	}
	ll tm = (tl + tr) / 2;
	t[v * 2] += t[v];
	t[v * 2 + 1] += t[v];
	t[v] = 0;
	update(v * 2, tl, tm, l, min(r, tm), val);
	update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
}

void answer(ll v, ll tl, ll tr) {
	if (tl == tr) {
		ans.push_back(t[v]);
		return;
	}
	ll tm = (tl + tr) / 2;
	t[v * 2] += t[v];
	t[v * 2 + 1] += t[v];
	t[v] = 0;
	answer(v * 2, tl, tm);
	answer(v * 2 + 1, tm + 1, tr);
}

int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector <ll> x(n);
	for (ll i = 0; i < n; i++)
		cin >> x[i];
	vector <triplet> q(m);
	for (ll i = 0; i < m; i++)
		cin >> q[i].l >> q[i].r >> q[i].val;
	for (ll i = 0; i < k; i++) {
		ll l, r;
		cin >> l >> r;
		update(1, 0, m - 1, l - 1, r - 1, 1);
	}
	answer(1, 0, m - 1);
	for (ll i = 0; i < 4 * max(m, n); i++)
		t[i] = 0;
	for (ll i = 0; i < m; i++)
		update(1, 0, n - 1, q[i].l - 1, q[i].r - 1, q[i].val * ans[i]);
	ans.resize(0);
	answer(1, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << ans[i] + x[i] << " ";
	return 0;
}