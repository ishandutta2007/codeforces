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
const int MX = 200001; //check the limits, dummy
 
template<int SZ> struct DSU {
    int parent[SZ], size[SZ], begin[SZ], end[SZ], ignore[SZ];

    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 0, begin[i] = i, end[i] = i, ignore[i] = 0;
    }

    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }

    void unify(int x, int y) {
        x = get(x); y = get(y);
        int newB = begin[x], newE = end[y];
        if (x == y) {ignore[x] = 1; return;}
        if (size[x] < size[y]) swap(x, y);
        if (size[x] == size[y]) size[x]++;
        parent[y] = x;
        begin[x] = newB; end[x] = newE;
        ignore[x] += ignore[y];

    }
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    int ans[N];
    F0R(i, N) cin >> ans[i];
    F0R(i, N) ans[i]--;

    DSU<MX> dsu;
    F0R(i, N) {
        if (ans[i] != -1) {
            dsu.unify(dsu.get(i), dsu.get(ans[i]));
        }
    }
    vi comps;
    F0R(i, N) {
        if (dsu.get(i) == i && !dsu.ignore[dsu.get(i)]) comps.pb(i);
    }

    FOR(i, 1, sz(comps)) {
        int A = dsu.get(comps[0]);
        int B = dsu.get(comps[i]);
        ans[dsu.end[A]] = dsu.begin[B];
//        cout << "appending " << dsu.begin[B] << " " << dsu.end[A] << endl;
        dsu.unify(A, B);
    }

    int A = dsu.get(comps[0]);
    ans[dsu.end[A]] = dsu.begin[A];

    F0R(i, N) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343