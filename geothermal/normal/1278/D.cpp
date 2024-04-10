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
const int MX = 500001; //check the limits, dummy
 
ll SZ = 262144*8;
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github


ll combine(ll a, ll b) { return a+b; }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    for (seg[p += SZ] = value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = 0, resR = 0; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}


template<int SZ> struct DSU {
    int parent[SZ], size[SZ];

    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 0;
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

    }
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
    DSU<MX> dsu;
    int N; cin >> N;
    bool start[2*N];
    int val[2*N];
    int cor[2*N];
    F0R(i, N) {
        int A, B; cin >> A >> B; A--; B--;
        start[A] = true; start[B] = false;
        val[A] = i; val[B] = i;
        cor[A] = B; cor[B] = A;
    }
    ll count = 0;
    map<int, int> curSegs;
    F0R(i, 2*N) {
        if (start[i]) {
            for (auto it = curSegs.begin(); it != curSegs.end() && it->f < cor[i]; it++) {
                if (dsu.get(val[i]) == dsu.get(it->s)) {
                        cout << "NO" << endl;
                        return 0;
                }
                dsu.unify(val[i], it->s);
                count++;
                if (count >= N) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            curSegs.insert({cor[i], val[i]});
        } else {
            curSegs.erase(i);
        }
    }

    cout << (count==N-1?"YES":"NO") << endl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343