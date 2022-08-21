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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

struct SegT {
private:
	int sz; vector<ll> node;
	ll sup;
public:
	SegT(int n,int a) {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, 0);
		sup = a;
	}
	ll f(ll a, ll b) {
		return a + b;
	}
	void add(int k, int a) {
		k += sz - 1;
		node[k] += a;
		if (node[k] > sup)node[k] = sup;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	ll query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return 0;
		else if (a <= l && r <= b)return node[k];
		else {
			ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
};


void solve() {
	int n, k, a, b, q;
	cin >> n >> k >> a >> b >> q;
	SegT s1(n,b), s2(n,a);
	rep(i, q) {
		int t; cin >> t;
		if (t == 1) {
			int d, a; cin >> d >> a;
			d--;
			s1.add(d, a);
			s2.add(d, a);
		}
		else {
			int p; cin >> p; p--;
			
			ll le = s1.query(0, p);
			ll ri = s2.query(p+k,n);
			cout << le + ri << endl;
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	//stop
	return 0;
}