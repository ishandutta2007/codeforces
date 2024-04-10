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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, K; cin >> N >> K;
    vi pos; pos.pb(-1);
    int A[N]; F0R(i, N) cin >> A[i];
    F0R(i, N) A[i] -= i;
    F0R(i, K) {
        int X; cin >> X; X--; pos.pb(X);
    }
    pos.pb(N);
    int ans = 0;
    int M[N+5];
    F0R(p, sz(pos) - 1) {
        int L = -1e9; if (pos[p] != -1) L = A[pos[p]];
        int R = 2e9; if (pos[p+1] != N) R = A[pos[p+1]];
        if (L > R) {
            cout << -1 << nl; return 0;
        }
        int len = 0;
        F0R(i, pos[p+1]-pos[p]+1) {
            M[i] = 2e9;
        }
        FOR(i, pos[p]+1, pos[p+1]) {
            int lo = 1, hi = len;
            while (lo <= hi) {
                int mid = (lo+hi+1)/2;
                if (A[M[mid]] <= A[i]) {
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            }
            int newL = lo;
            if (A[i] >= L && A[i] <= R) {
                M[newL] = i;
                ckmax(len, newL);
            }
        }
        ans += pos[p+1] - pos[p]-1-len;

    }
    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343