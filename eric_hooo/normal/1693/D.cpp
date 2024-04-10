#include <bits/stdc++.h>
using namespace std;

int n;
int a[200010], aa[200010];
long long ans;

namespace RMQ {
	int f[18][200010], lg[200010];
	void Init() {
		lg[0] = -1;
		for (int i = 1; i <= n; i++) {
			f[0][i] = a[i], lg[i] = lg[i >> 1] + 1;
		}
		for (int j = 1; j < 18; j++) {
			for (int i = 1; i <= n; i++) {
				if (i + (1 << j) - 1 > n) break;
				f[j][i] = max(f[j - 1][i], f[j - 1][i + (1 << j - 1)]);
			}
		}
	}
	int Query(int l, int r) {
		int k = lg[r - l + 1];
		return max(f[k][l], f[k][r - (1 << k) + 1]);
	}
}

// namespace SEG {
// 	int T[1 << 19];
// 	void Build(int now, int l, int r) {
// 		if (l == r) {
// 			T[now] = 0x3f3f3f3f;
// 			return ;
// 		}
// 		int mid = l + r >> 1;
// 		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
// 		pushup(now);
// 	}
// }

int f[200010], g[200010];

void WorkL(int l, int r) {
	if (l == r) return ;
	int mid = l + r >> 1;
	WorkL(l, mid);
	{
		int minj = 0x3f3f3f3f;
		for (int i = mid; i >= l; i--) {
			if (f[i]) minj = min(minj, a[i - 1]);
			if (a[i - 1] < a[i]) break;
		}
		for (int i = mid + 1; i <= r; i++) {
			if (a[i] > minj) g[i] = 1;
			if (a[i - 1] < a[i]) break;
		}
	}
	{
		int maxj = -0x3f3f3f3f;
		for (int i = mid; i >= l; i--) {
			if (g[i]) maxj = max(maxj, a[i - 1]);
			if (a[i - 1] > a[i]) break;
		}
		for (int i = mid + 1; i <= r; i++) {
			if (a[i] < maxj) f[i] = 1;
			if (a[i - 1] > a[i]) break;
		}
	}
	WorkL(mid + 1, r);
}

void WorkR(int l, int r) {
	if (l == r) return ;
	int mid = l + r >> 1;
	WorkR(mid + 1, r);
	{
		int minj = 0x3f3f3f3f;
		for (int i = mid + 1; i <= r; i++) {
			if (f[i]) minj = min(minj, a[i + 1]);
			if (a[i + 1] < a[i]) break;
		}
		for (int i = mid; i >= l; i--) {
			if (a[i] > minj) g[i] = 1;
			if (a[i + 1] < a[i]) break;
		}
	}
	{
		int maxj = -0x3f3f3f3f;
		for (int i = mid + 1; i <= r; i++) {
			if (g[i]) maxj = max(maxj, a[i + 1]);
			if (a[i + 1] > a[i]) break;
		}
		for (int i = mid; i >= l; i--) {
			if (a[i] < maxj) f[i] = 1;
			if (a[i + 1] > a[i]) break;
		}
	}
	WorkR(l, mid);
}

void Solve(int l, int r) {
	if (l > r) return ;
	int mid = aa[RMQ :: Query(l, r)];
	Solve(l, mid - 1), Solve(mid + 1, r);
	// cout << "  Solve:" << l << " " << r << endl;
	// long long _old = ans;
	int rig = mid;
	while (rig < r && a[rig + 1] < a[rig]) rig++;
	int lef = mid;
	while (lef > l && a[lef - 1] < a[lef]) lef--;
	{
		int qwq = a[mid + 1];
		a[mid + 1] = 0;
		; for (int i = l; i <= mid; i++) f[i] = g[i] = 0;
		f[mid] = 1, WorkR(l, mid);
		int tot = 0, dead = 0;
		for (int i = mid; i >= l; i--) {
			if (i < mid && a[i] < a[i + 1]) f[i] |= f[i + 1];
			if (i < mid && a[i] > a[i + 1]) g[i] |= g[i + 1];
			if (f[i] || g[i]) assert(!dead), tot++;
		}
		ans += tot;
		// cout << "                        qwq:" << tot << endl;
		a[mid + 1] = qwq;
		if (mid < rig) {
			; for (int i = l; i <= mid; i++) f[i] = g[i] = 0;
			f[mid] = 1, WorkR(l, mid);
			int tot = 0, dead = 0;
			for (int i = mid; i >= l; i--) {
				if (i < mid && a[i] < a[i + 1]) f[i] |= f[i + 1];
				if (i < mid && a[i] > a[i + 1]) g[i] |= g[i + 1];
				if (f[i] || g[i]) assert(!dead), tot++;
			}
			ans += tot * (rig - mid);
		}
	}
	{
		int qwq = a[mid - 1];
		a[mid - 1] = 0;
		; for (int i = mid; i <= r; i++) f[i] = g[i] = 0;
		f[mid] = 1, WorkL(mid, r);
		int tot = 0, dead = 0;
		for (int i = mid; i <= r; i++) {
			if (i > mid && a[i] < a[i - 1]) f[i] |= f[i - 1];
			if (i > mid && a[i] > a[i - 1]) g[i] |= g[i - 1];
			if (f[i] || g[i]) assert(!dead), tot++;
		}
		ans += tot;
		a[mid - 1] = qwq;
		if (lef < mid) {
			; for (int i = mid; i <= r; i++) f[i] = g[i] = 0;
			f[mid] = 1, WorkL(mid, r);
			int tot = 0, dead = 0;
			for (int i = mid; i <= r; i++) {
				if (i > mid && a[i] < a[i - 1]) f[i] |= f[i - 1];
				if (i > mid && a[i] > a[i - 1]) g[i] |= g[i - 1];
				if (f[i] || g[i]) assert(!dead), tot++;
			}
			ans += tot * (mid - lef);
		}
	}
	ans -= (mid - lef + 1) * (rig - mid + 1);
	// cout << "                                ans:" << ans - _old << endl;
}

struct Segment_tree {
	int T[1 << 19], tag[1 << 19];
	void addtag(int now, int t) {
		T[now] = tag[now] = t;
	}
	void pushdown(int now) {
		if (tag[now] == -1) return ;
		addtag(now << 1, tag[now]), addtag(now << 1 | 1, tag[now]), tag[now] = -1;
	}
	void pushup(int now) {
		T[now] = T[now << 1];
	}
	void Build(int now, int l, int r) {
		tag[now] = -1;
		if (l == r) {
			T[now] = 0;
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void Update(int now, int l, int r, int L, int R, int t) {
		if (L > R) return ;
		if (l == L && r == R) {
			addtag(now, t);
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, t);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, t);
		else Update(now << 1, l, mid, L, mid, t), Update(now << 1 | 1, mid + 1, r, mid + 1, R, t);
		pushup(now);
	}
	int GetLeq(int now, int l, int r, int L, int R, int lim) {
		if (l == r) return T[now] < lim ? l : l + 1;
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) return GetLeq(now << 1, l, mid, L, R, lim);
		if (L > mid) return GetLeq(now << 1 | 1, mid + 1, r, L, R, lim);
		if (T[now << 1 | 1] < lim) return GetLeq(now << 1, l, mid, L, mid, lim);
		return GetLeq(now << 1 | 1, mid + 1, r, mid + 1, R, lim);
	}
	int GetGeq(int now, int l, int r, int L, int R, int lim) {
		if (l == r) return T[now] > lim ? l : l + 1;
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) return GetGeq(now << 1, l, mid, L, R, lim);
		if (L > mid) return GetGeq(now << 1 | 1, mid + 1, r, L, R, lim);
		if (T[now << 1 | 1] > lim) return GetGeq(now << 1, l, mid, L, mid, lim);
		return GetGeq(now << 1 | 1, mid + 1, r, mid + 1, R, lim);
	}
}segf, segg;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		aa[a[i]] = i;
	}
	{
		long long ans = 0;
		static int f[200010], g[200010];
		segf.Build(1, 1, n), segg.Build(1, 1, n);
		for (int i = 1; i <= n; i++) {
			segf.Update(1, 1, n, i, i, n + 1);
			segg.Update(1, 1, n, i, i, 0);
			if (i > 1) {
				int pf = segf.GetGeq(1, 1, n, 1, i - 1, a[i]);
				int pg = segg.GetLeq(1, 1, n, 1, i - 1, a[i]);
				if (a[i - 1] < a[i]) {
					int ppf = segf.GetGeq(1, 1, n, pg, i - 1, a[i - 1]);
					segf.Update(1, 1, n, pg, ppf - 1, a[i - 1]);
					segg.Update(1, 1, n, 1, pf - 1, n + 1);
					segg.Update(1, 1, n, pf, i - 1, a[i - 1]);
				} else {
					int ppg = segg.GetLeq(1, 1, n, pf, i - 1, a[i - 1]);
					segg.Update(1, 1, n, pf, ppg - 1, a[i - 1]);
					segf.Update(1, 1, n, 1, pg - 1, 0);
					segf.Update(1, 1, n, pg, i - 1, a[i - 1]);
				}
			}
			// f[i] = n + 1, g[i] = 0;
			// if (i > 1) {
			// 	int pf = lower_bound(f + 1, f + i, a[i]) - f;
			// 	int pg = lower_bound(g + 1, g + i, a[i], greater <int>()) - g;
			// 	if (a[i - 1] < a[i]) {
			// 		for (int j = 1; j < i; j++) {
			// 			f[j] = max(f[j], j < pg ? 0 : a[i - 1]);
			// 			g[j] = j < pf ? n + 1 : a[i - 1];
			// 		}
			// 	} else {
			// 		for (int j = 1; j < i; j++) {
			// 			f[j] = j < pg ? 0 : a[i - 1];
			// 			g[j] = min(g[j], j < pf ? n + 1 : a[i - 1]);
			// 		}
			// 	}
			// }
			// for (int j = 1; j < i; j++) {
			// 	nf[j] = max(a[i - 1] < a[i] ? f[j] : 0, g[j] < a[i] ? a[i - 1] : 0);
			// 	ng[j] = min(a[i - 1] > a[i] ? g[j] : n + 1, f[j] > a[i] ? a[i - 1] : n + 1);
			// }
			{
				int pf = segf.GetGeq(1, 1, n, 1, i, 0);
				int pg = segg.GetLeq(1, 1, n, 1, i, n + 1);
				ans += i - min(pf, pg) + 1;
			}
			// for (int j = 1; j <= i; j++) {
			// 	if (f[j] > 0 || g[j] < n + 1) ans++;
			// }
		}
		printf("%lld\n", ans);
	}
	// RMQ :: Init();
	// Solve(1, n);
	// printf("%lld\n", ans);
	return 0;
}