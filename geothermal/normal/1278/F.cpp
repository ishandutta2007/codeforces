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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 10001; //check the limits, dummy
 
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
struct Frac {
	ll A, B;
    Frac(ll X, ll Y) {
        A = X; B = Y;
    }

	ll ans() {
		return dvd(A, B);
	}

	Frac operator+(const Frac& F) {
		ll num = add(mul(A, F.B), mul(B, F.A));
		ll den = mul(B, F.B);
		Frac res(num, den);
		return res;
	}

	Frac operator-(const Frac& F) {
		ll num = sub(mul(A, F.B), mul(B, F.A));
		ll den = mul(B, F.B);
		Frac res(num, den);
		return res;
	}

	Frac operator*(const Frac& F) {
		ll num = mul(A, F.A);
		ll den = mul(B, F.B);
		Frac res(num, den);
		return res;
	}

	Frac operator/(const Frac& F) {
		ll num = mul(A, F.B);
		ll den = mul(B, F.A);
		Frac res(num, den);
		return res;
	}

	Frac& operator+=(const Frac& F) { return *this = (*this) + F; }
	Frac& operator-=(const Frac& F) { return *this = (*this) - F; }
	Frac& operator*=(const Frac& F) { return *this = (*this) * F; }
	Frac& operator/=(const Frac& F) { return *this = (*this) / F; }
};

ll* facs = new ll[MX];
ll* facInvs = new ll[MX];

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
	FOR(i, 1, MX) {
		facs[i] = (facs[i-1] * i) % MOD;
		facInvs[i] = inv(facs[i]);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    ll N, M, K; cin >> N >> M >> K;
    initFacs();
    ll dist[K+1][K+1];
    F0R(i, K+1) F0R(j, K+1) dist[i][j] = 0;

    Frac ans(0ll, 1ll);
    ll kExps[K+1]; F0R(i, K+1) kExps[i] = modExp(i, K);
    FOR(i, 1, K+1) {
        Frac cur(1ll, 1ll);
        F0R(j, i) {
            cur *= Frac(N-j, 1ll);

        }
        cur *= Frac(1ll, facs[i]);
        cur *= Frac(1ll, modExp(M, i));
        ll counts = kExps[i];
        FORd(j, 1, i) {
            ll curVal = choose(i, j);
            curVal *= kExps[j]; curVal %= MOD;
            if (i % 2 != j % 2) curVal = MOD-curVal;
            curVal %= MOD;
            counts += curVal; counts %= MOD;
        }

        cur *= Frac(counts, 1ll);
        
        ans += cur;

    }

    cout << ans.ans() << endl;

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343