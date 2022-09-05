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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int N; cin >> N; N--;
    int B[N], C[N];
    
    F0R(i, N) {
    	cin >> B[i];
    }

    int nxtComp = 0;
    int compB[N], compC[N];
    map<int, int> comp, decomp;
    F0R(i, N) {
    	cin >> C[i];
    	if (C[i] < B[i]) {
    		cout << -1 << endl; return 0;
    	}
    	if (!comp.count(B[i])) {
    		comp.insert(mp(B[i], nxtComp));
    		decomp.insert(mp(nxtComp, B[i]));
    		//cout << "Compressed " << B[i] << " to " << nxtComp << endl;
    		nxtComp++;

    	}
    	if (!comp.count(C[i])) {
    		comp.insert(mp(C[i], nxtComp));
    		decomp.insert(mp(nxtComp, C[i]));
    		//cout << "Compressed " << C[i] << " to " << nxtComp << endl;
    		nxtComp++;
    	}

    	compB[i] = comp[B[i]];
    	compC[i] = comp[C[i]];
    		
    }

    vector<vpi> graph(nxtComp);
    F0R(i, N) {
    	graph[compB[i]].pb(mp(compC[i], i));
    	graph[compC[i]].pb(mp(compB[i], i));
    }
    
    int curV = 0, countOdd = 0;
    F0R(i, nxtComp) {
    	//cout << "Graph " << i << " has " << sz(graph[i]) << endl;
    	if (sz(graph[i]) % 2 == 1) {
    		countOdd++; curV = i;
    	}
    }
    if (countOdd != 0 && countOdd != 2) {
    	cout << -1 << endl; return 0;
    }

    bool active[N]; F0R(i, N) active[i] = true;

    vi path;
    stack<int> pending;
    while (sz(graph[curV]) || !pending.empty()) {
    	if (sz(graph[curV])) {
    		pending.push(curV);
    		int nxt = graph[curV].back().f;
    		active[graph[curV].back().s] = false;
    		graph[curV].pop_back();
    		curV = nxt;
    	} else {
    		path.pb(curV);
    		curV = pending.top(); pending.pop();
    	}
    	while (sz(graph[curV]) && !active[graph[curV].back().s]) {
    		graph[curV].pop_back();
    	}
    }
    path.pb(curV);

    if (sz(path) <= N) {
    	cout << -1 << endl; return 0;
    }

    F0R(i, sz(path)) {
    	cout << decomp[path[i]] << " ";
    }


    cout << endl;
    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343