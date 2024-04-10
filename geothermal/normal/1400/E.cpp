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
const int MX = 5001; //check the limits, dummy
int N;
ll A[MX];

ll solve(int L, int R) {
    if (R < L) return 0;
    ll lo = 1e9;
    FOR(i, L, R+1) {
        ckmin(lo, A[i]);
    }
    int S = -1;
    ll ans = lo;
    FOR(i, L, R+1) {
        A[i] -= lo;
        if (A[i] == 0) {
            if (S != -1) ans += solve(S, i-1);
            S = -1;
        } else {
            if (S == -1) S = i;
        }
    }
    if (S != -1 && A[R] != 0) ans += solve(S, R);

    return min(ans, (ll) R-L+1);

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N; F0R(i, N) cin >> A[i];


    cout << solve(0, N-1) << nl;

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343