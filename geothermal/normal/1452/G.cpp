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
#define dbg(x...) cerr << ""<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "" << endl;
#else
#define dbg(x...)
#endif
 
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 
 
 
 
void solve() {
    int N; cin >> N;
    vector<set<int>> graph(N);
    F0R(i, N-1) {
        int X, Y; cin >> X >> Y; X--; Y--;
        graph[X].ins(Y); graph[Y].ins(X);
    }
 
 
    int K; cin >> K;
    vi in(K);
    F0R(i, K) cin >> in[i];
    F0R(i, K) in[i]--;
    int dist[N]; F0R(i, N) dist[i] = N;
    set<int> lst[N];
    queue<int> qq;
    F0R(i, K) {
        dist[in[i]] = 0;
        qq.push(in[i]);
    }
    while (!qq.empty()) {
        int v = qq.front(); qq.pop();
        trav(a, graph[v]) {
            if (ckmin(dist[a], dist[v]+1)) {
                qq.push(a);
                lst[a].clear();
            }
            if (dist[a] == dist[v]+1) {
                lst[a].ins(v);
            }
        }
    }
    int ans[N];
    F0R(i, N) ans[i] = 0;
    int cnt[N];
    F0R(i, N) {
        cnt[i] = -1;
    }

    queue<int> q;
    vpi ev; F0R(i, N) ev.pb({dist[i], i});
    sort(all(ev)); reverse(all(ev));
    trav(e, ev) {
        int v = e.s;
        if (ckmax(cnt[v], dist[v]-1)) {
            ckmax(ans[v], dist[v]);
            q.push(v);
            while (!q.empty()) {
                int a = q.front(); q.pop();
                trav(b, graph[a]) {
                    if (ckmax(cnt[b], cnt[a]-1)) {
                        q.push(b);
                        ckmax(ans[b], dist[v]);
                    }
                }
            }
        }
    }
    F0R(i, N) {
        cout << ans[i] << " ";
    }
    cout << nl;
 
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