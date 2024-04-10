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
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy
 
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
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	int base = uniform_int_distribution<int>(1000, MOD-2)(rng);
    compPrimes(100000);
    int N, K; cin >> N >> K;
    int data[N]; F0R(i, N) cin >> data[i];
    map<pair<pi, int>, ll> hashes;
    ll ans = 0;
    int pos[MX]; F0R(i, sz(primes)) pos[primes[i]] = i;
    F0R(i, N) {
        pi cur, rev; cur.f = 0; cur.s = 0; rev.f = 0; rev.s = 0;
        F0R(j, 400) { 
            int curPrime = primes[j];
            int val = 0;
            while (data[i] % curPrime == 0) {
                val++; data[i] /= curPrime;

            }
            val %= K; int reVal = K-val; reVal %= K;
            cur.f *= base; cur.f += val; cur.f %= MOD;
            cur.s *= base; cur.s += val; cur.s %= MOD+2;
            rev.f *= base; rev.f += reVal; rev.f %= MOD;
            rev.s *= base; rev.s += reVal; rev.s %= MOD+2;

        }
        ll dif = sz(primes) - 400;
        ll other = 0;
        if (data[i] > 1) {
            int P = pos[data[i]];
            other = P;
        }


        if (hashes.count({rev, other}) && (other == 0 || K == 2)) {
            ans += hashes[{rev, other}];
        }
        if (!hashes.count({cur, other})) hashes.insert({{cur, other}, 0});
        hashes[{cur, other}]++;
    }
    cout << ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343