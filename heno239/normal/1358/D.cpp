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

ll calc(ll x) {
	return x * (x + 1) / 2;
}
void solve() {
	int n; cin >> n;
	ll x; cin >> x;
	vector<int> d(n);
	rep(i, n)cin >> d[i];
	rep(i, n)d.push_back(d[i]);
	P le = { 0,1 };
	P ri;
	ll sum = 0;
	ll cop = x;
	rep(i, n) {
		if (d[i] <= cop) {
			cop -= d[i];
			sum += calc(d[i]);
		}
		else {
			ri = { i,cop };
			sum += calc(cop);
			break;
		}
	}
	ll ans = sum;
	while (le.first < n) {
		ll m = min(d[le.first] - le.second + 1,d[ri.first]-ri.second);
		sum += calc(le.second-1);
		sum-= calc(le.second + m-1);
		sum += calc(ri.second + m);
		sum -= calc(ri.second);
		le.second += m;
		if (le.second > d[le.first]) {
			le.first++;
			le.second = 1;
		}
		ri.second += m;
		if (ri.second == d[ri.first]) {
			ri.first++;
			ri.second = 0;
		}
		
		ans = max(ans, sum);
	}
	cout << ans << "\n";
}




signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	solve();
	stop
		return 0;
}