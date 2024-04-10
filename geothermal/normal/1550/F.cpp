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
const int MX = 200001; 

int dist[MX];
int A[MX];
set<pi> rem;
pqg<pi> q;

void add(int p, int pre, bool ty) {
    auto it1 = rem.lb({p, -1});
    if (it1 != rem.end()) {
        int v = it1->s;
        int d = max(pre, abs(A[v]-p));
        if (ty) {
            d = pre + abs(A[v]-p);
        }
        if (d < dist[v]) {
            dist[v] = d;
            q.push({d, v});
        }
    }
    if (it1 != rem.begin()) {
        it1--;
        int v = it1->s;
        int d = max(pre, abs(A[v]-p));
        if (ty) {
            d = pre + abs(A[v]-p);
        }
        if (d < dist[v]) {
            dist[v] = d;
            q.push({d, v});
        }
    }
}

void push(int p, int K) {
    while (rem.lb({p, -1}) != rem.end() && rem.lb({p, -1})->f <= p+K) {
        int x = rem.lb({p, -1})->s;
        rem.erase({A[x], x});
        q.push({K, x});
        dist[x] = K;
    }
    auto it = rem.lb({p, -1});
    while (it != rem.begin()) {
        it--;
        if (it->f < p-K) break;
        int x = it->s;
        rem.erase({A[x], x});
        q.push({K, x});
        dist[x] = K;
        it = rem.lb({p, -1});
    }
}


void solve() {
    int N, Q; cin >> N >> Q;
    F0R(i, N) dist[i] = 100000000;
    int S; cin >> S; S--;
    int D; cin >> D;
    F0R(i, N) {
        cin >> A[i];
        if (i != S) rem.ins({A[i], i});
    }
    dist[S] = 0;
    add(A[S]+D, 0, true);
    add(A[S]-D, 0, true);
    bool vis[MX]; F0R(i, N) vis[i] = false;
    while (!q.empty()) {
        int v = q.top().s;
        int d = q.top().f;
        q.pop();
        if (vis[v]) continue;
        vis[v] = true;
        //dbg(v, d);
        rem.erase({A[v], v});
        add(A[v], d, true);
        push(A[v]+D, d);
        push(A[v]-D, d);
        add(A[v]+D, 0, true);
        add(A[v]-D, 0, true);
    }
    /*F0R(i, N) {
        cout << dist[i] << " ";
    }
    cout << nl;*/

    while(Q--) {
        int X, V; cin >> X >> V; X--;
        cout << (dist[X]<=V?"Yes":"No") << nl;
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