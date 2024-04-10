#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

ll powerMod(ll a, ll x) {
    if (!x)
        return 1;
    if (x%2)
        return (a*powerMod((a*a)%MOD, x/2))%MOD;
    return powerMod((a*a)%MOD, x/2);
}

ll inv(ll a) {
    return powerMod(a, MOD-2);
}


ll mod = (119 << 23) + 1, root = 3; // = 998244353
// For p < 2^30 there is also e.g. (5 << 25, 3), (7 << 26, 3),
// (479 << 21, 3) and (483 << 21, 5). The last two are > 10^9.

ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	ll x = modpow(a * a % mod, e >> 1);
	return e & 1 ? x * a % mod : x;
}

typedef vector<ll> vl;
void ntt(ll* x, ll* temp, ll* roots, int N, int skip) {
	if (N == 1) return;
	int n2 = N/2;
	ntt(x     , temp, roots, n2, skip*2);
	ntt(x+skip, temp, roots, n2, skip*2);
	rep(i,0,N) temp[i] = x[i*skip];
	rep(i,0,n2) {
		ll s = temp[2*i], t = temp[2*i+1] * roots[skip*i];
		x[skip*i] = (s + t) % mod; x[skip*(i+n2)] = (s - t) % mod;
	}
}
void ntt(vl& x, bool inv = false) {
	ll e = modpow(root, (mod-1) / sz(x));
	if (inv) e = modpow(e, mod-2);
	vl roots(sz(x), 1), temp = roots;
	rep(i,1,sz(x)) roots[i] = roots[i-1] * e % mod;
	ntt(&x[0], &temp[0], &roots[0], sz(x), 1);
}
vl conv(vl a, vl b) {
	int s = sz(a) + sz(b) - 1; if (s <= 0) return {};
	int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
	if (s <= 200) { // (factor 10 optimization for |a|,|b| = 10)
		vl c(s);
		rep(i,0,sz(a)) rep(j,0,sz(b))
			c[i + j] = (c[i + j] + a[i] * b[j]) % mod;
		return c;
	}
	a.resize(n); ntt(a);
	b.resize(n); ntt(b);
	vl c(n); ll d = modpow(n, mod-2);
	rep(i,0,n) c[i] = a[i] * b[i] % mod * d % mod;
	ntt(c, true); c.resize(s); return c;
}

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

template<class Z> Z chinese(Z a, Z m, Z b, Z n) {
	Z x, y; euclid(m, n, x, y);
	Z ret = a * (y + m) % m * n + b * (x + n) % n * m;
	if (ret >= m * n) ret -= m * n;
	return ret;
}

vl conv2(vl a, vl b) {
    mod = (119 << 23) + 1;
    ll mod1 = mod;
    vl c1 = conv(a, b);
    mod = (5 << 25) + 1;
    ll mod2 = mod;
    vl c2 = conv(a, b);
    vl c(sz(a));
    rep(i,0,sz(c)) {
        c[i] = chinese(c1[i], mod1, c2[i], mod2);
        c[i] %= MOD;
    }
    return c;
}


ll fac[2000005];

int main(){
    fac[0] = 1;
    rep(i,1,2000005)
        fac[i] = (fac[i-1]*i)%MOD;
	ios::sync_with_stdio(0);
    int n, m, AA, BB;
    cin >> n >> m >> AA >> BB;
    ll ans = 0;
    rep(k,1,n) {
        if (k > m)
            continue;
        ll term = fac[m-1];
        term = (term*inv(fac[m-k]))%MOD;
        term = (term*inv(fac[k-1]))%MOD;
        term = (term*fac[n-2])%MOD;
        term = (term*inv(fac[n-k-1]))%MOD;
        term = (term*powerMod(m, n-k-1))%MOD;
        if (k < n-1) {
            term = (term*(k+1))%MOD;
            term = (term*powerMod(n, n-k-2))%MOD;
        }
        //cerr << term << endl;
        ans = (ans + term)%MOD;
    }
    cout << ans << endl;
    /*vector<ll> a(n);    
    a[0] = 1;
    rep(i,1,n) {
        a[i] = ((powerMod(i, i-1)*inv(fac[i]))%MOD)*(k+1);
        a[i] %= MOD;
    }
    ll exponent = 20;
    rep(i,0,exponent) {
        a = conv2(a, a);
    }
    ll ans = 0;
    rep(k,1,n) {
        ll term = fac[m-1];
        term = (term*fac[n-2])%MOD;
        term = (term*inv(fac[k-1]))%MOD;
        term = (term*inv(fac[m-k]))%MOD;
        term = (term*powerMod(n-k-1))%MOD;
        ll additions = a[n-k-1];
        additions = (additions*inv(fac[1<<exponent]))%MOD;
        term = (term*a[n-k-1])%MOD;
        ans = (ans + term) % MOD;
    }
    if (ans < 0)
        ans += MOD;
    cout << ans << endl;*/
}