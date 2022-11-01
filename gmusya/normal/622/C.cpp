#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

const ll INF = 1e12;

struct tree {
	ll min, minid;
	ll max, maxid;
};

ll n, m;
vector <ll> a, ans;
vector <tree> t;

void build(ll v, ll tl, ll tr) {
	if (tr == tl) {
		t[v].min = t[v].max = a[tl];
		t[v].minid = t[v].maxid = tl;
		return;
	}
	ll tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);

	if (t[v * 2].min < t[v * 2 + 1].min) {
		t[v].min = t[v * 2].min;
		t[v].minid = t[v * 2].minid;
	}
	else {
		t[v].min = t[v * 2 + 1].min;
		t[v].minid = t[v * 2 + 1].minid;
	}

	if (t[v * 2].max > t[v * 2 + 1].max) {
		t[v].max = t[v * 2].max;
		t[v].maxid = t[v * 2].maxid;
	}
	else {
		t[v].max = t[v * 2 + 1].max;
		t[v].maxid = t[v * 2 + 1].maxid;
	}

}

pair <ll, ll> min_query(ll v, ll tl, ll tr, ll l, ll r) {
	if (l > r)
		return { INF, -1 };
	if (l == tl && r == tr)
		return { t[v].min, t[v].minid };
	ll tm = (tl + tr) / 2;
	pair <ll, ll> left = min_query(v * 2, tl, tm, l, min(r, tm)), right = min_query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	if (left.first < right.first)
		return left;
	else
		return right;
}

pair <ll, ll> max_query(ll v, ll tl, ll tr, ll l, ll r) {
	if (l > r)
		return { 0, -1 };
	if (l == tl && r == tr)
		return { t[v].max, t[v].maxid };
	ll tm = (tl + tr) / 2;
	pair <ll, ll> left = max_query(v * 2, tl, tm, l, min(r, tm)), right = max_query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	if (left.first > right.first)
		return left;
	else
		return right;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	a.resize(n);
	t.resize(n * 4);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	build(1, 0, n - 1);

	for (ll i = 0; i < m; i++) {
		ll l, r, val;
		cin >> l >> r >> val;
		pair <ll, ll> mi = min_query(1, 0, n - 1, l - 1, r - 1);
		if (mi.first != val) {
			ans.push_back(mi.second + 1);
			continue;
		}
		pair <ll, ll> ma = max_query(1, 0, n - 1, l - 1, r - 1);
		if (ma.first != val) {
			ans.push_back(ma.second + 1);
			continue;
		}
		ans.push_back(-1);
	}

	for (auto now : ans)
		cout << now << '\n';

	return 0;
}