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
const ll mod = 1000000007;
typedef long double ld;
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
const ld eps = 1e-4;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
typedef vector<string> svec;

ll mod_pow(ll x, ll n) {
	ll ret = 1;
	while (n) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
}
int n, m;

void solve() {
	cin >> n >> m;
	ll inv = mod_pow(m, mod - 2);
	vector<int> a(n), b(n);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> b[i];
	}
	ll ans = 0;
	ll pro = 1;
	rep(i, n) {
		if (a[i] > 0 && b[i] > 0) {
			if (a[i] < b[i]) {
				break;
			}
			else if (a[i] > b[i]) {
				ans = (ans + pro) % mod; break;
			}
			else continue;
		}
		else if (a[i] > 0) {
			ll u = (a[i] - 1)*inv%mod;
			ans = (ans + u * pro) % mod;
			pro = pro * inv%mod;
		}
		else if (b[i] > 0) {
			ll u = (m - b[i])*inv%mod;
			ans = (ans + u * pro) % mod;
			pro = pro * inv%mod;
		}
		else {
			ll t = (ll)m * (m - 1) / 2; t %= mod;
			t = t * inv%mod*inv%mod;
			ans = (ans + t * pro) % mod;
			pro = pro * inv%mod;
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(11);
	/*while (cin >> n, n) {
		solve();
	}*/
	solve();
	//stop
	return 0;
}