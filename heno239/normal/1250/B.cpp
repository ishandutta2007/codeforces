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
typedef pair<int, int>P;
typedef pair<int, bool> sP;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	int sum = 0;
	vector<int> loc;
	rep(i, n) {
		cin >> a[i]; sum += a[i];
		if (a[i])loc.push_back(i);
	}
	vector<ll> locs(loc.size()+1);
	rep(i, loc.size()) {
		locs[i + 1] += locs[i] + loc[i];
	}
	if (sum == 1) {
		cout << -1 << endl; return;
	}
	else {
		ll ans = INF;
		Rep1(j, 2, sum) {
			if (sum%j == 0) {
				int d = j;
				ll csum = 0;
				rep(i, sum / d) {
					int le = i * d; int ri = (i + 1)*d;
					int mid = loc[le + d / 2];
					ll cl = d/2;
					ll cr = d-cl;
					csum += mid * cl - (locs[le + d / 2] - locs[le]);
					csum += (locs[ri] - locs[le + d / 2]) - mid * cr;
				}
				ans = min(ans, csum);
			}
		}
		cout << ans << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(9);
	//init();
	solve();
	//stop
		return 0;
}