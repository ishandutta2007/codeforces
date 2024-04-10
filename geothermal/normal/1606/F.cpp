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
const int MX = 200011;  //CHANGE THIS BACK
const int K = 580;

int par[MX];
int nc[MX];
int dp[MX][K];
int cdp[MX];
int dep[MX];
vector<vi> graph(MX);
vi atNC[MX];

void dfs(int v, int p) {
    par[v] = p;
    if (p < 0) {
        dep[v] = 0;
    } else dep[v] = dep[p] + 1;
    trav(a, graph[v]) {
        if (a == p) continue;
        dfs(a, v);
        FOR(i, 1, K) {
            dp[v][i] += max(1, dp[a][i] - i + 1);
        }
        nc[v]++;
    }
}

void solve() {

    int N; cin >> N;
    F0R(i, N-1) {
        int X, Y; cin >> X >> Y; X--; Y--;
        graph[X].pb(Y); graph[Y].pb(X);
    }
    dfs(0, -1);
    F0R(i, N) atNC[nc[i]].pb(i);

    int Q; cin >> Q;
    int ans[Q];
    vector<vpi> atK(MX);
    F0R(i, Q) {
        int X, Y; cin >> X >> Y; X--;
        Y++;
        atK[Y].pb(mp(X, i));
    }

    FOR(i, 1, K) {
        trav(a, atK[i]) {
            ans[a.s] = dp[a.f][i];
        }
    }
    set<int> incVerts;
    FORd(i, K, MX) {
        trav(a, atNC[i]) {
            incVerts.ins({dep[a], a});
        }
        if (sz(atK[i]) == 0) {
            continue;
        }
        pq<pi> q;
        trav(a, incVerts) q.push({dep[a], a});
        set<int> used;
        while (!q.empty()) {
            int cur = q.top().s; q.pop();
            if (used.count(cur)) {
                continue;
            }
            used.ins(cur);
            if (cdp[cur] == 0) cdp[cur] = nc[cur];
            if (cur == 0) continue;
            if (cdp[par[cur]] == 0) cdp[par[cur]] = nc[par[cur]];
            cdp[par[cur]] += max(0, cdp[cur] - i);
            if (cdp[cur] - i > 0) {
                q.push({dep[par[cur]], par[cur]});
            }
        }
        /*F0R(j, N) {
            dbg(i, j, cdp[j]);
        }*/
        trav(a, atK[i]) {
            ans[a.s] = nc[a.f];
            //dbg(a.s, ans[a.s]);
            trav(b, used) {
                if (b == a.f) {
                    ans[a.s] = cdp[a.f];
                }
            }
        }
        trav(a, used) cdp[a] = 0;
    }

    F0R(i, Q) {
        cout << ans[i] << nl;
    }


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