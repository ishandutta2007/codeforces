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
#include<numeric>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);

void solve() {
	ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	ll lenx = x2 - x1 + 1;
	ll leny = y2 - y1 + 1;
	ll ans = 0;
	ll mi = min(lenx, leny);
	ans += (mi-1) * (mi - 2) / 2;
	ans += (mi-1) * (mi - 2) / 2;

	ll dif = mi - 1;
	ll num = lenx + leny - 1 - 2 * (mi-1);
	ans += dif * num;

	cout << ans+1 << "\n";
}




signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	int t; cin >> t;
	rep(i,t)solve();
	stop
		return 0;
}