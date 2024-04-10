#include <bits/stdc++.h>
#define ll long long
#define maxn 300005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
struct ST {
	int l, r;
	ST *ch[2];
	int lz, mn;
}p[maxn << 2], *root[2];
int stcnt = 0;
const int inf = 1e9 + 7; 
void bdtree(ST *a, int l, int r) {
	a->l = l, a->r = r, a->mn = inf, a->lz = inf;
	if (l == r) return ;
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), bdtree(a->ch[1], mid + 1, r);
}
void upd(ST *a) {
	a->mn = min(a->ch[0]->mn, a->ch[1]->mn);
}
void actlz(ST *a, int lz) {
	a->lz = min(a->lz, lz);
	a->mn = min(a->mn, lz);
}
void pushdown(ST *a) {
	if (a->lz == inf) return ;
	for (int i = 0; i < 2; i++)
		actlz(a->ch[i], a->lz);
	a->lz = inf;
}
void pushlz(ST *a, int l, int r, int lz) {
	if (a->l == l && a->r == r) {
		actlz(a, lz);
		return ;
	}
	int mid = (a->l + a->r) >> 1;
	pushdown(a); 
	if (r <= mid) pushlz(a->ch[0], l, r, lz);
	else if (l > mid) pushlz(a->ch[1], l, r, lz);
	else pushlz(a->ch[0], l, mid, lz), pushlz(a->ch[1], mid + 1, r, lz);
	upd(a);
}
int q(ST *a, int l, int r) {
	if (a->l == l && a->r == r)
		return a->mn;
	pushdown(a);
	int mid = (a->l + a->r) >> 1;
	if (r <= mid) return q(a->ch[0], l, r);
	else if (l > mid) return q(a->ch[1], l, r);
	else return min(q(a->ch[0], l, mid), q(a->ch[1], mid + 1, r));
}
int l[maxn], r[maxn], ans[maxn];	
vi eg;
int gt(int a) {
	return lower_bound(eg.begin(), eg.end(), a) - eg.begin();
}
int a[maxn];
int main() {
	int n, m;
	cin >> n;

	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), eg.pb(a[i]);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &l[i], &r[i]);
		ans[i] = inf;
	}
	sort(eg.begin(), eg.end());
	for (int i = 0; i < 2; i++) {
		stcnt = 0;
		vector<vector<pi> > qs(n + 1);
		for (int j = 1; j <= m; j++)
			qs[r[j]].pb(mp(l[j], j));
		root[0] = &p[stcnt++], root[1] = &p[stcnt++];
		bdtree(root[0], 1, n);
		bdtree(root[1], 0, n);
		for (int i = 1; i <= n; i++) {
			int lb = gt(a[i]), rb = n;
			while (1) {
				int cur = -q(root[1], lb, rb);
			//	cout << "Q" << lb << ' ' << rb << ' ' << cur << endl;
				if (cur < 0) break;
				pushlz(root[0], 1, cur, a[cur] - a[i]);
			//	cout << i << ' ' << cur << endl;
				if (a[cur] == a[i]) break;
				int uu = (a[cur] + a[i]) / 2;
				rb = gt(uu);
				if (eg[rb] > uu) rb--;
			}
			pushlz(root[1], lb, lb, -i);
		//	cout << "PUSH" << lb << ' ' << lb << ' ' << -i << endl;
			for (auto v : qs[i])
				ans[v.se] = min(ans[v.se], q(root[0], v.fi, v.fi));
		}
		reverse(a + 1, a + n + 1);
		for (int i = 1; i <= m; i++)
			l[i] = n + 1 - l[i], r[i] = n + 1 - r[i], swap(l[i], r[i]);
	}
	for (int i = 1; i <= m; i++) 
		printf("%d\n", ans[i]);
	return 0;
}
/*
8 4
3 8
4 6
6 8
2 8

*/