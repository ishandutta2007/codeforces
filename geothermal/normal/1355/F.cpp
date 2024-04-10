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
	
    compPrimes(1000);
    int T; cin >> T;
    while(T--) {
    ll ans = 2;
    int p = 0;
    vpl cur;
    F0R(iter, 22) {
        ld sum = 0;
        F0R(i, sz(cur)) {
            sum += log10(cur[i].f) * cur[i].s;
        }
        while (sum < 17.99) {
            sum += log10(primes[p]);
            if (sum > 17.99) break;
            cur.pb({primes[p], 1});
            p++;
        }
        ll q = 1;
        F0R(i, sz(cur)) {
            F0R(j, cur[i].s) {
                q *= cur[i].f;
            }
        }
        cout << "? " << q << endl;
        ll X; cin >> X;
        vpl nc;
        F0R(i, sz(cur)) {
            ll val = 1;
            F0R(j, cur[i].s) {
                val *= cur[i].f;
            }
            if (X % val == 0) {
                nc.pb({cur[i].f, cur[i].s+1});
                ans *= cur[i].s + 1;
                ans /= cur[i].s;
            }
        }
        cur = nc;
    }

    cout << "! " << ans << endl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343