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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
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
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
ll dp[1000001];
ll p[1000001];
void init() {
	p[0] = 1;
	p[1] = 1; dp[1] = 0;
	for (ll i = 2; i <= 1000000; i++) {
		p[i] = p[i - 1] * i%mod;
	}
	for (ll i = 2; i <= 1000000; i++) {
		dp[i] = dp[i - 1] * i%mod + (i*(i - 1) / 2) % mod*p[i - 1] % mod;
		dp[i] %= mod;
	}
}
ll bit[1 << 20]; int n;
void add(int a, ll w) {
	for (int i = a; i <= n + 1; i += i & -i)bit[i] += w;
}
ll sum(int a) {
	ll ret = 0;
	for (int i = a; i > 0; i -= i & -i)ret += bit[i];
	return ret;
}
int a[1000000];
int main(){
	init();
	cin >> n;
	rep(i, n) {
		cin >> a[i];
	}
	ll ans = 0;
	ll k = 0;
	rep(i, n-1) {
		ll t = a[i] - sum(a[i])-1;
		(ans += t * dp[n-i-1] % mod) %= mod;
		ll csum = (((k + t - 1)*(k + t) / 2) % mod - (k*(k - 1) / 2) % mod + mod) % mod;
		(ans += csum * p[n - i-1] % mod) %= mod;
		add(a[i], 1);
		(k += t) %= mod;
	}
	(ans += k) %= mod;
	cout << ans << endl;
	return 0;
}