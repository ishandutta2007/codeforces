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
const int MX = 150001; //check the limits, dummy
vector<vi> graph(MX); 

bool found = false;
bool bad = false;
vi poss;
int K; 
void dfs(int v, int p, int d) {
    if (d == K-1) {
        if (sz(graph[v]) != 1) {
            bad = true;
        }
        return;
    }

    int S = sz(graph[v]);
    if (v != p) S--;
    if (S == 1) {
        if (d == K-2) {
            if (found) {
                bad = true;
            } else {
                found = true;
                poss.pb(v);
            }
        } else {
            bad = true;
        }
    } else if (S == 2) {
        trav(a, graph[v]) {
            if (a != p) dfs(a, v, d+1);
        }
    } else if (S == 3) {
        if (found) {
            bad = true; return;
        }
        if (bad) return;
        found = true; poss.pb(v);
        F0R(it, 3) {
            bad = false;
            int c = 0;
            F0R(i, sz(graph[v])) {
                int nxt = graph[v][i];
                if (nxt == p) continue;
                int nd = d+1; if (c != it) nd = d+2;
                dfs(nxt, v, nd);
                c++;
            }
            if (!bad) break;
        }
    } else {
        bad = true;
    }
    return;
}


int dep[MX];
void depdfs(int v, int p, int d) {
    dep[v] = d;
    trav(a, graph[v]) {
        if (a == p) continue;
        depdfs(a, v, d+1);
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> K;
    int N = 1 << K; N -= 2;
    F0R(i, N-1) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].pb(B); graph[B].pb(A);
    }
    depdfs(0, 0, 0);
    int e1 = 0;
    F0R(i, N) {
        if (dep[e1] < dep[i]) {
            e1 = i;
        }
    }
    depdfs(e1, e1, 0);
    int e2 = 0;
    F0R(i, N) {
        if (dep[e2] < dep[i]) {
            e2 = i;
        }
    }

    int dist[N]; F0R(i, N) dist[i] = -1;
    int last[N]; F0R(i, N) last[i] = -1;
    dist[e1] = 0;
    queue<int> q;
    q.push(e1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        trav(a, graph[cur]) {
            if (dist[a] == -1) {
                dist[a] = dist[cur] + 1;
                last[a] = cur;
                q.push(a);
            }
        }
    }

    int D = dist[e2];
    F0R(i, D / 2) {
        e2 = last[e2];
    }
    dfs(e2, e2, 0);
    vi cur;
    if (!bad) {
        cur = poss;
    }
    bad = false; found = false; poss.clear();
    e2 = last[e2];
    dfs(e2, e2, 0);
    if (!bad) {
        trav(a, poss) cur.pb(a);
    }
    cout << sz(cur) << nl;
    
    sort(all(cur));
    cur.resize(unique(all(cur)) - cur.begin());
    trav(a, cur) cout << a+1 << " ";
    cout << nl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343