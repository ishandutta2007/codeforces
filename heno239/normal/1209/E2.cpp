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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);


void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n);
	rep(i, n) {
		a[i].resize(m);
		rep(j, m) {
			cin >> a[i][j];
		}
	}
	vector<P> z;
	rep(i, m) {
		int ma = 0;
		rep(j, n) {
			ma = max(ma, a[j][i]);
		}
		z.push_back({ ma,i });
	}
	sort(z.begin(), z.end(), greater<P>());
	int sz = min(n, m);
	vector<vector<int>> nw(n);
	rep(i, n) {
		nw[i].resize(sz);
		rep(j, sz) {
			nw[i][j] = a[i][z[j].second];
		}
	}
	m = sz; a = nw;
	vector<int> dp(1 << n, -mod), cop(1 << n), nex(1 << n);
	dp[0] = 0;
	rep(j, m) {
		fill(nex.begin(), nex.end(), -mod);
		rep(k, n) {
			rep(i, (1 << n)) {
				cop[i] = dp[i];
			}

			vector<int> v;
			rep(i, n) {
				v.push_back(a[(k + i) % n][j]);
			}
			rep(i, n) {
				rep(s, (1 << n)) {
					if (s&(1 << i))continue;
					cop[s ^ (1 << i)] = max(cop[s ^ (1 << i)], cop[s] + v[i]);
				}
			}
			rep(i, (1 << n)) {
				nex[i] = max(nex[i], cop[i]);
			}
		}
		rep(i, 1 << n)dp[i] = nex[i];
	}
	cout << dp[(1 << n) - 1] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(50);
	//init();
	int t; cin >> t;
	rep(aa, t) {
		solve();
	}

	//cout << "finish" << endl;
	//stop
	return 0;
}