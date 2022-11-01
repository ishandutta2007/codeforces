#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

vector <ll> t(4 * 10e5);

void update(ll v, ll tl, ll tr, ll pos, ll val) {
	if (tl == tr) {
		t[v] = val;
		return;
	}
	ll tm = (tl + tr) / 2;
	if (pos <= tm)
		update(v * 2, tl, tm, pos, val);
	else
		update(v * 2 + 1, tm + 1, tr, pos, val);
	t[v] = t[v * 2] + t[v * 2 + 1];
}

ll sum_query(ll v, ll tl, ll tr, ll l, ll r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	ll tm = (tl + tr) / 2;
	return sum_query(v * 2, tl, tm, l, min(r, tm)) + sum_query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
}

int main() {
	ll n;
	cin >> n;
	vector <pair <ll, ll>> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());
	ll cur_pos = 0, ans = 0, deleted = 0;
	for (ll i = 0; i < n; i++) {
		bool tf = true;
		ll r = i;
		while (r < n && a[r].first == a[i].first)
			r++;
		ll l = i;
		ll hm = sum_query(1, 0, n, 0, cur_pos);
		while (l < r && a[l].second < cur_pos)
			l++;
		for (ll j = l; j < r; j++) {
			ans += a[j].second - sum_query(1, 0, n, 0, a[j].second) - (cur_pos - sum_query(1, 0, n, 0, cur_pos));
			cur_pos = a[j].second;
			deleted++;
			update(1, 0, n, a[j].second, 1);
		}
		for (ll j = i; j < l; j++) {
			ans += a[j].second - sum_query(1, 0, n, 0, a[j].second) - (cur_pos - sum_query(1, 0, n, 0, cur_pos)) + (n - deleted) * tf;
			tf = false;
			cur_pos = a[j].second;
			deleted++;
			update(1, 0, n, a[j].second, 1);
		}
		i = r - 1;
	}
	cout << ans;
	return 0;
}