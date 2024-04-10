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

template<int SZ> struct DSU {
    int parent[SZ], size[SZ]; ll comp[SZ];

    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 0, comp[i] = 1;
    }

    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }

    void unify(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        if (size[x] == size[y]) size[x]++;
        comp[x] += comp[y];
        parent[y] = x;

    }
};
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 200011; //check the limits, dummy
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
	//MOOTUBE LMAOOOOOOOOOOOOO
	
	ll ans = 0;
	
	int N; cin >> N;
	
	vector<pair<int, pi> > edges;
	int M; cin >> M;
	
	vpi queries(M);
	
	F0R(i, N-1) {
		int A, B, C; cin >> A >> B >> C;
		A--;
		B--;
		edges.pb(mp(C, mp(A, B)));
	}
	
	F0R(i, M) {
		int cur; cin >> cur; queries[i] = {cur, i};
	}
	
	ll res[M];
	
	sort(all(queries));
	sort(all(edges));
	
	int nxt = 0;
	
	DSU<MX> dsu;
	F0R(i, M) {
		while (nxt < N-1 && edges[nxt].f <= queries[i].f) {
			int A = edges[nxt].s.f;
			int B = edges[nxt].s.s;
			A = dsu.get(A); B = dsu.get(B);
			
			ll cA = dsu.comp[A], cB = dsu.comp[B];
			ans -= (cA*(cA-1))/2;
			ans -= (cB*(cB-1))/2;
			
			dsu.unify(A, B);
			
			ll cC = dsu.comp[dsu.get(A)];
			ans += (cC*(cC-1))/2;
			nxt++;
		}
		
		res[queries[i].s] = ans;
		
	}
	
	
	F0R(i, M) cout << res[i] << " ";
	
	cout << endl;
	
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343