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

void solve() {
    int N, M; cin >> N >> M;
    vector<vpi> graph(3*N);
    F0R(i, M) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].pb(mp(B, i));
        graph[B].pb(mp(A, i));
    }

    int state[3*N]; F0R(i, 3*N) state[i] = 0;
    queue<pair<pi, int> > q;
    vi ans;
    F0R(i, N) {
        state[i] = 1;
        F0R(j, sz(graph[i])) {
            if (state[graph[i][j].f] == 1) {
                q.push(mp(mp(i, graph[i][j].f), graph[i][j].s));
            }
        }
    }

    int nextVal = N;
    while (!q.empty()) {
        pair<pi, int> cur = q.front(); q.pop();
        if (state[cur.f.f] != 1 || state[cur.f.s] != 1) continue;
        state[cur.f.f] = 2; state[cur.f.s] = 2;
        ans.pb(cur.s);
        FOR(i, nextVal, min(nextVal+2, 3*N)) {
            state[i] = 1;
            F0R(j, sz(graph[i])) {
                if (state[graph[i][j].f] == 1) {
                    q.push(mp(mp(i, graph[i][j].f), graph[i][j].s));
                }
            }
        }
        nextVal += 2;
    }

    if (sz(ans) >= N) {
        cout << "Matching" << endl;
        F0R(i, N) {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    } else {
        cout << "IndSet" << endl;
        int left = N;
        F0R(i, 3*N) {
            if (state[i] == 1) {
                cout << i+1 << " ";
                left--;
            }
            if (left == 0) {
                cout << endl;
                return;
            }
        }
        cout << " shouldn't get here" << endl;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    F0R(testCase, T) {
        solve();
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE