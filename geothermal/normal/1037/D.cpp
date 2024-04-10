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

    int N; cin >> N;
    vector<vi> graph(N);

    F0R(i, N-1) {
        int X, Y; cin >> X >> Y;
        X--; Y--;
        graph[X].pb(Y);
        graph[Y].pb(X);
    }

    queue<set<int> > q;
    vi data(N); F0R(i, N) cin >> data[i];
    F0R(i, N) data[i]--;

    set<int> first; first.insert(0); q.push(first);
    bool found[N]; F0R(i, N) found[i] = false;
    found[0] = true;

    F0R(i, N) {
        while (q.front().empty()) {
            q.pop();
        }
        if (!q.front().count(data[i])) {
            cout << "No" << endl; return 0;
        }

        q.front().erase(data[i]);
        set<int> cur;
        F0R(j, sz(graph[data[i]])) {
            int nxt = graph[data[i]][j];
            if (!found[nxt]) {
                found[nxt] = true;
                cur.insert(nxt);
            }
        }
        q.push(cur);
    }

    cout << "Yes" << endl;

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343
// license: https://github.com/bqi343/USACO/blob/master/LICENSE