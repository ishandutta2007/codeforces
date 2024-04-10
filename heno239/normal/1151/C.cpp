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
typedef unsigned long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
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
#define fr first
#define sc second

vector<LP> v;
void init() {
	ll ml = 1, mr = 2;
	rep(i, 60) {
		ll num = (ll)1 << i;
		if (i % 2 == 0) {
			v.push_back({ ml,num });
			ml += 2 * num;
		}
		else {
			v.push_back({ mr,num });
			mr += 2 * num;
		}
		//cout << ml << " " << mr << endl;
	}
}
//[1,x]
ll calc(ll x) {
	ll ret = 0;
	rep(i, 60) {
		ll num = v[i].second;
		if (x > num) {
			x -= num;
			ret = (ret+v[i].first%mod*(v[i].second%mod)%mod)%mod;
			ret = (ret + num % mod*((num - 1) % mod)) % mod;
		}
		else {
			ret = (ret + v[i].first%mod*(x%mod) % mod)%mod;
			ret = (ret + x % mod*((x - 1) % mod)%mod) % mod;
			break;
		}
	}
	return ret;
}
void solve() {
	init();
	ll l, r; cin >> l >> r;
	cout << (calc(r) - calc(l - 1)+mod)%mod << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}