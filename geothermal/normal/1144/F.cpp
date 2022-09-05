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
const int MX = 100001;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);


    int N, M; cin >> N >> M;
    vector<vi > graph(N);
    vpi edges;
    F0R(i, M) {
        int a, b; cin >> a >> b; a--; b--;
        graph[a].pb(b); graph[b].pb(a);
        edges.pb(mp(a, b));
    }

    int color[N];
    F0R(i, N) color[i] = -1;
    color[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i : graph[cur]) {
            if (color[i] == -1) {
                color[i] = 1 - color[cur];
                q.push(i);
            }
            if (color[i] == color[cur]) {
                cout << "NO" << endl; return 0;
            }
        }
    }

    cout << "YES" << endl;
    F0R(i, M) {
        if (color[edges.at(i).f] == 0) {
            cout << 0;
        } else cout << 1;
    }

    cout << endl;


    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343