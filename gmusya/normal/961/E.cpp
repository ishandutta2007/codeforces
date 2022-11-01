#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

vector <ll> t(800001);

void update(ll v, ll tl, ll tr, ll pos, ll val) {
	if (tl == tr) {
		t[v] += val;
		return;
	}
	ll tm = (tl + tr) / 2;
	if (pos <= tm) {
		update(v * 2, tl, tm, pos, val);
		t[v]++;
	}
	else {
		update(v * 2 + 1, tm + 1, tr, pos, val);
		t[v]++;
	}
}

ll sum_query(ll v, ll tl, ll tr, ll l, ll r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	ll tm = (tl + tr) / 2;
	return sum_query(v * 2, tl, tm, l, min(r, tm)) + sum_query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
}

bool cmp(pair <ll, ll> a, pair <ll, ll> b) {
	return (min(a.first, a.second) < min(b.first, b.second) || (min(a.first, a.second) == min(b.first, b.second) && (a.second < b.second)));
}

int main() {
	ll n;
	cin >> n;
	vector <pair <ll, ll>> b(n);
	for (ll i = 0; i < n; i++) {
		cin >> b[i].first;
		b[i].first = min(b[i].first, (ll) 200000);
		b[i].second = i + 1;
	}
	sort(b.begin(), b.end(), cmp);

	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ans += sum_query(1, 0, 200000, b[i].second, 200000);
		if (b[i].first >= b[i].second)
			update(1, 0, 200000, b[i].first, 1);
	}
	
	cout << ans;
	return 0;
}