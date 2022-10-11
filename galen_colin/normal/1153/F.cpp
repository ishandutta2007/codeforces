#include "bits/stdc++.h"
using namespace std;
 
/* 
find my code templates at https://github.com/galencolin/cp-templates
also maybe subscribe please thanks 
*/
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
 
typedef long long ll;
// typedef int ll;
// #pragma warning("int")
 
typedef long double lld;
typedef unsigned long long ull;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
// const int mod = 1000000007;
const ll mod = 998244353;
// ll mod;
 
namespace modop {
	ll madd(ll a, ll b) {
	  return (a + b) % mod;
	}
	ll msub(ll a, ll b) {
	  return (((a - b) % mod) + mod) % mod;
	}
	ll mmul(ll a, ll b) {
	  return ((a % mod) * (b % mod)) % mod;
	}
	ll mpow(ll base, ll exp) {
	  ll res = 1;
	  while (exp) {
		if (exp % 2 == 1){
			res = (res * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	  }
	  return res;
	}
	ll minv(ll base) {
	  return mpow(base, mod - 2);
	}
	ll mdiv(ll a, ll b) {
	  return mmul(a, minv(b));
	}
	
	const ll FACTORIAL_SIZE = 1.1e6;
	ll fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
	bool __factorials_generated__ = 0;
	void gen_factorial(ll n) {
		__factorials_generated__ = 1;
		fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
		
		for (ll i = 2; i <= n; i++) {
			fact[i] = (i * fact[i - 1]) % mod;
		}
		ifact[n] = minv(fact[n]);
		for (ll i = n - 1; i >= 2; i--) {
			ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
		}
	}
	ll nck(ll n, ll k) {
		if (!__factorials_generated__) {
			cerr << "Call gen_factorial you dope" << endl;
			exit(1);
		}
		ll den = (ifact[k] * ifact[n - k]) % mod;
		return (den * fact[n]) % mod;
	}
}

using namespace modop;

const ll root = 15311432;
const ll root_1 = 469870224;
const ll root_pw = 1 << 23;

void fft(vector<ll> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        ll wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            ll w = 1;
            for (int j = 0; j < len / 2; j++) {
                ll u = a[i+j], v = (1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        ll n_1 = minv(n);
        for (ll & x : a)
            x = (ll)(1LL * x * n_1 % mod);
    }
}

vector<ll> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (ll i = 0; i < n; i++)
        fa[i] = (fa[i] * fb[i]) % mod;
    fft(fa, true);

    return fa;
}
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 15258;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

const ll msq = mod * mod;
vector<ll> powa[2005];
vector<ll> powb[2005];
ll pows[5005];
ll invs[5005];

vector<ll> mul(vector<ll> a, vector<ll> b) {
	vector<ll> c(a.size() + b.size());
	
	for (ll i = 0; i < a.size(); i++) {
		for (ll j = 0; j < b.size(); j++) {
			// assert(a[i] < mod && b[j] < mod);
			c[i + j] = (c[i + j] + a[i] * b[j] >= msq ? c[i + j] + a[i] * b[j] - msq : c[i + j] + a[i] * b[j]);
		}
	}
	
	for (ll& x: c) x %= mod;
	while (c.back() == 0) c.pop_back();
	
	return c;
}
 
/* 
	try to think a bit more to simplify if sol is complicated
	also look for edge cases, please
*/
void solve(int tc = 0) {
	cin >> n >> k >> y;
			
	pows[0] = 1;
	pows[1] = y;
	for (ll i = 2; i <= 5002; i++) pows[i] = (y * pows[i - 1]) % mod;
	
	invs[1] = 1;
	for (ll i = 2; i <= 5002; i++) invs[i] = minv(i);
	
	gen_factorial(1e4);
	
	{
		powa[0] = vector<ll>(1, 1);
		vector<ll> a = {0, y, mod - 1};
		powa[1] = a;
		
		for (ll i = 2; i <= n; i++) powa[i] = mul(powa[i - 1], a);
	}
	
	{
		powb[0] = vector<ll>(1, 1);
		vector<ll> a = {(y * y) % mod, (3 * mod - 2 * y) % mod, 2};
		powb[1] = a;
		
		for (ll i = 2; i <= n; i++) powb[i] = mul(powb[i - 1], a);
	}
	
	ll ans = 0;
	for (ll a = k; a <= n; a++) {
		ll cur = nck(n, a);
		cur = (cur * mpow(2, a)) % mod;
		cur = cur * minv(mpow(y, 2 * n)) % mod;
		
		vector<ll> c = multiply(powa[a], powb[n - a]);
						
		ll tot = 0;
		for (ll i = 0; i < c.size(); i++) {
			ll cur = c[i];
			cur = (cur * pows[i + 1]) % mod;
			cur = (cur * invs[i + 1]) % mod;
			
			tot = (tot + cur) % mod;
		}
		
		cur = (cur * tot) % mod;
		ans = (ans + cur) % mod;
	}
	cout << ans << '\n';
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("code");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc2.cpp", "w", stdout);
		
	cout << setprecision(15) << fixed;
	
 
		
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}