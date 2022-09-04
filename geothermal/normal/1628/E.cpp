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
const int MX = 300001; 

const int L = 19;
int N;
int anc[MX][L];
int cap[MX][L];
int depth[MX];
int parent[MX];
vector<vpi> graph(MX);

pi LCA(int a, int b) {
    if (depth[a] < depth[b]) {
        int c = b;
        b = a;
        a = c;
    }

    int dist = depth[a] - depth[b];
    int ans = -1;
    while (dist > 0) {
        F0R(i, L) {
            if (dist & 1 << i) {
                ckmax(ans, cap[a][i]);
                a = anc[a][i];
                dist -= 1 << i;
            }
        }
    }

    if (a == b) return {a, ans};

    F0Rd(j, L) {
        if (anc[a][j] != -1 && anc[a][j] != anc[b][j]) {
            ckmax(ans, cap[a][j]);
            ckmax(ans, cap[b][j]);
            a = anc[a][j]; b = anc[b][j];
        }
    }
    ckmax(ans, cap[a][0]);
    ckmax(ans, cap[b][0]);
    return {parent[a], ans};
}

void parDFS(int v, int p, int d) {
    parent[v] = p; depth[v] = d;
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i].f;
        if (nxt == p) continue;
        cap[nxt][0] = graph[v][i].s;
        parDFS(nxt, v, d+1);
    }
}

void preprocess() {
    F0R(i, N) F0R(j, L) cap[i][j] = -1;
    parDFS(0, -1, 0);
    F0R(i, N) F0R(j, L) anc[i][j] = -1;
    F0R(i, N) anc[i][0] = parent[i];
    FOR(j, 1, L) {
        F0R(i, N) {
            cap[i][j] = cap[i][j-1];
            if (anc[i][j-1] != -1) {
                anc[i][j] = anc[anc[i][j-1]][j-1];
                ckmax(cap[i][j], cap[anc[i][j-1]][j-1]);
            }
        }
    }
}

int getCap(int v, int u) {
    int ans = -1;
    F0Rd(i, L) {
        while (depth[u] + (1 << i) <= depth[v]) {
            ckmax(ans, cap[v][i]);
            v = anc[v][i];
        }
    }
    return ans;
}


const ll SZ = 131072*4;
const pl BAD = {-1, -1};

pi sum[2*SZ]; 
int lazy[2*SZ];
pi def[2*SZ];

pi merge(pi A, pi B) {
    if (A.f == -1) return B;
    if (B.f == -1) return A;
    pi res = LCA(A.f, B.f);
    return {res.f, max(res.s, max(A.s, B.s))};
}

void push(int index, ll L, ll R) {
    if (lazy[index] == 1) {
        sum[index] = def[index];
    } else if (lazy[index] == 2) {
        sum[index] = BAD;
    }
    if (L != R && lazy[index] != 0) lazy[2*index] = lazy[index], lazy[2*index+1] = lazy[index];
    lazy[index] = 0;
}

void pull(int index) {
    if (sum[2*index] == def[2*index] && sum[2*index+1] == def[2*index+1]) sum[2*index] = def[2*index];
    sum[index] = merge(sum[2*index], sum[2*index+1]);
}

pi query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return BAD;
    if (lo <= L && R <= hi) return sum[index];

    int M = (L+R) / 2;
    return merge(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}

void update(int lo, int hi, int increase, int index = 1, ll L = 0, ll R = SZ-1) {
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



void solve() {
    int Q; cin >> N >> Q;
    F0R(i, N-1) {
        int X, Y; cin >> X >> Y; X--; Y--;
        int Z; cin >> Z;
        graph[X].pb({Y, Z}); graph[Y].pb({X, Z});
    }
    preprocess();
    FOR(i, SZ, 2*SZ) {
        if (i-SZ < N) {
            def[i] = {i-SZ, -1};
        } else def[i] = BAD;
    }
    FORd(i, 1, SZ) {
        def[i] = merge(def[2*i], def[2*i+1]);
    }
    F0R(i, 2*SZ) sum[i] = BAD;
    while(Q--) {
        int T; cin >> T;
        if (T == 1) {
            int L, R; cin >> L >> R;
            L--; R--;
            update(L, R, 1);
        } else if (T == 2) {
            int L, R; cin >> L >> R;
            L--; R--;
            update(L, R, 2);
        } else {
            int X; cin >> X; X--;
            pi val = query(0, N-1);
            val = merge(val, {X, -1});
            cout << val.s << nl;
        }
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