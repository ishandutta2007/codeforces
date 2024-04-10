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
const ll mod = 1000000087;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;


void solve() {
	int n, m, d; cin >> n >> m >> d;
	vector<ll> dp(n,0);
	vector<ll> cop(n, 0);
	ll cur = 0; ll ad = 0;
	rep(i, m) {
		int a; ll b, t; cin >> a >> b >> t; a--;
		ad += b;
		ll dif = t - cur; cur = t;
		ll range = dif * d; if (range + 1 > n)range = n - 1;
		deque<LP> st;
		rep(j, range+1) {
			while (!st.empty() && st.back().first > dp[j])st.pop_back();
			st.push_back({ dp[j],j });
		}
		cop[0] = st.front().first + abs(a);
		for (int j = 1; j < n; j++) {
			if (j + range < n) {
				while (!st.empty() && st.back().first > dp[j+range])st.pop_back();
				st.push_back({ dp[j+range],j+range });
			}
			if (j - range - 1 >= 0) {
				if (st.front().second == j - range - 1)st.pop_front();
			}
			cop[j] = st.front().first +abs(a-j);
		}
		swap(dp, cop);
	}
	ll ans = INF;
	rep(j, n)ans = min(ans, dp[j]);

	cout <<ad-ans << endl;
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