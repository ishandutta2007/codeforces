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
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<int> vec;


void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	vector<int> b(m);
	rep(i, m)cin >> b[i];
	vector<bool> used(n + 1, false);
	ll ans = 0;
	int loc = 0;
	rep(i, m) {
		if (used[b[i]]) {
			ans++;
		}
		else {
			while (a[loc] != b[i]) {
				used[a[loc]] = true;
				loc++;
			}
			int num = loc - i;
			ans += 2 * num + 1;
			loc++;
		}
	}
	cout << ans << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	//init();
	int t; cin >> t; rep(i, t)solve();
	//solve();
	stop
	return 0;
}