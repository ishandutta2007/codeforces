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

struct dp_hull {
 
    static const long long LL_INF = (long long) 2e18 + 5;
     
    struct point {
        long long x, y;
     
        point() : x(0), y(0) {}
     
        point(long long _x, long long _y) : x(_x), y(_y) {}
    };
 
    struct segment {
        point p;
        mutable point next_p;
 
        segment(point _p = {0, 0}, point _next_p = {0, 0}) : p(_p), next_p(_next_p) {}
 
        bool operator<(const segment &other) const {
            // Sentinel value indicating we should binary search the set for a single x-value.
            if (p.y == LL_INF)
                return p.x * (other.next_p.x - other.p.x) <= other.p.y - other.next_p.y;
 
            return make_pair(p.x, p.y) < make_pair(other.p.x, other.p.y);
        }
    };
 
    set<segment> segments;
 
    int size() const {
        return segments.size();
    }
 
    set<segment>::iterator prev(set<segment>::iterator it) const {
        return it == segments.begin() ? it : --it;
    }
 
    set<segment>::iterator next(set<segment>::iterator it) const {
        return it == segments.end() ? it : ++it;
    }
 
    static long long floor_div(long long a, long long b) {
        return a / b - ((a ^ b) < 0 && a % b != 0);
    }
 
    static bool bad_middle(const point &a, const point &b, const point &c) {
        // This checks whether the x-value where b beats a comes after the x-value where c beats b. It's fine to round
        // down here if we will only query integer x-values. (Note: plain C++ division rounds toward zero)
        return floor_div(a.y - b.y, b.x - a.x) >= floor_div(b.y - c.y, c.x - b.x);
    }
 
    bool bad(set<segment>::iterator it) const {
        return it != segments.begin() && next(it) != segments.end() && bad_middle(prev(it)->p, it->p, next(it)->p);
    }
 
    void insert(const point &p) {
        set<segment>::iterator next_it = segments.lower_bound(segment(p));
 
        if (next_it != segments.end() && p.x == next_it->p.x)
            return;
 
        if (next_it != segments.begin()) {
            set<segment>::iterator prev_it = prev(next_it);
 
            if (p.x == prev_it->p.x)
                segments.erase(prev_it);
            else if (next_it != segments.end() && bad_middle(prev_it->p, p, next_it->p))
                return;
        }
 
        // Note we need the segment(p, p) here for the single x-value binary search.
        set<segment>::iterator it = segments.insert(next_it, segment(p, p));
 
        while (bad(prev(it)))
            segments.erase(prev(it));
 
        while (bad(next(it)))
            segments.erase(next(it));
 
        if (it != segments.begin())
            prev(it)->next_p = it->p;
 
        if (next(it) != segments.end())
            it->next_p = next(it)->p;
    }
 
    void insert(long long a, long long b) {
        insert(point(a, b));
    }
 
    // Queries the maximum value of ax + b.
    long long query(long long x) const {
        assert(size() > 0);
        set<segment>::iterator it = segments.upper_bound(segment(point(x, LL_INF)));
        return it->p.x * x + it->p.y;
    }
};

int N, M, K;
vector<vpl> graph(MX);

ll dist[MX];

void dijk() {
    pqg<pl> q;
    F0R(i, N) {
        q.push({dist[i], i});
    }
    while (!q.empty()) {
        pl cur = q.top(); q.pop();
        if (cur.f != dist[cur.s]) continue;
        int v = cur.s;
        trav(a, graph[v]) {
            if (ckmin(dist[a.f], a.s + dist[v])) {
                q.push({dist[a.f], a.f});
            }
        }
    }
}

void cht() { 
    dp_hull dph;
    F0R(i, N) {
        dph.ins(2 * i, -1 * (dist[i] + ((ll) i) * ((ll) i)));
    }
    F0R(i, N) {
        ckmin(dist[i], -dph.query(i) + ((ll) i) * ((ll) i));
    }
}

void solve() {
    cin >> N >> M >> K;
    F0R(i, M) {
        int X, Y, Z; cin >> X >> Y >> Z;
        X--; Y--;
        graph[X].pb({Y, Z});
        graph[Y].pb({X, Z});
    }
    dist[0] = 0;
    FOR(i, 1, MX) dist[i] = 2e10;

    dijk();
    F0R(i, K) {
        cht();
        dijk();
    }

    F0R(i, N) {
        cout << dist[i] << " ";
    }
    cout << nl;

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