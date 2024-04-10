#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

vector <int> t;

void update(int v, int tl, int tr, int l, int r, int color) {
	if (l > r)
		return;
	if (l == tl && r == tr) {
		t[v] = color;
		//cout << tl << " " << tr << " " << color << endl;
		return;
	}
	if (t[v] != -2) {
		t[v * 2] = t[v * 2 + 1] = t[v];
		t[v] = -2;
	}
	int tm = (tl + tr) / 2;
	update(v * 2, tl, tm, l, min(r, tm), color);
	update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, color);
}

int color_query(int v, int tl, int tr, int pos) {
	//cout << v << " " << tl << " " << tr << " " << t[v] << endl;
	if (tl == tr)
		return t[v];
	if (t[v] != -2)
		return t[v];
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return color_query(v * 2, tl, tm, pos);
	else
		return color_query(v * 2 + 1, tm + 1, tr, pos);
}

int main() {
	int n, q;
	cin >> n >> q;
	vector <int> a(n), b(n);
	t.resize(4 * n);
	t[1] = -1;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	vector < pair <pair <int, int>, int>> query(q);
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y, k;
			cin >> x >> y >> k;
			x--;
			y--;
			query[i] = { {x, y},k };
			update(1, 0, n - 1, y, y + k - 1, i);
		}
		if (t == 2) {
			int pos;
			cin >> pos;
			pos--;
			int c = color_query(1, 0, n - 1, pos);
			if (c == -1) {
				cout << b[pos] << endl;
				continue;
			}
			int x = query[c].first.first;
			int y = query[c].first.second;
			int k = query[c].second;
			cout << a[pos - y + x] << endl;
		}
	}
	return 0;
}