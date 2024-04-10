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
const ll mod = 998244353;
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
typedef vector<int> vec;

ll mod_pow(ll x, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n % 2)res = res * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return res;
}
ll mod_inv(ll x) {
	return mod_pow(x, mod - 2);
}
int cnt[1 << 20];
vector<int> v[1 << 20];
void solve() {
	int n; cin >> n;
	ll sum = 0;
	rep(i, n) {
		int k; cin >> k; sum += k;
		rep(j, k) {
			int x; cin >> x;
			v[i].push_back(x);
			cnt[x]++;
		}
	}
	sum *= n;
	ll csum = 0;
	ll invn = mod_inv(n);
	rep(i, n) {
		ll invk = mod_inv(v[i].size());
		ll s = invn * invn%mod*invk%mod;
		rep(j, v[i].size()) {

			int c = cnt[v[i][j]];
			ll pro = s * c%mod;
			csum += pro;
		}
	}
	csum %= mod;
	cout << csum << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
	return 0;
}