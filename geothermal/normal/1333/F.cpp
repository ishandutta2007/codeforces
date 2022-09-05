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
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 500001; //check the limits, dummy


vi primes, leastFac;
void compPrimes(int N) {
	F0R(i, N+1) {
		leastFac.pb(0);
	}
	leastFac[0] = 1; leastFac[1] = 1;
	FOR(i, 2, N+1) {
		if (leastFac[i] == 0) {
			primes.pb(i);
			leastFac[i] = i;
		}
		for (int j = 0; j < sz(primes) && i*primes[j] <= N && primes[j] <= leastFac[i]; j++) {
			leastFac[i*primes[j]] = primes[j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    compPrimes(N);
    int cnt[N+1]; 
    int cur = N; cnt[N] = N;
    bool act[N+1]; F0R(i, N+1) act[i] = true;
    FORd(i, 2, N+1) {
        for (int j = 2; i * j <= N; j++) {
            if (act[i*j]) {
                act[i*j] = false; cur--;
            }
        }
        cnt[i-1] = cur;
    }
//    F0R(i, sz(primes)) act[primes[i]] = true;
/*    FOR(i, 2, N+1) {
        int hiPrime = 1;
        int X = i;
        while (X > 1) {
            hiPrime = leastFac[X]; X /= leastFac[X];
        }
        F0R(j, sz(primes)) {
            int val = primes[j] * i;
            if (primes[j] > hiPrime) break;
            if (val > N) break;
            if (!act[val]) {
                act[val] = true; cur++;
            }
        }
        cnt[i] = cur;
    }*/
    int val = 1;
    FOR(i, 2, N+1) {
        while (cnt[val] < i) val++;
        cout << val << " ";
    }
    cout << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343