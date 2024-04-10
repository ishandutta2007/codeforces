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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
vector<LP> a,b;
int x[1 << 19];
ll mod_pow(ll x,ll n) {
	ll res = 1;
	while (n) {
		if (n % 2)(res *= x)%=mod;
		(x *= x) %= mod; n >>= 1;
	}
	return res;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	rep(i, n) {
		cin >> x[i];
		a.push_back({ x[i],i });
	}
	b = a;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<LP>());
	ll out = 0;
	rep(i, n) {
		int rest = n - i - 1;
		out -= a[i].first*mod_pow(2, rest) % mod;
		out += a[i].first;
		out = (out + mod) % mod;
	}
	rep(i, n) {
		int rest = n - i - 1;
		out += b[i].first*mod_pow(2, rest) % mod;
		out -= b[i].first;
		out = (out + mod) % mod;
	}
	cout << out << endl;
	//stop
	return 0;
}