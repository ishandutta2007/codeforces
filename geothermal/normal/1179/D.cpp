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
const int MX = 500001; //check the limits, dummy
vector<vi> graph;
ll subSize[MX];
ll ans, N;

pl dfs(int v, int p) {
    map<ll, ll> data;
    ll subsize = 1;
    if (sz(graph[v]) == 1) {
        return {1, 0};
    }
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (nxt == p) continue;
        pl cur = dfs(nxt, v);
        subsize += cur.f;
        if (data.count(cur.f)) {
            ll remV = N - 2*cur.f;
            ans = min(ans, data[cur.f] + cur.s + (remV*remV-remV)/2);
            data[cur.f] = min(data[cur.f], cur.s);
        } else {
            data[cur.f] = cur.s;
        }

    }
    vpl options;
    for (auto it : data) options.pb(it);
    F0R(i, sz(options)) {
        FOR(j, i+1, sz(options)) {
            ll remV = N - options[i].f - options[j].f;
            ans = min(ans, options[i].s + options[j].s + (remV*remV-remV)/2);
        }
    }
    ll res = MX; res *= MX;
    F0R(i, sz(options)) {
        ll remV = subsize - options[i].f;
        res = min(res, options[i].s + (remV*remV-remV)/2);
    }
    return {subsize, res};

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N;
    if (N == 2) {
        cout << 2 << endl; return 0;
    }
    
    F0R(i, N) {
        vi blank; graph.pb(blank);
    }
    ans = (N*N-N)/2;

    F0R(i, N-1) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].pb(B);
        graph[B].pb(A);
    }

    int root = 0;
    if (sz(graph[0]) == 1) {
        root = graph[0][0];
    }

    dfs(root, -1);

    cout << N*(N-1)-ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343