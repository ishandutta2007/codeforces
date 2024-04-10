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
const int MX = 100001; //check the limits, dummy
int N, P1, P2;
vector<vi> graph;

vector<vpi> paths;
bool usable[MX];
int totalDist;

int dfs1(int v, int p) {
    trav(a, graph[v]) {
        if (a == p) continue;
        int X = dfs1(a, v);
        paths[v].pb({X+1, a});
    }
    if (sz(paths[v]) == 0) {
        paths[v].pb({1, -1});
    }
    sort(all(paths[v])); reverse(all(paths[v]));
    return paths[v][0].f;
}

void dfs2(int v, int p, int d) {
    paths[v].pb({d+1, -1});
    sort(all(paths[v])); reverse(all(paths[v])); 
    if (sz(paths[v]) > 2 && paths[v][2].f >= totalDist) usable[v] = true;

    trav(a, graph[v]) {
        if (a == p) continue;
        int nd = paths[v][0].f;
        if (paths[v][0].s == a) nd = paths[v][1].f;
        dfs2(a, v, nd);
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        cin >> N >> P1 >> P2; P1--; P2--;
        F0R(i, N) usable[i] = false;
        graph.clear();
        paths.clear();
        F0R(i, N) graph.pb(vi());
        F0R(i, N) paths.pb(vpi());
        F0R(i, N-1) {
            int X, Y; cin >> X >> Y; X--; Y--;
            graph[X].pb(Y);
            graph[Y].pb(X);
        }

        int dist[N]; F0R(i, N) dist[i] = N;
        dist[P1] = 0;
        int lst[N]; F0R(i, N) lst[i] = -1;
        lst[P1] = -1;
        queue<int> q; q.push(P1);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            trav(a, graph[cur]) {
                if (dist[a] != N) continue;
                dist[a] = dist[cur] + 1;
                lst[a] = cur;
                q.push(a);
            }
        }
        totalDist = dist[P2]+1;
        bool onPath[N]; F0R(i, N) onPath[i] = false;
        vi path;
        int ppos[N]; 
        int cur = P2;
        while (cur != -1) {
            onPath[cur] = true;
            ppos[cur] = sz(path);
            path.pb(cur);
            cur = lst[cur];
        }

        queue<int> pivs;
        pivs.push(P1);
        pivs.push(P2);
        F0R(i, N) dist[i] = N;
        bool ok[N]; F0R(i, N) ok[i] = false;
        bool so[N]; 
        ok[P1] = true; ok[P2] = true;
        so[P1] = true; so[P2] = false;

        bool valid[N]; F0R(i, N) valid[i] = false;
        while (!pivs.empty()) {
            int cp = pivs.front(); pivs.pop();
            dist[cp] = 0;
            q.push(cp);
            int best = 0;
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                valid[cur] = true;
                trav(a, graph[cur]) {
                    if (dist[a] != N || onPath[a]) continue;
                    dist[a] = dist[cur] + 1;
                    ckmax(best, dist[a]);
                    q.push(a);
                }
            }
            if (so[cp]) { //from sz(path) - 1
                int pos = ppos[cp];
                pos += best;
                pos -= sz(path) - 1;
                F0R(i, pos+1) {
                    if (i >= sz(path)) break;
                    if (!ok[path[i]]) {
                        ok[path[i]] = true;
                        so[path[i]] = !so[cp];
                        pivs.push(path[i]);
                    }
                }
            } else {
                int pos = ppos[cp];
                pos -= best;
                pos += sz(path) - 1;
                FORd(i, pos, sz(path)) {
                    if (i < 0) break;
                    if (!ok[path[i]]) {
                        ok[path[i]] = true;
                        so[path[i]] = !so[cp];
                        pivs.push(path[i]);
                    }
                }
            }
        }
        dfs1(0, 0);
        dfs2(0, 0, -1);
        F0R(i, N) {
            if (usable[i] && valid[i]) {
                cout << "YES" << nl; goto done;
            }
        }
        cout << "NO" << nl;
        done:
        ;

    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343