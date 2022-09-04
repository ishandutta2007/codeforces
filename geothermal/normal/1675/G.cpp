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
const int MX = 256; 

int dp[MX][MX][MX]; //at v, i used, j at cur
int N, M;
int cost[MX][MX];

void solve() {
    cin >> N >> M;
    int A[N];
    F0R(i, N) cin >> A[N-i-1];
    vi pos;
    F0R(i, N) {
        F0R(j, A[i]) {
            pos.pb(i+1);
        }
    }
    FOR(i, 1, N+1) {
        cost[i][0] = 0;
        F0R(j, M) {
            cost[i][j+1] = cost[i][j] + abs(i - pos[j]);
        }
    }

    F0R(i, N+1) F0R(j, M+1) F0R(k, M+1) dp[i][j][k] = MOD;
    dp[0][0][0] = 0;
    FOR(i, 1, N+1) {
        F0R(j, M+1) {
            F0R(k, j+1) {
                if ((N-i) * k + j > M) continue;
                F0R(x, min(j-k+1, k+1)) {
                    ckmin(dp[i][j][k], dp[i-1][j-k][x] + cost[i][j] - cost[i][j-k]);
                    if (x == 0 && i == 1 && j == 3 && k == 3) {
                        //dbg("GOT HERE");
                    }
                }
                //dbg(i, j, k, dp[i][j][k]);
            }
        }
    }
    int ans = MOD;
    F0R(i, M+1) ckmin(ans, dp[N][M][i]);
    cout << ans << nl;
    

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}