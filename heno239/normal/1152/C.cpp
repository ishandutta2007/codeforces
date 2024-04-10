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
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef double ld;
typedef complex<ld> Point;
const ll INF = mod*mod;
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
#define fr first
#define sc second

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}
void solve() {
	ll l, r; cin >> l >> r;
	if (l > r)swap(l, r);
	if (l == r) {
		cout << 0 << endl; return;
	}
	int dif = r - l;
	int k = sqrt(dif+0.1);
	vector<ll> d;
	rep1(i, k) {
		if (dif%i == 0) {
			d.push_back(i);
			d.push_back(dif / i);
		}
	}
	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());
	ll mi = lcm(l, r); ll ans = 0;
	rep(i, d.size()) {
		ll sup = (ll)d[i] * (((ll)l + d[i] - 1) / d[i]);
		ll sup2 = sup + r - l;
		ll p = lcm(sup, sup2);
		if (p < mi) {
			mi = p; ans = sup - l;
		}
	}
	cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
		return 0;
}