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
const int MX = 100001; 
 
int N;
 
template<int SZ> struct DSU {
    int parent[SZ], size[SZ];
    set<int> mems[SZ];
    set<int> comps;
    pqg<pi> smol;
 
    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 1;
        F0R(i, N) {
            mems[i].ins(i);
            comps.ins(i);
            smol.push({1, i});
        }
    }
 
    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }
 
    void unify(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        size[x] += size[y];
        comps.erase(y);
        smol.push({size[x], x});
        trav(a, mems[y]) {
            mems[x].ins(a);
        }
        parent[y] = x;
 
        while (smol.top().f != size[smol.top().s] || parent[smol.top().s] != smol.top().s) {
            smol.pop();
        }
 
    }
};
 
void solve() {
    int X, Y; cin >> N >> X >> Y;
    DSU<MX> A, B;
    F0R(i, X) {
        int U, V; cin >> U >> V; U--; V--;
        A.unify(U, V);
    }
    F0R(i, Y) {
        int U, V; cin >> U >> V; U--; V--;
        B.unify(U, V);
    }
 
    if (X < Y) {
        swap(A, B);
        swap(X, Y);
    }
 
 
    vpi ans;
    F0R(i, N-1-X) {
        int C = A.smol.top().s;
        trav(a, A.mems[C]) {
            trav(b, B.comps) {
                if (b == B.get(a)) continue;
                trav(c, B.mems[b]) {
                    if (A.get(c) != C) {
                        A.unify(a, c);
                        B.unify(a, c);
                        ans.pb({a+1, c+1});
                        goto done;
                    }
                }
            }
        }
        done:
        ;
    }
 
    
    cout << sz(ans) << nl;
    trav(a, ans) {
        cout << a.f << " " << a.s << nl;
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