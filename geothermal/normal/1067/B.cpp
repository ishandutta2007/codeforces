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
vector<vi > graph;
int n, k;
int center;

bool dfs(int v, int p, int d) {
    int size = graph.at(v).size();
    if (p != -1) size--;
    if (d == k) {
        if (size != 0) return false;
    } else {
        if (size < 3) return false;
        F0R(i, graph.at(v).size()) {
            int cur = graph.at(v).at(i);
            if (cur != p) {
                if (!dfs(cur, v, d+1)) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    F0R(i, n) {
        vi blank; graph.pb(blank);
    }
    F0R(i, n-1) {
        int a, b; cin >> a >> b; a--; b--;
        graph.at(a).pb(b);
        graph.at(b).pb(a);
    }

    bool seen[n], visited[n];
    queue<int> list;
    int value[n];
    F0R(i, n) {
        seen[i] = false; visited[i] = false;
        value[i] = 1;
        if (graph.at(i).size() == 1) {
            seen[i] = true;
            list.push(i);
        }
    }

    while (!list.empty()) {
        int cur = list.front();
        visited[cur] = true;
        list.pop();
        F0R(i, graph.at(cur).size()) {
            int next = graph.at(cur).at(i);
            if (!visited[next]) {
                value[next] += value[cur];
                if (!seen[next]) {
                    seen[next] = true;
                    list.push(next);
                }
            }
        }
    }

    F0R(i, n) {
        if (value[i] == n) center = i;
    }

    bool result = dfs(center, -1, 0);
    if (result) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

// read the question correctly (ll vs int)
// template by bqi343