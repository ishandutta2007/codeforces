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
	ll real() const { return (x+MOD) % MOD; }
	Int operator + (const Int& o) const { return Int(x+o.x); }
	Int operator - (const Int& o) const { return Int(x-o.x); }
	Int operator * (const Int& o) const { return Int(x*o.x); }
	Int& operator *= (const Int& o) { x = x*o.x % MOD; return *this; }
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

ll mem_rt[1789], inv_rt[1789];
ll prim_root(int dir, int m) {
	auto mem = (dir<0 ? inv_rt : mem_rt);
	int id = __builtin_clz(m);
	if(mem[id]) return mem[id];
	ll root = power(3, (MOD-1)/m);
	if(dir<0) root = inverse(root);
	return mem[id] = root;
}

// *** Fast Fourier Transform (Iterative) ***
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
vector<ll> convolution(vector<ll> a, vector<ll> b) {
  int sz = a.size()+b.size()-1;
  int n  = 1<<int(ceil(log2(sz)));
  vector<Int> av(n,0), bv(n,0), cv;
  for (int i=0; i<a.size(); i++) av[i] = a[i];
  for (int i=0; i<b.size(); i++) bv[i] = b[i];
  cv = FFT(bv); bv = FFT(av);
  for (int i=0; i<n; i++) av[i] = bv[i]*cv[i];
  cv = FFT(av, -1);
  // cv is now the convolution of a and b: cv[k] = sum_(i+j=k) a[i]*b[j]
  vector<ll> c(sz);
  for (int i=0; i<sz; i++)
    c[i] = cv[i].real(); // if result should be int, use int(cv[i].real()+0.5)
  return c;
}

const int N = 3e5+1;
int cnt[N];
ll fact[N], invf[N];

ll ncr(ll n, ll r) {
	if(r<0 || r>n) return 0;
	return fact[n] * invf[r] % MOD * invf[n-r] % MOD;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	fact[0] = invf[0] = 1;
	for(int i=1;i<N;i++) {
		fact[i] = fact[i-1] * i % MOD;
		invf[i] = inverse(fact[i]);
	}

	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i=0;i<n;i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	vector<ll> one[k], two[k], res[k];
	int b[k];
	for(int i=0;i<k;i++) {
		cin >> b[i];
		//cerr<<"do red "<<b[i]<<nl;
		int onedeg = 0;
		int twodeg = 0;
		for(int j=0;j<b[i];j++) {
			if(cnt[j]==1) onedeg++;
			else if(cnt[j]>1) twodeg++;
		}
		//cerr<<"onedeg: "<<onedeg<<nl;
		//cerr<<"twodeg: "<<twodeg<<nl;

		one[i].resize(onedeg+1);
		two[i].resize(2*twodeg+1);
		ll twopow = 1;
		for(int j=0;j<=onedeg;j++) {
			one[i][j] = ncr(onedeg,j) * twopow % MOD;
			//cerr<<"one "<<j<<" -> "<<one[i][j] << nl;
			twopow = (twopow * 2) % MOD;
		}
		for(int j=0;j<=2*twodeg;j++) {
			two[i][j] = ncr(2*twodeg,j);
			//cerr<<"two "<<j<<" -> "<<two[i][j] << nl;
		}
		res[i] = convolution(move(one[i]), move(two[i]));
		//cerr<<nl;
	}

	int m;
	cin >> m;
	for(int i=0;i<m;i++) {
		int p;
		cin >> p;
		p /= 2;
		ll ans = 0;
		for (int j=0;j<k;j++) {
			if(p > b[j] && p-b[j]-1 < res[j].size()) {
				//cerr<<"try red size "<<b[j]<<" -> query "<<p-b[j]-1 << nl;
				ans += res[j][p-b[j]-1];
				//cerr<<"add "<<res[j][p-b[j]-1] << nl;
			}
		}
		cout << ans % MOD << nl;
	}

	return 0;
}