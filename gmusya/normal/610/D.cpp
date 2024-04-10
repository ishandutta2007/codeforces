#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define endl '\n'
#define ll long long

using namespace std;

const ll INF = 1e12;

struct lane {
	ll x1, y1, x2, y2;
};

struct query {
	ll type; // 0 - add (x, 1); 1 - sum (l, r); 2 - add(x, -1)
	ll y;
	ll l, r, pos;
};

bool cmp_ver_1(lane a, lane b) {
	return (a.x1 < b.x1) || (a.x1 == b.x1 && a.y1 < b.y1);
}

bool cmp_hor_1(lane a, lane b) {
	return (a.y1 < b.y1) || (a.y1 == b.y1 && a.x1 < b.x1);
}

bool cmp_query(query a, query b) {
	return (a.y < b.y) || (a.y == b.y && a.type < b.type);
}

void add(ll i, ll val, vector <ll> &t) {
	while (i < t.size()) {
		t[i] += val;
		i |= (i + 1);
	}
}

ll pref(ll i, vector <ll> &t) {
	ll res = 0;
	while (i != -1) {
		res += t[i];
		i = (i & (i + 1)) - 1;
	}
	return res;
}


void read(vector <lane> &all, vector <lane> &ver, vector <lane> &hor) {
	for (ll i = 0; i < all.size(); i++) {
		cin >> all[i].x1 >> all[i].y1 >> all[i].x2 >> all[i].y2;
		if (all[i].x1 > all[i].x2)
			swap(all[i].x1, all[i].x2);
		if (all[i].y1 > all[i].y2)
			swap(all[i].y1, all[i].y2);
		if (all[i].x1 == all[i].x2)
			ver.push_back(all[i]);
		if (all[i].y1 == all[i].y2)
			hor.push_back(all[i]);
	}
}

vector <lane> prepare_vertical_lines(vector <lane> &old_ver) {
	if (old_ver.size() == 0)
		return {};
	ll ly = -INF, ry = -INF;
	vector <lane> new_ver;
	sort(old_ver.begin(), old_ver.end(), cmp_ver_1);
	for (ll i = 0; i < old_ver.size(); i++) {
		if (i != 0 && (old_ver[i].x1 != old_ver[i - 1].x1 || old_ver[i].y1 > ry)) {
			new_ver.push_back({ old_ver[i - 1].x1, ly, old_ver[i - 1].x1, ry });
			ry = -INF;
		}
		if (i == 0 || old_ver[i].x1 != old_ver[i - 1].x1 || old_ver[i].y1 > ry)
			ly = old_ver[i].y1;
		ry = max(ry, old_ver[i].y2);
	}
	new_ver.push_back({ old_ver[old_ver.size() - 1].x1, ly, old_ver[old_ver.size() - 1].x2, ry });
	return new_ver;
}

vector <lane> prepare_horizontal_lines(vector <lane> &old_hor) {
	if (old_hor.size() == 0)
		return {};
	ll lx = -INF, rx = -INF;
	vector <lane> new_hor;
	sort(old_hor.begin(), old_hor.end(), cmp_hor_1);
	for (ll i = 0; i < old_hor.size(); i++) {
		if (i != 0 && (old_hor[i].y1 != old_hor[i - 1].y1 || old_hor[i].x1 > rx)) {
			new_hor.push_back({ lx, old_hor[i - 1].y1, rx, old_hor[i - 1].y1 });
			rx = -INF;
		}
		if (i == 0 || old_hor[i].y1 != old_hor[i - 1].y1 || old_hor[i].x1 > rx)
			lx = old_hor[i].x1;
		rx = max(old_hor[i].x2, rx);
	}
	new_hor.push_back({ lx, old_hor[old_hor.size() - 1].y1, rx, old_hor[old_hor.size() - 1].y1 });
	return new_hor;
}

void compress_vector(vector <lane> &arr, set <ll> &x, set <ll> &y) {
	for (ll i = 0; i < arr.size(); i++) {
		x.insert(arr[i].x1);
		x.insert(arr[i].x2);
		y.insert(arr[i].y1);
		y.insert(arr[i].y2);
	}
}

void order(set <ll> &s, map <ll, ll> &m) {
	ll cnt = 1;
	for (ll x : s)
		m[x] = cnt++;
}

void make_it_beautiful(vector <lane> &arr, map <ll, ll> &x, map <ll, ll> &y) {
	for (ll i = 0; i < arr.size(); i++) {
		arr[i].x1 = x[arr[i].x1];
		arr[i].x2 = x[arr[i].x2];
		arr[i].y1 = y[arr[i].y1];
		arr[i].y2 = y[arr[i].y2];
	}
}

void compress_all(vector <lane> &ver, vector <lane> &hor) {
	set <ll> sx, sy;
	compress_vector(ver, sx, sy);
	compress_vector(hor, sx, sy);
	map <ll, ll> mx, my;
	order(sx, mx);
	order(sy, my);
	make_it_beautiful(ver, mx, my);
	make_it_beautiful(hor, mx, my);
}

void create_queries(vector <query> &queries, vector <lane> &ver, vector <lane> &hor) {
	for (ll i = 0; i < ver.size(); i++) {
		queries.push_back({ 0, ver[i].y1, 0, 0, ver[i].x1 });
		queries.push_back({ 2, ver[i].y2, 0, 0, ver[i].x1 });
	}
	for (ll i = 0; i < hor.size(); i++)
		queries.push_back({ 1, hor[i].y1, hor[i].x1, hor[i].x2, 0 });
}

ll run_queries(vector <query> &queries) {
	ll ans = 0;
	vector <ll> t(2 * queries.size() + 2);
	for (ll i = 0; i < queries.size(); i++) {
		if (queries[i].type == 0) add(queries[i].pos, 1, t);
		if (queries[i].type == 1) ans += pref(queries[i].r, t) - pref(queries[i].l - 1, t);
		if (queries[i].type == 2) add(queries[i].pos, -1, t);
	}
	return ans;
}

ll count(vector <lane> &arr) {
	ll ans = 0;
	for (ll i = 0; i < arr.size(); i++)
		ans += (abs(arr[i].x1 - arr[i].x2) + 1) * (abs(arr[i].y1 - arr[i].y2) + 1);
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector <lane> all(n), prep_ver, prep_hor;
	read(all, prep_ver, prep_hor);
	vector <lane> ver = prepare_vertical_lines(prep_ver);
	vector <lane> hor = prepare_horizontal_lines(prep_hor);
	ll ans = count(ver) + count(hor);
	compress_all(ver, hor);
	vector <query> queries;
	create_queries(queries, ver, hor);
	sort(queries.begin(), queries.end(), cmp_query);
	ans -= run_queries(queries);
	cout << ans;
	return 0;
}