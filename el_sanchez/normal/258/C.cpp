#pragma comment(linker, "/STACK:67108864")
 
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
 
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)
 
#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
 
using namespace std;
 
typedef long long ll;
 
const long double pi = 3.1415926535897932384626433832795;
const long double eps = 1e-9;
const int INF = 1e5;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
const int MAXN = 100500;

int n, mx, k, id, m, m2;
vi a;
pii ds[MAXN];
int d[MAXN], len[MAXN];
ll ans, cur;

void go(int id, int cur) {
	if (id == k) {
		d[m++] = cur;
		return;
	}

	forn(i, ds[id].ss + 1) {
		go(id + 1, cur);
		cur *= ds[id].ff;
	}
}

ll binpow(ll x, ll st) {
	ll p = x, ans = 1;
	while (st > 0) {
		if (st & 1) ans = (ans * p) % MOD;
		p = (p * p) % MOD;
		st >>= 1;
	}
	return ans;
}

ll variants(int l, int r) {
	ll ans = 1, all = 1;
	for (int i = l; i < r; i++) {
		ans = (ans * binpow(all, len[i] - len[i + 1])) % MOD;
		all++;
	}
	ans = (ans * binpow(all, len[r])) % MOD;
	return ans;
}

void getans(int x) {
	ll prim = 2;
	k = 0;
	int j = 0, cx = x;
	while (prim * prim <= cx) {
		if (cx % prim == 0) {
			ds[k].ff = prim;
			ds[k].ss = 0;
			while (cx % prim == 0) {
				cx /= prim;
				ds[k].ss++;
			}
			k++;
		}
		prim++;
	}
	if (cx > 1) {
		ds[k].ff = cx;
		ds[k].ss = 1;
		k++;
	}

	m = 0;
	go(0, 1);
	sort(d, d + m);

	forn(i, m) {
		len[i] = lower_bound(a.begin(), a.end(), d[i]) - a.begin();
		len[i] = n - len[i];
	}

	cur = variants(0, m - 1);
	cur = (cur + MOD - variants(0, m - 2)) % MOD;
}


int main() {
 
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

	scanf("%d", &n);
	a.resize(n);
	mx = 0;
	forn(i, n) {
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}
	sort(all(a));

	ans = 1;
	forab(i, 2, mx + 1) {
		cur = 0;
		getans(i);
		ans = (ans + cur) % MOD;
	}
	cout << ans;

    return 0;
}