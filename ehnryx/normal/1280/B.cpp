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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 60+1;
char g[N][N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	const int A = 'A';
	const int P = 'P';

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		bool god = true;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin >> g[i][j];
				god &= (g[i][j] == 'A');
			}
		}
		if(god) {
			cout << 0 << nl;
			continue;
		}

		int left, right;
		left = right = 0;
		for(int i=0; i<n; i++) {
			left += g[i][0];
			right += g[i][m-1];
		}
		if(left == A*n || right == A*n) {
			cout << 1 << nl;
			continue;
		}

		left = right = 0;
		for(int j=0; j<m; j++) {
			left += g[0][j];
			right += g[n-1][j];
		}
		if(left == A*m || right == A*m) {
			cout << 1 << nl;
			continue;
		}

		left = 0;
		for(int i=0; i<n; i++) {
			bool bad = false;
			for(int j=0; j<m; j++) {
				bad |= (g[i][j] != 'A');
			}
			if(!bad) {
				left = 1;
				break;
			}
		}

		right = 0;
		for(int j=0; j<m; j++) {
			bool bad = false;
			for(int i=0; i<n; i++) {
				bad |= (g[i][j] != 'A');
			}
			if(!bad) {
				right = 1;
				break;
			}
		}

		if(left || right) {
			cout << 2 << nl;
			continue;
		}

		if(g[0][0] == 'A' || g[0][m-1] == 'A' || g[n-1][0] == 'A' || g[n-1][m-1] == 'A') {
			cout << 2 << nl;
			continue;
		}

		left = right = 0;
		for(int i=0; i<n; i++) {
			left |= (g[i][0] == 'A');
			right |= (g[i][m-1] == 'A');
		}
		if(left || right) {
			cout << 3 << nl;
			continue;
		}

		left = right = 0;
		for(int j=0; j<m; j++) {
			left |= (g[0][j] == 'A');
			right |= (g[n-1][j] == 'A');
		}
		if(left || right) {
			cout << 3 << nl;
			continue;
		}

		bool ok = false;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				ok |= (g[i][j] == 'A');
			}
		}
		if(ok) {
			cout << 4 << nl;
		} else {
			cout << "MORTAL" << nl;
		}
	}

	return 0;
}