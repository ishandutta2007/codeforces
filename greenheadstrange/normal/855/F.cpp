#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
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
const ll inf = (1ll << 50);
struct ST {
	int l, r;
	ST *ch[2];
	ll mx[2];
	ll lz; // mx[0]lz
	int fl; // 1 : 
	ll c[2], s[2]; // c : mx[0] 
}p[maxn << 3], *r[2];
int stcnt = 0;
void upd(ST *a) {
	a->s[0] = a->ch[0]->s[0] + a->ch[1]->s[0];
	a->s[1] = a->ch[0]->s[1] + a->ch[1]->s[1];
	a->mx[0] = max(a->ch[0]->mx[0], a->ch[1]->mx[0]), a->mx[1] = 0;
	a->c[0] = a->c[1] = 0;
	for (int j = 0; j < 2; j++)	
		if (a->ch[j]->mx[0] == a->mx[0])
			for (int k = 0; k < 2; k++)
				a->c[k] += a->ch[j]->c[k];
	for (int j = 0; j < 2; j++)
		for (int k = 0; k < 2; k++)
			if (a->ch[j]->mx[k] != a->mx[0])
				a->mx[1] = max(a->mx[1], a->ch[j]->mx[k]); 
}
void bdtree(ST *a, int l, int r) {
	a->l = l, a->r = r, a->fl = 0, a->lz = inf;
	if (l == r) {
		a->mx[0] = inf, a->mx[1] = 0;
		a->s[0] = inf, a->s[1] = 0, a->c[0] = 1, a->c[1] = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), bdtree(a->ch[1], mid + 1, r);
	upd(a);
} 
void actfl(ST *a) {
	a->fl = 1;
	a->s[1] = a->s[0], a->c[1] = a->c[0];
}
void actlz(ST *a, ll d) {
	void pushdown(ST *a);
	if (d >= a->mx[0]) return ;
	if (d >= a->mx[1]) {
		a->lz = d;
		a->s[0] -= a->c[0] * (a->mx[0] - d);
		a->s[1] -= a->c[1] * (a->mx[0] - d); 
		a->mx[0] = d;
	}
	else {
		pushdown(a);
		actlz(a->ch[0], d), actlz(a->ch[1], d);
		upd(a);
	}
}
void pushdown(ST *a) {
	if (a->fl)
		actfl(a->ch[0]), actfl(a->ch[1]);
	if (a->lz != inf) {
		actlz(a->ch[0], a->lz);
		actlz(a->ch[1], a->lz);
		a->lz = inf;
	}
}
void push(ST *a, int l, int r, int mn) {
	if (a->l == l && a->r == r) {
		if (mn) actlz(a, mn);
		else actfl(a);
		return ;
	}
	pushdown(a);
	int mid = (a->l + a->r) >> 1;
	if (r <= mid) push(a->ch[0], l, r, mn);
	else if (l > mid) push(a->ch[1], l, r, mn);
	else push(a->ch[0], l, mid, mn), push(a->ch[1], mid + 1, r, mn);
	upd(a);
}
ll q(ST *a, int l, int r) {
	if (a->l == l && a->r == r) return a->s[1];
	pushdown(a);
	int mid = (a->l + a->r) >> 1;
	if (r <= mid) return q(a->ch[0], l, r);
	else if (l > mid) return q(a->ch[1], l, r);
	else return q(a->ch[0], l, mid) + q(a->ch[1], mid + 1, r);
} 
int main() {
	int qq;
	cin >> qq;
	r[0] = &p[stcnt++], r[1] = &p[stcnt++];
	bdtree(r[0], 1, 100000), bdtree(r[1], 1, 100000);
	for (int i = 1; i <= qq; i++) {
		int t, l, rr, k;
		scanf("%d%d%d", &t, &l, &rr);
		rr--;
		if (t == 1) {
			scanf("%d", &k);
			if (k < 0) push(r[0], l, rr, 0), push(r[1], l, rr, -k);
			else push(r[0], l, rr, k), push(r[1], l, rr, 0);
		} 
		else {
			ll ans = q(r[0], l, rr) + q(r[1], l, rr);
			ans %= inf;
			if (ans < 0) ans += inf;
			printf("%lld\n", ans);
		}
	} 
	return 0;
}