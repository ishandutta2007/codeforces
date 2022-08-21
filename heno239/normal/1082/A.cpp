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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = (ll)(1e+9) + 7;
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
typedef pair<ld, ld> LDP;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	rep(aa, t) {
		ll d, x, y, n; cin >> n >> x >> y >> d;
		ll dif = abs(x - y);
		ll ans = INF;
		if (dif%d == 0) {
			ans = min(ans, dif / d);
		}
		if ((y - 1) % d == 0) {
			ans = min(ans, (y - 1) / d + (x+d-2) / d);
		}
		if ((n - y) % d == 0) {
			ans = min(ans, (n - y) / d + (n - x + d-1) / d);
		}
		if (ans == INF)ans = -1;
		cout << ans << endl;
	}
	return 0;
}