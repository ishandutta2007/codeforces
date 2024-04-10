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

struct SegT {
private:
	int sz; vector<P> node;
	const P init_c = { mod,mod };
public:
	void init(int n) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	P f(P a, P b) {
		P ret;
		if (a.first < b.first) {
			ret.first = a.first;
			ret.second = min(a.second, b.first);
		}
		else {
			ret.first = b.first;
			ret.second = min(a.first, b.second);
		}
		return ret;
	}
	void update(int k, int a) {
		k += sz - 1;
		node[k] = { a,mod };
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	P query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			P vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			P vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};

vector<bool> trans(int x) {
	vector<bool> ret;
	rep(i, 9) {
		if (x % 10)ret.push_back(true);
		else ret.push_back(false);
		x /= 10;
	}
	return ret;
}

void solve() {
	int n, q; cin >> n >> q;
	SegT st[9];
	rep(i, 9) {
		st[i].init(n);
	}
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		vector<bool> b = trans(a[i]);
		rep(j, 9) {
			if (b[j]) {
				st[j].update(i,a[i]);
			}
		}
	}
	rep(i, q) {
		int t; cin >> t;
		if (t == 1) {
			int id, x; cin >> id >> x; id--;
			vector<bool> b = trans(a[id]);
			rep(j, 9) {
				if (b[j])st[j].update(id, mod);
			}
			a[id] = x; b = trans(a[id]);
			rep(j, 9) {
				if (b[j])st[j].update(id,a[id]);
			}
		}
		else {
			int l, r; cin >> l >> r; l--; r--;
			int ans = 2 * mod;
			rep(j, 9) {
				P p = st[j].query(l, r + 1);
				if (p.second < mod) {
					ans = min(ans, p.first + p.second);
				}
			}
			if (ans == 2 * mod) {
				cout << -1 << endl;
			}
			else {
				cout << ans << endl;
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(50);
	//init();
	solve();

	//cout << "finish" << endl;
	//stop
		return 0;
}