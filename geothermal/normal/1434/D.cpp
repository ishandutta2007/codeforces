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
const int MX = 500001; 


const ll identity = 0;
const ll SZ = 131072*4;

ll X[2*SZ], Y[2*SZ], lazy[2*SZ];

void push(int index, ll L, ll R) {
    if (lazy[index]%2) {
        swap(X[index], Y[index]);
    }
    if (L != R) lazy[2*index] = lazy[2*index]+ lazy[index], lazy[2*index+1] = lazy[2*index+1]+ lazy[index];
    lazy[index] = identity;
}

void pull(int index) {
    X[index] = max(X[2*index], X[2*index+1]);
    Y[index] = max(Y[2*index], Y[2*index+1]);
}

ll query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return identity;
    if (lo <= L && R <= hi) return X[index];

    int M = (L+R) / 2;
    return max(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}


void update(int lo, int hi, ll increase = 1, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = increase;
        push(index, L, R);
        return;
    }

    int M = (L+R) / 2;
    update(lo, hi, increase, 2*index, L, M); update(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}

int N, M;

ll ans[MX];
vector<vpi> graph(MX);
int dep[MX];
int rep[MX];
int tin[MX], tout[MX];
int ct;
vector<bool> og;
vi quers;

void dfs(int v, int p, bool odd) {
    tin[v] = ct; ct++;
    if (p < 0) {
        dep[v] = 0;
    } else dep[v] = dep[p]+1;
    trav(a, graph[v]) if (a.f != p) { 
        bool nxt = odd;
        if (og[a.s]) nxt = !odd;
        dfs(a.f, v, nxt); rep[a.s] = a.f; }
    if (odd) {
        dbg(v, tin[v], dep[v]);
        Y[SZ+tin[v]] = dep[v]; X[SZ+tin[v]] = 0;
    } else {
        dbg(v, tin[v], dep[v]);
        X[SZ+tin[v]] = dep[v]; Y[SZ+tin[v]] = 0;
    }
    tout[v] = ct-1;
}

void go(int v) {
    F0R(i, 2*SZ) {
        X[i] = 0; Y[i] = 0; lazy[i] = 0;
    }
    ct = 0;
    dfs(v, -1, false);
    F0Rd(i, SZ) {
        pull(i);
    }
    F0R(i, N) {
        dbg(i, tin[i], dep[i], X[i+SZ], Y[i+SZ]);
    }
    F0R(i, M) {
        int p = quers[i];
        int v = rep[p-1];
        dbg(v, tin[v], tout[v]);
        update(tin[v], tout[v]);
        ckmax(ans[i], query(0, N-1));
        if (query(0, N-1) >= 2) {
            dbg(i, query(0, N-1));
        }
        F0R(j, N) {
            dbg(j, X[j+SZ], Y[j+SZ]);
        }
    }

}


void solve() {

    F0R(i, MX) ans[i] = 0;
    cin >> N;
    F0R(i, N-1) {
        int X, Y, Z; cin >> X >> Y >> Z;
        X--; Y--;
        og.pb(Z);
        graph[X].pb({Y, i});
        graph[Y].pb({X, i});
    }
    ct = 0;
    dfs(0, -1, false);
    int v1 = 0;
    F0R(i, N) {
        if (dep[i] > dep[v1]) v1 = i;
    }
    int v2 = 0;
    ct = 0;
    dfs(v1, -1, false);
    F0R(i, N) {
        if (dep[i] > dep[v2]) v2 = i;
    }
    cin >> M;
    F0R(i, M) {
        int X; cin >> X; quers.pb(X);
    }
    go(v1); go(v2);
    F0R(i, M) cout << ans[i] << nl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}