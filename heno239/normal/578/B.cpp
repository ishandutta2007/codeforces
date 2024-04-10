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
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;


void solve() {
	int n, k, x; cin >> n >> k >> x;
	vector<ll> a(n);
	rep(i, n)cin >> a[i];
	//sort(a.begin(), a.end());
	vector<ll> le(n+1), ri(n+1);
	le[0] = 0;
	rep(i, n) {
		le[i + 1] = le[i] | a[i];
		ri[i + 1] = ri[i] | a[n - 1 - i];
	}
	ll ans = 0;
	rep(i, n) {
		ll c = a[i];
		rep(j, k) {
			c = c * x;
		}
		ll sum = c | le[i] | ri[n -1- i];
		ans = max(ans, sum);
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}