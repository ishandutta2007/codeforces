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
struct Segtree{

ll SZ = 262144*2; //set this to power of two
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github

ll combine(ll a, ll b) { return a + b; }

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


vi zFun(string s) {
    int n = (int) s.length();
    vi z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;

    string X, Y, S; cin >> X >> Y >> S;

    string Z1 = S; Z1.pop_back(); Z1 += '#'; Z1 += X;
    vi R1 = zFun(Z1);
    vi A; FOR(i, sz(S), sz(R1)) A.pb(R1[i]);

    reverse(all(S)); reverse(all(Y));
    string Z2 = S; Z2.pop_back(); Z2 += '#'; Z2 += Y;
    vi R2 = zFun(Z2);
    vi B; FORd(i, sz(S), sz(R2)) B.pb(R2[i]);


    Segtree seg1, seg2;
    F0R(i, 262144*4) {
        seg1.seg[i] = 0;
        seg2.seg[i] = 0;
    }

    F0R(i, min(N, M-1)) {
        seg1.update(B[i], B[i]);
        seg2.update(B[i], 1);
    }

/*    F0R(i, N) {
        cout << A[i] << " " << B[i] << nl;
    }*/

    ll ans = 0;
    F0R(i, N) {
        int P = max(M-A[i]-1, 0);
        ans += seg1.query(P, N+1) + seg2.query(P, N+1) * (A[i] + 1 - M);

        seg1.update(B[i], -B[i]);
        seg2.update(B[i], -1);
        if (i+M-1<N) {
            seg1.update(B[i+M-1], B[i+M-1]);
            seg2.update(B[i+M-1], 1);
        }
    }

    cout << ans << nl;

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343