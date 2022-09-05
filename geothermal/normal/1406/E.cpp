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
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
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
	
    int N; cin >> N;
    compPrimes(MX);
    vi smol, large;
    trav(a, primes) {
        if (a > N) continue;
        if (a < 400) {
            smol.pb(a);
        } else {
            large.pb(a);
        }
    }
    ll ans = 1;
    trav(a, smol) {
        ll cur = a;
        cout << "B " << cur << endl;
        int res; cin >> res;
        while (true) {
            if (cur > N) break;
            cout << "A " << cur << endl;
            cin >> res;
            if (res > 0) {
                ans *= a;
            } else break;
            cur *= a;
        }
    }

    int BS = 100;
    int cnt;
    cout << "A 1" << endl;
    cin >> cnt;
    for (int b = 0; b < sz(large); b += BS) {
        int sum = 0;
        FOR(i, b, min(b+BS, sz(large))) {
            cout << "B " << large[i] << endl;
            int res; cin >> res; sum += res;
        }
        int cnt2; cout << "A 1" << endl; cin >> cnt2;
        if (cnt - sum != cnt2) {
            FOR(i, b, min(b+BS, sz(large))) {
                cout << "A " << large[i] << endl;
                int res; cin >> res; if (res > 0) ans *= large[i];
            }
        }
        cnt = cnt2;
    }
    cout << "C " << ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343