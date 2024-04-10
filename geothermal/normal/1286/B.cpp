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
const int MX = 2001; //check the limits, dummy

vector<vi> graph;
int root;
int subsize[MX];
int ans[MX];
int C[MX];
void addDFS(int v, int p, int a, int b) { //add a to all >= b
    if (ans[v] >= b) ans[v] += a;
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        addDFS(nxt, v, a, b);
    }
}

bool dfs(int v, int p) { //assign subtree the numbers 1-N
    int sub = 1;

    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        if (!dfs(nxt, v)) return false;
        addDFS(nxt, v, sub-1, -1);
        sub += subsize[nxt];
    }
    //sub now has 1..N-1

    if (C[v] >= sub) {
        return false;
    }
    ans[v] = -1;
    addDFS(v, p, 1, C[v]+1);
    ans[v] = C[v]+1;
    subsize[v] = sub;

    return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    F0R(i, N) {
        vi blank; graph.pb(blank);
    }
    F0R(i, N) {
        int A, B; cin >> A >> B; A--;
        if (A == -1) {
            root = i;
        } else {
            graph[A].pb(i); graph[i].pb(A);
        }
        C[i] = B;
    }

    if(dfs(root, -1)) {
        cout << "YES" << endl;
        F0R(i, N) cout << ans[i] << " ";
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343