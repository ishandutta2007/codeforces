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
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
ll mod_pow(ll x, int n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return res;
}
struct SegT {
private:
	int n; vector<ll> node, lazy;
	const ll init_c = 1;
public:
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, 1);
		lazy.resize(2 * n - 1, 1);
	}
	ll f(ll a, ll b) {
		return a * b%mod;
	}
	void eval(int k, int l, int r) {
		node[k] = node[k] * mod_pow(lazy[k], r - l) % mod;
		if (r - l > 1) {
			(lazy[2 * k + 1] *= lazy[k]) %= mod;
			(lazy[2 * k + 2] *= lazy[k]) %= mod;
		}
		lazy[k] = 1;
	}
	void add(ll x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			(lazy[k] *= x) %= mod; eval(k, l, r);
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
	void update(int k, ll a) {
		k += n - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[2 * k + 1], node[2 * k + 2]);
		}
	}
};
typedef bitset<62> bt;
struct SegT2 {
private:
	int n; vector<bt> node, lazy;
	const bt init_c = 0;
public:
	void init(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, 0);
		lazy.resize(2 * n - 1, 0);
	}
	bt f(bt a, bt b) {
		return a | b;
	}
	void eval(int k, int l, int r) {
		node[k] = node[k] | lazy[k];
		if (r - l > 1) {
			lazy[2 * k + 1] = lazy[2 * k + 1] | lazy[k];
			lazy[2 * k + 2] = lazy[2 * k + 2] | lazy[k];
		}
		lazy[k] = 0;
	}
	void add(bt x,int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] = x; eval(k, l, r);
		}
		else {
			add(x,a, b, k * 2 + 1, l, (l + r) / 2);
			add(x,a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	bt query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k, l, r);
		if (r <= a || b <= l)return init_c;
		if (a <= l && r <= b)return node[k];
		else {
			bt vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			bt vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	void update(int k, bt a) {
		k += n - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[2 * k + 1], node[2 * k + 2]);
		}
	}
};

//x,yax+by=gcd(a,b)
ll extgcd(ll a, ll b, ll& x, ll& y) {
	ll d = a;
	if (b != 0) {
		d = extgcd(b, a%b, y, x);
		y -= (a / b)*x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}
//amod m
ll mod_inverse(ll a, ll m) {
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}
int n, q;
ll val[400001];
bool isp[301];
vector<int> p;
vector<P> v[301];
ll inv[301];
bt vq[301];
void init() {
	fill(isp + 2, isp + 301, true);
	Rep(i, 2, 301) {
		if (!isp[i])continue;
		p.push_back(i);
		for (int j = 2 * i; j < 301; j += i) {
			isp[j] = false;
		}
	}
	rep1(i, 300) {
		int cop = i;
		rep(j, p.size()) {
			int cnt = 0;
			while (cop%p[j] == 0) {
				cop /= p[j]; cnt++;
			}
			if (cnt) {
				v[i].push_back({ j,cnt });
				vq[i][j] = 1;
			}
		}
	}
	rep1(i, 300) {
		inv[i] = mod_inverse(i, mod);
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	init();

	cin >> n >> q;
	SegT sg(n);
	SegT2 s;
	s.init(n);
	rep(i, n) {
		val[i] = 1;
		int x; cin >> x;
		val[i] = x;
		s.update(i, vq[x]);
		sg.update(i, val[i]);
	}
	rep(i, q) {
		string st; cin >> st;
		if (st[0] == 'T') {
			int l, r; cin >> l >> r; l--;
			ll ans = sg.query(l, r);
			//cout << ans << endl;
			bt u = s.query(l, r);
			rep(j, 62) {
				if (u[j]) {
					ans = ans * (p[j] - 1) % mod*inv[p[j]] % mod;
				}
			}
			cout << ans << endl;
		}
		else {
			int l, r, x; cin >> l >> r >> x; l--;
			sg.add(x, l, r);
			s.add(vq[x], l, r);
		}
	}

	//stop
	return 0;
}