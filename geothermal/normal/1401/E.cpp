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
 
ll SZ = 262144*4; //set this to power of two
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
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; cin >> N >> M;

    ll ans = 1;
    vector<pair<int, pl> > H;
    vector<pair<int, pair<int, bool> > > ev;

    F0R(i, N) {
        int A, B, C; cin >> A >> B >> C;
        if (B == 0 && C == 1000000) {
            ans++;
        }
        H.pb({A, {B, C}});
    }

    F0R(i, M) {
        int A, B, C; cin >> A >> B >> C;
        if (B == 0 && C == 1000000) {
            ans++;
            update(A, 1);
        } else if (B == 0) {
            update(A, 1);
            ev.pb({C, {A, false}});
        } else if (C == 1000000) {
            ev.pb({B-1, {A, true}});
        }  else {
            assert(false);
        }
    }
    int p = 0;
    sort(all(H)); sort(all(ev));
    F0R(i, N) {
        while (p < sz(ev) && ev[p].f < H[i].f) {
//            cout << "PROC " << ev[p].s.f << " " << ev[p].s.s << nl;
            if (ev[p].s.s) {
                update(ev[p].s.f, 1);
            } else {
                update(ev[p].s.f, -1);
            }
            p++;
        }
        ans += query(H[i].s.f, H[i].s.s);
//        cout << i << " " << ans << nl;
    }
    cout << ans << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343