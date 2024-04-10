#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 32000000; //check the limits, dummy


vi primes, leastFac;
void compPrimes(int N) {
	F0R(i, N) {
		leastFac.pb(0);
	}
	leastFac[0] = 1; leastFac[1] = 1;
	FOR(i, 2, N) {
		if (leastFac[i] == 0) {
			primes.pb(i);
			leastFac[i] = i;
		}
		for (int j = 0; j < sz(primes) && i*primes[j] < N && primes[j] <= leastFac[i]; j++) {
			leastFac[i*primes[j]] = primes[j];
		}
	}
}

ll modExp(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}

ll inv(ll base) {
    int g = MOD, r = base, x = 0, y = 1;
    while (r != 0) {
        int q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }
    return x < 0 ? x+MOD : x;
}

ll mul(ll A, ll B) {
	return (A*B)%MOD;
}

ll add(ll A, ll B) {
	return (A+B)%MOD;
}

ll dvd(ll A, ll B) {
    return mul(A, inv(B));
}

ll sub(ll A, ll B) {
    return (A-B+MOD)%MOD;
}

ll* facs = new ll[100];
ll* facInvs = new ll[100];

ll choose(ll a, ll b) {
	if (b > a) return 0;
	if (a < 0) return 0;
	if (b < 0) return 0;
    ll cur = facs[a];
    cur = mul(cur, facInvs[b]);
    cur = mul(cur, facInvs[a-b]);
    return cur;
}

void initFacs() {
	facs[0] = 1;
	facInvs[0] = 1;
	FOR(i, 1, 80) {
		facs[i] = (facs[i-1] * i) % MOD;
		facInvs[i] = inv(facs[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    compPrimes(MX);
    initFacs();

    vl fac;
    ll D; cin >> D;
    F0R(i, sz(primes)) {
        ll cur = primes[i];
        if (D % cur == 0) {
            while (D % cur == 0) {
                D /= cur; 
            }
            fac.pb(cur);
        }
    }
    if (D > 1) {
        fac.pb(D);
    }
    int Q; cin >> Q;
    while(Q--) {
        ll A, B; cin >> A >> B;
        ll G = __gcd(A, B); A /= G; B /= G;
        ll ans = 1;
        ll ta = 0, tb = 0;
        F0R(i, sz(fac)) {
            ll ca = 0, cb = 0;
            while (A % fac[i] == 0) {
                ca++;  A/= fac[i];
            }
            while (B % fac[i] == 0) {
                cb++; B /= fac[i];
            }
            ta += ca; tb += cb;
            ans *= facInvs[ca]; ans %= MOD;
            ans *= facInvs[cb]; ans %= MOD;
        }
        ans *= facs[ta]; ans %= MOD;
        ans *= facs[tb]; ans %= MOD;
        cout << ans << '\n';
    }

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343