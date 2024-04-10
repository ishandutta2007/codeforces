#include <bits/stdc++.h>
using namespace std;

int N;
int n, k;
int a[100010];
vector <int> all;
int OP[100010], L[100010], R[100010], X[100010];

struct st {
	int f[100010][17], lg[100010], Min;
	void init(int *a, int n) {
		Min = 0x3f3f3f3f;
		for (int i = 0; i < n; i++) {
			f[i][0] = a[i];
			Min = min(Min, a[i]);
		}
		lg[0] = -1;
		for (int i = 1; i <= n; i++) {
			lg[i] = lg[i >> 1] + 1;
		}
		for (int j = 1; j < 17; j++) {
			for (int i = 0; i < n; i++) {
				if (i + (1 << j) - 1 >= n) break;
				f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
			}
		}
	}
	int query(int l, int r) {
		int k = lg[r - l + 1];
		return min(f[l][k], f[r - (1 << k) + 1][k]);
	}
	int Query(int l, int r) {
		if (r - l + 1 >= n) return Min;
		if (l / n == r / n) return query(l % n, r % n);
		return min(query(l % n, n - 1), query(0, r % n));
	}
}st;

struct Segment_tree {
	int T[800010], lazy[800010];
	void pushdown(int now) {
		if (lazy[now] == -1) return ;
		T[now << 1] = T[now << 1 | 1] = lazy[now << 1] = lazy[now << 1 | 1] = lazy[now];
		lazy[now] = -1;
	}
	void Build(int now, int l, int r) {
		lazy[now] = -1;
		if (l == r) {
			T[now] = st.Query(all[l], all[l + 1] - 1);
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		T[now] = min(T[now << 1], T[now << 1 | 1]);
	}
	void Update(int now, int l, int r, int L, int R, int x) {
		if (l == L && r == R) {
			T[now] = x, lazy[now] = x;
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, x);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, x);
		else Update(now << 1, l, mid, L, mid, x), Update(now << 1 | 1, mid + 1, r, mid + 1, R, x);
		T[now] = min(T[now << 1], T[now << 1 | 1]);
	}
	int Query(int now, int l, int r, int L, int R) {
		if (l == L && r == R) return T[now];
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return min(Query(now << 1, l, mid, L, mid), Query(now << 1 | 1, mid + 1, r, mid + 1, R));
	}
}seg;

int main () {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	st.init(a, n);
	int q; scanf("%d", &q);
	all.push_back(0), all.push_back(n * k);
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d", &OP[i], &L[i], &R[i]);
		L[i]--, R[i]--;
		if (OP[i] == 1) scanf("%d", &X[i]);
		all.push_back(L[i]), all.push_back(R[i] + 1);
	}
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	N = (int)all.size() - 2;
	seg.Build(1, 0, N);
	for (int i = 0; i < q; i++) {
		int l = lower_bound(all.begin(), all.end(), L[i]) - all.begin();
		int r = lower_bound(all.begin(), all.end(), R[i] + 1) - all.begin() - 1;
		if (OP[i] == 1) seg.Update(1, 0, N, l, r, X[i]);
		else printf("%d\n", seg.Query(1, 0, N, l, r));
	}
	return 0;
}