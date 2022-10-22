#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

typedef pair <long long, long long> pll;
typedef pair <pll, pll> ppl;

const pll EPT(0, 0);

pll operator + (const pll &A, const pll &B) {return mp(A.fi + B.fi, A.se + B.se);}
pll operator * (const pll &A, const long long &x) {return mp(A.fi * x, A.se * x);}

ppl a[200010];
int P[200010];
int n;

struct Segment_tree {
	long long T[800010], lazy[800010];
	void pushup(int now) {T[now] = min(T[now << 1], T[now << 1 | 1]);}
	void pushdown(int now) {
		if (lazy[now] == 0) return ;
		T[now << 1] = T[now << 1] + lazy[now], T[now << 1 | 1] = T[now << 1 | 1] + lazy[now];
		lazy[now << 1] = lazy[now << 1] + lazy[now], lazy[now << 1 | 1] = lazy[now << 1 | 1] + lazy[now];
		lazy[now] = 0;
	}
	void Build(int now, int l, int r, int B) {
		lazy[now] = 0;
		if (l == r) {T[now] = INF;/*a[l].fi.se < B ? INF : 0;*/ return ;}
		int mid = l + r >> 1; Build(now << 1, l, mid, B), Build(now << 1 | 1, mid + 1, r, B);
		pushup(now);
	}
	void Update(int now, int l, int r, int L, int R, long long val) {
		if (l == L && r == R) {T[now] = T[now] + val, lazy[now] = lazy[now] + val; return ;}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, val);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, val);
		else Update(now << 1, l, mid, L, mid, val), Update(now << 1 | 1, mid + 1, r, mid + 1, R, val);
		pushup(now);
	}
	int GetNxt(int now, int l, int r, int L, int R, long long x) {
		if (l == L && r == R) {
			if (T[now] > x) return -1;
			if (l == r) return l;
			pushdown(now);
			int mid = l + r >> 1;
			if (T[now << 1] <= x) return GetNxt(now << 1, l, mid, l, mid, x);
			return GetNxt(now << 1 | 1, mid + 1, r, mid + 1, r, x);
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) return GetNxt(now << 1, l, mid, L, R, x);
		if (L > mid) return GetNxt(now << 1 | 1, mid + 1, r, L, R, x);
		int tmp = GetNxt(now << 1, l, mid, L, mid, x);
		if (tmp == -1) return GetNxt(now << 1 | 1, mid + 1, r, mid + 1, R, x);
		return tmp;
	}
}seg[18];

struct BIT {
	long long T[200010];
	void Build() {memset(T, 0, sizeof(T));}
	void modify(int x, long long v) {while (x <= n) T[x] += v, x += x & -x;}
	long long query(int x) {long long res = 0; while (x) res += T[x], x -= x & -x; return res;}
}wei[18], mon[18];

void Modify(int x, long long val) {
	a[x].se.fi += val; long long w = a[x].fi.se;
	for (int i = 0; i < 18; i++) {
		if (w < (1 << i)) {
			seg[i].Update(1, 1, n, x, n, w * val);
			wei[i].modify(x, val * a[x].fi.se), mon[i].modify(x, val * a[x].fi.fi);
		} else {
			if (a[x].se.fi == val) seg[i].Update(1, 1, n, x, x, -INF + w);
			else if (a[x].se.fi == 0) seg[i].Update(1, 1, n, x, x, INF - w);
		}
	}
}

void Calc(long long &x, long long &ans, int p) {
	if (p < 1 || p > n) return ;
	long long tmp = min(a[p].se.fi, x / a[p].fi.se); x -= tmp * a[p].fi.se, ans += tmp * a[p].fi.fi;
}

int ___GetNxt(int cur, long long x, int i) {
	while (cur <= n) {
		if (a[cur].fi.se < (1 << i)) x -= a[cur].fi.se * a[cur].se.fi;
		if (x < 0) return -1;
		if (a[cur].fi.se >= (1 << i)) {
			if (x >= a[cur].fi.se && a[cur].se.fi) return cur;
		}
		cur++;
	}
	return -1;
}

int main() {
	int q; scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%I64d%I64d%I64d", &a[i].se.fi, &a[i].fi.se, &a[i].fi.fi);
	for (int i = 1; i <= n; i++) a[i].se.se = i, a[i].fi.se *= -1;
	sort(a + 1, a + n + 1), reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) a[i].fi.se *= -1, P[a[i].se.se] = i;
	for (int i = 0; i < 18; i++) seg[i].Build(1, 1, n, 1 << i);
	for (int i = 1; i <= n; i++) {
		long long tmp = a[i].se.fi; a[i].se.fi = 0;
		if (tmp) Modify(i, tmp);
	}
	while (q--) {
		int op; scanf("%d", &op);
		if (op <= 2) {int d, x; scanf("%d%d", &d, &x), x = P[x], Modify(x, op == 1 ? d : -d);}
		else {
			long long x; scanf("%I64d", &x);
			long long ans = 0;
			int cur = 1;
			for (int i = 16; i >= 0; i--) {
//				cerr << "     i:" << i << " " << (1 << i) << " " << x << " " << ans << " " << cur << endl;
				if (x >= (1 << i + 1)) {
					int tmp = 0; long long sum = -wei[i + 1].query(cur - 1);
					for (int j = 17; j >= 0; j--) {
						if (tmp + (1 << j) > n) continue;
						int ttt = tmp + (1 << j);
						if (x - sum - wei[i + 1].T[ttt] >= (1 << i + 1)) {
							tmp = ttt, sum += wei[i + 1].T[ttt];
						}
					}
//					cerr << "      wei:" << wei[i + 1].T[1] << endl;
//					cerr << " tmp:" << tmp << " " << sum << " " << mon[i + 1].query(tmp) - mon[i + 1].query(cur - 1) << endl;
					x -= sum, ans += mon[i + 1].query(tmp) - mon[i + 1].query(cur - 1);
					cur = tmp + 1, Calc(x, ans, cur), cur++;
					if (cur > n) break;
				}
				assert(x < (1 << i + 1));
//				cerr << "    cur:" << cur << endl;
				long long Base = wei[i].query(cur - 1);
				int nxt = seg[i].GetNxt(1, 1, n, cur, n, Base + x);//*/___GetNxt(cur, x, i);
				if (nxt == -1) continue;
				x -= wei[i].query(nxt) - Base, ans += mon[i].query(nxt) - mon[i].query(cur - 1);
				cur = nxt;
				assert(x / a[cur].fi.se == 1);
				assert(a[cur].fi.se >= (1 << i) && a[cur].fi.se < (1 << i + 1));
				Calc(x, ans, cur), cur++;
				if (cur > n) break;
			}
			printf("%I64d\n", ans);
		}
	}
	return 0;
}