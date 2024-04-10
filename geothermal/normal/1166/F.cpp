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

template<int SZ> struct DSU {
    int parent[SZ], size[SZ];
    int rep[SZ];
    set<int> colors[SZ];

    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 0, rep[i] = i;
    }

    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }
    
    int getRep(int x) {
		return rep[get(x)];
	}

    void unify(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return;
        int R = rep[x];
        if (sz(colors[rep[x]]) < sz(colors[rep[y]])) {
			R = rep[y];
			colors[rep[y]].insert(all(colors[rep[x]]));
		} else {
			colors[rep[x]].insert(all(colors[rep[y]]));
		}
        //int R = min(rep[y], rep[x]);
        rep[y] = R; rep[x] = R;
        
        if (size[x] < size[y]) swap(x, y);
        if (size[x] == size[y]) size[x]++;
        parent[y] = x;

    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    
    int N, M, C, Q; cin >> N >> M >> C >> Q;
    
    set<int> colors[N];
    
    vector<vpi> graph(N);
    
    map<int, int> indexToVertex;
    map<int, int> colorToVertex[N];
    
    int nextIndex = N;
    F0R(i, N) {
		indexToVertex.insert(mp(i, i));
	}
    
    F0R(i, M) {
		int X, Y, Z; cin >> X >> Y >> Z; 
		X--; Y--; Z--;
		graph[X].pb({Y, Z});
		graph[Y].pb({X, Z});
		if (!colors[X].count(Z)) {
			colors[X].insert(Z);
			indexToVertex.insert(mp(nextIndex, X));
			colorToVertex[X].insert(mp(Z, nextIndex));
			nextIndex++;
		}
		
		if (!colors[Y].count(Z)) {
			colors[Y].insert(Z);
			indexToVertex.insert(mp(nextIndex, Y));
			colorToVertex[Y].insert(mp(Z, nextIndex));
			nextIndex++;
		}
		
	}
	
	DSU<600000> dsu;
	
	F0R(i, N) { //add i odd to v even
		F0R(j, sz(graph[i])) {
			dsu.unify(i, colorToVertex[graph[i][j].f][graph[i][j].s]);
		}
	}
	
	F0R(i, nextIndex) {
		dsu.colors[dsu.getRep(i)].insert(indexToVertex[i]);
		//cout << "inserting " << indexToVertex[i] << " into " << dsu.getRep(i) << endl;
	}
	
	/*F0R(i, nextIndex) {
		cout << i << " " << indexToVertex[i] << " " << dsu.getRep(i) << endl;
	}*/
	
	F0R(i, Q) {
		//insert: just add a new vertex and unify if need be.
		char C; cin >> C;
		if (C == '+') {
			int X, Y, Z; cin >> X >> Y >> Z;
			X--; Y--; Z--;
			if (!colors[X].count(Z)) {
				colors[X].insert(Z);
				indexToVertex.insert(mp(nextIndex, X));
				colorToVertex[X].insert(mp(Z, nextIndex));
				nextIndex++;
			}
		
			if (!colors[Y].count(Z)) {
				colors[Y].insert(Z);
				indexToVertex.insert(mp(nextIndex, Y));
				colorToVertex[Y].insert(mp(Z, nextIndex));
				nextIndex++;
			}
			
			//merge X odd, Y-Z
			dsu.unify(X, colorToVertex[Y][Z]);
			dsu.unify(Y, colorToVertex[X][Z]);
			dsu.colors[dsu.getRep(X)].insert(Y);
			dsu.colors[dsu.getRep(X)].insert(X);
			dsu.colors[dsu.getRep(Y)].insert(X);
			dsu.colors[dsu.getRep(Y)].insert(Y);
			
		} else {
			int X, Y; cin >> X >> Y;
			X--;
			Y--;
			//cout << dsu.getRep(X) << " " << Y << endl;
			if (dsu.colors[dsu.getRep(X)].count(Y)) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
		
	}
	
	
    
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343