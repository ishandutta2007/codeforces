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
struct segtree1{ 
ll SZ = 262144*2;
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github


ll combine(ll a, ll b) { return a+b; }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    for (seg[p += SZ] += value; p > 1; p >>= 1)
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
};

struct segtree2{ 
ll SZ = 262144*2;
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
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;
    int lo[N], hi[N];

    int last[N]; F0R(i, N) last[i] = 0;

    F0R(i, N) {
        lo[i] = i+1, hi[i] = i+1;
    }
    segtree1 seg1; segtree2 seg2;
    F0R(i, 262144*2*2) {
        seg1.seg[i] = 0;
        seg2.seg[i] = 0;
    }
    seg1.update(0, N);
    FOR(i, 1,M+1) {
        int cur; cin >> cur; cur--;
        lo[cur] = 1;
        if (last[cur] == 0) {
            hi[cur] = cur+1+seg2.query(cur, 262143*2);

        } else {
            hi[cur] = max((ll)hi[cur], seg1.query(last[cur]+1, 262143*2)+1);
        }

        seg2.update(cur, 1);
        seg1.update(last[cur], -1);
        seg1.update(i, 1);

        last[cur] = i;
        
    }
    F0R(i, N) {
        int cur = i;
        if (last[cur] == 0) {
            hi[cur] = cur+1+seg2.query(cur, 262143*2);
            
        } else {
            hi[cur] = max((ll)hi[cur], seg1.query(last[cur]+1, 262143*2)+1);
            
        }
    }

    F0R(i, N) {
        cout << lo[i] << " " << hi[i] << endl;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343