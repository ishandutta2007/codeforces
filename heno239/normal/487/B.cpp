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

struct SegT {
private:
	int sz; vector<int> node;
	bool mi;
	int init_c = -mod;
public:

	int f(int a, int b) {
		if (mi)return min(a, b);
		else return max(a, b);
	}
	SegT(int n, bool fa) {
		if (fa)init_c = mod, mi = true;
		else init_c = -mod, mi = false;
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	SegT(vector<int> v, bool fa) {
		int n = v.size();
		if (fa)init_c = mod, mi = true;
		else init_c=-mod,mi = false;
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			node[i + sz - 1] = v[i];
		}
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
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
	int n; cin >> n;
	int s, l; cin >> s >> l;
	vector<int> a(n); rep(i, n)cin >> a[i];
	SegT ma(a, false), mi(a, true), dp(n+1, true);
	dp.update(0, 0);
	rep(i, n) {
		int le = -1, ri = i + 1;
		while (ri - le > 1) {
			int mid = (ri + le) / 2;
			int c = ma.query(mid, i+1) - mi.query(mid, i+1);
			if (c <= s) {
				ri = mid;
			}
			else le = mid;
		}
		le = ri; ri = i+1 - l;
		int z = dp.query(le, ri+1);
		dp.update(i + 1, z+1);
		//cout << i<<" "<<le << endl;
	}
	int ans = dp.query(n, n + 1);
	if (ans == mod)ans = -1;
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}