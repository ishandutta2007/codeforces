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

bool active[MX];
bool visited[MX];
vector<vi> graph(MX);

bool cycleDFS(int v, int p) {
    active[v] = true;
    visited[v] = true;
    F0R(i, sz(graph[v])) {
        int nxt = graph[v][i];
        if (active[nxt]) return true;
        if (visited[nxt]) continue;
        if (cycleDFS(nxt, v)) return true;
    }
    active[v] = false;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;


    F0R(i, N) {
        int cur; cin >> cur;
        set<int> already;
        F0R(j, cur) {
            int X; cin >> X; X--;
            if (!already.count(X)) {
                graph[i].pb(X);
                already.insert(X);
            }
        }
    }
    F0R(i, MX) {
        active[i] = false;
        visited[i] = false;
    }

    bool reach[2*N];
    int last[2*N];
    int S; cin >> S; S--;
    F0R(i, 2*N) reach[i] = false;
    reach[S] = true;
    last[S] = -1;

    queue<int> q;
    q.push(S);
    bool foundCycle = false, foundOddEnd = false;
    int oddEndState;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        bool odd = false; if (cur >= N) { cur -= N; odd = true; }

        F0R(i, sz(graph[cur])) {
            int nxt = graph[cur][i];
            if (!odd) nxt += N;
            if (!reach[nxt]) {
                q.push(nxt);
                reach[nxt] = true;
                last[nxt] = cur; if (odd) last[nxt] += N;
            } else {
                foundCycle = true;
            }
        }
        if (sz(graph[cur]) == 0 && odd) {
            foundOddEnd = true;
            oddEndState = cur+N;
        }
    }

    foundCycle= cycleDFS(S, -1);

    if (foundOddEnd) {
        cout << "Win" << endl;
        vi path;
        path.pb(oddEndState);
        while (last[path[sz(path)-1]] != -1) {
            path.pb(last[path[sz(path)-1]]);
        }
        reverse(all(path));
        assert(sz(path) < 1000000);
        assert(sz(path) % 2 == 0);
        assert(path[0] == S);
        F0R(i, sz(path)) {
            if (path[i] >= N) path[i] -= N;
            cout << path[i]+1 << " ";
        }
        cout << endl;

    } else if (foundCycle) {
        cout << "Draw" << endl;
    } else {
        cout << "Lose" << endl;
    }

    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343