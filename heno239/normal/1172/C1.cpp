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
#include<cassert>
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
typedef double ld;
typedef complex<ld> Point;
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
typedef vector<int> vec;
typedef vector<string> svec;

ll mod_pow(ll x, ll n) {
	x %= mod;
	ll ret = 1;
	while (n) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
}

//me,all_sub
ll dp[52][52];
ll cop[52][52];
void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	vector<int> w(n);
	int sum = 0;
	int cnt = 0;
	int adsum = 0;
	int decsum = 0;
	rep(i, n) {
		cin >> a[i];
		if (a[i])cnt++;
	}
	rep(i, n) {
		cin >> w[i]; sum += w[i];
	}
	rep(i, n) {
		if (a[i])adsum += w[i];
		else decsum += w[i];
	}
	rep(i, n) {
		//cout << i << endl;
		int id = -1;
		if (a[i])id = 1;
		rep(j, m + 2)rep(k, m + 2)dp[j][k] = 0;
		dp[0][0] = 1;
		rep(j, m) {
			rep(k, j + 2)rep(l, j + 2)cop[k][l] = 0;
			rep(k, j + 1) {
				ll cur = w[i]+id*k;
				rep(l, j + 1) {
					ll al = sum - l + j - l;
					//me
					int nl = l + 1;
					if (a[i])nl = l;
					(cop[k + 1][nl] += dp[k][l] * cur%mod*mod_pow(al, mod - 2) % mod)%=mod;
					//non
					ll decs = decsum - l;
					if (!a[i])decs -= (w[i] - k);
					ll pdec = decs * mod_pow(al, mod - 2) % mod;
					//dec
					(cop[k][l + 1] += dp[k][l] * pdec%mod) %= mod;
					//add
					ll ads = adsum + j - l;
					if (a[i])ads -= (w[i] + k);
					ll adp = ads * mod_pow(al, mod - 2) % mod;
					(cop[k][l] += dp[k][l] * adp%mod) %= mod;
				}
			}
			rep(k, j + 2)rep(l, j + 2)dp[k][l] = cop[k][l];
		}
		ll ans = 0;
		rep(j, m + 1) {
			ll csum = 0;
			rep(k, m + 1) {
				//cout << j << " " << k << " " << dp[j][k] << endl;
				csum = (csum + dp[j][k]) % mod;
			}
			csum = csum * (w[i] + id * j) % mod;
			ans += csum;
		}
		cout << ans % mod << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//while (cin >> n,n)solve();
	solve();
	//stop
	return 0;
}