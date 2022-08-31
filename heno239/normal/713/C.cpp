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
#include<numeric>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);

ll dp[3001][3001];
void solve() {
	int n; cin >> n;
	vector<int>a(n);
	rep(i, n)cin >> a[i];
	rep(i, n)a[i] -= i;
	vector<int>x = a;
	sort(all(x));
	rep(i, n) {
		dp[0][i] = abs(a[0] - x[i]);
	}
	rep1(i, n - 1) {
		ll mi = INF;
		rep(j, n) {
			mi = min(mi, dp[i - 1][j]);
			dp[i][j] = mi + abs(a[i] - x[j]);
		}
	}
	ll ans = INF;
	rep(j, n) {
		ans = min(ans, dp[n-1][j]);
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();

	solve();
	stop
		return 0;
}