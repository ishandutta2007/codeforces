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

    int T; cin >> T;
    F0R(testCase, T) {
        int N, M; cin >> N >> M;
        vector<vi> graph(N);
        F0R(i, M) {
            int A, B; cin >> A >> B; A--; B--;
            graph[A].pb(B); graph[B].pb(A);
        }

        vi evenDepth, oddDepth;
        int depth[N]; F0R(i, N) depth[i] = -1;
        depth[0] = 0;
        queue<int> q; q.push(0);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (depth[cur] % 2 == 0) {
                evenDepth.pb(cur);
            } else {
                oddDepth.pb(cur);
            }
            F0R(i, sz(graph[cur])) {
                int nxt = graph[cur][i];
                if (depth[nxt] == -1) {
                    depth[nxt] = depth[cur] + 1;
                    q.push(nxt);
                }
            }
        }

        if (evenDepth.size() < oddDepth.size()) {
            cout << evenDepth.size() << endl;
            F0R(i, sz(evenDepth)) {
                cout << evenDepth[i] + 1 << " ";
            }
            cout << endl;
        } else {
            cout << oddDepth.size() << endl;
            F0R(i, sz(oddDepth)) {
                cout << oddDepth[i] + 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343