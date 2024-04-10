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

struct SegT {
private:
	int sz; vector<int> node;
	const int init_c = -mod;
public:
	SegT(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	int f(int a, int b) {
		return max(a, b);
	}
	void update(int k, int a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	int query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};
struct Seg2T {
private:
	int sz; vector<int> node;
	const int init_c = mod;
public:
	Seg2T(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	int f(int a, int b) {
		return min(a, b);
	}
	void update(int k, int a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	int query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};


void solve() {
	string s; cin >> s;
	int n = s.length();
	int x = 0, y = 0;
	int xl = 0, xr = 0, yl = 0, yr = 0;
	SegT srx(n + 1), sry(n + 1);
	Seg2T slx(n + 1), sly(n + 1);
	rep(i, n) {
		srx.update(i, x); slx.update(i, x);
		sry.update(i, y); sly.update(i, y);
		if (s[i] == 'S') {
			y--;
		}
		else if (s[i] == 'W') {
			y++;
		}
		else if (s[i] == 'A') {
			x--;
		}
		else {
			x++;
		}
	}
	srx.update(n, x); slx.update(n, x);
	sry.update(n, y); sly.update(n, y);
	x = 0, y = 0;
	xl = 0, xr = 0, yl = 0, yr = 0;
	ll ans = INF;
	rep(i, n+1) {
		ll lx, rx, ly, ry;
		int dlx = x - slx.query(i, n+1);
		int drx = srx.query(i, n + 1)-x;
		int dly = y - sly.query(i, n + 1);
		int dry = sry.query(i, n + 1) - y;
		//D
		rx = max(xr, x + 1 + drx);
		lx = min(xl, x+1 - dlx);
		ry = max(yr, y +dry);
		ly = min(yl, y - dly);
		ans = min(ans, (rx - lx+1)*(ry - ly+1));
		//cout << lx << " " << rx << " " << ly << " " << ry << endl;
		//A
		rx = max(xr, x - 1 + drx);
		lx = min(xl, x - 1 - dlx);
		ry = max(yr, y + dry);
		ly = min(yl, y - dly);
		ans = min(ans, (rx - lx + 1)*(ry - ly + 1));
		//cout << lx << " " << rx << " " << ly << " " << ry << endl;
		//S
		rx = max(xr, x + drx);
		lx = min(xl, x - dlx);
		ry = max(yr, y+1 + dry);
		ly = min(yl, y+1 - dly);
		ans = min(ans, (rx - lx + 1)*(ry - ly + 1));
		//cout << lx << " " << rx << " " << ly << " " << ry << endl;
		//W
		rx = max(xr, x + drx);
		lx = min(xl, x - dlx);
		ry = max(yr, y-1 + dry);
		ly = min(yl, y-1 - dly);
		ans = min(ans, (rx - lx + 1)*(ry - ly + 1));
		//cout << lx << " " << rx << " " << ly << " " << ry << endl;

		if (i < n) {
			if (s[i] == 'S') {
				y--;
				yl = min(yl, y);
			}
			else if (s[i] == 'W') {
				y++;
				yr = max(yr, y);
			}
			else if (s[i] == 'A') {
				x--;
				xl = min(xl, x);
			}
			else {
				x++;
				xr = max(xr, x);
			}
		}
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	int t; cin >> t;
	rep(i, t) {
		solve();
	}
	//cout << "finish" << endl;
	//stop
	return 0;
}