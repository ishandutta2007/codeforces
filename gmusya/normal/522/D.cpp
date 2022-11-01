#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define endl '\n'

using namespace std;

bool cmp1(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b) {
	return (a.first.second < b.first.second);
}

vector <int> t;

int min_query(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 1e7;
	if (tl == l && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	int x = min_query(v * 2, tl, tm, l, min(tm, r));
	int y = min_query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
	return min(x, y);
}

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector <int> a(n);
	t.resize(4 * n, 1e7);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <pair <pair <int, int>, int>> query(q);
	for (int i = 0; i < q; i++) {
		cin >> query[i].first.first >> query[i].first.second;
		query[i].second = i;
	}
	sort(query.begin(), query.end(), cmp1);
	vector <int> answer(q);
	map <int, int> m;
	int i = 0;
	for (int j = 0; j < q; j++) {
		int l = query[j].first.first;
		int r = query[j].first.second;
		while (i < r) {
			int val = a[i];
			if (m.find(a[i]) != m.end())
				update(1, 0, n - 1, m[a[i]], i - m[a[i]]);
			m[a[i]] = i;
			i++;
		}
		answer[query[j].second] = min_query(1, 0, n - 1, l - 1, r - 1);
	}
	for (auto now : answer) {
		if (now > 1e6)
			cout << "-1" << endl;
		else
			cout << now << endl;
	}
	return 0;
}