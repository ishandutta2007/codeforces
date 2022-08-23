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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

void debug(vec &v) {
	int n = v.size();
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << v[i];
	}
	cout << "\n";
}

ll mod_pow(ll x, ll n) {
	ll ret = 1;
	while (n > 0) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
}


int dp[101][103][2];
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	vector<bool> exi(n + 1);
	rep(i, n) {
		cin >> a[i];
		exi[a[i]] = true;
	
	}
	vector<int> od, ev;
	rep1(i, n) {
		if (!exi[i]) {
			if (i % 2)od.push_back(i);
			else ev.push_back(i);
		}
	}
	rep(i, n + 1)rep(j,n+1)rep(k, 2)dp[i][j][k] = mod;
	dp[0][0][0] = dp[0][0][1] = 0;
	rep(i, n) {
		if (a[i] > 0) {
			int x = a[i] % 2;
			rep(j, n + 1) {
				dp[i + 1][j][x] = min(dp[i][j][x], dp[i][j][x ^ 1] + 1);
			}
		}
		else {
			rep(j, n) {
				dp[i + 1][j + 1][0] = min(dp[i][j][0], dp[i][j][1] + 1);
			}
			rep(j, n + 1) {
				dp[i + 1][j][1] = min(dp[i][j][1], dp[i][j][0] + 1);
			}
		}
	}
	int ans = min(dp[n][ev.size()][0], dp[n][ev.size()][1]);
	cout << ans << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(17);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}