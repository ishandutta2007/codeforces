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
typedef pair<int, bool> sP;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

ll dp[2001][2001][2];
ll add[2001][2001][2];

int h, w;
bool b[2001][2001];

int rh[2001][2001];
int rw[2001][2001];
void solve(){
	cin >> h >> w;
	rep(i, h) {
		string s; cin >> s;
		rep(j, w) {
			b[i][j] = (s[j] == 'R');
		}
	}
	if (h == 1 && w == 1) {
		cout << 1 << endl; return;
	}
	rep(i, h) {
		rep(j, w) {
			rh[i][j + 1] += rh[i][j]+b[i][j];
		}
	}
	dp[0][0][0] = dp[0][0][1] = 1;
	rep(i, w)rep(j, h) {
		rw[i][j + 1] += rw[i][j] + b[j][i];
	}
	rep(i, h)rep(j, w) {
		if (i > 0) {
			add[i][j][1] += add[i - 1][j][1];
			if (add[i][j][1] >= mod)add[i][j][1] -= mod;
		}
		if (j > 0) {
			add[i][j][0] += add[i][j - 1][0];
			if (add[i][j][0] >= mod)add[i][j][0] -= mod;
		}
		rep(k, 2) {
			dp[i][j][k] += add[i][j][k];
			if (dp[i][j][k] >= mod)dp[i][j][k] -= mod;
		}
		//under
		int num = rw[j][h] - rw[j][i + 1];
		add[i + 1][j][1] += dp[i][j][0];
		if (add[i+1][j][1] >= mod)add[i + 1][j][1] -= mod;
		add[h - num][j][1] -= dp[i][j][0];
		if (add[h - num][j][1] < 0)add[h - num][j][1] += mod;
		//side
		num = rh[i][w] - rh[i][j + 1];
		add[i][j + 1][0] += dp[i][j][1];
		if (add[i][j+1][0] >= mod)add[i][j+1][0] -= mod;
		add[i][w-num][0] -= dp[i][j][1];
		if (add[i][w-num][0] < 0)add[i][w-num][0] += mod;
	}
	ll ans = dp[h - 1][w - 1][0] + dp[h - 1][w - 1][1];
	/*rep(i, h)rep(j, w)rep(k, 2) {
		cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
	}*/
	cout << ans % mod << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	//stop
	return 0;
}