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
#include<set>

using namespace std;

//#define int long long

using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const ll INF = (1e+18) + 100;
const ll mod = 1000000007;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repl(i, l, n) for(int i=l;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define stop char nyaa;cin>>nyaa;

typedef long double ld;
const ld eps = 1e-8;

vector<int> G1[2000], G2[2000];
int par1[2000], par2[2000];
int r1[1000], r2[1000];
int val1[1000][1000], val2[1000][1000];
int deg1[2000], deg2[2000];

int dp[1001][2];
void solve() {
	int n; cin >> n;
	if (n == 1) {
		int x; cin >> x;
		rep(j, x-1) {
			int t; cin >> t;
		}
		rep(j, n) {
			int t; cin >> t;
		}
		int y; cin >> y;
		rep(j, y-1) {
			int t; cin >> t;
		}
		rep(j, n) {
			int t; cin >> t;
		}
		cout << max(x, y)-1 << endl; return;
	}
	int x; cin >> x;
	rep(i, x - 1) {
		int p; cin >> p; p--;
		par1[i + 1] = p;
		G1[p].push_back(i + 1);
	}
	rep(i, n) {
		int p; cin >> p; p--;
		r1[i] = p;
	}
	int y; cin >> y;
	rep(i, y - 1) {
		int p; cin >> p; p--;
		par2[i + 1] = p;
		G2[p].push_back(i + 1);
	}
	rep(i, n) {
		int p; cin >> p; p--;
		r2[i] = p;
	}
	par1[0] = par2[0] = -1;
	rep(i, n) {
		rep(j, x)deg1[j] = G1[j].size();
		rep(j, y)deg2[j] = G2[j].size();
		int nd1 = r1[i], nd2 = r2[i];
		deg1[par1[nd1]]--; deg2[par2[nd2]]--;
		int cnt1 = 0, cnt2 = 0;
		while (nd1 > 0 && deg1[nd1] == 0) {
			cnt1++;
			nd1 = par1[nd1];
			if (deg1[nd1]==0&&par1[nd1] >= 0)deg1[par1[nd1]]--;
		}
		val1[i][i] = cnt1;
		while (nd2 > 0 && deg2[nd2] == 0) {
			cnt2++;
			nd2 = par2[nd2];
			if (deg2[nd2]==0&&par2[nd2] >= 0)deg2[par2[nd2]]--;
		}
		val2[i][i] = cnt2;
		Rep(j, i + 1, n) {
			int nex1 = r1[j];
			deg1[par1[nex1]]--;
			while (nex1>0 && deg1[nex1] == 0) {
				cnt1++;
				nex1 = par1[nex1];
				if (deg1[nex1]==0&&par1[nex1] >= 0)deg1[par1[nex1]]--;
			}
			val1[i][j] = cnt1;
			int nex2 = r2[j];
			deg2[par2[nex2]]--;
			while (nex2 > 0 && deg2[nex2] == 0) {
				cnt2++;
				nex2 = par2[nex2];
				if (deg2[nex2]==0&&par2[nex2] >= 0)deg2[par2[nex2]]--;
			}
			val2[i][j] = cnt2;
		}

	}
	dp[0][0] = dp[0][1] = 0;
	rep1(i, n) {
		int ma0 = 0, ma1 = 0;
		rep(j, i) {
			ma0 = max(ma0, dp[j][1] + val2[j][i - 1]);
			ma1 = max(ma1, dp[j][0] + val1[j][i - 1]);
		}
		dp[i][0] = ma0;
		dp[i][1] = ma1;
	}
	int ans = max(dp[n][0], dp[n][1]);
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	solve();
	//stop
	return 0;
}