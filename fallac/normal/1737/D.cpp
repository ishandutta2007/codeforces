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

#define MAX 250250
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

int U[MAX], V[MAX], W[MAX];
vector<int> adj[505];
int dis[505][505];

int N;

void getdis(int k) {
	int i;
	for (i = 1; i <= N; i++) dis[k][i] = N + 10;
	dis[k][k] = 0;
	queue<int> q;
	q.push(k);
	while (q.size()) {
		int t = q.front(); q.pop();
		for (auto v : adj[t]) {
			if (dis[k][v] > dis[k][t] + 1) {
				dis[k][v] = dis[k][t] + 1;
				q.push(v);
			}
		}
	}
}

int calc(int s1, int t1, int s2, int t2) {
	return dis[s1][t1] + dis[s2][t2];
}

void solve() {
	int M;
	cin >> N >> M;
	int i, j;
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) dis[i][j] = 0;
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) adj[i].clear();
	ll mn = 1e18;
	for (i = 1; i <= M; i++) {
		cin >> U[i] >> V[i] >> W[i];
		adj[U[i]].push_back(V[i]);
		adj[V[i]].push_back(U[i]);
	}
	for (i = 1; i <= N; i++) getdis(i);
	for (i = 1; i <= M; i++) {
		int d = min(calc(U[i], 1, V[i], N), calc(V[i], 1, U[i], N)) + 1;
		for (j = 1; j <= N; j++) d = min(d, 2 + min(dis[U[i]][j], dis[V[i]][j]) + dis[1][j] + dis[N][j]);
		mn = min(mn, 1ll * d * W[i]);
	}
	cout << mn << ln;
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