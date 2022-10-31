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
typedef pair<int, int> pii;

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

map<int, ll > dp[MAX];
ll C[MAX];
int p[MAX];
vector<int> adj[MAX];

ll dfs(int x, int d) {
	if (d == 0) return 0;
	if (dp[x].find(d) != dp[x].end()) return dp[x][d];
	int s = adj[x].size();
	ll ans = C[x] * d;
	if (!s) return ans;
	int k = d / s;
	vector<ll> lst;
	int cnt = d % s;
	for (auto v : adj[x]) {
		ll r1 = dfs(v, k), r2 = 0;
		if (cnt) r2 = dfs(v, k + 1);
		ans += r1;
		lst.push_back(r2 - r1);
	}
	sort(lst.begin(), lst.end());
	while (cnt--) ans += lst.back(), lst.pop_back();
	return dp[x][d] = ans;
}

void solve() {
	int N, K;
	cin >> N >> K;
	int i;
	for (i = 1; i <= N; i++) adj[i].clear();
	for (i = 2; i <= N; i++) cin >> p[i], adj[p[i]].push_back(i);
	for (i = 1; i <= N; i++) cin >> C[i];
	for (i = 1; i <= N; i++) dp[i].clear();
	cout << dfs(1, K) << ln;
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