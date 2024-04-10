#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;

pii operator + (const pii &A, const int &x) {
	pii res = A;
	if (x < res.fi) res.se = res.fi, res.fi = x;
	else if (x < res.se) res.se = x;
	return res;
}

pii operator + (const pii &A, const pii &B) {
	return A + B.fi + B.se;
}

struct Segment_tree {
	pii T[800000];
	void Build(int now, int l, int r) {
		T[now] = mp(INF, INF);
		if (l == r) return ;
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
	}
	void Update(int now, int l, int r, int pos, int x) {
		if (l == r) {
			T[now] = mp(x, INF);
			return ;
		}
		int mid = l + r >> 1;
		if (pos <= mid) Update(now << 1, l, mid, pos, x);
		else Update(now << 1 | 1, mid + 1, r, pos, x);
		T[now] = T[now << 1] + T[now << 1 | 1];
	}
	pii Query(int now, int l, int r, int L, int R) {
		if (l == L && r == R) return T[now];
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return Query(now << 1, l, mid, L, mid) + Query(now << 1 | 1, mid + 1, r, mid + 1, R);
	}
}seg[9];

int n;

void Modify(int x, int val) {
	int cur = val;
	for (int i = 0; i < 9; i++) {
		if (cur % 10) seg[i].Update(1, 1, n, x, val);
		else seg[i].Update(1, 1, n, x, INF);
		cur /= 10;
	}
}

int Query(int l, int r) {
	int ans = -1;
	for (int i = 0; i < 9; i++) {
		pii tmp = seg[i].Query(1, 1, n, l, r);
		if (tmp.se == INF) continue;
		if (ans == -1 || ans > tmp.fi + tmp.se) ans = tmp.fi + tmp.se;
	}
	return ans;
}

int main () {
	int m; scanf("%d%d", &n, &m);
	for (int i = 0; i < 9; i++) {
		seg[i].Build(1, 1, n);
	}
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		Modify(i, x);
	}
	while (m--) {
		int op, l, r; scanf("%d%d%d", &op, &l, &r);
		if (op == 1) Modify(l, r);
		else printf("%d\n", Query(l, r));
	}
	return 0;
}