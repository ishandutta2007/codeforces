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
#include<utility>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<cassert>
#include<random>
#include<unordered_map>
#include<numeric>
using namespace std;
using ll = long long;
const ll mod = 1000000009;
const ll INF = mod * mod;

#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa;cin>>nyaa;

using ld = long double;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);


ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
void solve() {
	ll r, b, k; cin >> r >> b >> k;
	ll g = gcd(r, b);
	r /= g; b /= g;
	if (r < b)swap(r, b);
	if (r <= 2) {
		cout << "OBEY" << endl; return;
	}
	ll num = (r - 2) / b + 1;
	if (num >= k) {
		cout << "REBEL" << endl;
	}
	else {
		cout << "OBEY" << endl;
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t; cin >> t;rep(i,t) solve();
	stop
	return 0;
}