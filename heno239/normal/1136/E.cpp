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
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ld INF = (ld)10000000000000;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

ll rsum[1 << 17];
struct SegT {
private:
	int n; vector<ll> node, lazy;
	const ll init_c = 0;
public:
	ll f(ll a, ll b) {
		return a+b;
	}
	void init(vector<ll> &v) {
		n = 1; int sz = v.size();
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1,0); lazy.resize(2 * n - 1, 0);
		rep(i, sz) {
			node[i + n - 1] = v[i];
		}
		per(i, n - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	void eval(int k, int l, int r) {
		node[k] = max(node[k],lazy[k]*(r-l));
		if (r - l > 1) {
			lazy[2 * k + 1] = max(lazy[2*k+1],lazy[k]);
			lazy[2 * k + 2] = max(lazy[2*k+2],lazy[k]);
		}
	}
	void add(ll x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] = max(lazy[k],x); eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	ll query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return init_c;
		if (a <= l && r <= b)return node[k];
		else {
			ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};
struct Seg2T {
private:
	int n; vector<ll> node, lazy;
	const ll init_c = 0;
public:
	ll f(ll a, ll b) {
		return max(a, b);
	}
	void init(vector<ll> &v) {
		n = 1; int sz = v.size();
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1); lazy.resize(2 * n - 1, 0);
		rep(i, sz) {
			node[i + n - 1] = v[i];
		}
		per(i, n - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	void eval(int k, int l, int r) {
		node[k] =max(node[k], lazy[k]);
		if (r - l > 1) {
			lazy[2 * k + 1] = max(lazy[2*k+1],lazy[k]);
			lazy[2 * k + 2] = max(lazy[2*k+2],lazy[k]);
		}
	}
	void add(ll x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] = max(lazy[k],x); eval(k, l, r);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	int query(ll x,int k=0,int l=0,int r=-1) {
		r = n;
		while (k < n - 1) {
			eval(k, l, r);
			eval(2 * k + 2, (l+r)/2,r);
			eval(2 * k + 1, l, (l + r) / 2);
			if (node[2*k+1]>=x) {
				k = 2 * k + 1; r = (l + r) / 2;
			}
			else {
				k = 2 * k + 2; l = (l + r) / 2;
			}
		}
		return k - n + 1;
	}
};

int n;
vector<ll> a;ll k[1 << 17];
ll rs[1 << 17];
ll rrs[1 << 17];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n; a.resize(n);
	rep(i, n) {
		cin >> a[i];
	}
	ll z = a[0];
	rep(i, n) {
		a[i] -= z;
	}
	rep(i, n - 1) {
		cin >> k[i];
		rs[i + 1] = rs[i] + k[i];
	}
	rep(i, n) {
		rrs[i + 1] = rrs[i] + rs[i];
	}
	rep(i, n) {
		a[i] -= rs[i];
	}
	SegT st; Seg2T st2;
	st.init(a); st2.init(a);
	int q; cin >> q;
	rep(aa, q) {
		char t; cin >> t;
		if (t == '+') {
			int i; ll x; cin >> i >> x; i--;
			if (x == 0)continue;
			ll c = st.query(i, i + 1);
			//cout << c << endl;
			int ri = st2.query(x + c);
			ri = min(ri, n);
			//cout << "hello " << ri << endl;
			st.add(x + c, i, ri);
			st2.add(x + c, i, ri);
		}
		else {
			int l, r; cin >> l >> r;
			//cout << st.query(l - 1, r) << endl;
			cout << rrs[r]-rrs[l-1]+z*(r-l+1)+st.query(l - 1, r) << endl;
		}
	}
	//stop
	return 0;
}