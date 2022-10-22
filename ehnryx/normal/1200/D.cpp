#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	cin >> n >> k;
	string grid[n], trans[n];
	For(i,n) {
		cin >> grid[i];
		For(j,n) {
			trans[j].push_back(grid[i][j]);
		}
	}

	int last[n];
	int ans[n][n];
	memset(ans, 0, sizeof ans);

	For(i,n) {
		last[i] = grid[i].find_last_of('B');
	}
	For(j,n-k+1) {
		int cnt = 0;
		For(i,n) {
			if (i<k) cnt += (last[i] < j+k);
			else cnt += (last[i] < 0);
		}
		ans[0][j] += cnt;
		for (int i=k; i<n; i++) {
			cnt += (last[i-k] < 0) - (last[i-k] < j+k);
			cnt += (last[i] < j+k) - (last[i] < 0);
			ans[i-k+1][j] += cnt;
		}
		For(i,n) {
			if (grid[i][j] == 'B') {
				last[i] = INF;
			}
		}
	}

	For(i,n) {
		last[i] = trans[i].find_last_of('B');
	}
	For(j,n-k+1) {
		int cnt = 0;
		For(i,n) {
			if (i<k) cnt += (last[i] < j+k);
			else cnt += (last[i] < 0);
		}
		ans[j][0] += cnt;
		for (int i=k; i<n; i++) {
			cnt += (last[i-k] < 0) - (last[i-k] < j+k);
			cnt += (last[i] < j+k) - (last[i] < 0);
			ans[j][i-k+1] += cnt;
		}
		For(i,n) {
			if (trans[i][j] == 'B') {
				last[i] = INF;
			}
		}
	}

	cout << *max_element(&ans[0][0], &ans[0][0]+n*n) << nl;

	return 0;
}