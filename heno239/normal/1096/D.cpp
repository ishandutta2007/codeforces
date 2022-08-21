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
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int n;
string s;
ll a[1 << 17];
ll dp[1 << 17][5];
string z = "hard";
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> s;
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n + 1) {
		rep(j, 5) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	rep(i, n) {
		rep(j, 4) {
			if (s[i] == z[j]) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]+a[i]);
			}
			else {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			}
		}
	}
	ll ans = INF;
	rep(j, 4) {
		ans = min(ans, dp[n][j]);
	}
	cout << ans << endl;
	//stop
	return 0;
}