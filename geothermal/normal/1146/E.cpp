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
const int MX = 100010;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<pair<int, pi> > queries; //position, type

    int n, q; cin >> n >> q; int data[n];
    F0R(i, n) {
        cin >> data[i];
    }
    F0R(i, q) {
        int type;
        char c; int x; cin >> c >> x;
        if (c == '>') {
            if (x < 0) {
                type = 1;
            } else {
                type = 0;
            }
        } else {
            if (x < 0) {
                type = 3;
            } else {
                type = 2;
            }
        }
        queries.pb(mp(abs(x), mp(i, type)));
    }

    sort(all(queries));

    int force[MX];
    int lastF[MX];
    bool swap[MX];
    int curForce = 0;
    int lastForce = -1;
    int swaps = 0;
    int curQ = 0;
    F0R(i, MX) {
        vi types[4];
        while (curQ < q && queries[curQ].f == i) {
            types[queries[curQ].s.s].pb(queries[curQ].s.f);
            curQ++;
        }

        F0R(j, types[1].size()) {
            int cur = types[1][j];
            if (cur > lastForce) {
                lastForce = cur;
                curForce = -1;
            }
        }
        F0R(j, types[2].size()) {
            int cur = types[2][j];
            if (cur > lastForce) {
                lastForce = cur;
                curForce = 1;
            }
        }

        force[i] = curForce; lastF[i] = lastForce;

        F0R(j, types[0].size()) {
            int cur = types[0][j];
            if (cur > lastForce) {
                lastForce = cur;
                curForce = -1;
            }
        }
        F0R(j, types[3].size()) {
            int cur = types[3][j];
            if (cur > lastForce) {
                lastForce = cur;
                curForce = 1;
            }
        }
    }


    curQ = 0;


    set<int> unusedSwaps;
    reverse(all(queries));

    F0Rd(i, MX) {
        vi types[4];


        while (curQ < q && queries[curQ].f == i) {
            types[queries[curQ].s.s].pb(queries[curQ].s.f);
            curQ++;
        }


        if (i <= 5) {
            //cout << "Test" << endl;
        }

        auto it = unusedSwaps.end();
        if (!unusedSwaps.empty()) it--;
        while (!unusedSwaps.empty() && *it >= lastF[i]) {
            swaps++;
            unusedSwaps.erase(it);
            it = unusedSwaps.end(); if (!unusedSwaps.empty()) it--;
        }



        swap[i] = swaps % 2 == 1;

        if (i <= 5) {
            //cout << "Test" << endl;
        }


        F0R(j, sz(types[1])) {
            unusedSwaps.insert(types[1][j]);
        }

        F0R(j, sz(types[2])) {
            unusedSwaps.insert(types[2][j]);
        }


    }

    F0R(i, n) {
        int cur = data[i];

        if (force[abs(cur)] == -1) {
            cur = -1 * abs(cur);
        } else if (force[abs(cur)] == 1){
            cur = abs(cur);
        }

            if (swap[abs(cur)]) {
                cout << -1 * cur << " ";
            } else {
                cout << cur << " ";
            }

    }



    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343