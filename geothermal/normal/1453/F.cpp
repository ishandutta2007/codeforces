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
const int MX = 3001; //check the limits, dummy

struct Seg { 
ll SZ = 4096; //set this to power of two
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github

ll combine(ll a, ll b) { return min(a, b); }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    for (seg[p += SZ] = value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = MX, resR = MX; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    Seg dp[MX];
    F0R(i, MX) {
        F0R(j, 4096*2) {
            dp[i].seg[j] = MX;
        }
    }
    while(T--) {
        int N; cin >> N;
        int A[N]; F0R(i, N) cin >> A[i];
        dp[N-1].update(N-1, 0);
        F0Rd(i, N-1) {
            priority_queue<int, vi, greater<int>> q;
            FOR(j, i+1, i + A[i]+1) {
                while (sz(q) > 0 && q.top() < j) {
                    q.pop();
                }
                if (j == N-1) {
                    dp[i].update(j, sz(q));
                } else {
                    dp[i].update(j, dp[j].query(i+A[i]+1, N-1)+sz(q));
                }
                q.push(j+A[j]);
            }
        }
        cout << dp[0].query(0, A[0]+1) << nl;
/*        F0R(i, N) {
            FOR(j, i+1, N) {
                cout << dp[i].query(j, j) << " ";
            }
            cout << nl;
        }*/
        F0R(i, N) {
            FOR(j, i+1, i+A[i]+1) {
                dp[i].update(j, MX);
            }
        }
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343