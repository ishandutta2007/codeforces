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
#define shandom_ruffle random_shuffle

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 1001; //check the limits, dummy

vector<vpi> graph(MX);

pi leaves[MX];
vector<pair<pi, int> > ans;
int root = 0;

int dfs(int v, int p) {
	
	vi cur;
	int upInd;
	int addedAlready = 0;
	F0R(i, sz(graph[v])) {
		int nxt = graph[v][i].f;
		if (nxt == p) {
			upInd = i; continue;
		}
		addedAlready += dfs(nxt, v);
		cur.pb(leaves[nxt].f);
		if (leaves[nxt].s != leaves[nxt].f) cur.pb(leaves[nxt].s);
	}
	if (v == root) return 0;
	//process upwards node
	if (sz(cur) >= 2) {
		leaves[v] = mp(cur[0], cur[sz(cur) - 1]);
	} else {
		leaves[v] = mp(v, v);
	}
	
	int weight = graph[v][upInd].s - addedAlready;
	if (root != leaves[v].f) ans.pb(mp(mp(root, leaves[v].f), weight/2));
	if (root != leaves[v].s) ans.pb(mp(mp(root, leaves[v].s), weight/2));
	if (leaves[v].f != leaves[v].s) ans.pb(mp(mp(leaves[v].f, leaves[v].s), -1*weight/2));
	return addedAlready + weight;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N; cin >> N;
    
    F0R(i, N-1) {
		int A,B, C; cin >> A >> B >> C; A--; B--;
		graph[A].pb(mp(B, C)); graph[B].pb(mp(A, C));
	}
	
	
	while (sz(graph[root]) != 1) root++;
	//cout << root << " " << sz(graph[root]) << endl;
	F0R(i, N) {
		if (sz(graph[i]) == 2) {
			cout << "NO" << endl; return 0;
		}
	}
	
	dfs(root, -1);
	
	cout << "YES" << endl;
	cout << sz(ans) << endl;
	
	F0R(i, sz(ans)) {
		cout << ans[i].f.f+1 << " " << ans[i].f.s+1 << " " << ans[i].s << endl;
	}
	
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343