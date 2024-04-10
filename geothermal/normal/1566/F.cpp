#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
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

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

void solve() {
    int N, M; cin >> N >> M;
    vl A(N); F0R(i, N) cin >> A[i];
    sort(all(A));
    vpl segs[N+1];
    F0R(i, M) {
        ll L, R; cin >> L >> R;
        int p = ub(all(A), L) - A.begin();
        if (p == N || R < A[p]) {
            segs[p].pb({L, R});
        }
    }

    ll dp[N][2]; F0R(i, N) F0R(j, 2) dp[i][j] = 1e18;
    ll loF = 2e9; trav(a, segs[0]) ckmin(loF, a.s);
    ll dF = max(0ll, A[0] - loF);
    dp[0][0] = dF; dp[0][1] = dF * 2;
    FOR(i, 1, N) {
        if (sz(segs[i]) == 0) {
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
            continue;
        }
        sort(all(segs[i]));
        ll lo = 2e9;
        F0R(j, 2) { // lst takes all
            F0R(k, 2) {
                ckmin(dp[i][j], dp[i-1][k] + max(0ll, segs[i][sz(segs[i])-1].f - A[i-1]) * (2 - k));
            }
        }
        F0Rd(x, sz(segs[i])) {
            ckmin(lo, segs[i][x].s);
            ll d1 = 0;
            if (x > 0) d1 = segs[i][x-1].f - A[i-1];
            ll d2 = A[i] - lo;
            F0R(j, 2) {
                F0R(k, 2) {
                    ckmin(dp[i][j], dp[i-1][k] + d1 * (2 - k) + d2 * (j + 1));
                }
            }
        }
    }
    ll hiF = -2e9;
    trav(a, segs[N]) ckmax(hiF, a.f);
    ll dE = max(0ll, hiF - A[N-1]);
    /*F0R(i, N+1) {
        dbg(i, segs[i]);
    }
    F0R(i, N) {
        dbg(i, dp[i][0], dp[i][1]);
    }*/
    F0R(i, 2) {
        dp[N-1][i] += dE * (2 - i);
    }
    cout << min(dp[N-1][0], dp[N-1][1]) << nl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}