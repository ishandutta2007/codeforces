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

int query(set<int> &A) {
    cout << "? " << sz(A) << " ";
    trav(a, A) cout << a+1 << " ";
    cout << endl;
    int res; cin >> res;
    return res;
}

void solve() {
    int N; cin >> N;
    vector<vi> graph(N); 
    set<pi> valEdges;
    F0R(i, N-1) {
        int X, Y; cin >> X >> Y; X--; Y--;
        valEdges.ins({X, Y});
        graph[X].pb(Y); graph[Y].pb(X);
    }
    set<int> cq; F0R(i, N) cq.ins(i);
    int hi = query(cq);
    while (sz(valEdges) > 1) {
        bool found[N]; F0R(i, N) found[i] = false;
        int remEd = sz(valEdges) / 2;
        cq.clear();
        trav(a, valEdges) {
            vi cur = {a.f, a.s};
            trav(r, cur) {
                if (found[r]) continue;
                found[r] = true;
                cq.ins(r);
                queue<int> q; q.push(r);
                while (!q.empty()) {
                    int v = q.front(); q.pop();
                    trav(a, graph[v]) {
                        if (!found[a] && (valEdges.count(mp(v, a)) || valEdges.count(mp(a, v)))) {
                            q.push(a);
                            found[a] = true;
                            if (remEd) {
                                cq.ins(a);
                                remEd--;
                            }
                        }
                    }
                }
            }
        }

        set<pi> nxtEdges;
        if (query(cq) == hi) {
            trav(a, valEdges) {
                if (cq.count(a.f) && cq.count(a.s)) {
                    nxtEdges.ins(a);
                }
            }
        } else {
            trav(a, valEdges) {
                if (cq.count(a.f) == 0 || cq.count(a.s) == 0) {
                    nxtEdges.ins(a);
                }
            }
        }

        valEdges = nxtEdges;
    }
    
    auto a = *valEdges.begin();
    cout << "! " << a.f+1 << " " << a.s+1 << endl;

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