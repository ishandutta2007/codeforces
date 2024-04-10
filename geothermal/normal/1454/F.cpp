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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
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
const int MX = 100001; //check the limits, dummy
struct Seg1 { 
ll SZ = 262144; //set this to power of two
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github

ll combine(ll a, ll b) { return min(a, b); }

void build() { F0Rd(i,SZ) seg[i] = combine(seg[2*i],seg[2*i+1]); }

void update(int p, ll value) {  
    for (seg[p += SZ] = value; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

ll query(int l, int r) {  // sum on interval [l, r]
    ll resL = SZ, resR = SZ; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
    return combine(resL,resR);
}
};

struct Seg2 { 
ll SZ = 262144; //set this to power of two
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github

ll combine(ll a, ll b) { return max(a, b); }

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
	
    int T; cin >> T;
    Seg1 lo; Seg2 hi;
    while(T--) {
        int N; cin >> N;
        int A[N]; F0R(i, N) cin >> A[i];
        set<int> used; F0R(i, N) used.ins(A[i]);
        map<int, int> comp;
        trav(a, used) {
            comp.ins({a, sz(comp)});
        }
        F0R(i, N) A[i] = comp[A[i]];
        set<int> pos[sz(comp)];
        F0R(i, N) {
            pos[A[i]].ins(i);
        }
        F0R(i, sz(comp)) {
            lo.update(i, *pos[i].begin());
            hi.update(i, *pos[i].rbegin());
        }
        int mx = 0;
        F0R(i, N) {
            ckmax(mx, A[i]);
            pos[A[i]].erase(pos[A[i]].begin());
            if (sz(pos[A[i]]) > 0) {
                lo.update(A[i], *pos[A[i]].begin());
            } else {
                lo.update(A[i], N);
            }
            int loPos = max(lo.query(mx, mx), hi.query(mx+1, sz(comp) - 1));
            int hiPos = min(lo.query(0, mx - 1), hi.query(mx, mx)) - 1;
            if (loPos <= hiPos) {
                cout << "YES" << nl;
                cout << i+1 << " " << loPos-i << " " << N-loPos-1 << nl;
                goto done;
            }
        }
        cout << "NO" << nl;
        done:
        ;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343