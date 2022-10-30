/*

*/

#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 101010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

vector<ll> adj[MAX];
ll ord[MAX];
ll prt[MAX];
ll cnt = 0;

void dfs(ll x = 1, ll p = 0) {
	prt[x] = p;
	ord[++cnt] = x;
	for (auto v : adj[x]) {
		if (v == p) continue;
		dfs(v, x);
	}
}

void solve() {
	ll N;
	cin >> N;
	ll i;
	ll a, b;
	for (i = 1; i < N; i++) cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);
	dfs();
	ll l, r;
	l = 1;
	r = N;
	cout << '?' << bb;
	cout << N << bb;
	for (i = 1; i <= N; i++) cout << i << bb;
	cout << ln;
	cout.flush();
	ll mx;
	cin >> mx;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		cout << '?' << bb;
		cout << mid << bb;
		for (i = 1; i <= mid; i++) cout << ord[i] << bb;
		cout << ln;
		cout.flush();
		ll a;
		cin >> a;
		if (a == mx) r = mid;
		else l = mid;
	}
	cout << '!' << bb;
	cout << ord[r] << bb << prt[ord[r]] << ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	omode;
	while (T--) {
		init();
		solve();
	}
}