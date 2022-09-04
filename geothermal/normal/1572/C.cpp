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
    int N; cin >> N;
    int A[N]; F0R(i, N) cin >> A[i];
    F0R(i, N) A[i]--;
    int dp[N][N]; F0R(i, N) F0R(j, N) dp[i][j] = 0;
    F0R(i, N) dp[i][i] = 0;
    F0R(i, N) F0R(j, i) dp[i][j] = 0;
    vi pos[N];
    F0R(i, N) pos[A[i]].pb(i);

    FOR(l, 1, N) {
        F0R(i, N) {
            int j = i+l; if (j >= N) break;
            ckmax(dp[i][j], dp[i+1][j]);
            ckmax(dp[i][j], dp[i][j-1]);
            if (A[i] == A[j]) { 
                ckmax(dp[i][j], 1 + dp[i+1][j-1]);
                trav(a, pos[A[i]]) {
                    if (i < a && a < j) {
                        ckmax(dp[i][j], dp[i][a] + dp[a][j]);
                    }
                }
            }
            trav(a, pos[A[i]]) {
                if (i < a && a < j) ckmax(dp[i][j], dp[i][a] + dp[a+1][j]);
            }

        }
    }

    /*F0R(i, N) {
        F0R(j, N) {
            cout << dp[i][j] << " ";
        }
        cout << nl;
    }*/
    /*int res[N+1]; F0R(i, N+1) res[i] = N;
    res[0] = 0;
    F0R(i, N) {
        FOR(j, i, N) {
            ckmin(res[j+1], res[i] + dp[i][j] + 1);
        }
    }
    cout << res[N] - 1 << nl;*/
    cout << N-1-dp[0][N-1] << nl;

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