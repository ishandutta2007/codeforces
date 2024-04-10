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
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 300001; //check the limits, dummy

struct Segtree {
    ll SZ = 262144;
    ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github
    bool takeMod = false;


    ll combine(ll a, ll b) { if (takeMod && a+b >= MOD) return (a+b)-MOD;
        return a+b; }

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
	
    Segtree wt, pt, t1, t2;
    pt.takeMod = true, t1.takeMod = true, t2.takeMod = true;
    F0R(i, 262144*2) {
        wt.seg[i] = 0; pt.seg[i] = 0; t1.seg[i] = 0; t2.seg[i] = 0;
    }

    int N, Q; cin >> N >> Q;
//    int N = 200000, Q = 200000;
    ll pos[N], wei[N];
    F0R(i, N) cin >> pos[i];
    F0R(i, N) cin >> wei[i];
/*    F0R(i, N) {
        pos[i] = i+1;
        wei[i] = 1000000000;
    }*/
    F0R(i, N) {
        wt.update(i, wei[i]);
        pt.update(i, (wei[i]*pos[i])%MOD);
        t1.update(i, (wei[i]*i)%MOD);
        t2.update(i, (wei[i]*(N-i-1))%MOD);
    }

    while(Q--) {
        int X; cin >> X;
//        int X = Q;
        if (X < 0) {
            X *= -1;
            ll Y; cin >> Y; X--;
            wei[X] = Y; 
            wt.update(X, Y);
            pt.update(X, (Y*pos[X])%MOD);
            t1.update(X, (Y*X)%MOD);
            t2.update(X, (Y*(N-1-X))%MOD);
        } else {
            int Y; cin >> Y; X--; Y--;
//            int Y = N-1;
            int lo = X, hi = Y; // first with at least half of the weight
            ll total = wt.query(X, Y);

            while (lo < hi) {
                int mid = (lo+hi)/2;
                ll cur = wt.query(X, mid);
                if (cur * 2 >= total) {
                    hi = mid;
                } else {
                    lo = mid+1;
                }
            }
            ll curpos = pos[lo];

            ll ans = (wt.query(X, lo)%MOD) * curpos; ans %= MOD;
            ans += MOD - pt.query(X, lo); ans %= MOD;

            ans += MOD - (((wt.query(lo+1, Y)%MOD)*(curpos+1)) % MOD); ans %= MOD;
            ans += pt.query(lo+1, Y); ans %= MOD;

            ans += MOD - t2.query(X, lo) + (wt.query(X, lo)%MOD) * (N-lo-1); ans %= MOD;
            ans += MOD - t1.query(lo+1, Y) + (((wt.query(lo+1, Y)%MOD) * (lo+1))%MOD); ans %= MOD;

            cout << ans << '\n';
        }
    }


	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343