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
#include<cassert>
using namespace std;

typedef long long  ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000003;
typedef double ld;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
typedef vector<int> vec;

void solve() {
	int n, m,k;
	ll ta, tb;
	cin >> n >> m >> ta >> tb >> k;
	vector<ll> a(n), b(m);
	rep(i, n)cin >> a[i];
	rep(i, m)cin >> b[i];
	if (k >= m || k >= n) {
		cout << -1 << endl; return;
	}
	ll ans = 0;
	rep(i, n) {
		if (i > k)break;
		int r = k - i;
		ll t = ta + a[i];
		int id = lower_bound(b.begin(), b.end(), t) - b.begin();
		id += r;
		if (id >= m) {
			cout << -1 << endl; return;
		}
		t = b[id] + tb;
		ans = max(ans, t);
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//while (cin >> n)solve();
	solve();
	//stop
	return 0;
}