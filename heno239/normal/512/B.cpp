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
typedef long double ld;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

int gcd(int x, int y) {
	if (x < y)swap(x, y);
	while (y) {
		int r = x % y; x = y; y = r;
	}
	return x;
}

int l[300], c[300];
set<int> st;
map<int, int> dp;
map<int, bool> exi;
void solve() {
	int n; cin >> n;
	rep(i, n) {
		cin >> l[i];
	}
	rep(i, n) {
		cin >> c[i];
	}
	dp[0] = 0;
	st.insert(0);
	rep(i, n) {
		vector<int> v;
		for (auto itr = st.begin(); itr != st.end(); itr++) {
			int z = *itr;
			int g = gcd(l[i], z);
			v.push_back(g);
			if (exi[g]) {
				dp[g] = min(dp[g], dp[z] + c[i]);
			}
			else {
				exi[g] = true;
				dp[g] = dp[z] + c[i];
			}
		}
		rep(j, v.size())st.insert(v[j]);
	}
	if (exi[1]) {
		cout << dp[1] << endl;
	}
	else {
		cout << -1 << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}