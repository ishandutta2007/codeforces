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
	cout << endl;
}

int n, k, l;
int calc(vector<bool> &b) {
	function<LP(int)> check = [&](int x)->LP {
		vector<LP> dp(n + 1, { INF,0 });
		dp[0] = { 0,0 };
		rep(i, n) {
			int to = min(n, i + l);
			dp[to] = min(dp[to], {dp[i].first+x,dp[i].second+1});
			dp[i + 1] = min(dp[i + 1], { dp[i].first + (b[i]),dp[i].second });
		}
		return dp[n];
	};
	int le = -1, ri = n + 1;
	while (ri - le > 1) {
		int mid = (le + ri) / 2;
		LP c = check(mid);
		if (c.second <= k)ri = mid;
		else le = mid;
	}
	LP res = check(ri);
	return res.first - k * ri;
}

void solve() {
	cin >> n >> k >> l;
	string s; cin >> s;
	vector<bool> b(n);
	rep(i, n)b[i] = ('a' <= s[i] && s[i] <= 'z');
	int c1=calc(b);
	rep(i, n)b[i] = !b[i];
	int c2=calc(b);
	int ans = min(c1, c2);
	cout << ans << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	//stop
	return 0;
}