#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
#include<chrono>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;

#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	if (x == 0)return 0;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 20;
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
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
const ld pi = acosl(-1.0);
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

using mP = pair<modint, modint>;
//-----------------------------------

modint t2[200000];
void init() {
	t2[0] = 1;
	rep(i, 199999)t2[i + 1] = t2[i] + t2[i];
}
struct Node {
	Node* ch[2];
	int val;
	Node() {
		ch[0] = ch[1] = NULL;
		val = 0;
	}
};
void add(Node* nd, int t, int sz) {
	per(i, sz) {
		int id = 0;
		if (t & (1 << i)) {
			id = 1;
		}
		if (nd->ch[id] == NULL)nd->ch[id] = new Node();
		nd = nd->ch[id];
		nd->val++;
	}
}
modint query(Node* ndl, Node* ndr, int loc, int x) {
	if (loc == 0) {
		return (t2[ndl->val] - (modint)1) * (t2[ndr->val] - (modint)1);
	}
	modint res = 0;
	int b = 0;
	if (x & (1 << (loc - 1)))b = 1;
	if (b == 0) {
		rep(j, 2) {
			if (ndl->ch[j] != NULL && ndr->ch[j] != NULL) {
				res += query(ndl->ch[j], ndr->ch[j], loc - 1, x);
			}
		}
	}
	else {
		modint val[2] = {};
		rep(j, 2) {
			if (ndl->ch[j] != NULL && ndr->ch[j ^ 1] != NULL) {
				val[j]= query(ndl->ch[j], ndr->ch[j ^ 1], loc - 1, x);
			}
			if (ndl->ch[j] != NULL && ndr->ch[j] != NULL) {
				res += (t2[ndl->ch[j]->val] - (modint)1) * (t2[ndr->ch[j]->val] - (modint)1);
			}
		}
		rep(j, 2) {
			if (ndl->ch[j] != NULL) {
				if(ndl->ch[j]!=NULL)res += val[j ^ 1] * (t2[ndl->ch[j]->val] - (modint)1);
				if(ndr->ch[j]!=NULL)res += val[j] * (t2[ndr->ch[j]->val] - (modint)1);
			}
			res += val[j];
		}
		res += val[0] * val[1];
	}
	return res;
}
modint calc(vector<int> a, int x) {
	modint res = 0;
	int sz = 0;
	int z = 1;
	while (z <= x) {
		z *= 2; sz++;
	}
	Node* nd = new Node();
	rep(i, a.size())add(nd, a[i], sz);
	rep(j, 2) {
		if (nd->ch[j] != NULL) {
			res += t2[nd->ch[j]->val] - (modint)1;
		}
	}
	//cout << "? " << res << " " << sz << "\n";
	if (nd->ch[0] != NULL && nd->ch[1] != NULL) {
		res += query(nd->ch[0], nd->ch[1], sz - 1, x);
	}
	return res;
}
void solve() {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	if (x == 0) {
		sort(all(a));
		modint ans = 0;
		rep(i, a.size()) {
			int le = i;
			while (i + 1 < n && a[i] == a[i + 1])i++;
			int cnt = i - le + 1;
			modint csum = 0;
			for (int j = 1; j <= cnt; j++) {
				csum += comb(cnt, j);
			}
			ans += csum;
		}
		cout << ans << "\n";
		return;
	}
	int t = 1;
	while (t <= x)t *= 2;
	vector<P> v;
	rep(i, n) {
		v.push_back({ a[i] / t, a[i] % t });
	}
	sort(all(v));
	modint ans = 0;
	rep(i, v.size()) {
		int le = i;
		while (i + 1 < v.size() && v[i].first == v[i + 1].first)i++;
		vector<int> c;
		Rep1(j, le, i)c.push_back(v[j].second);
		ans += calc(c, x);
	}
	//cout << ans << "\n";
	cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	init_f();
	init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}