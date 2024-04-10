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
	
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        vi A(N); F0R(i, N) cin >> A[i];

        int cnt[N];  F0R(i, N) cnt[i] = 0;
        F0R(i, N) cnt[A[i]-1]++;
        bool bad = false;
        F0R(i, N) {
            if (cnt[i] > (N+1)/2) {
                cout << -1 << nl; bad = true; 
                break;
            }
        } 
            if (bad) continue;
        int p = 0;
        int cb[N]; F0R(i, N) cb[i] = 0;
        int co[N]; F0R(i, N) co[i] = 0;
        int ans = 0;
        while (p < N) {
            int S = A[p];
            int E = -1;
            p++;
            while (p < N) {
                if (A[p] == A[p-1]) {
                    E = A[p-1]; break;
                }
                p++;
            }
            if (p == N) {
                E = A[N-1];
            }
            if (S == E) {
                cb[S-1]++; co[S-1]++;
            } else {
                co[S-1]++; co[E-1]++;
            }
            ans++;
        }
        int best = 0;
        F0R(i, N) {
            ckmax(best, cb[i] - (ans - co[i]) - 1);
        }
        cout << ans+best-1 << nl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343