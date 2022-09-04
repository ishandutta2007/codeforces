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

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; 

vector<set<int>> graph(MX);
bool takePar[MX];
vpi remEdge;
vpi lines;

void eraseEdge(int v, int u) {
    graph[v].erase(u);
    graph[u].erase(v);
    remEdge.pb({v+1, u+1});
}

void dfs(int v, int p) {
    trav(a, graph[v]) {
        if (a != p) dfs(a, v);
    }

    int rem = 2;
    vpi tbr;
    trav(a, graph[v]) {
        if (a == p) continue;
        if (takePar[a]) { //Edge from parent is kept
            if (rem) {
                rem--;
            } else {
                tbr.pb({a, v});
            }
        } else {
            tbr.pb({a, v});
        }

    }
    trav(a, tbr) eraseEdge(a.f, a.s);
    takePar[v] = rem > 0;
}

void solve() {
    int N; cin >> N;
    F0R(i, N) graph[i].clear();
    remEdge.clear();
    lines.clear();
    F0R(i, N-1) {
        int X, Y; cin >> X >> Y; X--; Y--;
        graph[X].ins(Y); graph[Y].ins(X);
    }

    dfs(0, -1);

    bool found[N]; F0R(i, N) found[i] = false;
    F0R(r, N) {
        if (sz(graph[r]) == 0) {
            lines.pb({r+1, r+1});
        } else if (!found[r] && sz(graph[r]) < 2) {
            found[r] = true;
            queue<int> q; q.push(r);
            while (!q.empty()) {
                int v = q.front(); q.pop();
                if (sz(graph[v]) < 2 && v != r) {
                    lines.pb({r+1, v+1});
                }
                trav(a, graph[v]) {
                    if (!found[a]) {
                        q.push(a);
                        found[a] = true;
                    }
                }
            }
        } 
    }
    /*cout << sz(remEdge) << endl;
    cout << sz(lines) << endl;*/

    assert(sz(remEdge) == sz(lines)-1);
    cout << sz(remEdge) << nl;
    F0R(i, sz(remEdge)) {
        cout << remEdge[i].f << " " << remEdge[i].s << " "<< lines[i].s << " " << lines[i+1].f << nl;
    }
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