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
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa;cin>>nyaa;

using P = pair<int, int>;
using LP = pair<ll, ll>;

void solve() {
	ll n, m; cin >> n >> m;
	ll ans = n * (n + 1) / 2;
	ll rest = n - m;
	ll num = m + 1;
	ll d = rest / num;
	ll r = rest % num;
	ans -= (num - r)*d*(d + 1) / 2;
	ans -= r * (d + 1)*(d+2) / 2;
	cout << ans << endl;
	
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t; cin >> t;rep(i,t) solve();
	stop
		return 0;
}