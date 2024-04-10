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

int n;
vector<ld> a;
ld calc(ld x) {
	vector<ld> ra(n + 1);
	rep(i, n) {
		ra[i + 1] = ra[i] + a[i] - x;
	}
	ld ret = 0;
	ld mi = 0, ma = 0;
	rep1(i, n) {
		ret = max(ret, abs(ra[i] - mi));
		ret = max(ret, abs(ma - ra[i]));
		mi = min(mi, ra[i]);
		ma = max(ma, ra[i]);
	}
	return ret;
}
void solve() {
	cout << fixed << setprecision(7);
	cin >> n; a.resize(n);
	rep(i, n)cin >> a[i];
	ld le = -10000, ri = 10000;
	rep(aa, 100) {
		ld l = (le*2 + ri) / 3.0;
		ld r = (le + 2 * ri) / 3.0;
		ld cl = calc(l), cr = calc(r);
		if (cl < cr)ri = r;
		else le = l;
	}
	cout << calc(le) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}