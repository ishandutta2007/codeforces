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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	int c[2] = {};
	rep(i, n) {
		if (a[i] == 1)c[0]++;
		else c[1]++;
	}
	vector<int> ans;
	if (c[0]>=3) {
		rep(i, 3)ans.push_back(1);
		rep(i, c[1])ans.push_back(2);
		rep(i, c[0] - 3)ans.push_back(1);
	}
	else if (c[0] == 2||c[0]==1) {
		if (c[1]==0) {
			rep(i, c[0])ans.push_back(1);
		}
		else {
			ans.push_back(2); ans.push_back(1);
			rep(i, c[1] - 1)ans.push_back(2);
			rep(i, c[0] - 1)ans.push_back(1);
		}
	}
	else {
		rep(i, n)ans.push_back(2);
	}
	rep(i, ans.size()) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
		return 0;
}