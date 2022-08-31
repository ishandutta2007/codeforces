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
typedef long double ld;
const ld INF = (ld)10000000000000;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
int n, k;
ll a[5000];
vector<int> dp[5001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	rep(i, n)cin >> a[i];
	sort(a, a + n);
	rep(i, n + 1) {
		dp[i].resize(i + 1);
	}
	rep(i, n) {
		int to = upper_bound(a, a + n, a[i] + 5) - a;
		rep(j, i + 1) {
			dp[to][j + 1] = max(dp[to][j + 1], dp[i][j] + to - i);
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
		}
	}
	int ans = 0;
	rep(i, k+1) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans << endl;
	//stop
		return 0;
}