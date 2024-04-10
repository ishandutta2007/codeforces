#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

const int N = 200200;

int n;

vector<int> tree[N];
vector<int> sz_tree;

void get_sz(int v) {
    sz_tree[v] = 0;
    if (tree[v].size() == 0) {
        sz_tree[v] = 1;
    }
    for (auto i : tree[v]) {
        get_sz(i);
        sz_tree[v] += sz_tree[i];
    }
}

int dfs_max(int v, bool ok) {
    if (tree[v].size() == 0) {
        return 1;
    }
    if (ok) {
        int mx = -INF;
        for (auto i : tree[v]) {
            mx = max(mx, sz_tree[v] - (sz_tree[i] - dfs_max(i, false)));
        }
//        cout << v << ' ' << mx << endl;
        return mx;
    } else {
        int sum = 0;
        for (auto i : tree[v]) {
            sum += dfs_max(i, true) - 1;
        }
//        cout << v << ' ' << sum + 1 << endl;
        return sum + 1;
    }
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    sz_tree.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        tree[u].pb(v);
    }
    get_sz(1);

//    cout << sz_tree[1] << endl;

    cout << dfs_max(1, true) << ' ' << sz_tree[1] + 1 - dfs_max(1, false) << endl;
    return 0;
}