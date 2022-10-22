#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef unsigned long long ull;
typedef pair <int, ull> pil;
typedef pair <ull, ull> pll;
typedef pair <pil, pll> Data;

long long a[200010];
int OP[200010];
long long X[200010];
vector <long long> all;
int N;

pil operator + (const pil &A, const pil &B) {return mp(A.fi + B.fi, A.se + B.se);}

pll operator + (const pll &A, const pll &B) {return mp(A.fi + B.fi, A.se + B.se);}

Data operator + (const Data &A, const Data &B) {
	return mp(A.fi + B.fi, A.se + B.se + mp(A.fi.se * B.fi.fi, A.fi.fi * B.fi.se));
}

struct Segment_tree {
	Data T[1600010];
	Segment_tree() {}
	void pushup(int now) {T[now] = T[now << 1] + T[now << 1 | 1];}
	void Build(int now, int l, int r) {
		T[now] = mp(mp(0, 0), mp(0, 0));
		if (l == r) return ;
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
	}
	void Update(int now, int l, int r, int pos, long long val) {
		if (l == r) {
			T[now] = mp(mp(val > 0 ? 1 : 0, val), mp(val, val));
			return ;
		}
		int mid = l + r >> 1;
		if (pos <= mid) Update(now << 1, l, mid, pos, val);
		else Update(now << 1 | 1, mid + 1, r, pos, val);
		pushup(now);
	}
	ull getpre(int now, int l, int r, int k) {
		if (l == r) return k ? T[now].fi.se : 0;
		int mid = l + r >> 1;
		if (T[now << 1].fi.fi >= k) return getpre(now << 1, l, mid, k);
		return T[now << 1].fi.se + getpre(now << 1 | 1, mid + 1, r, k - T[now << 1].fi.fi);
	}
	ull getsuc(int now, int l, int r, int k) {
		if (l == r) return k ? T[now].fi.se : 0;
		int mid = l + r >> 1;
		if (T[now << 1 | 1].fi.fi >= k) return getsuc(now << 1 | 1, mid + 1, r, k);
		return T[now << 1 | 1].fi.se + getsuc(now << 1, l, mid, k - T[now << 1 | 1].fi.fi);
	}
	ull getpsum(int now, int l, int r, int k) {
		if (l == r) return k ? T[now].se.fi : 0;
		int mid = l + r >> 1;
		if (T[now << 1].fi.fi >= k) return getpsum(now << 1, l, mid, k);
		return T[now << 1].se.fi + T[now << 1].fi.se * (k - T[now << 1].fi.fi)
			 + getpsum(now << 1 | 1, mid + 1, r, k - T[now << 1].fi.fi);
	}
	ull getssum(int now, int l, int r, int k) {
		if (l == r) return k ? T[now].se.se : 0;
		int mid = l + r >> 1;
		if (T[now << 1 | 1].fi.fi >= k) return getssum(now << 1 | 1, mid + 1, r, k);
		return T[now << 1 | 1].se.se + T[now << 1 | 1].fi.se * (k - T[now << 1 | 1].fi.fi)
			 + getssum(now << 1, l, mid, k - T[now << 1 | 1].fi.fi);
	}
}seg;

int tot;

long long Query() {
	if (tot <= 1) return 0;
	if (tot == 2) return seg.getsuc(1, 0, N, 1) - seg.getpre(1, 0, N, 1);
	int l = 0, r = tot >> 1;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (seg.getpre(1, 0, N, mid + 1) > seg.getsuc(1, 0, N, mid)) l = mid;
		else r = mid - 1;
	}
	ull ans = 0;
	ans += seg.getpsum(1, 0, N, l + 1) - seg.getssum(1, 0, N, l) - 1;
	l = (tot >> 1) + 1, r = tot - 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (seg.getpre(1, 0, N, mid + 1) > seg.getsuc(1, 0, N, mid)) r = mid;
		else l = mid + 1;
	}
	ans += seg.T[1].se.fi - seg.getpsum(1, 0, N, l);
	ans -= seg.getssum(1, 0, N, tot - 1) - seg.getssum(1, 0, N, l - 1);
	ans = seg.T[1].fi.se - 1 - ans;
	return ans;
}

void read(int &x) {
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	x = c - '0', c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}

void read(long long &x) {
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	x = c - '0', c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}

char st[100]; int tp;

void print(long long x) {
	tp = 0;
	if (!x) st[tp++] = '0';
	while (x) st[tp++] = x % 10 + '0', x /= 10;
	while (tp--) putchar(st[tp]);
	putchar('\n');
}

int main() {
	int n, q; read(n), read(q);
	for (int i = 1; i <= n; i++) read(a[i]), all.push_back(a[i]);
	for (int i = 1; i <= q; i++) read(OP[i]), read(X[i]), all.push_back(X[i]);
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	for (int i = 1; i <= n; i++) a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
	for (int i = 1; i <= q; i++) X[i] = lower_bound(all.begin(), all.end(), X[i]) - all.begin();
	N = (int)all.size() - 1, seg.Build(1, 0, N), tot = 0;
	for (int i = 1; i <= n; i++) seg.Update(1, 0, N, a[i], all[a[i]]), tot++;
	print(Query());
	for (int i = 1; i <= q; i++) {
		if (OP[i] == 1) seg.Update(1, 0, N, X[i], all[X[i]]), tot++;
		else seg.Update(1, 0, N, X[i], 0), tot--;
		print(Query());
	}
	return 0;
}