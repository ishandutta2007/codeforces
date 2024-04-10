#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<utility>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<cassert>
#include<random>
#include<unordered_map>
#include<numeric>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa;cin>>nyaa;

using P = pair<int, int>;
using LP = pair<ll, ll>;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int dp[501][501];
void solve() {
	string s, t; cin >> s >> t;
	int n = s.size();
	vector<vector<int>> nex(n + 2,vector<int>(26));
	rep(j, 26) {
		nex[n][j] = nex[n + 1][j] = n;
	}
	per(i, n) {
		rep(j, 26) {
			nex[i][j] = nex[i + 1][j];
		}
		int c = s[i] - 'a';
		nex[i][c] = i;
	}
	int m = t.size();
	for (int l = 0; l < m; l++) {
		int sl = 0; int cl = l;
		int sr = l; int cr = m - l;
		rep(i, cl + 1)rep(j, cr + 1)dp[i][j] = n+1;
		dp[0][0] = 0;
		rep(i, cl + 1) {
			rep(j, cr + 1) {
				if (i<cl) {
					int c = t[sl + i] - 'a';
					dp[i + 1][j] = min(dp[i + 1][j], nex[dp[i][j]][c]+1);
				}
				if (j < cr) {
					int c = t[sr + j] - 'a';
					dp[i][j + 1] = min(dp[i][j + 1], nex[dp[i][j]][c]+1);
				}
			}
		}
		if (dp[cl][cr] <= n) {
			//cout << l << endl;
			//rep(i, cl + 1)rep(j, cr + 1)cout << i << " " << j << " " << dp[i][j] << endl;
			cout << "YES" << endl; return;
		}
	}
	cout << "NO" << endl;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t; cin >> t;rep(i,t) solve();
	//solve();
	stop
		return 0;
}