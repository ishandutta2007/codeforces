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
#define shandom_ruffle random_shuffle

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 1000001; //check the limits, dummy

struct SegTree{
    ll SZ = 1048576;
    ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github

    ll combine(ll a, ll b) { return max(a, b); }

    SegTree() {
        build();
    }

    void build() { F0Rd(i,2*SZ) seg[i] = -1; }

    void update(int p, ll value) {
        for (seg[p += SZ] = value; p > 1; p >>= 1)
            seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
    }

    ll query(int l, int r) {  // sum on interval [l, r]
        ll resL = -1, resR = -1; r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l&1) resL = combine(resL,seg[l++]);
            if (r&1) resR = combine(seg[--r],resR);
        }
        return combine(resL,resR);
    }
};

struct SegTree2{
    ll SZ = 1048576;
    ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github

    ll combine(ll a, ll b) { return min(a, b); }

    SegTree2() {
        build();
    }

    void build() { F0Rd(i,2*SZ) seg[i] = 1000000000; }

    void update(int p, ll value) {
        for (seg[p += SZ] = value; p > 1; p >>= 1)
            seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
    }

    ll query(int l, int r) {  // sum on interval [l, r]
        ll resL = 1000000000, resR = 1000000000; r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l&1) resL = combine(resL,seg[l++]);
            if (r&1) resR = combine(seg[--r],resR);
        }
        return combine(resL,resR);
    }
};

ll count(ll lo, ll hi, ll K) {
    if (lo > hi) swap(lo, hi);

    K--;
    lo++;
    ll ans = 0;

    //case one: 1 + XK <= lo

    //X <= lo / k
    ll cap = (lo-1) / K;

    //K+1, 2K+1, etc...
    ans += cap;
    cap = cap * (cap+1) / 2;
    cap %= MOD;
    cap *= K;
    cap %= MOD;
    ans += cap; ans %= MOD;

    //cout << ans << " after case 1" << endl;

    //case 2: lo < Xk+1 <= hi;
    cap = (lo-1) / K;
    cap++;
    ll hiCap = (hi - 1) / K;
    if (cap <= hiCap) {
        ll count = hiCap - cap + 1;
        ans += count * lo;
        //ans += count;
        ans %= MOD;
    }

    //cout << ans << " after case 2" << endl;

    //case 3: hi, lo < Xk + 1 <= (lo+hi)

    //hi / K <= X
    //max: 1
    //min: 1
    ll minVal = (max(hi, lo) + K - 1) / K;
    ll maxVal = (lo + hi - 1) / K;
    if (minVal <= 0) minVal = 1;
    //sum from minVal to maxVal of lo+hi-kX
    if (minVal > maxVal) return ans;

    ll count = maxVal - minVal + 1;
    //cout << "Count is "<<count << endl;
    ans += count * (lo + hi);
    ans %= MOD;

    ll subVal = ((minVal + maxVal) * count) / 2;
    subVal %= MOD;
    subVal *= K;
    subVal %= MOD;
    ans += MOD - subVal;
    ans %= MOD;
    return ans;
}

int N, K, data[MX];

ll solve() {
    SegTree2 hi = SegTree2();
    SegTree lo = SegTree();

    //map<pl, int> compress; //compress (val, pos) to position in sorted list
    int compress[N];
    vpl sorted;
    F0R(i, N) {
        sorted.pb({data[i], i});
    }
    sort(all(sorted));
    F0R(i, N) {
        //compress.insert(mp(sorted[i], i));
        compress[sorted[i].s] = i;
        hi.update(i, sorted[i].s); //position in sorted list to position in original list
    }


    ll ans = 0;

    F0R(i, N) {

        ll loVal, hiVal;
        loVal = i;
        hiVal = N-1-i;

        hi.update(compress[i], 100000000);
        //cout << lo.query(compress[mp(data[i], i)], N+1) << endl;
        loVal = min(loVal, i-lo.query(compress[i], N+1)-1);
        hiVal = min(hiVal, hi.query(compress[i], N+1)-1-i);
        //cout << loVal << " " << hiVal << endl;

        //ll X = (((loVal + 1) * (hiVal + 1) - 1) / (K - 1));
        //cout << loVal << " " << hiVal << endl;
        ll X = count(loVal, hiVal, K);
        //cout << X << " after case 3" << endl;
        X %= MOD; X *= data[i]; X %= MOD;
        ans += X;
        ans %= MOD;

        lo.update(compress[i], i);
    }

    return ans;
}

ll solveSlow() {
    vl cur;
    F0R(i, N) cur.pb(data[i]);

    ll ans = 0;
    while (sz(cur) >= K) {
        vl nxt;
        F0R(i, sz(cur)-K+1) {
            ll mx = cur[i];
            FOR(j, 1, K) {
                mx = max(mx, cur[i+j]);
            }
            ans += mx;
            ans %= MOD;
            nxt.pb(mx);
        }

        cur = nxt;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    F0R(i, N) cin >> data[i];

    cout << solve() << endl;

    /*mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    F0R(test, 1000) {
        uniform_int_distribution<> dist(2, 10);
        N = dist(rng);
        K = dist(rng);
        if (K > N) continue;
        F0R(i, N) data[i] = dist(rng);

        int X = solve(), Y = solveSlow();
        if (X == Y) {
            cout << "Test " << test << " passed" << endl;
        } else {
            cout << "Test " << test << " failed" << endl;
            cout << N << " " << K << endl;
            F0R(i, N) cout << data[i] << " ";
            cout << endl;
            cout << "Fast " << solve() << endl;
            cout << "Slow " << solveSlow() << endl;
            return 0;
        }
    }*/

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE