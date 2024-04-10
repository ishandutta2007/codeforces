//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

vector<int> dx = { 1, -1, 0, 0 };
vector<int> dy = { 0, 0, 1, -1 };

const int N = 300 + 2;
const int M = 2e6 + 2;
int g[N][N], idx[N][N], last[N][N];

int dsu[M];
int find(int i) {
	if(dsu[i] == -1) return i;
	return dsu[i] = find(dsu[i]);
}
int link(int i, int j) {
	i = find(i); j = find(j);
	if(i == j) return 0;
	dsu[i] = j;
	return 1;
}

int add[M], del[M], ans[M];
vector<tuple<int,int,int>> removal[M], insert[M];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m, q;
	cin >> n >> m >> q;
	for(int i=1; i<=q; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		if(g[x][y] != c) {
			removal[g[x][y]].push_back(make_tuple(i-1, x, y));
			insert[c].push_back(make_tuple(i, x, y));
			g[x][y] = c;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			insert[0].push_back(make_tuple(0, i, j));
			removal[g[i][j]].push_back(make_tuple(q, i, j));
		}
	}

	memset(g, -1, sizeof g);
	for(int c=0; c<M; c++) {
		if(insert[c].empty()) continue;
		fill(dsu, dsu+insert[c].size(), -1);
		int groups = 0;
		for(int i=0; i<insert[c].size(); i++) {
			auto [j, x, y] = insert[c][i];
			idx[x][y] = i;
			g[x][y] = c;
			add[j]++;
			groups++;
			for(int d=0; d<4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if(g[nx][ny] == g[x][y]) {
					int rem = link(i, idx[nx][ny]);
					add[j] -= rem;
					groups -= rem;
				}
			}
		}
		add[get<0>(insert[c].back()) + 1] -= groups;
	}

	memset(g, -1, sizeof g);
	for(int c=0; c<M; c++) {
		if(removal[c].empty()) continue;
		fill(dsu, dsu+removal[c].size(), -1);
		int groups = 0;
		reverse(removal[c].begin(), removal[c].end());
		for(int i=0; i<removal[c].size(); i++) {
			auto [j, x, y] = removal[c][i];
			idx[x][y] = i;
			g[x][y] = c;
			del[j]++;
			groups++;
			for(int d=0; d<4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if(g[nx][ny] == g[x][y]) {
					int rem = link(i, idx[nx][ny]);
					del[j] -= rem;
					groups -= rem;
				}
			}
		}
		del[get<0>(insert[c].back())] -= groups;
	}

	for(int i=0, cur=0; i<=q; i++) {
		cur += add[i];
		ans[i] += cur;
	}
	for(int i=q, cur=0; i>=0; i--) {
		cur += del[i];
		ans[i] += cur;
	}

	for(int i=1; i<=q; i++) {
		cout << ans[i] << nl;
	}

	return 0;
}