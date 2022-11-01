#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

vector <ll> a(200001), t(800001);

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
	if (tl == tr)
		return;
	ll tm = (tl + tr) / 2;
	t[v * 2] += t[v];
	t[v * 2 + 1] += t[v];
	t[v] = 0;
	answer(v * 2, tl, tm);
	answer(v * 2 + 1, tm + 1, tr);
}

int main() {
	ll n, q;
	cin >> n >> q;
	vector <ll> b(n);
	for (ll i = 0; i < n; i++)
		cin >> b[i];
	for (ll i = 0; i < q; i++) {
		ll l, r;
		cin >> l >> r;
		update(1, 0, n - 1, l - 1, r - 1, 1);
	}
	answer(1, 0, n - 1);
	vector <ll> ans;
	for (ll i = 0; i < 4 * n; i++)
		if (t[i] != 0)
			ans.push_back(t[i]);
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	ll cnt = 0;
	for (ll i = 0; i < ans.size(); i++)
		cnt += b[i] * ans[i];
	cout << cnt;
	return 0;
}