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
const ll mod = 1000000007;
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
typedef vector<ll> vec;

void debug(vec &v) {
	int n = v.size();
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << v[i];
	}
	cout << "\n";
}

ll c[2600];
void init() {
	rep(i, 3)c[i] = 0;
	for (ll i = 3; i <= 2500; i++) {
		c[i] = i * (i - 1)*(i - 2) / 6;
	}
}

ll x[2500], y[2500];
bool isclock(int i, int j, int k) {
	ll x1 = x[i] - x[j]; ll x2 = x[k] - x[j];
	ll y1 = y[i] - y[j]; ll y2 = y[k] - y[j];
	return x1 * y2-x2*y1>0;
}
void solve() {
	init();
	int n; cin >> n;
	rep(i, n) {
		cin >> x[i] >> y[i];
	}
	//cout << isclock(3, 0, 2) << endl;
	ll ans = 0;
	ll pro = (ll)(n - 1)*(n - 2)*(n - 3)*(n - 4) / 24;
	rep(i, n) {
		vector<pair<ld,int>> v;
		rep(j, n)if (i != j) {
			ld dx = x[j] - x[i], dy = y[j] - y[i];
			v.push_back({ atan2(dy, dx),j });
		}
		sort(v.begin(), v.end());
		rep(j, n - 1)v.push_back({ 0,v[j].second });
		int ri = 0;
		ll csum = pro;
		rep(j, n - 1) {
			ri = max(ri, j + 2);
			while (ri + 1 < v.size()&& isclock(v[j].second,i,v[ri+1].second))ri++;
			
			csum -= c[ri-j];
		}
		ans += csum;
		//cout << i << " " << csum << endl;
	}
	cout << ans << endl;
}



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(17);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
	return 0;
}