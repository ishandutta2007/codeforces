#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n, q;
int a[100010];
vector <pii> mdy[100010];

struct Segment_tree {
	int T[400010][2], tag[400010];
	void pushup(int now) {
		T[now][0] = T[now << 1][0] + T[now << 1 | 1][0];
		T[now][1] = T[now << 1][1] + T[now << 1 | 1][1];
	}
	void addtag(int now) {
		swap(T[now][0], T[now][1]), tag[now] ^= 1;
	}
	void pushdown(int now) {
		if (!tag[now]) return ;
		addtag(now << 1), addtag(now << 1 | 1);
		tag[now] = 0;
	}
	void Build(int now, int l, int r) {
		tag[now] = 0;
		if (l == r) {
			T[now][0] = 1, T[now][1] = 0;
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void Update(int now, int l, int r, int L, int R) {
		if (l == L && r == R) {
			addtag(now);
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R);
		else Update(now << 1, l, mid, L, mid), Update(now << 1 | 1, mid + 1, r, mid + 1, R);
		pushup(now);
	}
	int Query(int now, int l, int r, int L, int R) {
		if (l == L && r == R) return T[now][1];
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return Query(now << 1, l, mid, L, mid) + Query(now << 1 | 1, mid + 1, r, mid + 1, R);
	}
}seg;

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		l = lower_bound(a + 1, a + n + 1, l) - a;
		r = upper_bound(a + 1, a + n + 1, r) - a - 1;
		if (l > r) continue;
		mdy[l].push_back(mp(l, r));
		mdy[r + 1].push_back(mp(l, r));
	}
	seg.Build(1, 1, n);
	long long ans = 1ll * n * (n - 1) * (n - 2) / 6;
	for (int i = 1; i <= n; i++) {
		seg.Update(1, 1, n, i, i);
		for (auto it : mdy[i]) {
			int l = it.fi, r = it.se;
			seg.Update(1, 1, n, l, r);
		}
		int tmp = seg.T[1][1] - seg.Query(1, 1, n, i, i);
		ans -= 1ll * tmp * (tmp - 1) / 2;
	}
	printf("%lld\n", ans);
	return 0;
}