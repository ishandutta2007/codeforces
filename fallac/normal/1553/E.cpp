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
#define bbb ' '
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

ll N;

ll cycle(vector<ll>& v) {
	ll i;
	vector<ll> vis;
	vis.resize(N + 1);
	ll cnt = 0;
	for (i = 1; i <= N; i++) {
		if (!vis[i]) {
			ll x = i;
			cnt++;
			while (!vis[x]) vis[x] = 1, x = v[x];
		}
	}
	return cnt;
}

void solve() {
	ll M;
	cin >> N >> M;
	vector<ll> v;
	v.resize(N + 1);
	ll i;
	for (i = 1; i <= N; i++) cin >> v[i];
	vector<ll> c;
	c.resize(N);
	for (i = 1; i <= N; i++) {
		if (i == v[i]) c[0]++;
		if (i < v[i]) c[v[i] - i]++;
		if (i > v[i]) c[v[i] - i + N]++;
	}
	ll limit = 2 * M;
	vector<ll> vc;
	for (i = 0; i < N; i++) {
		if (N - c[i] <= limit) vc.push_back(i);
	}
	vector<ll> ans;
	for (auto x : vc) {
		vector<ll> p;
		p.resize(N + 1);
		for (i = 1; i <= N; i++) p[1 + ((i + x - 1) % N)] = i;
		vector<ll> vp;
		vp.resize(N + 1);
		for (i = 1; i <= N; i++) vp[i] = v[p[i]];
		if (N - cycle(vp) <= M) ans.push_back((N - x) % N);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << ln;
	for (auto x : ans) cout << x << ln;
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