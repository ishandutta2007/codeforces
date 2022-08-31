#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
vi eg[maxn];
int fa[25];
int id[25];
int gfa(int a) {
	if (fa[a] == a) return a;
	return fa[a] = gfa(fa[a]);
}
struct info {
	int u[2][6]; // 
	int l, r, len, dv;
	info() {len = dv = 0;}
	info (int x) {
		l = r = x, len = 1, dv = 0, u[0][1] = u[1][1] = 1;
	}
	void otp() {
		cout << l << ' ' << r << ' ' << len << ' ' << dv << endl;
		for (int i = 1; i <= len; i++) cout << u[0][i] << ' '; cout << endl;
		for (int i = len; i >= 1; i--) cout << u[1][i] << ' '; cout << endl;
	}
};
info uni(info a, info b) {
//	a.otp(), b.otp();
	info fn;

	const int mx = 12;
	for (int j = 0; j < 25; j++) fa[j] = j, id[j] = 0;
	fn.l = a.l, fn.r = b.r, fn.dv = a.dv + b.dv, fn.len = a.len + b.len;
	for (int i = 1; i <= min(5, b.len); i++) {
		b.u[0][i] += mx, 
		b.u[1][i] += mx;	
		assert(b.u[0][i] < 25 && b.u[1][i] < 25);
	}
	info q[2] = {a, b};
	for (int i = 1; i <= min(5, a.len); i++) {
		int nid = a.r - i + 1;
		for (auto v : eg[nid]) {
		//	cout << nid << ' ' << v << endl;
			if (v >= b.l && v <= b.r) {
				int ufa = gfa(a.u[1][i]), 
					vfa = gfa(b.u[0][v - b.l + 1]);
			//	cout << "!!!" << nid << ' ' << v - b.l + 1 << ' ' << ufa << ' ' << vfa << endl;
				if (ufa == vfa) continue;
				fn.dv++, fa[ufa] = vfa;
			}
		}
	}
	int cnt = 0;
	for (int tp = 0; tp < 2; tp++)
		for (int i = 1; i <= min(5, fn.len); i++) {
			int npl = q[tp].u[tp][i];
			if (i > q[tp].len) npl = q[tp ^ 1].u[tp][i - q[tp].len];
			if (id[gfa(npl)] == 0) id[gfa(npl)] = ++cnt;
//			cout << i << ' ' << npl << ' ' << cnt << ' ' << q[tp].len << endl;
			fn.u[tp][i] = id[gfa(npl)];
		}
//	fn.otp();
//	system("pause");
	return fn;
}
struct ST {
	int l, r;
	ST *ch[2];
	info cur;
}p[maxn << 1], *root;
int stcnt = 0;
void bdtree(ST *a, int l, int r) {
//	cout << "BUILD" << l << ' ' << r << ' ' << stcnt << endl;
	a->l = l, a->r = r;
	if (l == r) {
		a->cur = info(l);
		return ;
	}
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), 
	bdtree(a->ch[1], mid + 1, r);
	a->cur = uni(a->ch[0]->cur, a->ch[1]->cur);
}
info query(ST *a, int l, int r) {
	if (a->l == l && a->r == r) return a->cur;
	int mid = (a->l + a->r) >> 1;
	if (r <= mid) return query(a->ch[0], l, r);
	else if (l > mid) return query(a->ch[1], l, r);
	else return uni(query(a->ch[0], l, mid), query(a->ch[1], mid + 1, r));
}
int n, k, m;
int main() {
	int test = 0;
	if (test) n = 100000, k = 5, m = 100000;
	else
		scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		if (test) u = rand() % n + 1, v = u + rand() % k + 1;
		else scanf("%d%d", &u, &v);
		if (u > v) swap(u, v);
		eg[u].pb(v);
	}
	root = &p[stcnt++];
	bdtree(root, 1, n);
	int q;
	if (test) q = 100000;
	else scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int l, r;
		if (test) {
			l = rand() % n + 1, r = rand() % n + 1;
			if (l > r) swap(l, r);
		}
		else scanf("%d%d", &l, &r);
		info cur = query(root, l, r);
		printf("%d\n", r - l + 1 - cur.dv);
	}
	return 0;
}
/*
5 3
2
1 3
2 3
1
1 3

*/