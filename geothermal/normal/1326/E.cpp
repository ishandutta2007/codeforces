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
 
const ll identity = 0;
const ll SZ = 131072*4;

ll sum[2*SZ], lazy[2*SZ];

ll combine(ll A, ll B) {
    return min(A, B);
}

ll combineUpd(ll A, ll B) {
    return A+B;
}

void push(int index, ll L, ll R) {
    sum[index] = combineUpd(sum[index], lazy[index]);
    if (L != R) lazy[2*index] = combineUpd(lazy[2*index], lazy[index]), lazy[2*index+1] = combineUpd(lazy[2*index+1], lazy[index]);
    lazy[index] = identity;
}

void pull(int index) {
    sum[index] = combine(sum[2*index], sum[2*index+1]);
}

ll query(int lo, int hi, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (lo > R || L > hi) return 0;
    if (lo <= L && R <= hi) return sum[index];

    int M = (L+R) / 2;
    return combine(query(lo, hi, 2*index, L, M), query(lo, hi, 2*index+1, M+1, R));
}

void update(int lo, int hi, ll increase, int index = 1, ll L = 0, ll R = SZ-1) {
    push(index, L, R);
    if (hi < L || R < lo) return;
    if (lo <= L && R <= hi) {
        lazy[index] = increase;
        push(index, L, R);
        return;
    }

    int M = (L+R) / 2;
    update(lo, hi, increase, 2*index, L, M); update(lo, hi, increase, 2*index+1, M+1, R);
    pull(index);
}


struct SegTree{

ll SZ = 262144*2;
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github


ll combine(ll a, ll b) { return a+ b; }

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
	
    int N; cin >> N;
    int pos[N];
    F0R(i, N) {
        int X; cin >> X; X--;
        pos[X] = i;
    }
    cout << N << " ";
    set<int> bads;
    bads.insert(pos[N-1]); bads.insert(N);
    F0R(i, 2*SZ) sum[i] = 0, lazy[i] = 0;
    int ans = N-1;
    SegTree bombs; F0R(i, 2*SZ) bombs.seg[i] = 0;
    update(0, pos[N-1], -1);
    F0R(iter, N-1) {
        int X; cin >> X; X--;
        bombs.update(X, 1);
        if (bads.ub(X) != bads.begin()) {
            int val = *(--(bads.ub(X)));
            update(0, val, 1);
        }
/*        cout << "at " << iter << endl;
            F0R(i, N) cout << query(i, i) << " ";
            cout << endl;*/

        while (query(0, N-1) >= 0) {
            int below = -1;
            ans--;
            bads.insert(pos[ans]);
            if (bads.find(pos[ans]) != bads.begin()) {
                below = *(--(bads.find(pos[ans])));
            }
            int p1 = pos[ans];
            int p2 = *bads.ub(pos[ans]);
            int oCnt = bombs.query(below, p2-1);
            update(0, below, -1 * oCnt);
            update(0, below, bombs.query(below, p1-1));
            update(0, p1, bombs.query(p1, p2-1) - 1);
            //cout << "found " << p1 << " " << p2 << " " << below << " " << bombs.query(below, p1-1) << " " << bombs.query(p1, p2-1) << endl;
        }

        cout << ans+1 << " ";

    }
    cout << endl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343