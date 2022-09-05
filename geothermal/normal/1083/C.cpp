#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef complex<ll> cl;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<cl> vcl;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 200001; //check the limits, dummy
 
const int L = 18;
int anc[MX][L];
int depth[MX];
int parent[MX];
vector<vi> graph(MX);
int pos[MX], fin[MX];
int tim = 0;
int N;

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

void parDFS(int v, int p, int d) {
    parent[v] = p; depth[v] = d;
    pos[v] = tim; tim++;
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        parDFS(nxt, v, d+1);
    }
    fin[v] = tim;
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

ll SZ = 262144;
pi* seg = new pi[2*SZ]; //segtree implementation by bqi343's Github
int perm[MX];

pi combine(pi a, pi b) { 
    vi data = {a.f, a.s, b.f, b.s};
    if (data[0] == -2) {
        return b;
    }
    if (data[2] == -2) {
        return a;
    }
    if (data[0] == -1 || data[2] == -1) return {-1, -1};
    F0R(i, 3) {
        FOR(j, i+1, 4) {
            int L = LCA(data[i], data[j]);
            F0R(k, 4) {
                if (k == i || k == j) continue;
                if (pos[L] > pos[data[k]] || fin[L] <= pos[data[k]]) goto done;
                bool A = (pos[data[k]] <= pos[data[i]] && fin[data[k]] > pos[data[i]]);
                bool B = (pos[data[k]] <= pos[data[j]] && fin[data[k]] > pos[data[j]]);
                if (!A && !B) goto done;
            }
            return {data[i], data[j]};
            done:
            ;
        }
    }
    return {-1, -1};
}


void update(int p, int value) {  
    seg[p += SZ] = {value, value};
    for (; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

int query() {  // sum on interval [l, r]
    int index = 1;
    int value = 1 << 17;
    pi res = {-2, -2};
    int ans = 0;
    while (index < SZ) {
        pi opt = combine(res, seg[2*index]);
        if (opt.f != -1) {
            res = opt;
            index = 2*index+1;
            ans += value;
        } else {
            index = 2*index;
        }
        value /= 2;
    }
    return ans;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N;
    F0R(i, N) cin >> perm[i];
    F0R(i, N-1) {
        int P; cin >> P; P--;
        graph[i+1].pb(P);
        graph[P].pb(i+1);
    }
    preprocess();
    F0R(i, 2*SZ) seg[i] = {-1, -1};
    F0R(i, N) update(perm[i], i);

/*    pi res = combine({2, 2}, {4, 4});
    cout << res.f << " " << res.s << endl;
    cout << LCA(2, 4) << endl;
    cout << pos[2] << " " << fin[2] << " " << pos[4] << " " << fin[4] << endl;*/
    int Q; cin >> Q;
    while(Q--) {
        int T; cin >> T;
        if (T == 1) {
            int X, Y; cin >> X >> Y; X--; Y--;
            update(perm[X], Y);
            update(perm[Y], X);
            swap(perm[X], perm[Y]);
        } else {
            printf("%d\n", query());
        }
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343