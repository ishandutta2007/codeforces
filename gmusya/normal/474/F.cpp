#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define ll long long

using namespace std;

struct kek {
	ll start_pos; //   
	ll type; //0 - l, //1 - r, //2 - add a[i];
	ll val; // 0,  ans[start_pos] -= m[val];  1,  ans[start_pos] += val;  2,  m[val]++;
	ll x; //,   
};

ll gcd(ll a, ll b) {
	if (min(a, b) == -1)
		return max(a, b);
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

ll n, q;
vector <ll> a, t, gcd_for_query, ans;
vector <kek> scanline;
vector <pair <ll, ll>> query;

void build(ll v, ll tl, ll tr) {
	if (tl == tr) {
		t[v] = a[tl];
		return;
	}
	ll tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = gcd(t[v * 2], t[v * 2 + 1]);
}
ll gcd_query(ll v, ll tl, ll tr, ll l, ll r) {
	if (l > r)
		return -1;
	if (l == tl && r == tr)
		return t[v];
	ll tm = (tl + tr) / 2;
	return gcd(gcd_query(v * 2, tl, tm, l, min(r, tm)), gcd_query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r));
}
bool cmp(kek a, kek b) {
	return (a.x < b.x) || (a.x == b.x && a.type < b.type);
}

int main() {
	cin >> n;
	a.resize(n);
	t.resize(n << 2);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	build(1, 0, n - 1);
	cin >> q;
	query.resize(q), ans.resize(q), gcd_for_query.resize(q);
	for (ll i = 0; i < q; i++) {
		cin >> query[i].first >> query[i].second;
		query[i].first--;
		query[i].second--;
	}
	for (ll i = 0; i < q; i++)
		gcd_for_query[i] = gcd_query(1, 0, n - 1, query[i].first, query[i].second);
	for (ll i = 0; i < n; i++)
		scanline.push_back({ 0, 1, a[i], i });
	for (ll i = 0; i < q; i++) {
		scanline.push_back({ i, 0, gcd_for_query[i], query[i].first });
		scanline.push_back({ i, 2, gcd_for_query[i], query[i].second });
	}
	sort(scanline.begin(), scanline.end(), cmp);
	unordered_map <ll, ll> pre_num;
	for (ll i = 0; i < scanline.size(); i++) {
		if (scanline[i].type == 1) {
			pre_num[scanline[i].val]++;
			continue;
		}
		if (scanline[i].type == 0)
			ans[scanline[i].start_pos] -= pre_num[scanline[i].val];
		else
			ans[scanline[i].start_pos] += pre_num[scanline[i].val];
	}
	for (ll i = 0; i < q; i++)
		cout << query[i].second - query[i].first + 1 - ans[i] << " ";
	return 0;
}