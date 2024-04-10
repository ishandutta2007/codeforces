#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
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
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
pi merge (pi X, int A) {
    if (X.f > A) {
        return {A, X.f};
    } else if (X.s > A) {
        return {X.f, A};
    } else return X;
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
	
    int N; cin >> N;
    compPrimes(1000);

    map<ll, pi> res;
    F0R(i, sz(primes)) {
        res.ins({primes[i], {1000, 1000}});
    }
    map<ll, int> use;
    F0R(i, N) {
        int X; cin >> X;
        F0R(j, sz(primes)) {
            int cnt = 0;
            while (X % primes[j] == 0) {
                cnt++; X /= primes[j];
            }
            res[primes[j]] = merge(res[primes[j]], cnt);
        }
        if (X > 1) {
            use[X]++;
        }
    }
    ll ans = 1;
    for(auto it : res) {
        F0R(i, it.s.s) {
            ans *= it.f;
        }
    }
    for(auto it : use) {
        if (it.s >= N-1) {
            ans *= it.f;
        }
    }

    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343