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
 
ll SZ = 262144;
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github


ll combine(ll a, ll b) { return min(a, b); }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    p += SZ;
    for (seg[p] = combine(value, seg[p]); p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = 1e12, resR = 1e12; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, K; cin >> N >> K;
    vector<pair<int, pi> > routers;
    F0R(i, N) {
        char C; cin >> C;
        if (C == '1') {
            int end = (i+K+1);
            end = min(end, N);
            int start = (i+1-K);
            start = max(1, start);
            int cost = i+1;
            routers.pb({end, {start, cost}});
        }
    }

    F0R(i, 2*SZ) seg[i] = 1000000000000;

    update(0, 0);
    routers.pb({N+1, {-1, -1}});
    sort(all(routers));
    int nxt = 0;
    FOR(i, 1, N+1) {
        update(i, query(i-1, i-1) + i);
        while(routers[nxt].f == i) {
            ll cost = routers[nxt].s.s;
            ll start = routers[nxt].s.f-1;
            update(i, query(start, i) + cost);

            nxt++;
        }
    }

    cout << query(N, N) << endl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343