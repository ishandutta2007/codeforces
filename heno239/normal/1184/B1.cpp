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
using namespace std;

typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;

void solve() {
	int n, m; cin >> n >> m;
	vector<ll> a(n);
	rep(i, n)cin >> a[i];
	vector<LP> b(m);
	rep(i, m) {
		cin >> b[i].first >> b[i].second;
	}
	sort(b.begin(), b.end());
	vector<ll> ra(m + 1),x(m);
	rep(i, m) {
		x[i] = b[i].first;
		ra[i + 1] = ra[i] + b[i].second;
	}
	rep(i, n) {
		if (i > 0)cout << " ";
		int id = upper_bound(x.begin(), x.end(), a[i]) - x.begin();
		cout << ra[id];
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();
	//stop
	return 0;
}