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
    
    int N; cin >> N;
    if (N == 1) {
    	cout << 1 << endl; return 0;
    }
    vector<vi> graph(N);
    F0R(i, N-1) {
    	int A, B; cin >> A >> B; A--; B--;
    	graph[A].pb(B); graph[B].pb(A);
    }

    vi leaves; F0R(i, N) {
    	if (sz(graph[i]) == 1) {
    		leaves.pb(i);
    	}
    }

    int depths[N], parent[N];
    F0R(i, N) {
    	depths[i] = -1; parent[i] = -1;
    }
    queue<int> Q;
    vi degDepth, rep;
    F0R(i, sz(leaves)) {
    	if (i == 0) {
    		degDepth.pb(1); rep.pb(leaves[0]);
    	}
    	int cur = leaves[i];
    	depths[cur] = 0;
    	parent[cur] = cur;
    	Q.push(cur);
    }

    vi options;
    int best, index; queue<int> empty;
    while (!Q.empty()) {
    	int cur = Q.front(); Q.pop();
    	F0R(i, sz(graph[cur])) {
    		int nxt = graph[cur][i];
    		if (depths[nxt] == -1) {
    			depths[nxt] = depths[cur] + 1;
    			parent[nxt] = parent[cur];
    			if (sz(degDepth) <= depths[nxt]) {
    				degDepth.pb(sz(graph[nxt]));
    				rep.pb(nxt);
    			} else if (sz(graph[nxt]) != degDepth[depths[nxt]]) {
    				options.pb(parent[rep[depths[nxt]]]);
    				options.pb(parent[nxt]);
    				goto done;
    			}
    			Q.push(nxt);
    		} else {
    			if (depths[nxt] != depths[cur] + 1 && depths[nxt] != depths[cur] - 1) {
    				options.pb(parent[cur]); options.pb(parent[nxt]);
    				goto done;
    			}
    		}
    	}
    }

    best = -1, index = -1;
    F0R(i, N) {
    	if (depths[i] > best) {
    		best = depths[i];
    		index = i;
    	}
    }

    options.pb(index);
    

    done:;
    Q = empty;

    F0R(curVal, sz(options)) {
    	int root = options[curVal];
    	//cout << root << endl;
    	F0R(i, N) depths[i] = -1;
    	depths[root] = 0;
    	int goodDeg[N]; F0R(i, N) goodDeg[i] = -1;
    	goodDeg[0] = sz(graph[root]);
    	Q.push(root);
    	while (!Q.empty()) {
    		int cur = Q.front(); Q.pop();
	    	F0R(i, sz(graph[cur])) {
	    		int nxt = graph[cur][i];
	    		if (depths[nxt] == -1) {
	    			depths[nxt] = depths[cur] + 1;
	    			//cout << nxt << " " << depths[nxt] << endl;
	    			if (goodDeg[depths[nxt]] == -1) {
	    				goodDeg[depths[nxt]] = sz(graph[nxt]);
	    			} else if (goodDeg[depths[nxt]] != sz(graph[nxt])) {
	    				//cout << "Bad: " << nxt << " " << sz(graph[nxt]) << " different from " << goodDeg[depths[nxt]] << endl;
	    				goto bad;
	    			}
	    			Q.push(nxt);
	    		}
	    	}
    	}

    	cout << root+1 << endl; return 0;

    	bad:;
    	Q = empty;
    }

    cout << -1 << endl;
    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343