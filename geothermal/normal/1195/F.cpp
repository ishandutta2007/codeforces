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

ll SZ = 131072;
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
    vector<vi> data;
    map<pi, int> comp;
    int nxtComp = 0;
    F0R(i, N) {
        int K; cin >> K;
        //cout << K << endl;
        ll X[K+1], Y[K+1];
        F0R(j, K) {
            cin >> X[j] >> Y[j];
        }
        X[K] = X[0]; Y[K] = Y[0];
        vi blank; data.pb(blank);
        FOR(j, 1, K+1) {
            ll dx = X[j] - X[j-1];
            ll dy = Y[j] - Y[j-1];
            if (dy == 0) {
                if (dx > 0) {
                    dx = 1;
                } else dx = -1;
            }  else {
                ll gcd = __gcd(abs(dx), abs(dy));
                dx = dx / gcd;
                dy = dy / gcd;
                if (dy < 0) {
                    //dx = dx * -1; dy = dy * -1;
                }
            }

            if (!comp.count(mp(dx, dy))) {
                comp.insert(mp(mp(dx, dy), nxtComp));
                nxtComp++;
            }
            //cout << i << " " << j << " " << dx << " " << dy << " " << comp[mp(dx, dy)] << endl;

            data[i].pb(comp[mp(dx, dy)]);
        }
    }

    int Q; cin >> Q;
    vector<pair<int, pi> > queries;
    F0R(i, Q) {
        int A, B; cin >> A >> B; A--; B--;
        queries.pb(mp(B, mp(A, i)));
    }

    int ans[Q];

    sort(all(queries));
    int nxt = 0;
    int last[nxtComp]; F0R(i, nxtComp) last[i] = -1;
    F0R(i, 2*SZ) seg[i] = 0;
    F0R(q, Q) {
        while (nxt < N && nxt <= queries[q].f) {
            F0R(i, sz(data[nxt])) {
                int cur = data[nxt][i];
                //cout << "Update " << cur << " " << last[cur] << endl;
                if (last[cur] != -1) update(last[cur], -1);
                last[cur] = nxt; update(nxt, 1);
            }
            nxt++;
        }

        F0R(i, N) {
            //cout << i << " " << query(i, i) << endl;
        }

        ans[queries[q].s.s] = query(queries[q].s.f, queries[q].f);
    }


    F0R(i, Q) {
        cout << ans[i] << endl;
    }
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343