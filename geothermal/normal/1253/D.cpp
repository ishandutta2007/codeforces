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
    int parent[SZ], size[SZ], hi[SZ];

    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 0, hi[i] = i;
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

        parent[y] = x;
        hi[x] = max(hi[x], hi[y]);

    }
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;
    DSU<MX> dsu;
    F0R(i, M) {
        int A, B; cin >> A >> B;
        A--; B--;
        dsu.unify(A, B);
    }

    int cur = -1;
    int hi = -1;
    int ans = 0;
    F0R(i, N) {
        if (cur == -1) {

            cur = dsu.get(i);
            hi = dsu.hi[cur];
        } else {
            if (dsu.get(i) != cur) {
                dsu.unify(cur, i);
                ans++;
                hi = dsu.hi[dsu.get(cur)];
                cur = dsu.get(cur);
            }
        }

        if (i == hi) {
            hi = -1; cur = -1;
        }
    }

    cout << ans << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343