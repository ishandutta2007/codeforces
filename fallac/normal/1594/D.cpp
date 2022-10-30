/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 301010
#define MOD 1000000007
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

typedef pair<ll, ll> pll;

vector<pll> adj[MAX];
ll vis[MAX];
ll color[MAX];
ll ans = 0;

ll cnt = 0;

ll dfs(ll x, ll c) {
	if (vis[x]) return 0;
	vis[x] = 1;
	color[x] = c;
	cnt++;
	ll ret = 0;
	if (c) ret++;
	for (auto v : adj[x]) {
		if (v.second) ret += dfs(v.first, !c);
		else ret += dfs(v.first, c);
	}
	return ret;
}

void solve() {
	ll N, M;
	cin >> N >> M;
	ll i;
	string s;
	ll a, b;
	for (i = 1; i <= N; i++) adj[i].clear(), vis[i] = 0, color[i] = 0;
	ans = 0;
	for (i = 1; i <= M; i++) {
		cin >> a >> b >> s;
		adj[a].emplace_back(b, (s[0] == 'i'));
		adj[b].emplace_back(a, (s[0] == 'i')); //xor
	}
	ll ans = 0;
	for (i = 1; i <= N; i++) {
		if (vis[i] == 0) {
			cnt = 0;
			ll res = dfs(i, 0);
			ans += max(cnt - res, res);
		}
	}
	for (i = 1; i <= N; i++) {
		for (auto v : adj[i]) {
			if (color[v.first] ^ color[i] != v.second) {
				cout << -1 << ln;
				return;
			}
		}
	}
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