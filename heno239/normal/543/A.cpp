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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
//const ll mod = 1000000007;
//const ll INF = mod * mod;
typedef pair<int, int> P;
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
const ld eps = 1e-5;

//i,j
ll dp[501][501];
ll cop[501][501];
void solve(){
	int n, m, b; cin >> n >> m >> b;
	ll mod; cin >> mod;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	if(mod==1){
	    cout<<0<<endl;return;
	}
	dp[0][0] = 1;
	rep(i, m) {
		rep(j, n) {
			rep(k, b + 1) {
				cop[j][k] = 0;
			}
		}
		rep(j, n) {
			per(k, b + 1) {
				if (k + a[j] <= b) {
					cop[j][k + a[j]] += dp[j][k];
					if (cop[j][k + a[j]] >= mod)cop[j][k + a[j]]-= mod;
				}
				if (j < n - 1) {
					dp[j + 1][k] += dp[j][k];
					if (dp[j + 1][k] >= mod)dp[j + 1][k] -= mod;
				}
			}
		}
		rep(j, n) {
			rep(k, b + 1) {
				dp[j][k] = cop[j][k];
			}
		}
	}
	ll ans = 0;
	rep(i, n) {
		rep(j, b + 1) {
			ans += dp[i][j];
			if (ans >= mod)ans -= mod;
		}
	}
	cout << ans % mod << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//init();
	solve();

	//cout << "finish" << endl;
	//stop
	return 0;
}