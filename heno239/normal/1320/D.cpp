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
#include<numeric>
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
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-9;
const ld pi = acos(-1.0);
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n, ll m) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%m;
		a = a * a%m; n >>= 1;
	}
	return res;
}

struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint &a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint &a, modint b) { a.n = ((ll)a.n*b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

const int max_n = 1 << 18;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
using mP = pair<modint, modint>;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


int n;
string s;
ll m;
ll t = 2;
ll memot[1 << 18];

void init() {
	memot[0] = 1;
	rep(i, n) {
		memot[i + 1] = memot[i] * t%m;
	}

}
struct status {
	int sz;
	int num;
	int cl, cr;
	ll r;
};
status merge(status s1, status s2) {
	if (s1.sz == 0)return s2;
	if (s2.sz == 0)return s1;
	status res;
	res.sz = s1.sz + s2.sz;
	if (s1.cl == s1.sz)res.cl = s1.cl + s2.cl;
	else res.cl = s1.cl;
	if (s2.cr == s2.sz)res.cr = s2.cr + s1.cr;
	else res.cr = s2.cr;
	if ((s1.cr % 2) == (s2.cl % 2)&&(s1.cr%2)) {
		res.num = s1.num + s2.num + 2;
		ll le = s1.r - memot[s1.sz - 1]; if (le < 0)le += m;
		ll ri = s2.r - memot[s2.num]; if (ri < 0)ri += m;
		ri = ri * memot[s1.sz] % m;
		le = le * memot[s2.num + 2] % m;
		res.r = le + ri;
		if (res.r >= m)res.r -= m;
	}
	else {
		res.num = s1.num + s2.num;
		ll le = s1.r, ri = s2.r;
		le = le * memot[s2.num] % m;
		ri = ri * memot[s1.sz] % m;
		res.r = le + ri;
		if (res.r >= m)res.r -= m;
	}
	return res;
}

struct SegT {
private:
	int sz; vector<status> node;
	const status init_c = {0,0,0,0,0};
public:
	SegT() {
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			if (s[i] == '0') {
				node[i + sz - 1] = { 1,0,0,0,0 };
			}
			else {
				node[i + sz - 1] = { 1,0,1,1,1 };
			}
		}
		per(i, sz - 1) {
			node[i] = merge(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	status query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			status vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			status vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return merge(vl, vr);
		}
	}
};

vector<P> v;

vector<ll> calc() {
	init();
	vector<ll> res(v.size());
	SegT st;
	rep(i, v.size()) {
		int l = v[i].first;
		int r = v[i].second;
		status out = st.query(l, r + 1);
		res[i] = out.r;
	}
	
	return res;
}


void solve() {
	cin >> n >> s;
	vector<int> rcnt(n+1);
	rep(i, n) {
		rcnt[i + 1] = rcnt[i];
		if (s[i] == '1')rcnt[i + 1]++;
	}
	int q; cin >> q;
	rep(aa, q) {
		int a, b, len;
		cin >> a >> b >> len; a--; b--;
		v.push_back({ a,a + len - 1 });
		v.push_back({ b,b + len - 1 });
	}
	m = 1000068233;
	vector<ll> hs1 = calc();
	//rep(i, 2 * q)cout << hs1[i] << endl;
	m = 1000068241;
	vector<ll> hs2 = calc();
	rep(i, q) {
		int c1 = rcnt[v[2 * i].second + 1] - rcnt[v[2 * i].first];
		int c2 = rcnt[v[2 * i+1].second + 1] - rcnt[v[2 * i+1].first];
		if (c1==c2&&hs1[2 * i] == hs1[2 * i + 1] && hs2[2 * i] == hs2[2 * i + 1]) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}