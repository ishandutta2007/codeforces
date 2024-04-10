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
const int MX = 1000001; 


const ll identity = 0;
const ll SZ = 131072*8;

ll sum[2*SZ], lazy[2*SZ];

ll combine(ll A, ll B) {
    return A+B;
}

ll combineUpd(ll A, ll B) {
    return A+B;
}

void push(int index, ll L, ll R) {
    sum[index] = combineUpd(sum[index], lazy[index]);
    if (L != R) lazy[2*index] = combineUpd(lazy[2*index], lazy[index]), lazy[2*index+1] = combineUpd(lazy[2*index+1], lazy[index]);
    lazy[index] = identity;
}

void pull(int index) {
    sum[index] = combine(sum[2*index], sum[2*index+1]);
}

ll query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return identity;
    if (lo <= L && R <= hi) return sum[index];

    int M = (L+R) / 2;
    return combine(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}

void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ-1) {
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

int parent[MX], siz[MX];

void init(int N) {
    F0R(i, N) parent[i] = i, siz[i] = 0;
}

int get(int x) {
    if (parent[x] != x) parent[x] = get(parent[x]);
    return parent[x];
}

void unify(int x, int y) {
    x = get(x); y = get(y);
    if (x == y) return;
    if (siz[x] < siz[y]) swap(x, y);
    if (siz[x] == siz[y]) siz[x]++;
    parent[y] = x;

}

vector<set<int>> graph(MX);
int C[MX];
vi cyc;
bool fl[MX];

int dfs(int v, int p) {
    trav(a, graph[v]) {
        if (a == p) continue;
        if (C[a] == C[v]) {
            cyc.pb(a); cyc.pb(v); return 1;
        } else if (C[a] == -1) { 
            C[a] = 1 - C[v];
            int res = dfs(a, v);
            if (res == 1) {
                if (v == cyc[0]) {
                    res = 2;
                } else cyc.pb(v);
            }
            if (res) return res;
        }
    }
    return 0;
}

void solve() {
    int N; cin >> N;
    int M; cin >> M;
    graph = vector<set<int>>(N);
    cyc.clear();
    F0R(i, M) {
        int X, Y; cin >> X >> Y; X--; Y--;
        graph[X].ins(Y); graph[Y].ins(X);
    }

    F0R(i, N) C[i] = -1;
    C[0] = 0;
    if (dfs(0, -1) == 0) {
        cout << "YES" << nl;
        F0R(i, N) {
            cout << C[i];
        }
        cout << nl;
        return;
    }

    F0R(i, sz(cyc)) {
        int X = cyc[i], Y = cyc[(i+1)%sz(cyc)];
        graph[X].erase(Y); graph[Y].erase(X);
    }

    init(N);
    F0R(i, N) {
        trav(a, graph[i]) {
            unify(i, a);
        }
    }

    F0R(i, N) {
        C[i] = -1;
    }
    F0R(i, N) {
        if (C[i] == -1) {
            C[i] = 0;
            if (dfs(i, -1)) {
                cout << "NO" << nl; return;
            }
        }
    }

    F0R(i, N) {
        update(i, i, -query(i, i));
    }

    map<int, vi> comps;
    F0R(i, sz(cyc)) {
        comps[get(cyc[i])].pb(i);
    }

    int no = 0;
    trav(a, comps) {
        F0R(i, sz(a.s)-1) {
            int X = a.s[i], Y = a.s[i+1];
            no++;
            if ((C[cyc[Y]] ^ C[cyc[X]]) == (Y-X)%2) {
                //dbg(X, Y, 1);
                update(0, X-1, 1);
                update(Y, sz(cyc), 1);
            } else {
                //dbg(X, Y, 0);
                update(X, Y-1, 1);
            }
        }
    }

    int p = -1;
    F0R(i, sz(cyc)) {
        if (query(i, i) == no) {
            p = i; break;
        }
    }
    if (p == -1) {
        cout << "NO" << nl; return;
    }
    //dbg(cyc, p);

    F0R(i, N) fl[i] = false;
    int c = 0;
    F0R(i, sz(cyc)) {
        if (C[cyc[i]] != c) {
            fl[get(cyc[i])] = true;
        }
        //dbg(i, c, fl[get(cyc[i])]);
        if (i != p) c = 1 - c;
    }
    cout << "YES" << nl;
    F0R(i, N) {
        if (fl[get(i)]) C[i] = 1 - C[i];
    }
    if (C[cyc[p]] == 0) {
        F0R(i, N) C[i] = 1-C[i];
    }
    F0R(i, N) {
        cout << C[i];
    }
    cout << nl;

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