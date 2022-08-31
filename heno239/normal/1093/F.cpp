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
const ll mod = 998244353;
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
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
ll dp[100001][101];
bool c[100001][101];
int a[100000];
ll s[100001];
int main() {
	int n, k, len; cin >> n >> k >> len;
	rep(i, n) {
		cin >> a[i];
	}
	rep1(i, k) {
		vector<int> v;
		rep(j, n) {
			if (a[j] >= 0 && a[j] != i) {
				v.push_back(j);
			}
		}
		Rep(j, len - 1, n) {
			int num = upper_bound(v.begin(), v.end(), j) - upper_bound(v.begin(), v.end(), j - len);
			if (num > 0)c[j][i] = false;
			else c[j][i] = true;
		}
	}
	dp[0][0] = 1;
	rep(i, n) {
		ll sum = 0;
		rep(j, k + 1) {
			sum = (sum + dp[i][j]) % mod;
		}
		s[i] = sum;
		rep1(j, k) {
			if (a[i] != -1 && a[i] != j)continue;
			(dp[i + 1][j] += sum) %= mod;
			if (c[i][j]) {
				//cout << i << " " << j << endl;
				dp[i + 1][j] = (dp[i + 1][j] - s[i - len + 1]+dp[i-len+1][j] + mod) % mod;
			}
		}
	}
	ll ans = 0;
	rep(j, k+1) {
		ans = (ans + dp[n][j]) % mod;
		//cout << dp[3][j] << endl;
	}
	cout << ans << endl;
	//stop
	return 0;
}