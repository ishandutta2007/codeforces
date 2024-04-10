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

    uniform_int_distribution<int> dist(0, N-1);

    vl A(N); F0R(i, N) cin >> A[i];

    compPrimes(1000000);

    map<ll, int> cnt;
    vl tbf;
    F0R(iter, 400) {
        int p = dist(rng);
        tbf.pb(A[p]-1); tbf.pb(A[p]); tbf.pb(A[p]+1);
    }

    F0R(i, sz(tbf)) {
        ll x = tbf[i];
        if (x == 0) continue;
        F0R(j, sz(primes)) {
            if (x % primes[j] == 0) {
                cnt[primes[j]]++;
                while (x % primes[j] == 0) x /= primes[j];
            }
        }
        if (x > 1) cnt[x]++;
    }

    vpl freq;
    trav(p, cnt) {
        freq.pb({p.s, p.f});
    }
    sort(all(freq)); reverse(all(freq));
    ll ans = N;
    F0R(j, min(sz(freq), 500)) {
        ll cur = 0;
        ll p = freq[j].s;
        F0R(i, N) {
            ll x = p-A[i]%p;
            if (A[i] >= p) ckmin(x, A[i]%p);
            cur += x;
        }
        ans = min(ans, cur);
    }
    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343