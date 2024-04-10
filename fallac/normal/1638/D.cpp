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
typedef pair<int, int> pi;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 1010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

int arr[MAX][MAX];
int c[MAX][MAX];
int dx[4] = { 0, 1, 0, 1 };
int dy[4] = { 0, 0, 1, 1 };
int N, M;

int chk(int x, int y) {
	int i, j;
	int c = -1;
	if (x < 1 || y < 1) return 0;
	if (x >= N || y >= M) return 0;
	for (i = 0; i < 4; i++) {
		if (!arr[x + dx[i]][y + dy[i]]) continue;
		c = arr[x + dx[i]][y + dy[i]];
		for (j = 0; j < 4; j++) {
			if (arr[x + dx[j]][y + dy[j]] && arr[x + dx[j]][y + dy[j]] != arr[x + dx[i]][y + dy[i]]) return 0;
		}
	}
	return c;
}

void solve() {
	cin >> N >> M;
	int i, j;
	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) cin >> arr[i][j];
	queue<pi> q;
	for (i = 1; i < N; i++) {
		for (j = 1; j < M; j++) {
			if (chk(i, j)) q.emplace(i, j);
		}
	}
	int x, y;
	vector<pair<pi, int>> ans;
	while (q.size()) {
		tie(x, y) = q.front();
		q.pop();
		if (x < 1 || y < 1) continue;
		if (x >= N || y >= M) continue;
		if (c[x][y]) continue;
		int cc = chk(x, y);
		if (cc == -1) continue;
		ans.push_back({ {x, y} , cc });
		c[x][y] = 1;
		for (i = 0; i < 4; i++) arr[x + dx[i]][y + dy[i]] = 0;
		for (i = -1; i < 2; i++) { for (j = -1; j < 2; j++) { if (!c[x + i][y + j] && chk(x + i, y + j)) q.emplace(x + i, y + j); } }
	}
	int a = 0;
	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) if (arr[i][j]) a = 1;
	if (a) {
		cout << -1 << ln;
		return;
	}
	cout << ans.size() << ln;
	reverse(ans.begin(), ans.end());
	for (auto x : ans) cout << x.first.first << bb << x.first.second << bb << x.second << ln;
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