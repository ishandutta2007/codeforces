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
const ll mod = 998244353;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
ll p[1 << 20];
//x,yax+by=gcd(a,b)
ll extgcd(ll a, ll b, ll& x, ll& y) {
	ll d = a;
	if (b != 0) {
		d = extgcd(b, a%b, y, x);
		y -= (a / b)*x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}
//amod m
ll mod_inverse(ll a, ll m) {
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}
void init() {
	p[0] = 1;
	rep1(i, (1 << 20) - 1) {
		p[i] = p[i - 1] * i%mod;
	}
}
ll c[1 << 20];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	init();
	ll n; cin >> n;
	if (n == 1) {
		cout << 1 << endl; return 0;
	}
	ll k = p[n-1];
	ll csum = 0;
	rep1(i, n - 1) {
		c[i] = k * mod_inverse(p[n - i], mod) % mod;
		csum += (c[i]-c[i-1]+mod) * i%mod; csum %= mod;
	}
	cout << csum * n%mod << endl;
	return 0;
}