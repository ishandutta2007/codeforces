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
const int MX = 300001; //check the limits, dummy
 
template<int SZ> struct DSU {
    int parent[SZ], size[SZ], W[SZ], B[SZ], inv[SZ], col[SZ], man[SZ]; 
    vector<vi> graph;
    int ans = 0;

    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 1, W[i] = 1, B[i] = 0, man[i] = -1;
        graph = vector<vi>(SZ);
    }

    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }

    int findAns(int x) {
        if (man[x] == -1) {
            return min(W[x], B[x]);
        } else if (man[x] == 0) {
            return W[x];
        } else {
            return B[x];
        }
    }

    void unify(int x, int y, bool same) {
        int ox = x, oy = y;
//        cout << col[0] << " " << col[1] << " " << col[2] << " " << man[get(0)] << nl;
        if (col[x] != col[y]) same = !same;
        x = get(x); y = get(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
//        cout << x << " " << y << " " << same << nl;
        if (!same) {
            swap(W[y], B[y]);
            if (man[y] != -1) man[y] = 1 - man[y];
            queue<int> q; q.push(y);
            set<int> found; found.ins(y);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                col[cur] = 1 - col[cur];
                F0R(i, sz(graph[cur])) {
                    int nxt = graph[cur][i];
                    if (!found.count(nxt)) {
                        found.ins(nxt);
                        q.push(nxt);
                    }
                }
            }
        }
        graph[ox].pb(oy); graph[oy].pb(ox);
        size[x]+=size[y];
        ans -= findAns(x); ans -= findAns(y);
        ckmax(man[x], man[y]);
        W[x] += W[y]; B[x] += B[y];
//        cout << col[0] << " " << col[1] << " " << col[5] << nl;
//        cout << W[x] << " " << B[y] << " " << man[x] << nl;
        ans += findAns(x);
        parent[y] = x;

    }
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    DSU<MX> dsu;

    int N, K; cin >> N >> K;

    string S; cin >> S;

    vector<vi> A(N);
    F0R(i, K) {
        int C; cin >> C;
        F0R(j, C) {
            int X; cin >> X; X--;
            A[X].pb(i);
        }
    }

    F0R(i, N) {
        if (sz(A[i]) == 2) {
            if (S[i] == '1') {
                dsu.unify(A[i][0], A[i][1], true);
            } else {
                dsu.unify(A[i][0], A[i][1], false);
            }
        } else if (sz(A[i]) == 1) {
            int C = A[i][0];
            dsu.ans -= dsu.findAns(dsu.get(C));
            if (S[i] == '1') {
                dsu.man[dsu.get(C)] = 1 - dsu.col[C];
            } else {
                dsu.man[dsu.get(C)] = dsu.col[C];
            }
            dsu.ans += dsu.findAns(dsu.get(C));
        }
        cout << dsu.ans << nl;
    }


	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343