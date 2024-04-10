#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>

using namespace std;

void re(long long& x);

template<class T, class... Ts> void re(T& t, Ts&... ts);

void pr(long long x);

void pr(const char *x);

void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);

#ifdef FFDBG

#else
#define dbg(x...) dsfdsfsdfasd
#endif

template <typename T> T extGcd(T a, T b, T& x, T& y);
template <typename T> T modInv(T a, T m);

typedef long long ll;

#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)

const ll mod = 1000000007;

ll fac[5100];
ll ifac[5100];
ll inv[5100];

typedef vector<long long> vd;
vd interpolate(vd x, vd y, int n) {
	vd res(n), temp(n);
	rep(k,0,n-1) rep(i,k+1,n) {
        int dy = (y[i] - y[k]);
        
        y[i] = (dy * inv[i-k]) % mod;
    }
	ll last = 0; temp[0] = 1;
	rep(k,0,n) rep(i,0,n) {
		res[i] = (res[i] +  y[k] * temp[i])%mod;
		swap(last, temp[i]);
		temp[i] = (temp[i] - last * x[k]) % mod;
        if (temp[i] < 0) temp[i] += mod;
	}
	return res;
}

ll C(int n, int k) {
    ll t = (fac[n]*1ll*ifac[k])%mod;
    return (t*ifac[n-k])%mod;
}

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

ll signpow(ll b, ll e) {
    ll r = modpow(b, abs(e));
    if (e < 0) r = modInv(r, mod);
    return r;
}

ll pi[5100];

void solve()
{
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= 5010; i++) {
        fac[i] = (fac[i-1] * 1ll * i) % mod;
        ifac[i] = (ifac[i-1] * 1ll * modInv(i,(int)mod)) % mod;
    }

    ll n, k;
    re(n,k);
    vector<ll> xs;
    vector<ll> vals;

    rep(i,0,k+1) pi[i] = modpow(i,k);
    rep(i,0,k+1) inv[i] = modInv(i,(int)mod);

    rep(nn,0,k+1) {
        ll cur = 0;
        rep(i,0,nn+1) cur = (cur + C(nn,i) * pi[i]) % mod;
        cur = (cur * signpow(2,k-nn)) % mod;
        xs.push_back(nn);
        vals.push_back(cur);
        //dbg(nn,vals.back());
    }
    
    vector<ll> rec = interpolate(xs, vals, k+1);
    // rep(i,0,k+1) dbg(i,rec[i]);
    vals.resize(sz(rec));
    
    ll ans = 0;
    ll p = 1;
    rep(i,0,k+1) {
         ans = (ans + p * 1ll * rec[i]) % mod;
         p = (p * n) % mod;
    } 
    ans = (ans * signpow(2,n-k)) % mod;
    if (ans < 0) ans += mod;
    ps(ans);
    
    // ll ans = 1;
    // rep(i,0,k) ans = (ans * (n+i)) % mod;
    
    // if (n - k >= 0) ans = (ans * modpow(2,n-k)) % mod;
    // else ans = (ans * modInv(modpow(2, k-n), mod)) % mod;
    // ps(ans);
}

int main() {

    solve();
}

template <typename T>
T extGcd(T a, T b, T& x, T& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	else {
		int g = extGcd(b, a % b, y, x);
		y -= a / b * x;
		return g;
	}
}

template <typename T>
T modInv(T a, T m) {
	T x, y;
	extGcd(a, m, x, y);
	return (x % m + m) % m;
}

void re(long long& x) { scanf("%lld", &x); }

template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}

void pr(long long x) { printf("%lld", x); }

void pr(const char *x) { printf("%s", x); }

void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}