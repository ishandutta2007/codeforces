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




int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M, K; cin >> N >> M >> K; int Q; cin >> Q;
    map<ll, pl> initPos; //maxPos, minPos.

    F0R(i, K) {
        ll X, Y; cin >> Y >> X; X--; Y--;
        if (!initPos.count(Y)) {
            initPos.insert(mp(Y, mp(M+1, -1)));
        }
        initPos[Y].f = min(initPos[Y].f, X); initPos[Y].s = max(initPos[Y].s, X);

    }

    set<ll> safe;

    F0R(i, Q) {
        ll cur; cin >> cur; cur--; safe.insert(cur);
    }


    ll cost[2];
    ll pos[2];
    cost[0] = 0; cost[1] = 0; pos[0] = 0; pos[1] = 0;
    if (initPos.begin()->f == 0) {
        auto it = initPos.begin();
        cost[0] = it->s.s + it->s.s - it->s.f;
        pos[0] = it->s.f;
        cost[1] = it->s.s;
        pos[1] = it->s.s;
        initPos.erase(it);
    }
    ll lastY = 0;
    for (auto it = initPos.begin(); it != initPos.end(); it++) {
        ll Y = it->f;
        ll curCost[4], curPos[4];
            F0R(i, 4) {
                ll P = pos[i%2];

                ll col;
                if (i > 1) {
                    auto it2 = safe.lower_bound(P);
                    if (it2 == safe.end()) {
                        curCost[i] = 1000000000000000;
                        curPos[i] = 0;
                        continue;
                    }
                    col = *it2;
                } else {
                    auto it2 = safe.lower_bound(P);
                    if (it2 == safe.begin()) {
                        curCost[i] = 1000000000000000;
                        curPos[i] = 0;
                        continue;
                    }
                    it2--;
                    col = *it2;
                }
                curPos[i] = col;
                curCost[i] = cost[i%2] + abs(col-P) + Y-lastY;
            }


        lastY = Y;

        F0R(i, 2) {
            cost[i] = 1000000000000000;
        }
        pos[0] = it->s.f; pos[1] = it->s.s;
        F0R(i, 4) {
            //cout << curCost[i] << " " << curPos[i] << endl;
            ll nxtCost = curCost[i] + abs(curPos[i] - it->s.f) + abs(it->s.f - it->s.s);
            cost[1] = min(cost[1], nxtCost);
            nxtCost = curCost[i] + abs(curPos[i] - it->s.s) + abs(it->s.f - it->s.s);
            cost[0] = min(cost[0], nxtCost);
        }

        //cout << cost[0] << " " << cost[1] << " " << pos[0] << " " << pos[1] << endl;
    }

    cout << min(cost[0], cost[1]) << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE