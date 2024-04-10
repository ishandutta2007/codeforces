#include <bits/stdc++.h>
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
const ll mod = (119 << 23) + 1, root = 3; // = 998244353
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

int main(){
	ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vl a(10);
    rep(i,0,k) {
        int d;
        cin >> d;
        a[d] = 1;
    }
    vl b(1);
    b[0] = 1;
    int m = n/2;
    while (m) {
        if (m%2) {
            b = conv(b, a);
        }
        m /= 2;
        if (m) {
            a = conv(a, a);
        }
    }
    ll ans = 0;
    for (ll x : b) {
        x %= mod;
        ans += x*x;
        ans %= mod;
    }
    cout << ans << endl;
}