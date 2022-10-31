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

#define MAX 301010
//#define MOD 100000007
//#define MOD 100000009
#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

int N, M;
ll dist[MAX];
int vis[MAX];
vector<pii> adj[MAX];

pii dpi[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

pii operator+(pii p1, pii p2) {
	return pii(p1.first + p2.first, p1.second + p2.second);
}

pii operator-(pii p1, pii p2) {
	return pii(p1.first - p2.first, p1.second - p2.second);
}

pii trans(int x) {
	return pii(x / M, x % M);
}

int trans(int i, int j) {
	return i * M + j;
}

int trans(pii p) {
	return trans(p.first, p.second);
}

bool chk(pii p) {
	return 0 <= p.first && 0 <= p.second && p.first < N && p.second < M;
}

vector<pair<pii, pii>> vpi;

void solve() {
	cin >> N >> M;
	int i, j, k;
	vector<string> mp;
	int r, m; // rotate, move
	cin >> r >> m;
	for (i = 0; i < N; i++) {
		string s;
		cin >> s;
		mp.push_back(s);
	}
	typedef pair<ll, int> T;
	priority_queue<T, vector<T>, greater<T>> pq;
	int K = N * M;
	for (i = 0; i < K; i++) dist[i] = 1e17;
	for (i = 0; i < N; i++) for (j = 0; j < M; j++) if (mp[i][j] == '.') {
		int v = trans(i, j);
		dist[v] = 0;
		pq.push(T(0ll, v));
	}
	int cnt = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			int c = 0;
			pii p1, p2;
			if (mp[i][j] == 'D') {
				p1 = pii(i, j);
				p2 = pii(i - 1, j);
				c = 1;
			}
			else if (mp[i][j] == 'R') {
				p1 = pii(i, j);
				p2 = pii(i, j - 1);
				c = 1;
			}
			if (c) {
				cnt++;
				for (k = 0; k < 4; k++) {
					pii np = p1 + dpi[k];
					if (!chk(np)) continue;
					if (np == p2) continue;
					int cst = r;
					if (np + p2 == p1 + p1) cst = m;
					adj[trans(np)].emplace_back(trans(p2), cst);
				}
				swap(p1, p2);
				for (k = 0; k < 4; k++) {
					pii np = p1 + dpi[k];
					if (!chk(np)) continue;
					if (np == p2) continue;
					int cst = r;
					if (np + p2 == p1 + p1) cst = m;
					adj[trans(np)].emplace_back(trans(p2), cst);
				}
			}
		}
	}
	while (pq.size()) {
		int t = pq.top().second;
		ll c = pq.top().first;
		pq.pop();
		if (vis[t]) continue;
		vis[t] = 1;
		for (auto& [v, c] : adj[t]) {
			if (vis[v]) continue;
			if (dist[v] > dist[t] + c) dist[v] = dist[t] + c, pq.emplace(dist[v], v);
		}
	}
	ll ans = 1e17;
	/*
	for (i = 1; i < N; i++) for (j = 0; j < M; j++) {
		int c1, c2;
		c1 = cmap[i][j];
		c2 = cmap[i - 1][j];
		if ((~c1) && c1 == c2) continue;
		pii p1, p2;
		p1 = pii(i, j);
		p2 = pii(i - 1, j);
		if (~c1) {
			if (~c2) {
				pii pp1 = vpi[c1].first + vpi[c1].second - p1;
				pii pp2 = vpi[c2].first + vpi[c2].second - p2;
				for (int p = 0; p < 4; p++) {
					pii np1 = p1 + dpi[p];
					if (!chk(np1)) continue;
					if (np1 == pp1 || np1 == p2) continue;
					ans = min(ans, dist[trans(np1)]);
					for (int q = 0; q < 4; q++) {
						pii np2 = p2 + dpi[q];
						if (!chk(np2)) continue;
						if (np2 == pp2 || np2 == p1) continue;
						ans = min(ans, dist[trans(np1)] + dist[trans(np2)]);
					}
				}
			}
			else {
				pii pp1 = vpi[c1].first + vpi[c1].second - p1;
				for (int p = 0; p < 4; p++) {
					pii np = pp1 + dpi[p];
					if (!chk(np)) continue;
					if (np == p1 || np == p2) continue;
					ans = min(ans, dist[trans(np)]);
				}
			}
		}
		else {
			pii pp2 = vpi[c2].first + vpi[c2].second - p2;
			for (int p = 0; p < 4; p++) {
				pii np = p2 + dpi[p];
				if (!chk(np)) continue;
				if (np == pp2 || np == p1) continue;
				ans = min(ans, dist[trans(np)]);
			}
		}
	}
	*/
	for (i = 1; i < N; i++) for (j = 0; j < M; j++) ans = min(ans, dist[trans(i, j)] + dist[trans(i - 1, j)]);
	for (i = 0; i < N; i++) for (j = 1; j < M; j++) ans = min(ans, dist[trans(i, j)] + dist[trans(i, j - 1)]);
	if (ans >= (ll)1e17) ans = -1;
	cout << ans << ln;
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