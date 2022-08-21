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
const ll mod = 1000000007;
typedef long double ld;
const ll INF = 1e+14;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

const int sup = 8 * 840+1;
void solve() {
	ll w; ll c[8];
	ll dp[9][sup];
	cin >> w;
	rep(i, 8)cin >> c[i];
	rep(i, 9) {
		rep(j, sup) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	rep(i, 8) {
		rep(j, sup) {
			if (dp[i][j] < 0)continue;
			rep(k, 840 / (i+1)) {
				if (k > c[i])continue;
				ll sum = j + k * (i + 1);
				if (sum >= sup)continue;
				ll r = c[i] - k;
				r /= (840 / (i + 1));
				dp[i + 1][sum] = max(dp[i + 1][sum], dp[i][j] + r);
			}
		}
	}
	ll ans = 0;
	rep(j, sup) {
		if (dp[8][j] < 0)continue;
		if (j > w)continue;
		ll dif = w - j;
		ll m = dif / 840;
		m = min(m, dp[8][j]);
		ans = max(ans, j + m * 840);
	}
	cout << ans << endl;
}
int main() {
	solve();
	//stop
	return 0;
}