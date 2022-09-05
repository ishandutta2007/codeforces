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

bool solve(vi &arr, int N, int K) {
    bool found[K]; F0R(i, K) found[i] = false;
    F0R(i, K) {
        if (arr[i] >= K) return false;
        found[arr[i]] = true;
    }
    F0R(i, K) if (!found[i]) return false;
    bool f2[N-K]; F0R(i, N-K) f2[i] = false;
    FOR(i, K, N) {
        if (arr[i] >= N-K) return false;
        f2[arr[i]] = true;
    }
    F0R(i, N-K) if (!f2[i]) return false;
    return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        vi A(N); F0R(i, N) cin >> A[i];
        F0R(i, N) A[i]--;
        int M = 0;
        F0R(i, N) M = max(M, A[i]);
        vpi ans;
        if (solve(A, N, M+1)) {
            ans.pb({M+1, N-M-1});
        } 
        if (M+1 != N-M-1 && solve(A, N, N-M-1)) {
            ans.pb({N-M-1, M+1});
        }
        cout << sz(ans) << nl;
        F0R(i, sz(ans)) {
            cout << ans[i].f << " " << ans[i].s << nl;
        }
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343