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
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
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
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 1100; //check the limits, dummy
 
vector<vi> graph;
int subSize[MX];
int weight[MX];
int total[MX];
int root;
int parent[MX];
int nextWeight = 1;

int subsizeDFS(int v, int p) {
    int ans = 1;
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        ans += subsizeDFS(nxt, v);
    }
    return subSize[v] = ans;
}

int rerootDFS(int v, int p) {
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        if (subSize[nxt] > sz(graph) / 2) {
            return rerootDFS(nxt, v);
        }
    }
    return v;

}

void multiplyDFS(int v, int p, int k) {
    weight[v] *= k;
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        multiplyDFS(nxt, v, k);
    }
}

void assignDFS(int v, int p) {
    parent[v] = p;
    if (v != root) {
        total[v] = nextWeight;
        weight[v] = total[v] - total[p];
    } else {
        total[v] = 0;

    }

    //cout << v << " " << p << " " << nextWeight << endl;

    nextWeight++;

    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        assignDFS(nxt, v);
    }
    
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    F0R(i, N) {
        vi blank; graph.pb(blank);
    }

    F0R(i, N-1) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].pb(B); graph[B].pb(A);
    }
    subsizeDFS(0, -1);

    root = rerootDFS(0, -1);

    subsizeDFS(root, -1);

    bool dp[MX]; F0R(i, MX) dp[i] = false;
    dp[0] = true;
    int last[MX], lastPoint[MX];

    F0R(i, sz(graph[root])) {
        int cur = subSize[graph[root][i]];
        F0Rd(j, MX-cur) {
            if (dp[j] && !dp[j+cur]) {
                dp[j+cur] = true;
                last[j+cur] = i;
                lastPoint[j+cur] = j;
            }
        }
    }

    bool use[sz(graph[root])];
    int totalUsed;
    F0Rd(cnt, (N+1)/2) {
        if (!dp[cnt]) continue;
        totalUsed = cnt;
        F0R(i, sz(graph[root])) use[i] = false;
        int cur = cnt;
        while (cur > 0) {
            use[last[cur]] = true;
            cur = lastPoint[cur]; 
        }
        break;
    }

    //cout << last[2] << " " << last[1] << endl;

    //cout << totalUsed << endl;

    total[root] = 0;

    F0R(i, sz(graph[root])) {
        //cout << i << (use[i] ? "YES" : "NO") << " " << graph[root][i] << endl;
        if (!use[i]) continue;
        assignDFS(graph[root][i], root);
    }

    nextWeight = 1;

    F0R(i, sz(graph[root])) {
        if (use[i]) continue;
        assignDFS(graph[root][i], root);
        multiplyDFS(graph[root][i], root, totalUsed+1);
    }

    F0R(i, N) {
        if (i == root) continue;
        cout << i+1 << " " << parent[i]+1 << " " << weight[i] << endl;
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343