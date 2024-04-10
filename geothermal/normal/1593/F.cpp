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
    int N, A, B; cin >> N >> A >> B;
    string S; cin >> S;
    bool dp[N+1][A][B][2*N+1];
    char lst[N+1][A][B][2*N+1];
    array<int, 4> lp[N+1][A][B][2*N+1];
    F0R(i, N+1) F0R(j, A) F0R(k, B) F0R(l, 2*N+1) dp[i][j][k][l] = false;
    dp[0][0][0][N] = true;
    F0R(i, N) {
        F0R(j, A) {
            F0R(k, B) {
                FOR(x, 1, 2*N) {
                    if (!dp[i][j][k][x]) continue;
                    int nj = (j * 10 + S[i] - '0') % A;
                    dp[i+1][nj][k][x+1] = true;
                    lst[i+1][nj][k][x+1] = 'R';
                    lp[i+1][nj][k][x+1] = {i, j, k, x};

                    int nk = (k * 10 + S[i] - '0') % B;
                    dp[i+1][j][nk][x-1] = true;
                    lst[i+1][j][nk][x-1] = 'B';
                    lp[i+1][j][nk][x-1] = {i, j, k, x};
                }
            }
        }
    }

    int best = 0;
    FOR(i, 1, 2*N) {
        if (dp[N][0][0][i] && abs(i-N) < abs(best-N)) best = i;
    }

    if (best == 0) {
        cout << -1 << nl; return;
    }
    string ans;
    array<int, 4> c = {N, 0, 0, best};
    F0Rd(i, N) {
        //dbg(c, lst[c[0]][c[1]][c[2]][c[3]], dp[c[0]][c[1]][c[2]][c[3]]);
        ans += lst[c[0]][c[1]][c[2]][c[3]];
        c = lp[c[0]][c[1]][c[2]][c[3]];
    }
    reverse(all(ans));
    cout << ans << nl;

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}