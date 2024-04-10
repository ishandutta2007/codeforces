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
    int K; cin >> K;
    int A[N][N]; F0R(i, N) F0R(j, N) cin >> A[i][j];
    set<int> vals;
    F0R(i, N) F0R(j, N) vals.ins(A[i][j]);
    if (sz(vals) <= K) {
        cout << K - sz(vals) << nl; return;
    }
    int ps[N+1][N+1];
    int lx[N*N], ly[N*N], hx[N*N], hy[N*N];
    F0R(i, N*N) {
        lx[i] = N; ly[i] = N; hx[i] = -1; hy[i] = -1;
    }
    F0R(i, N) {
        F0R(j, N) {
            A[i][j]--;
            int v = A[i][j];
            ckmax(hx[v], i); ckmax(hy[v], j);
            ckmin(lx[v], i); ckmin(ly[v], j);
        }
    }
    FOR(s, 1, N+1) {
        F0R(i, N+1) F0R(j, N+1) ps[i][j] = 0;
        F0R(v, N*N) {
            if (hx[v] == -1) continue;
            int a = max(hx[v] - s + 1, 0);
            int b = max(hy[v] - s + 1, 0);
            int c = lx[v];
            int d = ly[v];
            if (b <= d && a <= c) {
                ps[a][b]++;
                ps[a][d+1]--;
                ps[c+1][b]--;
                ps[c+1][d+1]++;
            }
        }

        F0R(i, N-s+1) {
            F0R(j, N-s+1) {
                if (i) {
                    ps[i][j] += ps[i-1][j];
                }
                if (j) {
                    ps[i][j] += ps[i][j-1];
                    if (i) {
                        ps[i][j] -= ps[i-1][j-1];
                    }
                }
                if (sz(vals) - ps[i][j] == K || sz(vals) - ps[i][j] + 1 == K) {
                    cout << 1 << nl; return;
                }
            }
        }
    }
    cout << 2 << nl;



}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}