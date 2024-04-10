#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

pii operator + (const pii &A, const pii &B) {
	return A.fi != B.fi ? A.fi < B.fi ? A : B : mp(A.fi, A.se + B.se);
}

const int N = 1000000;

int n, q;
int a[500010];

struct Segment_tree {
	pii T[1 << 21];
	int tag[1 << 21];
	void pushup(int now) {
		T[now] = T[now << 1] + T[now << 1 | 1];
	}
	void addtag(int now, int x) {
		tag[now] += x, T[now].fi += x;
	}
	void pushdown(int now) {
		if (!tag[now]) return ;
		addtag(now << 1, tag[now]), addtag(now << 1 | 1, tag[now]);
		tag[now] = 0;
	}
	void Build(int now, int l, int r) {
		tag[now] = 0;
		if (l == r) {
			T[now] = mp(0, 1);
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void Update(int now, int l, int r, int L, int R, int x) {
		if (l == L && r == R) {
			addtag(now, x);
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, x);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, x);
		else Update(now << 1, l, mid, L, mid, x), Update(now << 1 | 1, mid + 1, r, mid + 1, R, x);
		pushup(now);
	}
}seg;

multiset <int> S;

int main() {
	scanf("%d%d", &n, &q);
	seg.Build(1, 1, N);
	a[0] = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	a[n + 1] = -0x3f3f3f3f;
	auto Calc = [&](int x, int coef) -> void {
		if (a[x] < a[x + 1]) seg.Update(1, 1, N, a[x], a[x + 1] - 1, coef);
	};
	for (int i = 0; i <= n; i++) {
		Calc(i, 1);
	}
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		if (!S.count(x)) seg.Update(1, 1, N, x, x, -1);
		S.insert(x);
	}
	while (q--) {
		int x, v; scanf("%d%d", &x, &v);
		Calc(x - 1, -1), Calc(x, -1);
		S.erase(S.find(a[x]));
		if (!S.count(a[x])) seg.Update(1, 1, N, a[x], a[x], 1);
		a[x] = v;
		if (!S.count(v)) seg.Update(1, 1, N, v, v, -1);
		S.insert(v);
		Calc(x - 1, 1), Calc(x, 1);
		printf("%d\n", seg.T[1].se);
	}
	return 0;
}