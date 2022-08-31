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
int n; ll le, ri;
ll c[3];
ll dp[3],cop[3];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> le >> ri;
	c[0] = ri / 3 - (le - 1) / 3;
	c[1] = (ri + 2) / 3 - (le + 1) / 3;
	c[2] = (ri + 1) / 3 - (le) / 3;
	dp[0] = 1;
	rep(i, n) {
		rep(j, 3) {
			cop[j] = 0;
		}
		rep(j, 3) {
			rep(k, 3) {
				cop[(j + k) % 3] += dp[j] * c[k] % mod;
			}
		}
		rep(j, 3) {
			dp[j] = cop[j]%mod;
		}
	}
	cout << dp[0] << endl;
	//stop
	return 0;
}