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
 
ll div(ll X) {
    if (X >= 0) {
        return X/2;
    } else {
        return X/2 - (X%2!=0?1:0);
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    ll A[N]; F0R(i, N) cin >> A[i];
    ll dif[N-1];
    F0R(i, N-1) dif[i] = A[i+1] - A[i];
    ll S = A[0];
    ll T = 0; F0R(i, N-1) if (dif[i] > 0) T += dif[i];
    cout << div(S+T+1) << nl;
    int Q; cin >> Q;
    while(Q--) {
        int L, R; ll D; cin >> L >> R >> D;
        L--; R--;
        if (L == 0) S += D;
        if (L > 0) {
            L--;
            T -= max(0ll, dif[L]);
            dif[L] += D;
            T += max(0ll, dif[L]);
        }
        if (R < N-1) {
            T -= max(0ll, dif[R]);
            dif[R] -= D;
            T += max(0ll, dif[R]);
        }
        cout << div(S+T+1) << nl;
    }

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343