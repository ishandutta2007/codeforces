//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma")
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

int solve_rook(int g[3][3]) {
	const int n = 3;
	bool vis[n][n];
	memset(vis, 0, sizeof vis);

	pair<int,int> s;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(g[i][j] == 1) {
				s = make_pair(i, j);
			}
		}
	}

	int res = 0;
	for(int bs=0; bs<n*n; bs++) {
		tuple<int,int,int> cand(INF, 0, 0);
		tuple<int,int,int> minv(INF, 0, 0);
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(vis[i][j]) continue;
				tuple<int,int,int> cur = make_tuple(g[i][j], i, j);
				minv = min(minv, cur);
				if(s.first == i || s.second == j) {
					cand = min(cand, cur);
				}
			}
		}
		auto [v, i, j] = cand;
		if(v < INF) {
			s = make_pair(i, j);
			vis[i][j] = true;
		} else {
			auto [_, ii, jj] = minv;
			s = make_pair(ii, jj);
			vis[ii][jj] = true;
			res++;
		}
	}
	return res;
}

int solve_queen(int g[3][3]) {
	const int n = 3;
	bool vis[n][n];
	memset(vis, 0, sizeof vis);

	pair<int,int> s;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(g[i][j] == 1) {
				s = make_pair(i, j);
			}
		}
	}

	int res = 0;
	for(int bs=0; bs<n*n; bs++) {
		tuple<int,int,int> cand(INF, 0, 0);
		tuple<int,int,int> minv(INF, 0, 0);
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(vis[i][j]) continue;
				tuple<int,int,int> cur = make_tuple(g[i][j], i, j);
				minv = min(minv, cur);
				if(s.first == i || s.second == j || abs(s.first-i) == abs(s.second-j)) {
					cand = min(cand, cur);
				}
			}
		}
		auto [v, i, j] = cand;
		if(v < INF) {
			s = make_pair(i, j);
			vis[i][j] = true;
		} else {
			auto [_, ii, jj] = minv;
			s = make_pair(ii, jj);
			vis[ii][jj] = true;
			res++;
		}
	}
	return res;
}

void solve() {
	const int n = 3;
	vector<int> p;
	for(int i=1; i<=n*n; i++) {
		p.push_back(i);
	}

	int g[n][n];
	do {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				g[i][j] = p[i*n + j];
			}
		}
		if(solve_rook(g) < solve_queen(g)) {
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					cout << g[i][j] << " ";
				}
				cout << nl;
			}
			return;
		}
	} while(next_permutation(p.begin(), p.end()));
	cout << -1 << nl;
}

vector<vector<int>> bad =  {
	{12, 15, 10,  2},
	{ 6,  9, 11, 16},
	{ 3,  5,  1,  8},
	{ 4,  7, 14, 13},
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	if(n < 3) {
		cout << -1 << nl;
	} else if(n == 3) {
		solve();
	} else {
		int g[n][n];
		for(int i=0; i<4; i++) {
			for(int j=0; j<4; j++) {
				g[n-4+i][n-4+j] = bad[i][j] + n*n-16;
			}
		}
		for(int k=0, cur=1; k<n-4; k++) {
			if(k%2 == 0) {
				g[n-2][k] = cur++;
				g[n-1][k] = cur++;
				for(int i=n-3; i>=k; i--) {
					g[i][k] = cur++;
				}
				for(int j=k+1; j<=n-3; j++) {
					g[k][j] = cur++;
				}
				g[k][n-1] = cur++;
				g[k][n-2] = cur++;
			} else {
				g[k][n-2] = cur++;
				g[k][n-1] = cur++;
				for(int j=n-3; j>=k; j--) {
					g[k][j] = cur++;
				}
				for(int i=k+1; i<=n-3; i++) {
					g[i][k] = cur++;
				}
				g[n-1][k] = cur++;
				g[n-2][k] = cur++;
			}
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cout << g[i][j] << " ";
			}
			cout << nl;
		}
	}

	return 0;
}