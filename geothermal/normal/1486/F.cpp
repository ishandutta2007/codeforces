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

int N;
const int L = 19;
int anc[MX][L];
int depth[MX];
int parent[MX];
vector<vi> graph(MX);
vector<vi> chil(MX);

int LCA(int a, int b) {
    if (depth[a] < depth[b]) {
        int c = b;
        b = a;
        a = c;
    }

    int dist = depth[a] - depth[b];
    while (dist > 0) {
        F0R(i, L) {
            if (dist & 1 << i) {
                a = anc[a][i];
                dist -= 1 << i;
            }
        }
    }

    if (a == b) return a;

    F0Rd(j, L) {
        if (anc[a][j] != -1 && anc[a][j] != anc[b][j]) {
            a = anc[a][j]; b = anc[b][j];
        }
    }
    return parent[a];
}

int lift(int v, int d) {
    F0Rd(i, L) {
        if (depth[v] - (1 << i) >= d) {
            v = anc[v][i];
        }
    }
    return v;
}

void parDFS(int v, int p, int d) {
    parent[v] = p; depth[v] = d;
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        chil[v].pb(nxt);
        parDFS(nxt, v, d+1);
    }
}

void preprocess() {
    parDFS(0, -1, 0);
    F0R(i, N) F0R(j, L) anc[i][j] = -1;
    F0R(i, N) anc[i][0] = parent[i];
    FOR(j, 1, L) {
        F0R(i, N) {
            if (anc[i][j-1] != -1) {
                anc[i][j] = anc[anc[i][j-1]][j-1];
            }
        }
    }
}

ll ans = 0;
ll sta[MX];
ll cap[MX];
map<pi, ll> Ls[MX];

ll dfs(int v) {
    ll numPaths = sta[v]-cap[v];
    ll cnt[sz(chil[v])];
    F0R(i, sz(chil[v])) {
        cnt[i] = dfs(chil[v][i]);
        numPaths += cnt[i];
    }
    trav(a, Ls[v]) {
        numPaths -= a.s;
        ll val = numPaths;
        if (a.f.f != MX) {
            cnt[a.f.f]-= a.s;
            val -= cnt[a.f.f];
        }
        if (a.f.s != MX) {
            cnt[a.f.s] -= a.s;
            val -= cnt[a.f.s];
        }
        ans += val * a.s;
        if (a.f.f == MX && a.f.s == MX) {
            ans += (a.s * (a.s-1))/2;
        }
    }
    return numPaths;

}

void solve() {

    cin >> N;
    F0R(i, N-1) {
        int X, Y; cin >> X >> Y; X--; Y--;
        graph[X].pb(Y); graph[Y].pb(X);
    }
    preprocess();

    F0R(i, N) sort(all(chil[i]));
    int M; cin >> M;
    F0R(i, M) {
        int X, Y; cin >> X >> Y; X--; Y--;
        int lc = LCA(X, Y);
        sta[X]++; sta[Y]++; cap[lc]++;
        int A = MX, B = MX;
        if (X != lc) {
            X = lift(X, depth[lc] + 1);
            auto it = lb(all(chil[lc]), X);
            A = it-chil[lc].begin();
        } 
        if (Y != lc) {
            Y = lift(Y, depth[lc] + 1);
            auto it = lb(all(chil[lc]), Y);
            B = it-chil[lc].begin();
        }
        if (A > B) swap(A, B);
        Ls[lc][{A, B}]++;
    }

    dfs(0);
    cout << ans << nl;

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
 
// read the question correctly (ll vs int)
// template by bqi343