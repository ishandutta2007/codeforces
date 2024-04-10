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

ll SZ = 131072;
ll seg[262144][26]; //segtree implementation by bqi343's Github


ll combine(ll a, ll b) { return a+b; }


void update(int p, ll value, int X) {  
    for (seg[p += SZ][X] = value; p > 1; p >>= 1)
        seg[p>>1][X] = combine(seg[(p|1)^1][X], seg[p|1][X]);
}

ll query(int l, int r, int X) {  // sum on interval [l, r]
    ll resL = 0, resR = 0; r++;
    for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
        if (l&1) resL = combine(resL,seg[l++][X]);
        if (r&1) resR = combine(seg[--r][X],resR);
    }
    return combine(resL,resR);
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
	string S; cin >> S;
	
	int N = sz(S);
	
	F0R(i, 2*SZ) F0R(j, 26) seg[i][j] = 0;
	
	F0R(i, N) {
		update(i, 1, S[i] - 'a');
	}
	
	int Q; cin >> Q;
	
	F0R(i, Q) {
		int X; cin >> X;
		if (X == 1) {
			int P; cin >> P; P--;
			char C; cin >> C;
			update(P, 0, S[P] - 'a');
			update(P, 1, C-'a');
			S[P] = C;
		} else {
			int X, Y; cin >> X >> Y;
			X--;
			Y--;
			int ans = 0;
			F0R(i, 26) if (query(X, Y, i) > 0) ans++;
			cout << ans << endl;
		}
	}
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343