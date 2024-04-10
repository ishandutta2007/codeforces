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
 
//#define int long long
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
typedef vector<ll> vec;
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
 
ll num[10000];
void init() {
	for (int i = 2; i < 10000; i++) {
		num[i] = i * (i - 1) / 2;
	}
}
const int sz = 10000;
void solve() {
	int n; cin >> n;
	string ans;
	vector<int> c(sz,0);
	for (int i = sz-1; i > 0; i--) {
		if (num[i] > 0){
			c[i] += n / num[i]; n %= num[i];
		}
	}
	ans.push_back('1');
	rep(i, sz) {
		rep(j, c[i]) {
			ans.push_back('7');
		}
		ans.push_back('3');
	}
	cout << ans << endl;
}
 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	init();
	int t; cin >> t;
	rep(i, t) {
		solve();
	}
	//cout << "finish" << endl;
	//stop
	return 0;
}