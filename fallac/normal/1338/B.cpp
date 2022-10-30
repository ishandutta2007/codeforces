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

#define MAX 101010
#define MOD 100000009
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

vector<ll> adj[MAX];

ll nl;
ll depth[MAX];
ll isleaf[MAX];
ll cnt = 0;

void dfs(ll x, ll p = 0, ll d = 1) {
	depth[x] = d;
	ll asdf = 0;
	for (auto v : adj[x]) {
		if (v == p) continue;
		if (isleaf[v]) asdf++;
		dfs(v, x, d + 1);
	}
	if (asdf) cnt += asdf - 1;
}

void solve() {
	ll N;
	cin >> N;
	ll a, b;
	ll i;
	for (i = 1; i < N; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ll r;
	for (i = 1; i <= N; i++) {
		if (adj[i].size() >= 2) {
			r = i;
			break;
		}
	}
	for (i = 1; i <= N; i++) {
		if (adj[i].size() == 1) {
			nl++;
			isleaf[i] = 1;
		}
	}
	dfs(r);
	if (nl == 2) {
		if (N == 3) cout << 1 << Ln << 1 << ln;
		else if (N % 2) cout << 1 << ln << N - 1 << Ln;
		else cout << 3 << ln << N - 1 << Ln;
		return;
	}
	else {
		vector<ll> asdf(2);
		for (i = 1; i <= N; i++) if (isleaf[i]) asdf[depth[i] % 2] = 1;
		if (asdf[1] && asdf[0]) cout << 3 << ln;
		else cout << 1 << ln;
	}
	cout << N - cnt - 1 << ln;
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