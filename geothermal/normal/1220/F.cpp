#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
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
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 200001; //check the limits, dummy
const ll SZ = 262144*2; 
struct Segtree1 {

ll identity = 0;

ll sum[2*SZ], lazy[2*SZ];
ll combine(ll A, ll B) {
    return max(A, B);
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
    if (lo > R || L > hi) return identity;
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
};

struct Segtree2 {

ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github

ll combine(ll a, ll b) { return min(a, b); }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    for (seg[p += SZ] = value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = 1000000, resR = 1000000; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}
};

Segtree1 seg1;
Segtree2 seg2;
int N;
int A[2*MX];

int L[2*MX], R[2*MX];

void add(int p) {
    seg1.update(L[p], R[p], 1);
}

void remove(int p) {
    seg1.update(L[p], R[p], -1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    F0R(i, 2*SZ) {
        seg1.sum[i] = 0;
        seg2.seg[i] = 1000000;
        seg1.lazy[i] = 0;
    }
    cin >> N;
    F0R(i, N) {
        cin >> A[i];
        seg2.update(i, A[i]);
        seg2.update(i+N, A[i]);
        A[i+N] = A[i];
    }
    F0R(i, 2*N) {
        int lo = 0, hi = i;
        while (lo < hi) {
            int mid = (lo+hi)/2;
            if (seg2.query(mid, i) == A[i]) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        L[i] = lo;
        lo = i;
        hi = 2*N;
        while (lo < hi) {
            int mid = (lo+hi+1)/2;
            if (seg2.query(i, mid) == A[i]) {
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        R[i] = lo;
    }
/*    F0R(i, 2*N) {
        cout << i << " " << L[i] << " " << R[i] << nl;
    }*/
    F0R(i, N) {
        add(i);
    }
    ll ans = seg1.query(0, N-1);
    int pos = 0;
    FOR(i, N, 2*N) {
        remove(i-N);
        add(i);
        if (ckmin(ans, seg1.query(i-N+1, i))) {
            pos = i-N+1;
        }
    }

    cout << ans << " " << pos << nl;

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343