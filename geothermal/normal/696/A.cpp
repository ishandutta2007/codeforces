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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    map<ll, ll> cost;
    ll level[61];
    level[0] = 1;
    FOR(i, 1, 61) {
        level[i] = level[i-1] + (1LL << i);
    }
    F0R(i, 61) {
        //cout << level[i] << endl;
    }
    int Q; cin >> Q;
    F0R(testCase, Q) {
        int T; cin >> T;
        ll U, V; cin >> U >> V;
        vl positions;
        if (V > U) { //now U is higher
            ll K = U;
            U = V;
            V = K;
        }

        int levU, levV;
        F0Rd(i, 61) {
            if (U <= level[i]) levU = i;
            if (V <= level[i]) levV = i;
        }

        //cout << levV << " " << levU << endl;

        FOR(i, levV, levU) {
            positions.pb(U);
            U /= 2;
        }
        while (U != V) {
            positions.pb(U);
            positions.pb(V);
            U /= 2; V /= 2;
        }

        if (T == 1) {
            ll cur; cin >> cur;
            F0R(i, sz(positions)) {
                ll curPos = positions[i];
                if (!cost.count(curPos)) cost.insert(mp(curPos, 0));
                cost[curPos] += cur;
            }
        } else {
            ll total = 0;
            F0R(i, sz(positions)) {
                //cout << positions[i] << " ";
                if (cost.count(positions[i])) {
                    total += cost[positions[i]];
                    //cout << cost[positions[i]] << endl;
                }
            }
            //cout << endl;
            cout << total << endl;
        }
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343