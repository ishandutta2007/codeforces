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
const int MX = 300002; 
const int SZ = (1 << 19) - 1;

struct Node {
    Node *L = NULL, *R = NULL;
    int l, r;
    ll V;
    Node(int x, int y) {
        l = x; r = y;
        V = 0;
    }
    void pull() {
        if (l == r) return;
        V = 0;
        if (L != NULL) V ^= L->V;
        if (R != NULL) V ^= R->V;
    }
};

Node *root[MX];
ll val[MX];
int cn = 0;

void init(Node *cur) {
    if (cur->l == cur->r) return;
    int m = (cur->l + cur->r) / 2;
    cur->L = new Node(cur->l, m);
    init(cur->L);
    cur->R = new Node(m+1, cur->r);
    init(cur->R);
}

Node* update(Node* cur, int p) {
    if (p < cur->l || p > cur->r) return cur;
    if (cur->l != cur->r) {
        Node* res = new Node(cur->l, cur->r);
        res->L = update(cur->L, p);
        res->R = update(cur->R, p);
        res->pull();
        return res;
    }
    Node* res = new Node(cur->l, cur->r);
    res->V = cur->V ^ val[p];
    return res;
}

int query(Node* n1, Node* n2, Node* n3, Node* n4, int L, int R) {
    if (n1->l > R || n1->r < L) return -1;
    if (((n1->V ^ n2->V) ^ (n3->V ^ n4->V)) == 0) return -1;
    if (n1->l == n1->r) return n1->l+1;
    int res = query(n1->L, n2->L, n3->L, n4->L, L, R);
    if (res == -1) res = query(n1->R, n2->R, n3->R, n4->R, L, R);
    return res;
}

vector<vi> graph(MX);
int A[MX];

void dfs(int v, int p) {
    dbg(v);
    if (p == -1) {
        root[MX-2] = new Node(0, SZ);
        init(root[MX-2]);
        root[v] = update(root[MX-2], A[v]);
    } else {
        root[v] = update(root[p], A[v]);
    }
    //dbg(v);
    trav(a, graph[v]) {
        if (a != p) dfs(a, v);
    }
}


const int L = 19; 
int N;
int anc[MX][L];
int depth[MX];
int parent[MX];

int LCA(int a, int b) {
    if (depth[a] < depth[b]) {
        int c = b;
        b = a;
        a = c;
    }

    int dist = depth[a] - depth[b];
    while (dist > 0) {
        F0R(i, L) {
            if (dist & 1 << i) {
                a = anc[a][i];
                dist -= 1 << i;
            }
        }
    }

    if (a == b) return a;

    F0Rd(j, L) {
        if (anc[a][j] != -1 && anc[a][j] != anc[b][j]) {
            a = anc[a][j]; b = anc[b][j];
        }
    }
    return parent[a];
}

void parDFS(int v, int p, int d) {
    parent[v] = p; depth[v] = d;
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        parDFS(nxt, v, d+1);
    }
}

void preprocess() {
    parDFS(0, -1, 0);
    F0R(i, N) F0R(j, L) anc[i][j] = -1;
    F0R(i, N) anc[i][0] = parent[i];
    FOR(j, 1, L) {
        F0R(i, N) {
            if (anc[i][j-1] != -1) {
                anc[i][j] = anc[anc[i][j-1]][j-1];
            }
        }
    }
}


void solve() {
    int Q; cin >> N >> Q;
    F0R(i, N) cin >> A[i];
    F0R(i, N) A[i]--;
    F0R(i, N) val[i] = uniform_int_distribution<ll>(1, (1ll << 60) - 1)(rng);
    F0R(i, N-1) {
        int X, Y; cin >> X >> Y; X--; Y--;
        graph[X].pb(Y); graph[Y].pb(X);
    }
    root[MX-1] = new Node(0, SZ-1);
    init(root[MX-1]);
    dfs(0, -1);
    preprocess();
    parent[0] = MX-1;
    F0R(i, Q) {
        int U, V, l, r; cin >> U >> V >> l >> r;
        int lc = LCA(U-1, V-1);
        cout << query(root[U-1], root[V-1], root[lc], root[parent[lc]], l-1, r-1) << nl;
    }

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