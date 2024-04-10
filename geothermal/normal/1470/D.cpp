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
const int MX = 300001; //check the limits, dummy


template<int SZ> struct DSU {
    int parent[SZ], size[SZ];

    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 0;
    }

    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }

    void unify(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        if (size[x] == size[y]) size[x]++;
        parent[y] = x;

    }
};
DSU<MX> dsu;
vector<set<int> > graph;
vi ans;

void solve() {

    int N, M; cin >> N >> M;
    F0R(i, N) {
        dsu.parent[i] = i; dsu.size[i] = i;
    }
    int cnt = 0;
    graph = vector<set<int> >(N); ans.clear();
    F0R(i, M) {
        int X, Y; cin >> X >> Y; X--; Y--; 
        if (dsu.get(X) != dsu.get(Y)) {
            dsu.unify(X, Y); cnt++; 
        }
        graph[X].ins(Y); graph[Y].ins(X);
    }
    if (cnt != N-1) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;

        bool done[N]; F0R(i, N) done[i] = false;
        stack<int> s;
        s.push(0);
        done[0] = true; ans.pb(0);
        trav(a, graph[0]) {
            done[a] = true; s.push(a);
        }
        while (!s.empty()) {
            int cur = s.top();
            while (!graph[cur].empty()) {
                int X = *graph[cur].begin();
                if (!done[X]) {
                    done[X] = true;
                    s.push(X);
                    ans.pb(X);
                    trav(a, graph[X]) {
                        done[a] = true; s.push(a);
                    }
                    goto fin;
                }
                graph[cur].erase(X);
            }
            s.pop();
            fin:
            ;
            
        }

        cout << sz(ans) << nl;
        trav(a, ans) cout << a+1 << " ";
        cout << nl;
    }
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
 
// read the question correctly (ll vs int)
// template by bqi343