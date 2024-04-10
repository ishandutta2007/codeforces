#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 300005, MAXT = MAXN * 20;
int n, xx[MAXN], yy[MAXN], cnt[MAXT][3], ls[MAXT], rs[MAXT];
int rt[MAXN], per[3], chs[MAXN], nx, ny, tot, ans;
struct Po { int x, y, c, id; } po[MAXN];
bool cmpx(const Po &x, const Po &y) {
	return x.x < y.x;
}
int update(int pre, int x, int c, int l, int r) {
	int k = ++tot;
	ls[k] = ls[pre], rs[k] = rs[pre];
	memcpy(cnt[k], cnt[pre], sizeof(cnt[k]));
	++cnt[k][c];
	if (l == r) return k;
	int mid = (l + r) >> 1;
	if (x <= mid) ls[k] = update(ls[pre], x, c, l, mid);
	else rs[k] = update(rs[pre], x, c, mid + 1, r);
	return k;
}

int query1(int k, int a, int b, int c, int l, int r) {
	if (!k || l > b || r < a) return 0;
	if (l >= a && r <= b) return cnt[k][c];
	int mid = (l + r) >> 1;
	return query1(ls[k], a, b, c, l, mid) + query1(rs[k], a, b, c, mid + 1, r);
}

int query(int x1, int y1, int x2, int y2, int c) {
	x1 = max(x1, 1);
	x2 = min(x2, nx);
	y1 = max(y1, 1);
	y2 = min(y2, ny);
	if (x1 > x2 || y1 > y2) return 0;
	return query1(rt[x2], y1, y2, c, 1, ny) - query1(rt[x1 - 1], y1, y2, c, 1, ny);
}

void setans(int x1, int y1, int x2, int y2, int c) {
	int cnt = 0;
	for (int i = 1; i <= n && cnt < ans; i++) {
		if (po[i].x >= x1 && po[i].y >= y1 && po[i].x <= x2 && po[i].y <= y2 && po[i].c == c)
			chs[i] = 1, ++cnt;
	}
}

int cmax(int x1, int y1, int x2, int y2, int dep, bool out) {
	if (x1 > x2 || y1 > y2) return 0;
	if (dep == 2) {
		if (out) setans(x1, y1, x2, y2, per[2]);
		return query(x1, y1, x2, y2, per[2]);
	}
	int l = x1 - 1, r = x2 + 1;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (query(x1, y1, mid, y2, per[dep]) <= cmax(mid + 1, y1, x2, y2, dep + 1, 0)) l = mid;
		else r = mid;
	}
	int a = query(x1, y1, l, y2, per[dep]);
	if (out && a >= ans) {
		setans(x1, y1, l, y2, per[dep]);
		cmax(l + 1, y1, x2, y2, dep + 1, 1);
		return a;
	}
	a = max(a, cmax(l + 2, y1, x2, y2, dep + 1, 0));
	if (out && a >= ans) {
		setans(x1, y1, l + 1, y2, per[dep]);
		cmax(l + 2, y1, x2, y2, dep + 1, 1);
		return a;
	}
	
	l = x1 - 1, r = x2 + 1;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (cmax(x1, y1, mid, y2, dep + 1, 0) <= query(mid + 1, y1, x2, y2, per[dep])) l = mid;
		else r = mid;
	}
	a = max(a, cmax(x1, y1, l, y2, dep + 1, 0));
	if (out && a >= ans) {
		cmax(x1, y1, l, y2, dep + 1, 1);
		setans(l + 1, y1, x2, y2, per[dep]);
		return a;
	}
	a = max(a, query(l + 2, y1, x2, y2, per[dep]));
	if (out && a >= ans) {
		cmax(x1, y1, l + 1, y2, dep + 1, 1);
		setans(l + 2, y1, x2, y2, per[dep]);
		return a;
	}
	
	l = y1 - 1, r = y2 + 1;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (query(x1, y1, x2, mid, per[dep]) <= cmax(x1, mid + 1, x2, y2, dep + 1, 0)) l = mid;
		else r = mid;
	}
	a = max(a, query(x1, y1, x2, l, per[dep]));
	if (out && a >= ans) {
		setans(x1, y1, x2, l, per[dep]);
		cmax(x1, l + 1, x2, y2, dep + 1, 1);
		return a;
	}
	a = max(a, cmax(x1, l + 2, x2, y2, dep + 1, 0));
	if (out && a >= ans) {
		setans(x1, y1, x2, l + 1, per[dep]);
		cmax(x1, l + 2, x2, y2, dep + 1, 1);
		return a;
	}
	
	l = y1 - 1, r = y2 + 1;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (cmax(x1, y1, x2, mid, dep + 1, 0) <= query(x1, mid + 1, x2, y2, per[dep])) l = mid;
		else r = mid;
	}
	a = max(a, cmax(x1, y1, x2, l, dep + 1, 0));
	if (out && a >= ans) {
		cmax(x1, y1, x2, l, dep + 1, 1);
		setans(x1, l + 1, x2, y2, per[dep]);
		return a;
	}
	a = max(a, query(x1, l + 2, x2, y2, per[dep]));
	if (out && a >= ans) {
		cmax(x1, y1, x2, l + 1, dep + 1, 1);
		setans(x1, l + 2, x2, y2, per[dep]);
		return a;
	}
	return a;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		po[i] = (Po) { x, y, c - 1, i };
		xx[i] = x, yy[i] = y;
	}
	sort(xx + 1, xx + 1 + n);
	sort(yy + 1, yy + 1 + n);
	nx = unique(xx + 1, xx + 1 + n) - xx - 1;
	ny = unique(yy + 1, yy + 1 + n) - yy - 1;
	sort(po + 1, po + 1 + n, cmpx);
	for (int i = 1; i <= n; i++) {
		po[i].x = lower_bound(xx + 1, xx + nx + 1, po[i].x) - xx;
		po[i].y = lower_bound(yy + 1, yy + ny + 1, po[i].y) - yy;
		rt[po[i].x] = update(rt[po[i - 1].x], po[i].y, po[i].c, 1, ny);
	}
	per[0] = 0, per[1] = 1, per[2] = 2;
	do {
		ans = max(ans, cmax(1, 1, nx, ny, 0, 0));
	} while (next_permutation(per, per + 3));
	per[0] = 0, per[1] = 1, per[2] = 2;
	do {
		if (cmax(1, 1, nx, ny, 0, 1) >= ans) break;
	} while (next_permutation(per, per + 3));
	printf("%d\n", ans * 3);
	//for (int i = 1; i <= n; i++) if (chs[i]) printf("%d ", po[i].id);
	return 0;
}