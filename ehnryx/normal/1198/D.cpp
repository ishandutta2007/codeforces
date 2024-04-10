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

const int N = 50+1;
char grid[N][N];
int pre[N][N];
int dp[N][N][N][N];

int sum(int a, int b, int x, int y) {
	return pre[x][y] + pre[a-1][b-1] - pre[x][b-1] - pre[a-1][y];
}

int solve(int a, int b, int x, int y) {
	if (a>x || b>y) return 0;
	if (dp[a][b][x][y] != -1) return dp[a][b][x][y];
	if (sum(a,b,x,y) == 0) return dp[a][b][x][y] = 0;
	int res = max(x-a, y-b) + 1;
	for (int i=a; i<=x; i++) {
		if (sum(i,b,i,y) == 0 && solve(a,b,i-1,y) < res) {
			res = min(res, solve(a,b,i-1,y) + solve(i+1,b,x,y));
		}
	}
	for (int j=b; j<=y; j++) {
		if (sum(a,j,x,j) == 0 && solve(a,b,x,j-1) < res) {
			res = min(res, solve(a,b,x,j-1) + solve(a,j+1,x,y));
		}
	}
	return dp[a][b][x][y] = res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	memset(dp, -1, sizeof dp);

	int n;
	cin >> n;

	FOR(i,1,n) {
		FOR(j,1,n) {
			cin >> grid[i][j];
			pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + (grid[i][j] == '#');
		}
	}
	cout << solve(1,1,n,n) << nl;

	return 0;
}