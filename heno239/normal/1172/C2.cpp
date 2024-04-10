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
ll dp[3001];
void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	vector<int> w(n);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> w[i];
	}
	vector<int> na = { 0,1 }, nw(2);
	rep(i, n) {
		if (a[i]) {
			nw[1] += w[i];
		}
		else {
			nw[0] += w[i];
		}
	}
	ll sum = nw[0] + nw[1];
	dp[0] = 1;
	rep(i, m) {

		per(j, i + 1) {
			ll al = sum+i-2*j;
			ll ads = nw[1] + i - j;
			ll adp = ads * mod_pow(al, mod - 2) % mod;
			ll decp = (mod + 1 - adp) % mod;
			(dp[j + 1] += decp * dp[j] % mod)%=mod;
			dp[j] = adp * dp[j] % mod;
		}
	}
	ll ans[2] = {};
	rep(i, m+1) {
		ll u = nw[0] - i;
		(ans[0] += u * dp[i]) %= mod;
	}
	rep(i, m + 1) {
		ll u = nw[1] + m-i;
		(ans[1] += u * dp[i]) %= mod;
	}
	rep(i, n) {
		if (a[i]) {
			ll z = w[i] * mod_pow(nw[1], mod - 2)%mod;
			z = z * ans[1] % mod;
			cout << z << endl;
		}
		else {
			ll z = w[i] * mod_pow(nw[0], mod - 2)%mod;
			z = z * ans[0] % mod;
			cout << z << endl;
		}
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