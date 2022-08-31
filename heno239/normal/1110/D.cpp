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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int n, m;
int cnt[1 << 20];
int dp[1 << 20][3][3];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int ans = 0;
	rep(i, n) {
		int a; cin >> a; cnt[a]++;
	}
	rep(i, (1 << 20)) {
		rep(j, 3) {
			rep(k, 3) {
				dp[i][j][k] = -mod;
			}
		}
	}
	dp[0][0][0] = 0;
	int key = (1 << 20) - 3;
	rep1(i,key) {
		rep(j, 3) {
			rep(k, 3) {
				if (dp[i - 1][j][k] < 0)continue;
				int rest = cnt[i] - j - k;
				dp[i][k][0] = max(dp[i][k][0], dp[i - 1][j][k] + rest / 3);
				if (rest > 0 && cnt[i + 1] - k > 0 && cnt[i + 2] > 0) {
					dp[i][k][1] = max(dp[i][k][1], dp[i - 1][j][k] + (rest - 1) / 3 + 1);
				}
				if (rest > 1 && cnt[i + 1] - k > 1 && cnt[i + 2] > 1) {
					dp[i][k][2] = max(dp[i][k][2], dp[i - 1][j][k] + (rest - 2) / 3 + 2);
				}
			}
		}
	}
	cout << dp[key][0][0] << endl;
	//stop
	return 0;
}