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
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

ll dp[300001][5];
void solve() {
	int n, x; cin >> n >> x;
	vector<ll> a(n); rep(i, n)cin >> a[i];
	rep1(i, n) {
		rep(j, 5) {
			dp[i][j] = -INF;
		}
	}
	rep(i, n) {
		ll ma = -INF;
		rep(j, 5) {
			ma = max(dp[i][j], ma);
			if (j == 0 || j == 4)dp[i + 1][j] = ma;
			else if (j == 1 || j == 3)dp[i + 1][j] = ma + a[i];
			else dp[i + 1][j] = ma + x * a[i];
		}
		/*dp[i + 1][0] = dp[i][0];
		dp[i + 1][1] = max(dp[i][1], dp[i][0]) + a[i];
		dp[i + 1][2] = max(dp[i][1], dp[i][2]) + x * a[i];
		dp[i + 1][3] = max(dp[i][3], dp[i][2]) +a[i];
		dp[i + 1][4] = max(dp[i][4], dp[i][3]);*/
		rep(j, 5)dp[i + 1][j] = max(dp[i + 1][j], -INF);
	}
	ll ans = 0;
	rep(i, 5) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
		return 0;
}