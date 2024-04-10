/*














 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
 
 
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
const string FILENAME = "input";


int n, m;
int dist[102][102];
int s, b, k, h;
int x[1001], a[1001], f[1001];
int y[1001], d[1001];
vector<int> g[1001];
int used[1001];
int mt[1001];
int uk;

bool dfs(int u) {
	if (used[u] == uk) {
		return false;
	}
	used[u] = uk;
	for (auto h: g[u]) {
		if (mt[h] == -1 || dfs(mt[h]))  {
			mt[h] = u;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
		cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				dist[i][j] = 1e9; 
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				chkmin(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	cin >> s >> b >> k >> h;
	for (int i = 0; i < s; i++) {
		cin >> x[i] >> a[i] >> f[i];
		x[i]--;
	}
	for (int i = 0; i < b; i++) {
		cin >> y[i] >> d[i];
		y[i]--;
		mt[i] = -1;
	}
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < b; j++) {
			if (dist[x[i]][y[j]] + 1 <= f[i] && a[i] >= d[j]) {
				g[i].pb(j);
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < s; i++) {
		uk++;
		if (dfs(i)) {
			cnt++;
		}
	}
	long long ans = 1LL * cnt * k;
	for (int t = 0; t <= cnt; t++) {
		chkmin(ans, 1LL * t * k + 1LL * (cnt - t + s - cnt) * h);
	}
	cout << ans << '\n';
	return 0;
}