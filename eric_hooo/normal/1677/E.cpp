#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n, q;
int a[200010], p[200010];
int L[1000010], R[1000010];
long long ans[1000010];
int seq[1000010];
vector <int> sub[200010];

struct BIT {
	long long T[200010];
	void clear() {memset(T, 0, sizeof(T));}
	void modify(int x, long long v) {
		while (x <= 200005) T[x] += v, x += x & -x;
	}
	void modify(int l, int r, long long v) {
		modify(l, v), modify(r + 1, -v);
	}
	long long query(int x) {
		long long res = 0;
		while (x) res += T[x], x -= x & -x;
		return res;
	}
}bit0, bit1;

struct DS {
	vector <pii> all[200010];
	DS() {
		for (int i = 0; i <= 200005; i++) {
			all[i].clear();
		}
	}
	void Append(int x, int l, int r) {
		if (l <= r) all[x].push_back(mp(l, r));
	}
	void Solve() {
		sort(seq, seq + q, [&](int x, int y) -> bool {return L[x] < L[y];});
		int pos = n;
		bit0.clear(), bit1.clear();
		for (int i = q - 1; i >= 0; i--) {
			int id = seq[i];
			while (pos >= L[id]) {
				for (auto it : all[pos]) {
					bit0.modify(it.fi, it.se, 1);
					bit1.modify(it.fi, it.se, -it.fi + 1);
					bit1.modify(it.se + 1, it.se - it.fi + 1);
				}
				pos--;
			}
			ans[id] += bit0.query(R[id]) * R[id] + bit1.query(R[id]);
		}
	}
}Lef, Rig;

namespace RMQ {
	int T[1 << 19];
	void Build(int now, int l, int r) {
		if (l == r) {
			T[now] = a[l];
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		T[now] = max(T[now << 1], T[now << 1 | 1]);
	}
	int Query(int now, int l, int r, int L, int R) {
		if (l == L && r == R) return T[now];
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return max(Query(now << 1, l, mid, L, mid), Query(now << 1 | 1, mid + 1, r, mid + 1, R));
	}
}

void Solve(int l, int r) {
	if (l > r) return ;
	int mid = p[RMQ :: Query(1, 1, n, l, r)];
	Solve(l, mid - 1), Solve(mid + 1, r);
	static int f[200010];
	if (mid - l + 1 < r - mid + 1) {
		for (int i = l; i <= mid; i++) {
			f[i] = 0x3f3f3f3f;
		}
		for (auto x : sub[a[mid]]) {
			int y = a[mid] / x;
			if (x >= y) break;
			x = p[x], y = p[y];
			if (x > y) swap(x, y);
			if (x >= l && x <= mid) f[x] = min(f[x], max(y, mid));
			else if (x > mid) f[mid] = min(f[mid], y);
		}
		for (int i = mid; i >= l; i--) {
			if (i < mid) f[i] = min(f[i], f[i + 1]);
			Lef.Append(i, f[i], r);
		}
	} else {
		for (int i = mid; i <= r; i++) {
			f[i] = -0x3f3f3f3f;
		}
		for (auto x : sub[a[mid]]) {
			int y = a[mid] / x;
			if (x >= y) break;
			x = p[x], y = p[y];
			if (x > y) swap(x, y);
			if (y >= mid && y <= r) f[y] = max(f[y], min(x, mid));
			else if (y < mid) f[mid] = max(f[mid], x);
		}
		for (int i = mid; i <= r; i++) {
			if (i > mid) f[i] = max(f[i], f[i - 1]);
			Rig.Append(n - i + 1, n - f[i] + 1, n - l + 1);
		}
	}
}

int main() {
	for (int i = 1; i <= 200000; i++) {
		for (int j = i; j <= 200000; j += i) {
			sub[j].push_back(i);
		}
	}
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		p[a[i]] = i;
	}
	RMQ :: Build(1, 1, n);
	Solve(1, n);
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &L[i], &R[i]);
		seq[i] = i;
	}
	Lef.Solve();
	for (int i = 0; i < q; i++) {
		swap(L[i], R[i]);
		L[i] = n - L[i] + 1, R[i] = n - R[i] + 1;
	}
	Rig.Solve();
	for (int i = 0; i < q; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}