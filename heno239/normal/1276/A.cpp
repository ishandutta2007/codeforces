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
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;
typedef pair<int, bool> sP;
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
	int t; cin >> t;
	rep(aa, t) {
		string s; cin >> s;
		int n = s.size();
		vector<int> ans;
		rep(i, n - 3 + 1) {
			if (i + 5 <= n) {
				string u = s.substr(i, 5);
				if (u == "twone") {
					ans.push_back(i + 2);
					i += 4;
					continue;
				}
			}
			string u = s.substr(i, 3);
			if (u == "one" || u == "two") {
				ans.push_back(i + 1);
				i += 2;
			}
		}
		cout << ans.size() << "\n";
		rep(i, ans.size()) {
			if (i > 0)cout << " ";
			cout << ans[i] + 1;
		}
		cout << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	//stop
	return 0;
}