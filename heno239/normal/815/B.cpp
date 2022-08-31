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
const ll mod = (ll)(1e+9) + 7;
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
const ld eps = 1e-12;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
ll a[1 << 18],b[1<<18];
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
const int N_MAX = 1 << 18;
ll p[N_MAX];
void init() {
	p[0] = 1;
	rep1(i, N_MAX - 1) {
		p[i] = p[i - 1] * i%mod;
	}
}
//xCy
ll comb(ll x, ll y, ll m) {
	if (x < y)return 0;
	ll res = p[x];
	(res *= mod_inverse(p[y], m)) %= mod;
	(res *= mod_inverse(p[x - y], m)) %= mod;
	return res;
}
int main() {
	init();
	int n; cin >> n;
	rep(i, n) {
		scanf(" %lld", &b[i]);
		//cin >> b[i];
	}
	if (n == 1) {
		cout << b[0] << endl; return 0;
	}
	if (n % 2) {
		n--;
		rep(i, n) {
			if (i % 2) {
				a[i] = b[i] - b[i + 1];
			}
			else {
				a[i] = b[i] + b[i + 1];
			}
		}
	}
	else {
		rep(i, n) {
			a[i] = b[i];
		}
	}
	ll le = 0, ri = 0;
	for (int i = 0; i < n;i+=2) {
		int l = i / 2;
		int r = n / 2 - l - 1;
		le = ((le + comb(l + r, l, mod)*a[i] % mod) % mod + mod) % mod;
	}
	for (int i = 1; i < n; i += 2) {
		int l = i / 2;
		int r = n / 2 - l - 1;
		ri = ((ri + comb(l + r, l, mod)*a[i] % mod) % mod + mod) % mod;
	}
	if (n % 4 == 0) {
		cout << (le - ri + mod) % mod << endl;
	}
	else {
		cout << (le + ri) % mod << endl;
	}
	return 0;
}