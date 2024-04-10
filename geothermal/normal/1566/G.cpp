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
const int MX = 100011; 

typedef pair<ll, int> pli;
vector<pli> threes[MX];
set<pli> extras[MX];
set<pair<int, pl>> edges;
ll tri[MX];
set<pl> tris;
const ll INF = 1e10;
map<pi, ll> lens;

void updTri(int p) {
    tris.erase({tri[p], p});
    if (sz(threes[p]) < 3) {
        tri[p] = INF;
    } else {
        tri[p] = 0; trav(a, threes[p]) tri[p] += a.f;
    }
    tris.ins({tri[p], p});
}


void addEdge(int X, int Y, ll Z) {
    if (X > Y) swap(X, Y);
    lens[mp(X, Y)] = Z;
    vi ps = {X, Y};
    trav(a, ps) {
        pli cur = {Z, X+Y-a};
        auto it = threes[a].begin();
        while (it != threes[a].end() && *it <= cur) it++;
        threes[a].ins(it, cur);
        sort(all(threes[a]));
        if (sz(threes[a]) <= 3 || threes[a][3] != cur) {
            if (sz(threes[X+Y-a]) < 3 || mp(Z, a) <= threes[X+Y-a][2]) edges.ins({Z, {a, X+Y-a}});
        }
        if (sz(threes[a]) > 3) {
            edges.erase({threes[a][3].f, {a, threes[a][3].s}});
            edges.erase({threes[a][3].f, {threes[a][3].s, a}});
            extras[a].ins({threes[a][3].f, threes[a][3].s});
            threes[a].pop_back();
        }
        updTri(a);
    }
}

void remEdge(int X, int Y) {
    if (X > Y) swap(X, Y);
    ll Z = lens[mp(X, Y)];
    vi ps = {X, Y};
    trav(a, ps) {
        pli cur = {Z, X+Y-a};
        extras[a].erase(cur);
        int p = 0;
        trav(b, threes[a]) {
            if (b == cur) {
                threes[a].erase(threes[a].begin()+p);
                edges.erase({cur.f, {a, cur.s}});
                edges.erase({cur.f, {cur.s, a}});
            }
            p++;
        }
        if (sz(threes[a]) < 3 && sz(extras[a])) {
            pli tba = *extras[a].begin(); extras[a].erase(extras[a].begin());
            threes[a].pb(tba);
            if (sz(threes[tba.s]) < 3 || threes[tba.s][2] >= mp(tba.f, a)) edges.ins({tba.f, {a, tba.s}});
        }

        updTri(a);
    }
}

ll outAns() {
    ll ans = tris.begin()->f;
    pair<ll, pi> firEd = *edges.begin();
    int x = firEd.s.f, y = firEd.s.s;
    trav(a, threes[x]) {
        trav(b, threes[y]) {
            if (x != b.s && y != a.s && b.s != a.s) {
                ckmin(ans, a.f + b.f);
            }
        }
    }

    int cnt = 0;
    trav(a, edges) {
        cnt++;
        if (a.s.f != x && a.s.f != y && a.s.s != x && a.s.s != y) {
            if (cnt > 20) {
                trav(b, edges) {
                    cout << b.f << " " << b.s.f << " " << b.s.s << endl;
                }
                assert(false);
            }
            ckmin(ans, firEd.f + a.f);
            break;
        }
    }
    return ans;
}


void solve() {
    int N, M; cin >> N >> M;
    F0R(i, N) {
        tri[i] = INF; 
        tris.ins({INF, i});
    }
    while(M--) {
        int X, Y; ll Z; cin >> X >> Y >> Z;
        X--; Y--;
        if (X > Y) swap(X, Y);
        addEdge(X, Y, Z);
    }

    //dbg(edges);

    int Q; cin >> Q;


    cout << outAns() << nl;
    F0R(i, Q) {
        int T, X, Y; cin >> T >> X >> Y; X--; Y--;
        if (T) {
            ll Z; cin >> Z;
            addEdge(X, Y, Z);
        } else {
            remEdge(X, Y);
        }
        cout << outAns() << nl;
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