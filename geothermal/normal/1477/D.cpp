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

void solve() {
    int N; cin >> N;
    int M; cin >> M;
    set<int> rem; F0R(i, N) rem.ins(i);
    vector<set<int>> adj(N);
    F0R(i, M) {
        int X, Y; cin >> X >> Y; X--; Y--;
        adj[X].ins(Y); adj[Y].ins(X);
    }
    vector<set<int>> adj2 = adj;
    pq<pi> q;
    F0R(i, N) q.push({sz(adj[i]), i});
    int ans1[N], ans2[N];
    int nxt = 1;
    while (!q.empty()) {
        int v = q.top().s; int x = q.top().f; q.pop();
        if (x != sz(rem)-1) continue;
        if (x != sz(adj[v])) continue;
        rem.erase(v);
        ans1[v] = nxt; ans2[v] = nxt; nxt++;
        trav(a, adj[v]) {
            adj[a].erase(v);
            q.push({sz(adj[a]), a});
        }
    }
    vector<vi> graph(N);
    set<int> tr = rem;
    queue<int> q2;

    while (sz(rem)) {
        q2.push(*rem.begin());
        rem.erase(rem.begin());
        while (!q2.empty()) {
            int v = q2.front(); q2.pop();
            vi cr;
            trav(a, rem) {
                if (!adj2[v].count(a)) {
                    cr.pb(a);
                }
            }
            trav(a, cr) {
                rem.erase(a); q2.push(a); graph[a].pb(v); graph[v].pb(a);
            }
        }
    }

    int star[N]; F0R(i, N) star[i] = -1;
    trav(v, tr) {
        if (star[v] != -1) continue;
        int f1 = -1; bool  f2 = false;
        trav(a, graph[v]) {
            if (star[a] == a) f1 = a;
            if (star[a] == -1) f2 = true;
        }
        if (f1 >= 0) {
            star[v] = f1;
        } else if (f2) {
            star[v] = v;
            trav(a, graph[v]) {
                if (star[a] == -1) star[a] = v;
            }
        } else {
            int a = graph[v][0];
            int st = star[a];
            int cnt = 0;
            trav(b, graph[st]) if (star[b] == st) cnt++;
            if (cnt > 1) {
                star[a] = a; star[v] = a;
            } else {
                star[a] = a; star[v] = a; star[st] = a;
            }
        }
    }

    map<int, vi> stars;
    F0R(i, N) {
        if (star[i] >= 0 && star[i] != i) {
            stars[star[i]].pb(i);
        }
    }

    trav(a, stars) {
        int cnt = sz(a.s);
        ans1[a.f] = nxt;
        F0R(i, cnt) {
            ans1[a.s[i]] = nxt+1;
            ans2[a.s[i]] = nxt;
            nxt++;
        }
        ans2[a.f] = nxt; nxt++;
    }

    F0R(i, N) cout << ans1[i] << " ";
    cout << nl;
    F0R(i, N) cout << ans2[i] << " ";
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