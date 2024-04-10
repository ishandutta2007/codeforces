#include <bits/stdc++.h>
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
const int MX = 400001; 


vector < vector<int> > g, gr; //g stores graph, gr stores graph transposed
vector<bool> used;
vector<int> order, component;
vector<bool> isMult;
vi comp(MX);

void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}

void findSCCs(int n) {

    used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n, false);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            int nc = sz(isMult);
            trav(a, component) {
                comp[a] = nc;
            }
            if (sz(component) > 1) {
                isMult.pb(true);
            } else isMult.pb(false);
            component.clear();
        }
    }

}


void solve() {
    g.clear();
    gr.clear();
    order.clear();
    component.clear();
    isMult.clear();
    int N, M; cin >> N >> M;
    g = vector<vi>(N); gr = vector<vi>(N);
    F0R(i, M) {
        int X, Y; cin >> X >> Y; X--; Y--;
        g[X].pb(Y);
        gr[Y].pb(X);
    }

    findSCCs(N);
    F0R(i, N) {
        trav(a, g[i]) {
            if (i == a) {
                isMult[comp[a]] = true;
            }
        }
    }

    int nc = sz(isMult);
    vector<set<int>> graph(nc);
    F0R(i, N) {
        trav(a, g[i]) {
            if (comp[a] != comp[i]) {
                graph[comp[i]].ins(comp[a]);
            }
        }
    }

    int ans[nc]; F0R(i, nc) ans[i] = 0;
    ans[comp[0]] = 1;
    int ind[nc];
    F0R(i, nc) ind[i] = 0;
    F0R(i, nc) {
        trav(a, graph[i]) {
            ind[a]++;
        }
    }
    queue<int> q;
    F0R(i, nc) if (ind[i] == 0) q.push(i);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (isMult[v] && ans[v] != 0) {
            ans[v] = -1;
        }
        trav(a, graph[v]) {
            if (ans[v] != 0) {
                if (ans[a] == 0) {
                    ans[a] = ans[v];
                } else if (ans[v] == -1) {
                    ans[a] = -1;
                } else if (ans[a] != -1) {
                    ans[a] = 2;
                }
            }
            ind[a]--;
            if (ind[a] == 0) {
                q.push(a);
            }
        }
    }

    F0R(i, N) {
        cout << ans[comp[i]] << " ";
    }
    cout << nl;
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