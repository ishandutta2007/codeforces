#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define MOD(x, mod) (((x) % (mod) + (mod)) % (mod))
using namespace std;

typedef pair <int, int> pii;

void chans(pii &a, pii b) {
	if (b.se - b.fi > a.se - a.fi) a = b;
	else if (b.se - b.fi == a.se - a.fi && b.fi < a.fi) a = b;
}

int n, k, d;
int a[200010];

struct Segment_tree {
	long long T[800010], tag[800010];
	void Build(int now, int l, int r) {
		T[now] = tag[now] = 0;
		if (l == r) return ;
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
	}
	void pushup(int now) {
		T[now] = min(T[now << 1], T[now << 1 | 1]);
	}
	void addtag(int now, long long x) {
		T[now] += x, tag[now] += x;
	}
	void pushdown(int now) {
		if (!tag[now]) return ;
		addtag(now << 1, tag[now]), addtag(now << 1 | 1, tag[now]);
		tag[now] = 0;
	}
	void Update(int now, int l, int r, int L, int R, long long x) {
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
	int Query(int now, int l, int r, int L, int R, int lim) {
		if (l == L && r == R) {
			if (T[now] > lim) return -1;
			if (l == r) return l;
			pushdown(now);
			int mid = l + r >> 1;
			return T[now << 1] > lim ? Query(now << 1 | 1, mid + 1, r, mid + 1, r, lim) : Query(now << 1, l, mid, l, mid, lim);
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R, lim);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R, lim);
		int tmp = Query(now << 1, l, mid, L, mid, lim);
		return tmp == -1 ? Query(now << 1 | 1, mid + 1, r, mid + 1, R, lim) : tmp;
	}
}seg;

vector <int> up, dw;
set <int> S;

pii Solve(int l, int r) {
	for (int i = l; i <= r; i++) {
		a[i] -= a[r], a[i] /= d;
	}
	seg.Build(1, l, r), up = {l - 1}, dw = {l - 1}, S.clear();
	int cur = l;
	pii ans = mp(l, l);
	for (int i = l; i <= r; i++) {
		while (S.count(a[i])) S.erase(a[cur]), cur++;
		S.insert(a[i]);
		while (up.size() > 1 && a[up.back()] > a[i]) {
			int p = up.back(); up.pop_back();
			seg.Update(1, l, r, up.back() + 1, p, a[p]);
		}
		while (dw.size() > 1 && a[dw.back()] < a[i]) {
			int p = dw.back(); dw.pop_back();
			seg.Update(1, l, r, dw.back() + 1, p, -a[p]);
		}
		seg.Update(1, l, r, up.back() + 1, i, -a[i]), up.push_back(i);
		seg.Update(1, l, r, dw.back() + 1, i, a[i]), dw.push_back(i);
		seg.Update(1, l, r, l, i, -1);
		int tmp = seg.Query(1, l, r, cur, i, k - 1);
		if (tmp != -1) chans(ans, mp(tmp, i));
	}
	return ans;
}

int main() {
	scanf("%d%d%d", &n, &k, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (d == 0) {
		pii ans = mp(1, 1);
		for (int i = 1; i <= n; i++) {
			int j = i; while (j <= n && a[i] == a[j]) j++;
			chans(ans, mp(i, j - 1)), i = j - 1;
		}
		printf("%d %d\n", ans.fi, ans.se);
	} else {
		pii ans = mp(1, 1);
		for (int i = 1; i <= n; i++) {
			int j = i; while (j <= n && MOD(a[i], d) == MOD(a[j], d)) j++;
			chans(ans, Solve(i, j - 1)), i = j - 1;
		}
		printf("%d %d\n", ans.fi, ans.se);
	}
	return 0;
}