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
const int MX = 500001; //check the limits, dummy
vector<vi> graph;
vector<vi> dep;
bool vis[MX];
int par[MX];

void dfs(int v, int p, int d) {
    vis[v] = true;
    par[v] = p;
    if (sz(dep) <= d) {
        dep.pb(vi());
    }
    dep[d].pb(v);
    trav(a, graph[v]) {
        if (a == p || vis[a]) continue;
        dfs(a, v, d+1);
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        graph = vector<vi>(N);
        dep.clear();
        F0R(i, N) vis[i] = false;
        int M; cin >> M;
        F0R(i, M) {
            int A, B; cin >> A >> B; A--; B--;
            graph[A].pb(B);
            graph[B].pb(A);
        }
        dfs(0, -1, 0);

        if (sz(dep) >= (N+1)/2) {
            cout << "PATH" << nl;
            cout << (N+1)/2 << nl;
            int v = dep[(N-1)/2][0];
            cout << v+1 << " ";
            F0R(i, (N-1)/2) {
                v = par[v];
                cout << v+1 << " ";
            }
            cout << nl;
        } else {
            cout << "PAIRING" << nl;
            vpi ans;
            F0R(i, sz(dep)) {
                for (int j = 0; j < sz(dep[i])-1; j += 2) {
                    ans.pb({dep[i][j]+1, dep[i][j+1]+1});
                }
            }
            cout << sz(ans) << nl;
            trav(a, ans) {
                cout << a.f << " " << a.s << nl;
            }
        }

/*        F0R(i, sz(dep)) {
            cout << "DEP " << i << " " << sz(dep[i]) << nl;
            trav(a, dep[i]) {
                cout << a << " ";
            }
            cout << nl;
        }*/
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343