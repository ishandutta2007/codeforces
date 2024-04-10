#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 500005;
struct ST {
	int mx;
	ST *ch[2];
	int l, r;
	int lz; 
}p[maxn << 1], *root;
int stcnt = 0;
int x[maxn];
void upd(ST *a) {
	a->mx = max(a->ch[0]->mx, a->ch[1]->mx);
}
void bdtree(ST *a, int l, int r) {
	a->l = l, a->r = r;
	if (l == r) {
		a->mx = x[l];
		return ;
	}
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), bdtree(a->ch[1], mid + 1, r);
	upd(a);
}
void actlz(ST *a, int lz) {
	a->mx += lz, a->lz += lz;
}
void pushdown(ST *a) {
	if (a->lz) {
		actlz(a->ch[0], a->lz), 
		actlz(a->ch[1], a->lz);
		a->lz = 0;
	}
}
void push(ST *a, int l, int r, int lz) {
	if (a->l == l && a->r == r) {
		actlz(a, lz);
		return;
	}
	pushdown(a);
	int mid = (a->l + a->r) >> 1;
	if (r <= mid) push(a->ch[0], l, r, lz);
	else if (l > mid) push(a->ch[1], l, r, lz);
	else push(a->ch[0], l, mid, lz), push(a->ch[1], mid + 1, r, lz);
	upd(a);
}
int a[maxn], b[maxn];
int main() {
	int n, m, pp;
	cin >> n >> m >> pp;
	vector<pi> u, v;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		u.pb(mp(a, b));
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v.pb(mp(a, b));
	}
	sort(u.begin(), u.end());
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)	
		x[i] = -v[i].se;
	root = &p[stcnt++];
	bdtree(root, 0, v.size() - 1);
	vector<pair<pi, int> >x; 
	for (int i = 0; i < pp; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
	//	swap(a, b);
		a++, b++;
		x.pb(mp(mp(a, b), c));
	}
	int dd = -2e9;
	sort(x.begin(), x.end());
	int pl = 0;
	int ans = -2e9;
	for (int i = 0; i < n; i++) {
		int gg = -u[i].se;
		while (pl < x.size() && x[pl].fi.fi <= u[i].fi) {
			int er = lower_bound(v.begin(), v.end(), mp(x[pl].fi.se, dd)) - v.begin();
			if (er < v.size())
				push(root, er, v.size() - 1, x[pl].se);
			pl++;
		}
		gg += root->mx;
		ans = max(ans, gg);
	}
	cout << ans << endl;
	return 0;
}
/*
1 2
..
*/