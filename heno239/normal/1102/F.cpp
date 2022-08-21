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
const ld eps = 1e-9;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int n, m;
int a[16][10000];
int d[16][16];
void calc() {
	rep(i, n) {
		rep(j, n) {
			if (i == j)continue;
			int mi = mod;
			rep(k, m) {
				mi = min(mi, abs(a[i][k] - a[j][k]));
			}
			d[i][j] = mi;
		}
	}
}
int dp[16][1 << 16];
bool used[16][1 << 16];
queue<P> q;
int bitdp(int s) {
	rep(i, n) {
		rep(j, 1<<n) {
			used[i][j] = false;
			dp[i][j] = -mod;
		}
	}
	dp[s][1 << s] = mod; q.push({ s,1 << s });
	while (!q.empty()) {
		P p = q.front(); q.pop();
		int id = p.first; int ss = p.second;
		rep(i, n) {
			if (ss&(1 << i))continue;
			int ns = ss ^ (1 << i);
			dp[i][ns] = max(dp[i][ns], min(dp[id][ss], d[id][i]));
			if (!used[i][ns]) {
				used[i][ns] = true;
				q.push({ i,ns });
			}
		}
	}
	int res = -mod;
	rep(i, n) {
		if (i == s)continue;
		int mi = mod;
		rep(j, m - 1) {
			mi = min(mi, abs(a[i][j] - a[s][j + 1]));
		}
		res = max(res, min(mi, dp[i][(1 << n) - 1]));
	}
	return res;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			cin >> a[i][j];
		}
	}
	if (n == 1) {
		int mi = mod;
		rep(j, m - 1) {
			mi = min(mi, abs(a[0][j] - a[0][j + 1]));
		}
		cout << mi << endl;
		return 0;
	}
	calc();
	int ans = -mod;
	rep(i, n) {
		ans = max(ans, bitdp(i));
	}
	cout << ans << endl;
	//stop
	return 0;
}