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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;
    int happy[512];
    vpi pizzas[512];

    F0R(i, 512) {
        happy[i] = 0;
    }

    F0R(i, N) {
        int type = 0;
        int F; cin >> F;
        F0R(i, F) {
            int cur; cin >> cur; cur--; type += (1 << cur);
        }
        F0R(j, 512) {
            if ((j & type) == type) {
                happy[j]++;
            }
        }
    }

    F0R(i, M) {
        int cost; cin >> cost;
        int type = 0;
        int F; cin >> F;
        F0R(i, F) {
            int cur; cin >> cur; cur--; type += (1 << cur);
        }
        pizzas[type].pb(mp(cost, i+1));

    }

    int maxFriends = 0;
    int minCost = 2000000001;
    int index[2]; index[0] = 1; index[1] = 2;
    F0R(i, 512) {
        sort(all(pizzas[i]));
        if (sz(pizzas[i]) >= 2 && happy[i] >= maxFriends) {
            if (happy[i] > maxFriends || pizzas[i][0].f + pizzas[i][1].f < minCost) {
                index[0] = pizzas[i][0].s; index[1] = pizzas[i][1].s;
                maxFriends = happy[i];
                minCost = pizzas[i][0].f + pizzas[i][1].f;
            }
        }
    }

    F0R(i, 512) {
        FOR(j, i+1, 512) {
            if (sz(pizzas[i]) < 1 || sz(pizzas[j]) < 1) continue;
            int pleased = happy[i|j];
            if (pleased > maxFriends || (pleased == maxFriends && pizzas[i][0].f + pizzas[j][0].f < minCost)) {
                maxFriends = pleased;
                index[0] = pizzas[i][0].s; index[1] = pizzas[j][0].s;
                minCost = pizzas[i][0].f + pizzas[j][0].f;
            }
        }
    }

    cout << index[0] << " " << index[1] << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343