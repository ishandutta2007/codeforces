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
const int MX = 200001; 

int pa[MX], ra[MX];
int pasc[MX];

set<int> subcomps[MX];
set<int> inSubcomp[MX];
int esi[MX];
set<int> edgeSet[MX];
set<pi> isEdge;
int ans[MX];

void init(int N) {
    F0R(i, N) {
        pa[i] = i; ra[i] = 0;
    }
    F0R(i, N) {
        subcomps[i].clear();
        subcomps[i].ins(i);
        inSubcomp[i].clear();
        inSubcomp[i].ins(i);
        esi[i] = i;
        edgeSet[i].clear();
        pasc[i] = i;
    }
    isEdge.clear();
}

int get(int x) {
    if (pa[x] != x) pa[x] = get(pa[x]);
    return pa[x];
}
int getSC(int x) {
    if (pasc[x] != x) pasc[x] = getSC(pasc[x]);
    return pasc[x];
}


void unify(int x, int y, int d) {
    //dbg(x, y);
    x = get(x); y = get(y);
    if (x == y) return;
    if (ra[x] < ra[y]) swap(x, y);
    if (ra[x] == ra[y]) ra[x]++;
    pa[y] = x;
    vpi scMerges;
    trav(a, subcomps[x]) {
        trav(b, subcomps[y]) {
            trav(x, inSubcomp[a]) {
                trav(y, inSubcomp[b]) {
                    if (!isEdge.count({x, y})) {
                        //dbg(x, y, a, b);
                        scMerges.pb({a, b}); goto done;
                    }
                }
            }
            done:
            ;
        }
    }
    trav(a, subcomps[y]) {
        subcomps[x].ins(a);
    }
    trav(a, scMerges) {
        //dbg("GO", a.f, a.s);
        a.f = getSC(a.f); a.s = getSC(a.s);
        if (a.f == a.s) continue;
        if (sz(inSubcomp[a.f]) < sz(inSubcomp[a.s])) {
            swap(a.f, a.s);
        }
        //dbg("MERGE", a.f, a.s);
        pasc[a.s] = a.f;
        subcomps[x].erase(a.s);
        trav(b, inSubcomp[a.s]) inSubcomp[a.f].ins(b);
        int es1 = esi[a.f], es2 = esi[a.s];
        if (sz(edgeSet[es1]) < sz(edgeSet[es2])) {
            esi[a.f] = es2;
            trav(b, edgeSet[es1]) {
                if (edgeSet[es2].count(b)) ans[b] = d;
                edgeSet[es2].ins(b);
            }
        } else {
            trav(b, edgeSet[es2]) {
                if (edgeSet[es1].count(b)) ans[b] = d;
                edgeSet[es1].ins(b);
            }
        }
    }
    //dbg(subcomps[x]);
}

void solve() {
    int N, M; cin >> N >> M;
    init(N);
    vector<pair<int, pi>> graph;
    F0R(i, M) {
        int X, Y; cin >> X >> Y; X--; Y--;
        int Z; cin >> Z;
        graph.pb({Z, {X, Y}});
        isEdge.ins({X, Y});
        isEdge.ins({Y, X});
        edgeSet[X].ins(i); edgeSet[Y].ins(i);
    }
    sort(all(graph));

    trav(a, graph) {
        unify(a.s.f, a.s.s, a.f);
    }

    F0R(i, M) {
        cout << ans[i] << " ";
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