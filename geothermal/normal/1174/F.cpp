// read the question correctly (ll vs int)
// template by bqi343

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
const int MX = 200001;
vector<vi> graph;
int anc[MX], depth[MX], subSize[MX], goalDepth;

void precompDFS(int V) {
    int size = 1;
    F0R(i, sz(graph[V])) {
        if (graph[V][i] == anc[V]) continue;
        int nxt = graph[V][i];
        anc[nxt] = V;
        depth[nxt] = depth[V] + 1;
        precompDFS(nxt);
        size += subSize[nxt];
    }
    subSize[V] = size;
}

int nextDFS(int cur) {
    F0R(i, sz(graph[cur])) {
        if (graph[cur][i] == anc[cur]) continue;
        int nxt = graph[cur][i];
        int size = subSize[nxt];
        if (size > (subSize[cur] - 1) / 2) {
            return nextDFS(nxt);
        }
    }
    cout << "d " << (cur+1) << endl;
    int ans; cin >> ans;
    if (ans == -1) return 0;
    while (ans != abs(goalDepth - depth[cur])) {
        cur = anc[cur];
        ans--;
    }
    return cur;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    F0R(i, N) {
        vi blank; graph.pb(blank);
    }

    F0R(i, N-1) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].pb(B);
        graph[B].pb(A);
    }

    anc[0] = -1; depth[0] = 0;
    precompDFS(0);
    cout << "d 1" << endl;
    cin >> goalDepth;
    int cur = 0;
    set<int> disabled;
    while (depth[cur] < goalDepth) {
        bool found = false;
        F0R(i, sz(graph[cur])) {
            if (graph[cur][i] == anc[cur]) continue;
            int nxt = graph[cur][i];
            if (disabled.count(nxt)) continue;
            int size = subSize[nxt];
            if (size > (subSize[cur] - 1) / 2) {
                int nextCur = nextDFS(nxt);
                if (nextCur == cur) {
                    disabled.insert(nxt);
                    subSize[cur] -= subSize[nxt];
                }
                cur = nextCur;
                found = true;
            }
        }
        if (!found) {
            cout << "s " << (cur+1) << endl;
            cin >> cur;
            if (cur == -1) {
                return 0;
            }
            cur--;
        }
    }

    while (depth[cur] > goalDepth) cur = anc[cur];

    cout << "! " << (cur+1) << endl;
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343