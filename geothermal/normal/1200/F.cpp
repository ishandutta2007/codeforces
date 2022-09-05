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
const int MX = 100001; //check the limits, dummy
const int states = 2520;

vector<vi> graph;
bool inCycle[1001][2520];
int cycle[1001][2520];
vector<set<int> > cycleVals;
int values[1001];

set<pi> curStack;

int nextCycle = 0;

pair<pi, int> cycleDFS(int v, int c) {
	if (curStack.count(mp(v, c))) { //found cycle
		cycle[v][c] = nextCycle;
		inCycle[v][c] = true;
		set<int> cur; cur.insert(v);
		cycleVals.pb(cur);
		nextCycle++;
		return mp(mp(v, c), nextCycle-1);
	}
	if (cycle[v][c] != -1) {
		return mp(mp(-1, -1), cycle[v][c]);
	}
	
	curStack.insert(mp(v, c));
	
	c += values[v]; c %= 2520;
	
	pair<pi, int> res = cycleDFS(graph[v][c % sz(graph[v])], c);
	c -= values[v]; c += 2520; c %= 2520;
	
	if (curStack.count(res.f)) {
		inCycle[v][c] = true;
		cycleVals[res.s].insert(v);
	} else {
		inCycle[v][c] = false;
	}
	
	cycle[v][c] = res.s;
	
	
	curStack.erase(mp(v, c));
	
	return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);    
    
    int N; cin >> N;
    F0R(i, N) {
		vi blank; graph.pb(blank);
	}
	
	F0R(i, N) {
		ll K; cin >> K;
		K += 1008000000;
		K %= 2520;
		values[i] = K;
	}
	
	F0R(i, N) {
		int M; cin >> M;
		vi cur(M);
		F0R(j, M) {
			int K; cin >> K; K--; cur[j] = K;
		}
		graph[i] = cur;
	}
	
	F0R(i, N) {
		F0R(j, 2520) {
			cycle[i][j] = -1;
		}
	}
	
	
	F0R(i, N) {
		F0R(j, 2520) {
			if (cycle[i][j] == -1) {
				cycleDFS(i, j);
			}
		}
	}
	
	/*F0R(i, N) {
		cout << "Cycle: ";
		cout << cycle[i][0] << " ";
	}
	cout << endl;
	cout << "Size: " << sz(cycleVals[0]) << endl;*/
	
	int Q; cin >> Q;
	
	F0R(i, Q) {
		int X; ll Y; cin >> X >> Y; X--;
		Y += 1008000000; Y %= 2520;
		cout << sz(cycleVals[cycle[X][Y]]) << endl;
	}
	
    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343