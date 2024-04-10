#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Int {
	ll x;
	Int(ll v=0): x(v%MOD) {}
	int real() const { return (x+MOD) % MOD; }
	Int operator * (const Int& o) const { return Int(x*o.x); }
	Int operator + (const Int& o) const { return Int(x+o.x); }
	Int operator - (const Int& o) const { return Int(x-o.x); }
	Int& operator *= (const Int& o) { x = x*o.x%MOD; return *this; }
};

ll power(ll n, ll e) {
	ll res = 1;
	for(;e;e/=2) {
		if(e&1) res = res*n % MOD;
		n = n*n % MOD;
	}
	return res;
}

ll inverse(ll n) {
	return power(n, MOD-2);
}

int mem_rt[1789], mem_inv[1789];
ll prim_root(int dir, int m) {
	int clz = __builtin_clz(m);
	auto mem = (dir > 0 ? mem_rt : mem_inv);
	if(mem[clz]) return mem[clz];
	int e = 7*17;
	for(;m<1<<23;m<<=1) {
		e *= 2;
	}
	ll root = power(3, e);
	if(dir < 0) root = inverse(root);
	return mem[clz] = root;
}

// Reverse-bitmasking adder. rev_incr(a,n) returns REV(REV(a)+1)
inline int rev_incr(int a, int n) { int msk = n/2, cnt=0;
  while ( a&msk ) { cnt++; a<<=1; }
  a &= msk-1; a |= msk;
  while ( cnt-- ) a >>= 1;
  return a; }
// Compute in V the discrete fourier transform of v
// dir=1: forward transform, evaluates polynomial at complex roots of unity
// dir=-1: inverse transform, interpolates point-value form to coefficients
vector<Int> FFT(vector<Int> v, int dir=1) {
  Int wm,w,u,t; int n = v.size(); vector<Int> V(n);
	Int invn = inverse(n);
  for (int k=0,a=0; k<n; ++k, a=rev_incr(a,n)) {
    V[a] = (dir>0 ? v[k] : v[k]*invn);
	}
  for (int m=2; m<=n; m<<=1) {
    wm = prim_root(dir, m);
    for (int k=0; k<n; k+=m) {
      w = 1;
      for (int j=0; j<m/2; ++j, w*=wm) {
        u = V[k + j];
        t = w * V[k + j + m/2];
        V[k + j] = u + t;
        V[k + j + m/2] = u - t;
      } } } return V; }
// Multiply two polynomials sum_i a[i]x^i and sum_i b[i]x^i
vector<int> convolution(vector<int> a, vector<int> b) {
  int sz = a.size()+b.size()-1;
  int n  = 1<<int(ceil(log2(sz)));
  vector<Int> av(n,0), bv(n,0), cv;
  for (int i=0; i<a.size(); i++) av[i] = a[i];
  for (int i=0; i<b.size(); i++) bv[i] = b[i];
  cv = FFT(bv); bv = FFT(av);
  for (int i=0; i<n; i++) av[i] = bv[i]*cv[i];
  cv = FFT(av, -1);
  // cv is now the convolution of a and b: cv[k] = sum_(i+j=k) a[i]*b[j]
  vector<int> c(sz);
  for (int i=0; i<sz; i++)
    c[i] = cv[i].real(); // if result should be int, use int(cv[i].real()+0.5)
  return c;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	unordered_map<int,int> cnt;
	for (int i=0;i<n;i++) {
		int v;
		cin >> v;
		cnt[v]++;
	}

	vector<pii> ord;
	for(const auto& it:cnt) {
		ord.push_back(make_pair(it.second,it.first));
	}
	//sort(ord.begin(),ord.end());

	vector<vector<int>> v;
	for(const auto& it:ord) {
		vector<int> cur;
		for(int i=0;i<=it.first;i++) {
			cur.push_back(1);
		}
		v.push_back(move(cur));
	}

	while(v.size() != 1) {
		vector<vector<int>> nxt;
		int m = v.size();
		for(int i=0;i<m;i+=2) {
			if(i+1==m) {
				nxt.push_back(move(v[i]));
			} else {
				nxt.push_back(convolution(move(v[i]),move(v[i+1])));
			}
		}
		v = move(nxt);
	}

	cout << v[0][n/2] << nl;

	return 0;
}