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

#define MAX 201010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

vector<int> adj[MAX];
ll arrs[MAX];
ll l[MAX];
ll r[MAX];

int ans = 0;

void dfs(int x) {
	for (auto v : adj[x]) {
		dfs(v);
		arrs[x] += arrs[v];
	}
	if (arrs[x] >= r[x]) arrs[x] = r[x];
	else if (arrs[x] < l[x]) ans++, arrs[x] = r[x];
}

void solve() {
	int N;
	cin >> N;
	int i;
	ans = 0;
	for (i = 1; i <= N; i++) arrs[i] = 0, adj[i].clear();
	int x;
	for (i = 2; i <= N; i++) {
		cin >> x;
		adj[x].push_back(i);
	}
	for (i = 1; i <= N; i++) cin >> l[i] >> r[i];
	dfs(1);
	cout << ans << ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		init();
		solve();
	}
}