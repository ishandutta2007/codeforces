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
const int MX = 2001; 
const int CAP = 1e9 + 10;

int N, M;
vector<vi> og;
int A[MX], B[MX];
bool proc[MX];
vector<vi> graph;
int basePow;
int pa[MX];
int numZ[MX];

bool dfs(int v, int p, int curPow) {
    if (curPow <= A[v]) return false;
    //dbg(v, p, curPow);
    if (pa[v] != -1 || numZ[v] >= 2) {
        //found cycle
        //dbg("FOUND", v);
        int cur = v;
        while (cur > 0) {
            if (!proc[cur]) {
                proc[cur] = true;
                basePow += B[cur];
                ckmin(basePow, CAP);
                trav(a, graph[cur]) {
                    if (a != 0 && numZ[a] == 0) { graph[0].pb(a); graph[a].pb(0); }
                    if (a != 0) numZ[a]++;
                }
            }
            cur = pa[cur];
        }
        return true;
    }
    pa[v] = p;
    curPow += B[v];
    ckmin(curPow, CAP);
    trav(a, graph[v]) {
        if (a == p || (a > 0 && proc[a])) continue;
        if (dfs(a, v, curPow)) {
            if (!proc[v]) {
                proc[v] = true; basePow += B[v];
                ckmin(basePow, CAP);
                trav(b, graph[v]) {
                    if (b != 0 && numZ[b] == 0) { graph[0].pb(b); graph[b].pb(0); }
                    if (b != 0) numZ[b]++;
                }
            }
            return true;
        }
    }
    return false;
    
}

bool ok(int p) {
    basePow = p;
    F0R(i, N) proc[i] = false;
    proc[0] = true;
    graph = og;
    F0R(i, N) numZ[i] = 0;
    trav(a, graph[0]) numZ[a]++;
    while (true) {
        F0R(i, N) pa[i] = -1;
        if (!dfs(0, 0, basePow)) {
            return false;
        }
        /*F0R(i, N) {
            dbg(i, proc[i]);
        }*/
        bool done = true;
        F0R(i, N) if (!proc[i]) done = false;
        if (done) return true;
    }
}

void solve() {
    cin >> N >> M;
    og = vector<vi>(N);
    F0R(i, N-1) {
        cin >> A[i+1];
    }
    F0R(i, N-1) cin >> B[i+1];
    F0R(i, M) {
        int X, Y; cin >> X >> Y; X--; Y--;
        og[X].pb(Y); og[Y].pb(X);
    }

    int lo = 0, hi = CAP;
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (ok(mid)) {
            hi = mid;
        } else lo = mid+1;
    }
    cout << lo << nl;
    //cout << ok(19) << nl;


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