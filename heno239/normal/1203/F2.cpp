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
const ll mod = 1000000007;
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

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}

bool comp(P a, P b) {
	return a.first + a.second < b.first+b.second;
}
void solve() {
	int n,r;
	cin >> n>>r;
	vector<P> pos, neg;

	int ans = 0;
	rep(i, n) {
		int a, b; cin >> a >> b;
		if (b >= 0) {
			pos.push_back({ a,b });
		}
		else {
			neg.push_back({ a,b });
		}
	}
	sort(pos.begin(), pos.end());
	rep(i, pos.size()) {
		if (pos[i].first > r) {
			continue;
			//cout << "NO" << endl; return;
		}
		r += pos[i].second; ans++;
	}
	vector<int> dp(r + 1, -mod);
	dp[r] = ans;
	sort(neg.begin(), neg.end(), comp);
	
	per(i, (int)neg.size()) {
		rep(j, r + 1) {
			if (j >= neg[i].first&&j + neg[i].second >= 0) {
				dp[j + neg[i].second] = max(dp[j + neg[i].second], dp[j] + 1);
			}
		}
	}
	int ma = 0; rep(i, r + 1)ma = max(ma, dp[i]);
	cout << ma << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}