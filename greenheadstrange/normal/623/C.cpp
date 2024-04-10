#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353 
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int n;
pi r[maxn];
const int inf = mod;

struct th {
	int mx, mn, m[2];
	th() {mx = -inf, mn = inf; m[0] = -inf, m[1] = inf;}
	th(int a) {
		mx = -inf, mn = inf;
		if (a > 0) mx = a;
		else mn = a;
		m[0] = m[1] = a;
	}
	th u(th f) {
		th fn;
		fn.mx = max(mx, f.mx), fn.mn = min(mn, f.mn);
		fn.m[0] = max(m[0], f.m[0]), fn.m[1] = min(m[1], f.m[1]);
		return fn;
	} 
};
th fr[maxn], ed[maxn], cur[maxn];
int u[maxn];
ll sq(int a) {
	return 1ll * a * a;
}
bool check(ll k) {
	int sqr = sqrt(k) - 10;
	sqr = max(sqr, 0);
	while (sq(sqr + 1) <= k) sqr++;
	if (sq(ed[1].m[0] - ed[1].m[1]) <= k) return 1;
	for (int i = 1; i <= n; i++) {
		int ls, rs;
		if (r[i].fi >= 0) ls = max(-r[i].fi, r[i].fi - sqr), rs = r[i].fi;
		else ls = r[i].fi, rs = min(-r[i].fi, r[i].fi + sqr);
		th g;
		ls = lower_bound(u + 1, u + n + 1, ls) - u;
		g = fr[ls - 1];
		rs = lower_bound(u + 1, u + n + 1, rs + 1) - u;
		g = g.u(ed[rs]);
	//	cout << ls << ' ' << rs << ' ' << g.m[0] << ' ' << g.m[1] << endl;
		if (g.m[0] - g.m[1] > sqr) continue;
		if (g.mx >= 0 && 1ll * g.mx * g.mx + 1ll * r[i].fi * r[i].fi > k) continue;
		if (g.mn <= 0 && sq(g.mn) + sq(r[i].fi) > k) continue;
		return 1;
	}
	return 0;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &r[i].fi, &r[i].se);
	sort(r + 1, r + n + 1);
	for (int i = 1; i <= n; i++)
		u[i] = r[i].fi;
	for (int i = 1; i <= n; i++)
		cur[i] = th(r[i].se);
	for (int i = 1; i <= n; i++)	
		fr[i] = fr[i - 1].u(cur[i]);
	for (int i = n; i >= 1; i--)
		ed[i] = ed[i + 1].u(cur[i]);
	ll ls = 0, rs = 1e18;
	while (ls < rs) {
		ll mid = (ls + rs) >> 1;
		if (check(mid)) rs = mid;
		else ls = mid + 1;
	}
	cout << ls << endl;
	return 0;
}
/*
1 2
..
*/