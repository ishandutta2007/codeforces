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
const int MX = 200011; //check the limits, dummy


template<int SZ> struct DSU {
    int parent[SZ], size[SZ], weight[SZ];

    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 0, weight[i] = 0;
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
        weight[y] += weight[x];

    }
};
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    DSU<26> dsu;
    vi masks;
    int N; cin >> N;
    F0R(i, N) {
        string S; cin >> S;
        int cur = 0; int first = -1;
        F0R(j, sz(S)) {
            cur |= (1 << (S[j] - 'a'));
        }
        F0R(a, 26) {
            if (first == -1 && cur & (1 << a)) first = a;
            FOR(b, a+1, 26) {
                if (cur & (1 << a) && cur & (1 << b)) {
                    dsu.unify(a, b);
                }
            }
        }
        dsu.weight[dsu.get(first)]++;
        
    }
    int ans = 0;
    F0R(i, 26) {
        if (i == dsu.get(i) && dsu.weight[i] != 0) {
            ans++;
        }
    }
    cout << ans << endl;

	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343