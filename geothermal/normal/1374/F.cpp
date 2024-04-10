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
const int MX = 100001; //check the limits, dummy
 
ll SZ = 512; //set this to power of two
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
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        vi A(N); F0R(i, N) cin >> A[i];
        int ic = 0;
        F0R(i, 2*SZ) seg[i] = 0;
        F0R(i, N) {
            ic += query(0, A[i] - 1);
            update(A[i], 1);
        }
//        if (ic % 2 != 0) {
            //cout << -1 << nl; continue;
//        }
        vi ans;
        int E = 0;
        F0R(i, SZ) if (query(i, i) > 1) E = i;
        int lit = 0;
        FORd(it, 2, N) {
            int lo = 0, lp = -1;
            F0Rd(i, it+1) {
                if (ckmax(lo, A[i])) {
                    lp = i;
                }
            }
            if (lo <= E) {
                lit = it;
                break;
            }
            while (lp < it) {
                if (lp == 0) {
                    ans.pb(0);
                    swap(A[0], A[2]);
                    swap(A[1], A[2]);
                } else {
                    ans.pb(lp-1);
                    swap(A[lp-1], A[lp+1]);
                    swap(A[lp], A[lp+1]);
                }
                lp++;
            }
/*            while (lp > it+1) {
                ans.pb(lp-2);
                swap(A[lp], A[lp-2]);
                swap(A[lp], A[lp-1]);
                lp -= 2;
            }
            if (lp == it+1) {
                ans.pb(lp-1); ans.pb(lp-1);
                swap(A[lp], A[lp-1]);
                swap(A[lp], A[lp+1]);
            }*/
        }

        F0R(it, lit+1) {
            int lo = 501, lp = -1;
            FOR(i, it, N) {
                if (ckmin(lo, A[i])) {
                    lp = i;
                }
            }
            while (lp > it+1) {
                ans.pb(lp-2);
                swap(A[lp], A[lp-2]);
                swap(A[lp], A[lp-1]);
                lp -= 2;
            }
            if (lp == it+1) {
                ans.pb(lp-1); ans.pb(lp-1);
                swap(A[lp], A[lp-1]);
                swap(A[lp], A[lp+1]);
            }
        }
        F0R(i, N-1) {
            if (A[i] > A[i+1]) {
                cout << -1 << nl; goto bad;
            }
        }
        cout << sz(ans) << nl;
        F0R(i, sz(ans)) {
            cout << ans[i]+1 << " ";
        }
        cout << nl;
        bad:
        ;
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343