#include <iostream>
#include <vector>
#include <algorithm>
 
#define endl '\n'
#define ll long long
 
using namespace std;
 
struct tree {
	ll sum;
	ll max;
	ll mod;
};
 
void build(ll v, ll tl, ll tr, vector <tree> &t, vector <ll> &a) {
	if (tl == tr) {
		t[v].max = t[v].sum = a[tl];
		return;
	}
	ll tm = (tl + tr) / 2;
	build(v * 2, tl, tm, t, a);
	build(v * 2 + 1, tm + 1, tr, t, a);
	t[v].max = max(t[v * 2].max, t[v * 2 + 1].max);
	t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
}
 
ll query(ll v, ll tl, ll tr, ll l, ll r, vector <tree> &t, vector <ll> &a) {
	if (l > r) return 0;
	if (l == tl && r == tr) return t[v].sum;
	ll tm = (tl + tr) / 2;
	ll x = query(v * 2, tl, tm, l, min(r, tm), t, a);
	ll y = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, t, a);
	return x + y;
}
 
void modify(ll v, ll tl, ll tr, ll l, ll r, ll x, vector <tree> &t, vector <ll> &a) {
	if (l > r) return;
	if (t[v].max < x) return;
	if (tl == tr) {
		t[v].sum %= x;
		t[v].max %= x;
		return;
	}
	ll tm = (tl + tr) / 2;
	modify(v * 2, tl, tm, l, min(r, tm), x, t, a);
	modify(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x, t, a);
	t[v].max = max(t[v * 2].max, t[v * 2 + 1].max);
	t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
}
 
void update(ll v, ll tl, ll tr, ll pos, ll x, vector <tree> &t, vector <ll> &a) {
	if (tl == tr) {
		t[v].sum = t[v].max = x;
		return;
	}
	ll tm = (tl + tr) / 2;
	if (tm >= pos) update(v * 2, tl, tm, pos, x, t, a);
	if (tm < pos) update(v * 2 + 1, tm + 1, tr, pos, x, t, a);
	t[v].max = max(t[v * 2].max, t[v * 2 + 1].max);
	t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector <ll> ans;
	ll n, q;
	cin >> n >> q;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	vector <tree> t(4 * n);
	build(1, 0, n - 1, t, a);
	for (ll i = 0; i < q; i++) {
		ll type;
		cin >> type;
		if (type == 1) {
			ll l, r;
			cin >> l >> r;
			l--, r--;
			ans.push_back(query(1, 0, n - 1, l, r, t, a));
		}
		if (type == 2) {
			ll l, r, x;
			cin >> l >> r >> x;
			l--, r--;
			modify(1, 0, n - 1, l, r, x, t, a);
		}
		if (type == 3) {
			ll pos, x;
			cin >> pos >> x;
			pos--;
			update(1, 0, n - 1, pos, x, t, a);
		}
	}
	for (ll x : ans)
		cout << x << endl;
	return 0;
}