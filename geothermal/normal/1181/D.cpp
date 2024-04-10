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

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

ll SZ = 524288;
ll* seg = new ll[2*SZ]; //segtree implementation by bqi343's Github


ll combine(ll a, ll b) { return a+b; }

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

int binSearch(int val) { // get val'th active segtree element
    int lo = 0;
    int hi = SZ - 1;
    F0R(i, 23) {
        int mid = (lo+hi) / 2;
        int X = query(0, mid);
        if (X > val) {
            hi = mid - 1;
        } else if (X < val) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    return lo;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    F0R(i, 2*SZ) seg[i] = 0;

    int N, M, Q; cin >> N >> M >> Q;
    //N = 500000; M = 500000; Q = 500000;

    int counts[M]; F0R(i, M) counts[i] = 0;
    F0R(i, N) {
        int cur; cin >> cur; cur--; counts[cur]++;
        //counts[0]++;
    }

    vi* atCount = new vi[N+1];

    F0R(i, M) {
        atCount[counts[i]].pb(i);
    }

    int* ans = new int[Q];
    vpl queries;
    F0R(i, Q) {
        ll curQ; cin >> curQ;
        //int curQ = 500001 + i;
        queries.pb(mp(curQ, i));
    }
    sort(all(queries));

    int nxtQ = 0;
    ll curDay = N;
    ll incorp = 0;
    F0R(i, N+1) {
        incorp += sz(atCount[i]);
        F0R(j, sz(atCount[i])) {
            update(atCount[i][j], 1);
            //cout << query(0, 100) << endl;
        }
        while (nxtQ < Q && curDay + incorp >= queries[nxtQ].f) {
            int needed = (int) (queries[nxtQ].f - curDay);
            ans[queries[nxtQ].s] = binSearch(needed);
            nxtQ++;
        }
        curDay += incorp;
    }

    while (nxtQ < Q) {
        ll val = queries[nxtQ].f - curDay - 1;
        ans[queries[nxtQ].s] = (val % M);

        nxtQ++;
    }



    F0R(i, Q) {
        cout << ans[i] + 1 << endl;
    }



    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343