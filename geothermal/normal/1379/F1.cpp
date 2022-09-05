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
const ll SZ = 262144; //set this to power of two
struct node {
    ll O, E;
    bool F;
    node() {
        O = 1000000; E = -1; F = false;
    }
    node(ll X, ll Y) {
        O = X; E = Y; F = false;
    }

};
node seg[2*SZ];

node combine(node A, node B) {
    node res;
    res.O = min(A.O, B.O);
    res.E = max(A.E, B.E);
    res.F = A.O <= B.E || A.F || B.F;
    return res;
}


void update(int p, pl value) {  
    p += SZ;
    seg[p].O = value.f;
    seg[p].E = value.s;
    seg[p].F = value.f <= value.s;
    for (; p > 1; p >>= 1)
        seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
}

bool query(int l, int r) {  // sum on interval [l, r]
    node resL, resR; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++]);
        if (r&1) resR = combine(seg[--r],resR);
    }
/*    cout << resL.O << " " << resL.E << " " << resL.F << nl;
    cout << resR.O << " " << resR.E << " " << resR.F << nl;*/
    return combine(resL,resR).F;
}



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M, Q; cin >> N >> M >> Q;

    set<int> odd[N], even[N];
    F0R(i, N) {
        odd[i].ins(1000000);
        even[i].ins(-1);
    }
    while(Q--) {
        int X, Y; cin >> X >> Y; X--; Y--;

        if (X % 2 == 0) {
            if (odd[X / 2].count(Y)) {
                odd[X / 2].erase(Y);
            } else odd[X / 2].ins(Y);
        } else {
            if (even[X / 2].count(Y)) {
                even[X / 2].erase(Y);
            } else {
                even[X / 2].ins(Y);
            }
        }
        pl cur = {*odd[X / 2].begin(), *even[X / 2].rbegin()};
        update(X / 2, cur);
        if (!query(0, N-1)) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
    }
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343