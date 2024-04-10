#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

struct sqr {
	int x1, y1, x2, y2;
	int start;
};

bool cmp1 (pair <int, int> a, pair <int, int> b) {
	return a.first < b.first;
}

bool cmp2(pair <int, int> a, pair <int, int> b) {
	return a.second < b.second;
}

bool cmp3(sqr a, sqr b) {
	return a.x2 < b.x2;
}

bool cmp4(sqr a, sqr b) {
	return a.y2 < b.y2;
}

vector <int> t;
int INF = 1e7;

void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		t[v] = val;
		return;
	}
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		update(v * 2, tl, tm, pos, val);
	else
		update(v * 2 + 1, tm + 1, tr, pos, val);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int min_query(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return INF;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	int x = min_query(v * 2, tl, tm, l, min(r, tm));
	int y = min_query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	return min(x, y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector <pair <int, int>> l(k);
	for (int i = 0; i < k; i++)
		cin >> l[i].first >> l[i].second;
	vector <sqr> query(q);
	vector <int> ans(q);
	for (int i = 0; i < q; i++) {
		cin >> query[i].x1 >> query[i].y1 >> query[i].x2 >> query[i].y2;
		query[i].start = i;
	}
	sort(l.begin(), l.end(), cmp1);
	sort(query.begin(), query.end(), cmp3);
	t.resize(4 * m + 4, -1);
	int uk_l = 0;
	int uk_q = 0;
	for (int i = 1; i <= n; i++) {
		while (uk_l < k && l[uk_l].first == i) {
			update(1, 0, m, l[uk_l].second, i);
			uk_l++;
		}
		while (uk_q < q && query[uk_q].x2 == i) {
			int hm = min_query(1, 0, m, query[uk_q].y1, query[uk_q].y2);
			if (hm >= query[uk_q].x1)
				ans[query[uk_q].start] = 1;
			uk_q++;
		}
	}
	sort(l.begin(), l.end(), cmp2);
	sort(query.begin(), query.end(), cmp4);
	t.assign(4 * n + 4, -1);
	uk_l = 0;
	uk_q = 0;
	for (int i = 1; i <= m; i++) {
		while (uk_l < k && l[uk_l].second == i) {
			update(1, 0, n, l[uk_l].first, i);
			uk_l++;
		}
		while (uk_q < q && query[uk_q].y2 == i) {
			int hm = min_query(1, 0, n, query[uk_q].x1, query[uk_q].x2);
			if (hm >= query[uk_q].y1)
				ans[query[uk_q].start] = 1;
			uk_q++;
		}
	}
	for (auto now : ans) {
		if (now)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;
}