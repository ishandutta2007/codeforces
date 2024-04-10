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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> p(n);
	vector<ll> rp(n + 1);
	rep(i, n) {
		cin >> p[i];
		rp[i + 1] = rp[i] + p[i];
	}
	vector<vector<ll>> dp(n + 1,vector<ll>(k + 1,-INF));
	dp[0][0] = 0;
	rep(i, n) {
		rep(j, k + 1) {
			if (i + m <= n && j<k) {
				dp[i + m][j + 1] = max(dp[i + m][j + 1], dp[i][j] + rp[i + m] - rp[i]);
			}
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
		}
	}
	cout << dp[n][k] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();

	solve();
	stop
		return 0;
}