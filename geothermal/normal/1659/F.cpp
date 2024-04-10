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

ll SZ = 262144; //set this to power of two
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github

ll combine(ll a, ll b) { return a + b; }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    for (seg[p += SZ] = value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = 0, resR = 0; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}
void solve() {
    int N, X; cin >> N >> X;
    X--;
    vector<vi> graph(N);
    F0R(i, N-1) {
        int X, Y; cin >> X >> Y; X--; Y--;
        graph[X].pb(Y); graph[Y].pb(X);
    }

    int P[N]; F0R(i, N) {
        int X; cin >> X;
        X--;
        P[X] = i;
    }
    int r = -1;
    F0R(i, N) if (sz(graph[i]) == N-1) r = i;

    if (r == -1) {
        cout << "Alice" << nl; return;
    }
    vi sw;
    F0R(i, N) if (P[i] != i) sw.pb(i);
    if (sz(sw) == 0) {
        cout << "Alice" << nl; return;
    }
    if (X != r) {
        if (sz(sw) == 2 && sw[0] != X && sw[1] != X) {
            cout << "Alice" << nl; return;
        }
        if (P[r] != r) {
            F0R(i, N) {
                if (P[i] == r && i != X) {
                    swap(P[i], P[r]);
                    goto done;
                }
            }
            cout << "Bob" << nl; return;
            done:
            ;
        } else {
            int x = 0, y = 0;
            while (x == X || x == r) {
                x++;
            }
            while (y == X || y == r || y == x) y++;
            if (y < N) swap(P[x], P[y]);
            if (y >= N) {
                cout << "Bob" << nl; return;
            }
        }
    }
    if (P[r] != r) {
        cout << "Bob" << nl; return;
    }
    F0R(i, N) update(i, 0);
    int V = 0;
    F0R(i, N) {
        V = (V + query(P[i]+1, N-1)) % 2;
        update(P[i], 1);
    }
    cout << (V % 2 == 0 ? "Bob" : "Alice") << nl;

    /*bool found[N]; F0R(i, N) found[i] = false;
    vector<vi> cyc;
    F0R(i, N) {
        if (found[i] || P[i] == i) continue;
        vi cur;
        cur.pb(i);
        int v = P[i];
        while (v != i) {
            cur.pb(v); v = P[v];
        }
        cyc.pb(cur);
    }

    if (sz(cyc) == 0) {
        cout << "Alice" << nl; return;
    }
    if (sz(cyc) == 1 && sz(cyc[0]) == 2 && cyc[0][0] != X && cyc[0][1] != X) {
        cout << "Alice" << nl; return;
    }
    if (sz(cyc) == 2 && sz(cyc[0]) == 2 && sz(cyc[1]) == 2 && X != r) {
        F0R(i, 2) {
            if (cyc[0][0] != X && cyc[0][1] != X && cyc[1][0] != r && cyc[1][1] != r) {
                cout << "Alice" << nl; return;
            }
            swap(cyc[0], cyc[1]);
        }
    }
    if (sz(cyc) == 1 && sz(cyc[0]) == 3 && X != r) {
        trav(a, cyc[0]) {
            if (P[a] == r && a != X) {
                cout << "Alice" << nl; return;
            }
        }
    }
    cout << "Bob" << nl; */

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