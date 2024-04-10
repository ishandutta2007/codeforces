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

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 2e5 + 100;

int n, m, q, dp[N], t_in[N], cur_t = 1, bridge[N];
vector<int> graph[N], tree[N];
vector<int> edge_num[N];
vector<pair<int, int> > tree_edges;
int color[N], cur_c = 0;
int tree_in[N], tree_out[N];
int up[20][N];
int up_to[N], down_to[N];
bool used[N];
bool bad = false;

void dfs1(int v, int par_edge_num, int par) {
    dp[v] = t_in[v] = cur_t++;
    for (int i = 0; i < (int) graph[v].size(); i++) {
        if (!t_in[graph[v][i]]) {
            dfs1(graph[v][i], edge_num[v][i], v);
            dp[v] = min(dp[v], dp[graph[v][i]]);
        } else if (edge_num[v][i] != par_edge_num) {
            dp[v] = min(dp[v], t_in[graph[v][i]]);
        }
    }
    if (par_edge_num != -1 && dp[v] == t_in[v]) {
        tree_edges.eb(par, v);
        bridge[par_edge_num] = 1;
    }
}

void dfs2(int v, int par_edge_num) {
    color[v] = cur_c;
    for (int i = 0; i < (int) graph[v].size(); i++) {
        if (!bridge[edge_num[v][i]]) {
            if (!color[graph[v][i]]) {
                dfs2(graph[v][i], edge_num[v][i]);
            }
        }
    }
}

void dfs3(int v) {
    tree_in[v] = cur_t++;
    for (auto i : tree[v]) {
        if (!tree_in[i]) {
            up[0][i] = v;
            dfs3(i);
        }
    }
    tree_out[v] = cur_t;
}

inline bool is_upper(int a, int b) {
    return tree_in[a] <= tree_in[b] && tree_out[a] >= tree_out[b];
}

int lcp(int a, int b) {
    for (int i = 19; i >= 0; i--) {
        if (!is_upper(up[i][a], b)) {
            a = up[i][a];
        }
    }
    if (!is_upper(a, b)) {
        a = up[0][a];
    }
    return a;
}

pair<int, int> dfs4(int v) {
    pair<int, int> ans(up_to[v], down_to[v]);
    used[v] = true;
    for (auto i : tree[v]) {
        if (!used[i]) {
            pair<int, int> cur_ans = dfs4(i);
            ans.fs = min(ans.fs, cur_ans.fs);
            ans.sc = min(ans.sc, cur_ans.sc);
        }
    }
    if (ans.fs < tree_in[v] && ans.sc < tree_in[v]) {
        bad = true;
    }
    return ans;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].pb(v);
        graph[v].pb(u);
        edge_num[u].pb(i);
        edge_num[v].pb(i);
    }
    for (int i = 1; i <= n; i++) {
        if (!t_in[i]) {
            dfs1(i, -1, -1);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            cur_c++;
            dfs2(i, -1);
        }
    }
//    for (int i = 1; i <= n; i++) {
//        cout << color[i] << ' ';
//    }
//    cout << endl;
//    for (auto i : tree_edges) {
//        cout << i.fs << ' ' << i.sc << endl;
//    }
    for (auto i : tree_edges) {
        tree[color[i.fs]].pb(color[i.sc]);
        tree[color[i.sc]].pb(color[i.fs]);
    }
    cur_t = 1;
    tree_in[0] = cur_t;
    for (int i = 1; i <= cur_c; i++) {
        if (!tree_in[i]) {
            dfs3(i);
        }
    }
    tree_out[0] = cur_t;
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= cur_c; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
    for (int i = 1; i <= cur_c; i++) {
        up_to[i] = down_to[i] = INF;
    }
    for (int i = 0; i < q; i++) {
        int s, d;
        scanf("%d%d", &s, &d);
        int l = lcp(color[s], color[d]);
        if (l == 0) {
            bad = true;
            break;
        } else {
            up_to[color[s]] = min(up_to[color[s]], tree_in[l]);
            down_to[color[d]] = min(down_to[color[d]], tree_in[l]);
        }
    }
//    for (int i = 1; i <= cur_c; i++) {
//        cout << tree_in[i] << ' ' << up_to[i] << ' ' << down_to[i] << endl;
//    }
    for (int i = 1; i <= cur_c && !bad; i++) {
        if (!used[i]) {
            dfs4(i);
        }
    }
    if (bad) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    return 0;
}