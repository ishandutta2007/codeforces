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
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;



void solve() {
	int n, m; cin >> n >> m;
	vector<ll> c(n);
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		ll x; cin >> x;
		c[a] += x; c[b] -= x;
	}
	vector<LP> ps, ns;
	rep(i, n) {
		if (c[i] > 0)ps.push_back({ c[i],i });
		else if (c[i] < 0)ns.push_back({ -c[i],i });
	}
	vector<pair<P, ll>> ans;
	int loc = 0;
	rep(i, ps.size()) {
		ll d = min(ps[i].first,ns[loc].first);
		ans.push_back({ {ps[i].second,ns[loc].second},d });
		ps[i].first -= d;
		ns[loc].first -= d;
		if (ps[i].first > 0)i--;
		if (ns[loc].first == 0)loc++;
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) {
		int l = ans[i].first.first;
		int r = ans[i].first.second;
		ll x = ans[i].second;
		cout << l + 1 << " " << r + 1 << " " << x << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(4);
	//init();
	solve();
	stop
		return 0;
}