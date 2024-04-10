#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int N = 300000;

int be[100010];
pii c[300010];
pii a[300010];
vector <int> all[300010];
vector <pii> qry[300010];
map <pii, int> lst;
int T[300010], ans[300010];

void modify(int x, int v) {
	while (x <= N) T[x] += v, x += x & -x;
}

int query(int x) {
	int res = 0;
	while (x) res += T[x], x -= x & -x;
	return res;
}

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int main () {
	int T; scanf("%d", &T);
	int n = 0;
	for (int i = 0; i < T; i++) {
		be[i] = n + 1;
		int k; scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d%d", &c[j].fi, &c[j].se);
		}
		for (int j = 0; j < k; j++) {
			a[n + j + 1] = mp(c[(j + 1) % k].fi - c[j].fi, c[(j + 1) % k].se - c[j].se);
		}
		n += k;
	}
	be[T] = n + 1;
	int q; scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int l, r; scanf("%d%d", &l, &r);
		l--, r--;
		l = be[l], r = be[r + 1] - 1;
		qry[l].push_back(mp(r, i));
	}
	for (int i = 1; i <= n; i++) {
		int tmp = gcd(abs(a[i].fi), abs(a[i].se));
		a[i].fi /= tmp, a[i].se /= tmp;
		int x = lst[a[i]]; lst[a[i]] = i;
		all[x].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < all[i - 1].size(); j++) {
			int x = all[i - 1][j];
			modify(x, 1);
		}
		for (int j = 0; j < qry[i].size(); j++) {
			int r = qry[i][j].fi, id = qry[i][j].se;
			ans[id] = query(r) - query(i - 1);
		}
	}
	for (int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}