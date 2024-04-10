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
typedef vector<int> vec;

void debug(vec &v) {
	int n = v.size();
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << v[i];
	}
	cout << "\n";
}

void solve() {
	int n; cin >> n;
	vector<int> a(n+1);
	rep1(i, n)cin >> a[i];
	int cur = 1;
	vector<int> v; v.push_back(cur);
	vector<bool> used(n + 1, false);
	used[cur] = true;
	while (!used[cur - a[cur]]) {
		cur = cur - a[cur]; v.push_back(cur); used[cur] = true;
	}
	int last = cur - a[cur];
	vector<int> ans; ans.push_back(last);
	while (v.back() != last) {
		ans.push_back(v.back()); v.pop_back();
	}
	cout << ans.size() << "\n";
	debug(ans);
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	//init();
	int t; cin >> t; rep(i, t)solve();
	//solve();
	stop
	return 0;
}