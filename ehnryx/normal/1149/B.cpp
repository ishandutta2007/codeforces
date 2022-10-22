#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
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

const int N = 1e5+1;
const int M = 250+1;

vector<int> adj[N];
vector<int> idx[26];
int dp[M][M][M];
int p[3];
char val[3][M];

vector<function<void(void)>> update = {
	[&] () {
		int c, n=N;
		int i = p[0];
		FOR(j,0,p[1]) {
			FOR(k,0,p[2]) {
				dp[i][j][k] = INF;
				c = val[0][i]-'a';
				if (i>0) dp[i][j][k] = min(dp[i][j][k], *upper_bound(idx[c].begin(), idx[c].end(), min(n,dp[i-1][j][k])));
				c = val[1][j]-'a';
				if (j>0) dp[i][j][k] = min(dp[i][j][k], *upper_bound(idx[c].begin(), idx[c].end(), min(n,dp[i][j-1][k])));
				c = val[2][k]-'a';
				if (k>0) dp[i][j][k] = min(dp[i][j][k], *upper_bound(idx[c].begin(), idx[c].end(), min(n,dp[i][j][k-1])));
			}
		}
	},
	[&] () {
		int c, n=N;
		int j = p[1];
		FOR(i,0,p[0]) {
			FOR(k,0,p[2]) {
				dp[i][j][k] = INF;
				c = val[0][i]-'a';
				if (i>0) dp[i][j][k] = min(dp[i][j][k], *upper_bound(idx[c].begin(), idx[c].end(), min(n,dp[i-1][j][k])));
				c = val[1][j]-'a';
				if (j>0) dp[i][j][k] = min(dp[i][j][k], *upper_bound(idx[c].begin(), idx[c].end(), min(n,dp[i][j-1][k])));
				c = val[2][k]-'a';
				if (k>0) dp[i][j][k] = min(dp[i][j][k], *upper_bound(idx[c].begin(), idx[c].end(), min(n,dp[i][j][k-1])));
			}
		}
	},
	[&] () {
		int c, n=N;
		int k = p[2];
		FOR(i,0,p[0]) {
			FOR(j,0,p[1]) {
				dp[i][j][k] = INF;
				c = val[0][i]-'a';
				if (i>0) dp[i][j][k] = min(dp[i][j][k], *upper_bound(idx[c].begin(), idx[c].end(), min(n,dp[i-1][j][k])));
				c = val[1][j]-'a';
				if (j>0) dp[i][j][k] = min(dp[i][j][k], *upper_bound(idx[c].begin(), idx[c].end(), min(n,dp[i][j-1][k])));
				c = val[2][k]-'a';
				if (k>0) dp[i][j][k] = min(dp[i][j][k], *upper_bound(idx[c].begin(), idx[c].end(), min(n,dp[i][j][k-1])));
			}
		}
	}
};

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;

	For(i,n) {
		idx[s[i]-'a'].push_back(i+1);
	}
	For(i,26) {
		idx[i].push_back(INF);
	}

	For(i,m) {
		char t; int id;
		cin >> t >> id;
		--id;

		if (t == '+') {
			cin >> val[id][++p[id]];
			update[id]();
		} else {
			--p[id];
		}

		if (dp[p[0]][p[1]][p[2]] <= n) {
			cout << "YES" << nl;
		} else {
			cout << "NO" << nl;
		}
	}

	return 0;
}