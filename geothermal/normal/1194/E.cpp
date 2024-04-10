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
const int MX = 100001; //check the limits, dummy

ll SZ = 16384;
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

    int N; cin >> N;
    F0R(i, 2*SZ) seg[i] = 0;

    ll ans = 0;
    vector<pair<int, pi> > dataX; //X, min Y, max Y
    vector<pair<int, pi> > dataY; //max X, Y, min X
    F0R(i, N) {
        int A, B, C, D; cin >> A >> B >> C >> D;
        A += 5000; B += 5000; C += 5000; D += 5000;
        if (A == C) {
            dataX.pb(mp(A, mp(min(B, D), max(B, D))));
        } else {
            dataY.pb(mp(max(A, C), mp(B, min(A, C))));
        }
    }
    sort(all(dataX));
    sort(all(dataY));

    F0R(i, sz(dataX)-1) {
        vector<pi> curYs;
        F0R(j, sz(dataY)) {
            if (dataY[j].s.s <= dataX[i].f) {
                update(dataY[j].s.f, 1);
                curYs.push_back(mp(dataY[j].f, dataY[j].s.f));
            }
        }

            int nxtRem = 0;
            FOR(j, i+1, sz(dataX)) {
                while (nxtRem < sz(curYs) && curYs[nxtRem].f < dataX[j].f) {
                    update(curYs[nxtRem].s, -1);
                    nxtRem++;
                }
                int lo1 = dataX[i].s.f;
                int hi1 = dataX[i].s.s;
                int lo2 = dataX[j].s.f;
                int hi2 = dataX[j].s.s;
                if (hi1 < lo2 || hi2 < lo1) {
                    continue;
                }
                int lo = max(lo1, lo2);
                int hi = min(hi1, hi2);
                ll count = query(lo, hi);
                //cout << i << " " << j << " " << count << endl;
                ans += count * (count - 1) / 2;
            }

            FOR(k, nxtRem, sz(curYs)) {
                update(curYs[k].s, -1);
            }
        }

    cout << ans << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343