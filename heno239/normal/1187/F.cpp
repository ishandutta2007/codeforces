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

typedef long long ll;
#define int long long

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<LP> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

ll mod_pow(ll x, ll n) {
	ll ret = 1;
	while (n > 0) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
}


void solve() {
	int n; cin >> n;
	vector<ll> l(n), r(n),len(n);
	rep(i, n)cin >> l[i];
	rep(i, n)cin >> r[i];
	rep(i, n) {
		len[i] = (r[i] - l[i] + 1);
	}
	vector<ll> p(n);
	p[0] = 1;
	rep(i, n - 1) {
		ll b = len[i] * len[i + 1] % mod;
		ll le = max(l[i], l[i + 1]);
		ll ri = min(r[i], r[i + 1]);
		ll a = (ri - le + 1); if (a < 0)a = 0;
		p[i+1] = a*mod_pow(b,mod-2) % mod;
		p[i + 1] = (1 - p[i + 1] + mod) % mod;
	}
	ll ans = 0;
	ll sum = 0;
	rep(i, n) {
		sum += p[i]; if (sum >= mod)sum -= mod;
	}
	rep(i, n) {
		//cout << p[i] << endl;
		ll csum = sum;
		if (i - 1 >= 0)csum -= p[i - 1];
		if (i + 1 < n)csum -= p[i + 1];
		csum -= p[i];
		while (csum < 0)csum += mod;
		ans += p[i] * csum%mod; if (ans >= mod)ans -= mod;
	}
	ans += sum; if (ans >= mod)ans -= mod;
	{
		if (n > 1) {
			ans += 2 * p[1]; ans %= mod;
		}
	}

	rep(i, n - 2) {
		ll csum = 0;
		ll le = max({ l[i],l[i + 1],l[i + 2] });
		ll ri = min({ r[i],r[i + 1],r[i + 2] });
		ll a = ri - le + 1; if (a < 0)a = 0;
		ll b = len[i] * len[i + 1] % mod*len[i + 2] % mod;
		b = mod_pow(b, mod - 2);
		a = a * b%mod;
		csum += 1 + a - (1 - p[i + 1])-(1- p[i + 2]);
		csum = (csum%mod + mod) % mod;
		//cout << csum << endl;
		ans += 2 * csum; ans %= mod;
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cout << fixed << setprecision(10);
	//init();
	solve();
	//stop
		return 0;
}