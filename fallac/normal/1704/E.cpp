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

#define MAX 1010
//#define MOD 100000007
//#define MOD 100000009
#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

int N, M;

int chk[MAX][MAX];
ll val[MAX];
ll A[MAX];
int deg[MAX];
vector<int> adj[MAX], radj[MAX];

void solve() {
	cin >> N >> M;
	int i, j;
	for (i = 0; i <= N + 5; i++) {
		for (j = 0; j <= 1005; j++) chk[i][j] = 0;
		val[i] = 0;
		deg[i] = 0;
		adj[i].clear();
		radj[i].clear();
	}
	for (i = 1; i <= N; i++) cin >> A[i];
	int a, b;
	for (i = 1; i <= M; i++) {
		cin >> a >> b;
		radj[b].push_back(a);
		adj[a].push_back(b);
		deg[b]++;
	}
	int c = 1;
	for (i = 1; i <= N; i++) if (A[i]) c = 0;
	if (c) {
		cout << 0 << ln;
		return;
	}
	queue<int> q;
	for (i = 1; i <= N; i++) if (deg[i] == 0) q.push(i);
	while (q.size()) {
		int v = q.front();
		q.pop();
		val[v] = A[v];
		for (i = 1; i <= min((int)A[v], N); i++) chk[v][i] = 1;
		for (auto x : radj[v]) {
			val[v] += val[x];
			val[v] %= MOD;
			int sum = 0;
			for (int t = 1; t < N; t++) {
				sum += chk[x][t];
				if (chk[v][t + 1] == 0 && sum) sum--, chk[v][t + 1] = 1;
			}
		}
		for (auto x : adj[v]) {
			deg[x]--;
			if (deg[x] <= 0) q.push(x);
		}
	}
	int v = 1;
	for (i = 1; i <= N; i++) if (adj[i].empty()) v = i;
	for (i = 1; i <= N; i++) val[v] += (1 - chk[v][i]);
	val[v] += MOD;
	val[v] %= MOD;
	cout << val[v] << ln;
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