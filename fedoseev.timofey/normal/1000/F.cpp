#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

const int N = 5e5 + 7;
const int Inf = 2e9;

struct node {
	int val, ind;
	node(int val = Inf, int ind = -1) : val(val), ind(ind) {}
	node operator+(const node &other) const {
		if (val < other.val) return node(val, ind);
		else return node(other.val, other.ind);
	}
};

node t[4 * N];

void modify(int ind, int val = Inf, int l = 0, int r = N - 1, int v = 0) {
	if (ind < l || r < ind) return;
	if (l == r) t[v] = node(val, l);
	else {
		int m = (l + r) >> 1;
		modify(ind, val, l, m, 2 * v + 1);
		modify(ind, val, m + 1, r, 2 * v + 2);
		t[v] = t[2 * v + 1] + t[2 * v + 2];
	}
}

node get(int ql, int qr, int l = 0, int r = N - 1, int v = 0) {
	if (qr < l || r < ql) return node();
	if (ql <= l && r <= qr) return t[v];
	int m = (l + r) >> 1;
	return get(ql, qr, l, m, 2 * v + 1) + get(ql, qr, m + 1, r, 2 * v + 2);
}

vector <pair <int, int>> qr[N];
int last[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	for (int i = 0; i < N; ++i) last[i] = -1;
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		qr[r].emplace_back(l, i);
	}
	vector <int> ans(q);
	for (int i = 0; i < n; ++i) {
		if (last[a[i]] != -1) modify(last[a[i]]);
		modify(i, last[a[i]]);
		last[a[i]] = i;
		for (auto &p : qr[i]) {
			node c = get(p.first, i);
			if (c.val < p.first) {
				ans[p.second] = a[c.ind];
			}
		}
	}
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << '\n';
	}
}