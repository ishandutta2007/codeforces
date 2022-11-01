#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define endl '\n'

using namespace std;

struct psp {
	int open, closed, siz;
};

vector <psp> t;
string s;

void build(int v, int tl, int tr) {
	if (tl == tr) {
		if (s[tl] == '(') 
			t[v].open = 1;
		if (s[tr] == ')')
			t[v].closed = 1;
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	int k = min(t[v * 2].open, t[v * 2 + 1].closed);
	t[v].siz = t[v * 2].siz + t[v * 2 + 1].siz + k;
	t[v].closed = t[v * 2].closed + t[v * 2 + 1].closed - k;
	t[v].open = t[v * 2].open + t[v * 2 + 1].open - k;
}

psp query(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return { 0, 0, 0 };
	if (l == tl && r == tr) 
		return t[v];
	int tm = (tl + tr) / 2;
	psp x = query(v * 2, tl, tm, l, min(tm, r));
	psp y = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	psp z;
	int k = min(x.open, y.closed);
	z.siz = x.siz + y.siz + k;
	z.closed = x.closed + y.closed - k;
	z.open = x.open + y.open - k;
	return z;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	t.resize(s.size() << 2);
	build(1, 0, s.size() - 1);
	vector <int> ans;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		ans.push_back(query(1, 0, s.size() - 1, l - 1, r - 1).siz);
	}
	for (auto now : ans)
		cout << (now << 1) << endl;
	return 0;
}