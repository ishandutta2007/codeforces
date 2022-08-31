//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
struct ST {
	ST *ch[2];
	int len, l, r;
	ll sum;
	int mx, mn, lz; //  lz 
}p[maxn << 1], *root;
int stcnt = 0;
int le[maxn];
vi tr; // x  
void bdtree(ST *a, int l, int r) {
	a->l = l, a->r = r;
	a->mx = a->mn = a->lz = a->sum = 0;
	if (l == r) {
		a->len = le[l];
		return ;
	}
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), 
	bdtree(a->ch[1], mid + 1, r);
	a->len = a->ch[0]->len + a->ch[1]->len;
}
void upd(ST *a) {
	a->mx = max(a->ch[0]->mx, a->ch[1]->mx);
	a->mn = min(a->ch[0]->mn, a->ch[1]->mn);
	a->sum = a->ch[0]->sum + a->ch[1]->sum; 
}
void actlz(ST *a, int p) {
	if (p <= a->mn) return ;
	if (p >= a->mx) {
		a->mx = a->mn = a->lz = p;
		a->sum = 1ll * a->len * p;
		return ;
	}
	a->lz = 0;
	for (int i = 0; i < 2; i++)
		actlz(a->ch[i], p);
	upd(a);
}
void pushdown(ST *a) {
	if (a->lz) {
		actlz(a->ch[0], a->lz);
		actlz(a->ch[1], a->lz);
		a->lz = 0;
	}
}
void push(ST *a, int l, int r, int p) {
	if (l > r) return ;
	if (a->l == l && a->r == r) {
		actlz(a, p);
		return ;
	}
	pushdown(a);
	int mid = (a->l + a->r) >> 1;
	if (r <= mid) push(a->ch[0], l, r, p);
	else if (l > mid) push(a->ch[1], l, r, p);
	else push(a->ch[0], l, mid, p), 
		push(a->ch[1], mid + 1, r, p);
	upd(a);
}
ll q(ST *a, int l, int r) {
	if (l > r) return 0;
	if (a->l == l && a->r == r) return a->sum;
	pushdown(a);
	int mid = (a->l + a->r) >> 1;
	if (r <= mid) return q(a->ch[0], l, r);
	else if (l > mid) return q(a->ch[1], l, r);
	else return q(a->ch[0], l, mid) + q(a->ch[1], mid + 1, r);
}
int n, k, L;
vector<pi> cur[maxn];
pi st[maxn];
int top = 0;
vi xs;
int id(int u) {
	return lower_bound(xs.begin(), xs.end(), u) - xs.begin();
}
#define act pair<pi, int>
act calc(int x) {
	// x ~ x - 1
	int ls = id(st[x].fi);
	if (x == top) ls = 0;
	int rs = xs.size() - 1;
	if (x) rs = id(st[x - 1].fi);
	rs--;
	int to = st[x].se;
	if (x == top) to = L;
	return mp(mp(ls, rs), to);
}
void otp(act x) {
	cout << x.fi.fi << ' ' << x.fi.se << ' ' << x.se << endl;
}
vector<act> nd[maxn];
int main() {
	cin >> n >> k >> L;
	vi ys;
	for (int i = 1; i <= n; i++) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		cur[c].pb(mp(x, y));
		ys.pb(y);
		xs.pb(x);
	}
	xs.pb(L);
	xs.pb(-1);
	sort(xs.begin(), xs.end());
	for (int i = 1; i <= k; i++)
		sort(cur[i].begin(), cur[i].end()), 
		reverse(cur[i].begin(), cur[i].end());
	for (int i = 0; i < xs.size() - 1; i++)
		le[i] = xs[i + 1] - xs[i];
	ys.pb(L - 1);
	ys.pb(-1);
	sort(ys.begin(), ys.end());
	ll ans = 0;
	for (int i = 0; i < ys.size() - 1; i++) {
		ll cw = ys[i + 1] - ys[i];
		if (!cw) continue;
		stcnt = 0;
		root = &p[stcnt++];
		bdtree(root, 0, xs.size() - 2);
		for (int j = 0; j < xs.size(); j++)
			nd[j].clear();
	//	cout << i << ' ' << "BD" << endl;
		for (int s = 1; s <= k; s++) {
			top = 0;
			for (auto h : cur[s]) {
				if (h.se <= ys[i]) continue;
				int eid = id(h.fi) + 1;
				nd[eid].pb(calc(top));
				while (top && st[top - 1].se >= h.se) {
					nd[eid].pb(calc(top - 1));
					top--;
				}
				st[top++] = h;
			}
			for (int i = 0; i <= top; i++)
				nd[0].pb(calc(i));
		}
		ll ca = 0;
		for (int j = 0; j < xs.size() - 1; j++) {
			int ur = 0;
			if (j) ur = xs[j] - xs[j - 1];
			for (auto v : nd[j])
				push(root, v.fi.fi, v.fi.se, v.se);
			ll nans = 1ll * L * (L - xs[j]) - q(root, j, xs.size() - 2);
			nans %= mod;
			ca += nans * ur;
			ca %= mod;
		}
		ans += ca * cw;
		ans %= mod;
	}
	if (ans < 0) ans += mod;
	cout << ans << endl;
	return 0;
}