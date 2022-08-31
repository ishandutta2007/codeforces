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
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;
ll time2[1 << 17];
void init() {
	time2[0] = 1;
	Rep(i, 1, (1 << 17)) {
		time2[i] = time2[i - 1] * 2 % mod;
	}
	rep(i, (1 << 17)) {
		time2[i] -= 1;
	}
}
ll dp[1 << 17];
vector<int> v,u;
int next(int x) {
	int id = v[x];
	x = lower_bound(u.begin(), u.end(), id) - u.begin();
	if (x == u.size())return v.size();
	id = u[x];
	x = lower_bound(v.begin(), v.end(), id) - v.begin();
	return x;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	init();
	string s; cin >> s; int n = s.length();
	rep(i, n) {
		if (s[i] == 'a') {
			v.push_back(i);
		}
		else if (s[i] == 'b') {
			u.push_back(i);
		}
	}
	int m = v.size();
	dp[0] = 1;
	rep(i, m) {
		(dp[i + 1] += dp[i]) %= mod;
		(dp[next(i)] += dp[i]) %= mod;
	}
	cout << dp[m]-1 << endl;
	return 0;
}