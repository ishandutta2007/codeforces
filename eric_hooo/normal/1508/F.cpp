#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> ppi;

const int B = 158;

int a[25010], p[25010], L[100010], R[100010], T[25010];
vector <int> all[25010], val[2][25010];
vector <pii> op;
set <int> S;
vector <ppi> qry;
vector <ppi> mdy;
int n, q;
int ans[100010];

void modify(int x, int v) {while (x <= n) T[x] = min(T[x], v), x += x & -x;}

int query(int x) {int res = q; while (x) res = min(res, T[x]), x -= x & -x; return res;}

bool cmp(const pii &a, const pii &b) {
	return a.fi / B != b.fi / B ? a.fi < b.fi : a.se < b.se;
}

void Insert(int x) {
	set <int> :: iterator it = S.lower_bound(a[x]);
	if (it != S.end()) all[x].push_back(p[*it]);
	if (it != S.begin()) it--, all[p[*it]].push_back(x);
	S.insert(a[x]);
}

void Erase(int x) {
	S.erase(a[x]); set <int> :: iterator it = S.lower_bound(a[x]);
	if (it != S.end() && it != S.begin()) {
		int suc = *it; it--; int pre = *it;
		all[p[pre]].push_back(p[suc]);
	}
}

bool IsSmall(const int &x, const int &y) {return a[x] < a[y];}

bool IsBig(const int &x, const int &y) {return a[x] > a[y];}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), p[a[i]] = i;
	for (int i = 0; i < q; i++) scanf("%d%d", &L[i], &R[i]), op.push_back(mp(L[i], R[i]));
	for (int i = 0; i < q; i++) mdy.push_back(mp(mp(L[i], R[i]), i));
	sort(op.begin(), op.end(), cmp);
	int L = 1, R = 0;
	for (int i = 0; i < op.size(); i++) {
		int l = op[i].fi, r = op[i].se;
		while (L > l) Insert(--L);
		while (R < r) Insert(++R);
		while (L < l) Erase(L++);
		while (R > r) Erase(R--);
	}
	for (int i = 1; i <= n; i++) {
		sort(all[i].begin(), all[i].end());
		all[i].resize(unique(all[i].begin(), all[i].end()) - all[i].begin());
		int pos = lower_bound(all[i].begin(), all[i].end(), i) - all[i].begin();
		for (int j = 0; j < all[i].size(); j++) {
			qry.push_back(mp(mp(min(i, all[i][j]), max(all[i][j], i)), i << 2));
		}
		for (int j = 0; j < pos; j++) {
			int x = all[i][j]; auto it = lower_bound(all[i].begin() + pos, all[i].end(), x, IsBig);
			if (it != all[i].end()) qry.push_back(mp(mp(x, *it), i << 2 | 1));
		}
		for (int j = pos; j < all[i].size(); j++) {
			int x = all[i][j]; auto it = lower_bound(all[i].rend() - pos, all[i].rend(), x, IsBig);
			if (it != all[i].rend()) qry.push_back(mp(mp(*it, x), i << 2 | 2));
		}
		val[0][i].resize(all[i].size());
		val[1][i].resize(all[i].size(), q);
	}
	sort(qry.begin(), qry.end()), sort(mdy.rbegin(), mdy.rend());
	memset(T, 0x3f, sizeof(T));
	for (int i = 0; i < qry.size(); i++) {
		int l = qry[i].fi.fi, r = qry[i].fi.se, d = qry[i].se & 3, p = qry[i].se >> 2;
		while (mdy.size() && mdy.back().fi.fi <= l) {
			modify(n - mdy.back().fi.se + 1, mdy.back().se), mdy.pop_back();
		}
		int nxt = d == 0 ? l + r - p : d == 1 ? l : r;
		if (d == 2) d = 1;
		val[d][p][lower_bound(all[p].begin(), all[p].end(), nxt) - all[p].begin()] = query(n - r + 1);
	}
	for (int i = 1; i <= n; i++) {
		int pos = lower_bound(all[i].begin(), all[i].end(), i) - all[i].begin();
		for (int j = 0; j < pos; j++) {
			int l = val[0][i][j], r = val[1][i][j];
			if (j) r = min(r, val[0][i][j - 1]);
			if (l < r) ans[l]++, ans[r]--;
		}
		for (int j = pos; j < all[i].size(); j++) {
			int l = val[0][i][j], r = val[1][i][j];
			if (j + 1 < all[i].size()) r = min(r, val[0][i][j + 1]);
			if (l < r) assert(r <= q), ans[l]++, ans[r]--;
		}
	}
	for (int i = 0; i < q; i++) ans[i + 1] += ans[i];
	for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
	return 0;
}