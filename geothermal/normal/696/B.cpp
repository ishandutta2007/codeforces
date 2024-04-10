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
const int MX = 100001; //check the limits, dummy

vector<vi> graph;

double ans[MX];
int sub[MX];

int subDFS(int v, int p) {
	int count = 1;
	F0R(i, sz(graph[v])) {
		int nxt = graph[v][i];
		if (nxt == p) continue;
		count += subDFS(nxt, v);
	}
	return sub[v] = count;
}

void ansDFS(int v, int p, double val) {
	ans[v] = val;
	val++;
	int sum = sub[v] - 1;
	
	F0R(i, sz(graph[v])) {
		int nxt = graph[v][i];
		if (nxt == p) continue;
		ansDFS(nxt, v, val + ((double) (sum - sub[nxt]) / 2));
	}
	
}
	

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);	
	
	int N; cin >> N;
	
	vi blank; F0R(i, N) graph.pb(blank);
	
	FOR(i, 1, N) {
		int P; cin >> P; P--;
		graph[P].pb(i); graph[i].pb(P);
	}
	
	subDFS(0, -1);
	ansDFS(0, -1, 1);
	
	F0R(i, N) {
		cout << setprecision(20) << ans[i] << " ";
	}
	cout << endl;
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343