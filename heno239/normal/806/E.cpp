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
constexpr ll mod = 1000000007;
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
const ld eps = 1e-12;
const ld pi = acos(-1.0);

ll mod_pow(ll x, ll n, ll m) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
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
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
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
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct BIT {
private:
	vector<ll> node; int n;
public:
	BIT(int n_) {
		n = n_; node.resize(n, 0);
	}
	//0-indexed
	void add(int a, ll w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	//[0,a)
	ll sum(int a) {
		ll ret = 0;
		for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)ret += node[i];
		return ret;
	}
	//[a,b)
	ll sum(int a, int b) {
		return sum(b) - sum(a);
	}
};

struct SegT {
private:
	int n; vector<P> node;
	vector<int>lazy;
	const P init_c = { mod,-mod };
public:
	SegT(int sz) {
		n = 1;
		while (n < sz)n <<= 1;
		node.resize(2 * n - 1, init_c);
		lazy.resize(2 * n - 1, 0);
	}
	P f(P a, P b) {
		return { min(a.first,b.first),max(a.second,b.second) };
	}
	void eval(int k) {
		node[k].first += lazy[k];
		node[k].second += lazy[k];
		if (k<n-1) {
			lazy[2 * k + 1] += lazy[k];
			lazy[2 * k + 2] += lazy[k];
		}
		lazy[k] = 0;
	}
	void add(int x, int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k);
		if (r <= a || b <= l)return;
		if (a <= l && r <= b) {
			lazy[k] += x; eval(k);
		}
		else {
			add(x, a, b, k * 2 + 1, l, (l + r) / 2);
			add(x, a, b, k * 2 + 2, (l + r) / 2, r);
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	P query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = n;
		eval(k);
		if (r <= a || b <= l)return init_c;
		if (a <= l && r <= b)return node[k];
		else {
			P vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			P vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	void update(int loc, ll x) {
		int k = 0, l = 0, r = n;
		stack<P> st;
		while (k < n - 1) {
			eval(k);
			st.push({ l,r });
			if (loc < (l + r) / 2) {
				k = 2 * k + 1;
				r = (l + r) / 2;
			}
			else {
				k = 2 * k + 2;
				l = (l + r) / 2;
			}
		}
		eval(k);
		st.push({ l,r });
		node[k] = { x,x };
		while (k > 0) {
			k = (k - 1) / 2;
			st.pop();
			l = st.top().first, r = st.top().second;
			eval(2 * k + 1);
			eval(2 * k + 2);
			node[k] = f(node[2 * k + 1], node[2 * k + 2]);
		}
	}
	int search1(int loc, int inf) {
		int k = 0, l = 0, r = n;
		stack<P> st;
		while (k < n - 1) {
			eval(k);
			st.push({ l,r });
			if (loc < (l + r) / 2) {
				k = 2 * k + 1;
				r = (l + r) / 2;
			}
			else {
				k = 2 * k + 2;
				l = (l + r) / 2;
			}
		}
		eval(k);

		k = loc + n - 1;
		while (k > 0) {
			int pre = k;
			k = (k - 1) / 2;
			if (2 * k + 2 == pre)continue;
			else {
				eval(2 * k + 2);
				if (node[2 * k + 2].second >= inf) {
					k = 2 * k + 2; break;
				}
			}
		}
		if (k == 0)return -1;
		while (k < n - 1) {
			eval(2 * k + 1);
			if (node[2 * k + 1].second >= inf) {
				k = 2 * k + 1;
			}
			else {
				eval(2 * k + 2);
				k = 2 * k + 2;
			}
		}
		return k - (n - 1);
	}
	int search2(int loc, int sup) {
		
		int k = 0, l = 0, r = n;
		stack<P> st;
		while (k < n - 1) {
			eval(k);
			st.push({ l,r });
			if (loc < (l + r) / 2) {
				k = 2 * k + 1;
				r = (l + r) / 2;
			}
			else {
				k = 2 * k + 2;
				l = (l + r) / 2;
			}
		}
		eval(k);

		k = loc + n - 1;
		if (node[k].first == sup || node[k].first == sup - 1)return loc;
		while (k > 0) {
			int pre = k;
			k = (k - 1) / 2;
			if (2 * k + 2 == pre)continue;
			else {
				eval(2 * k + 2);
				if (node[2 * k + 2].first <= sup) {
					k = 2 * k + 2; break;
				}
			}
		}
		if (k == 0)return -1;
		while (k < n - 1) {
			eval(2 * k + 1);
			if (node[2 * k + 1].first <= sup) {
				k = 2 * k + 1;
			}
			else {
				eval(2 * k + 2);
				k = 2 * k + 2;
			}
		}
		if (node[k].first == sup - 1 || node[k].first == sup)return k - (n - 1);
		else return -1;
	}
	int search(int loc, int c) {
		int r = search1(loc, c);
		if (r < 0)return -1;
		return search2(r,c+1);
	}
};


void solve(){
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	vector<P> v;
	rep(i, n) {
		v.push_back({ a[i],i });
	}
	sort(all(v));
	vector<int> loc(n);
	rep(i, n) {
		loc[v[i].second] = i;
	}
	
	SegT gt(n);
	set<int> st;
	int ma = -mod;
	rep(i, n) {
		ma = max(ma, a[i]);
		int id = loc[i];
		int pre;
		st.insert(id);
		if ((*st.begin())==id) {
			pre = 0;
		}
		else {
			auto itr = st.find(id); itr--;
			int pid = *itr;
			int dif = gt.query(pid, pid + 1).first;
			int cc = v[pid].first - dif;
			if (cc < v[pid].first)cc++;
			else if (cc > v[pid].first)cc--;
			pre = cc;
		}
		//cout << "? " << pre << "\n";
		gt.update(id, a[i]-pre);
		if (pre == a[i]) {
			//
		}
		else if (pre < a[i]) {
			int ri = gt.search(id, 0);
			if (ri < 0) {
				gt.add(-1, id + 1, n);
			}
			else {
				gt.add(-1, id + 1, ri + 1);
			}
		}
		else if (pre > a[i]) {
			int ri = gt.search(id, -1);
			//cout << "! " << i << " " << ri << "\n";
			if (ri < 0) {
				gt.add(1, id + 1, n);
			}
			else {
				gt.add(1, id + 1, ri + 1);
			}
		}
		int idlas = *st.rbegin();
		int las = gt.query(idlas, idlas + 1).first;
		//cout << "hoge " << las << "\n";
		las = ma - las;
		if (las < ma)las++;
		else if (las > ma)las--;
		cout << las << "\n";
	}
}




signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
//	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}