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
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e3 + 2;
char g[N][N];
int dsu[N*N];
int find(int i) {
	if(dsu[i] == 0) return i;
	return dsu[i] = find(dsu[i]);
}
int link(int i, int j) {
	i = find(i); j = find(j);
	if(i == j) return 0;
	dsu[i] = j;
	return 1;
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;
	set<int> row, col;
	int groups = 0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> g[i][j];
			if(g[i][j] == '#') {
				row.insert(i);
				col.insert(j);
				groups++;
				if(g[i-1][j] == '#') {
					groups -= link(i*N+j, (i-1)*N + j);
				}
				if(g[i][j-1] == '#') {
					groups -= link(i*N+j, i*N + (j-1));
				}
			}
		}
	}

	if((row.size() < n) ^ (col.size() < m)) {
		cout << -1 << nl;
		return 0;
	}

	bool ok = true;
	for(int i=1; ok && i<=n; i++) {
		int cnt = 0;
		int first = -1;
		int last = -2;
		for(int j=1; j<=m; j++) {
			if(g[i][j] == '#') {
				if(first == -1) first = j;
				last = j;
				cnt++;
			}
		}
		ok &= (cnt == last - first + 1);
	}
	for(int j=1; ok && j<=m; j++) {
		int cnt = 0;
		int first = -1;
		int last = -2;
		for(int i=1; i<=n; i++) {
			if(g[i][j] == '#') {
				if(first == -1) first = i;
				last = i;
				cnt++;
			}
		}
		ok &= (cnt == last - first + 1);
	}

	if(ok) {
		cout << groups << nl;
	} else {
		cout << -1 << nl;
	}

	return 0;
}