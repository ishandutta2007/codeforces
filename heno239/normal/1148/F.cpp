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
const ll mod = 998244353;
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



void solve() {
	int n; cin >> n;
	vector<ll> val(n), mask(n);
	ll sum = 0;
	rep(i, n) {
		cin >> val[i] >> mask[i];
		sum += val[i];
	}
	if (sum < 0) {
		rep(i, n) {
			val[i] = -val[i];
			sum = -sum;
		}
	}
	ll ans = 0;
	rep(i, 62) {
		ll k = (ll)1 << i;
		ll csum = 0;
		rep(j, n) {
			if (mask[j] < 2 * k && (mask[j] & k)) {
				csum += val[j];
			}
		}
		if (csum > 0) {
			ans += k;
			rep(j, n) {
				if (mask[j]&k) {
					val[j] = -val[j];
				}
			}
		}
	}
	/*sum = 0;
	rep(i, n) {
		sum += val[i];
	}
	cout << sum << endl;*/
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}