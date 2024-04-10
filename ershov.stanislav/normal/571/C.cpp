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

const int INF = 2e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-10;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 2e5 + 100;

int n, m;
vector<int> graph[N];
vector<int> edge[N];
vector<int> in[N];
bool var[N];
bool used[N];
bool used2[N];
vector<int> edges[N];
vector<int> q;
vector<int> was;

int sgn(int v) {
    if (v > 0) {
        return 1;
    } else if (v == 0) {
        return 0;
    } else {
        return -1;
    }
}

bool dfs(int v, int par_edge) {
    used[v] = true;
    was.pb(v);
    for (int i = 0; i < (int) graph[v].size(); i++) {
        if (edge[v][i] != par_edge) {
            if (used[graph[v][i]]) {
                var[edge[v][i]] = (in[v][i] == 1);
                q.pb(v);
                return true;
            } else {
                if (dfs(graph[v][i], edge[v][i])) {
                    var[edge[v][i]] = (in[v][i] == 1);
                    q.pb(v);
                    return true;
                }
            }
        }
    }
    return false;
}

void dfs2(int v) {
    used[v] = true;
    for (int i = 0; i < (int) graph[v].size(); i++) {
        if (!used[graph[v][i]]) {
            var[edge[v][i]] = (in[v][i] == 0);
            dfs2(graph[v][i]);
        }
    }
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);
            edges[abs(v)].pb(i * sgn(v));
        }
    }
    for (int i = 1; i <= m; i++) {
        if ((int) edges[i].size() == 1) {
            if (edges[i][0] > 0) {
                var[i] = true;
            } else {
                var[i] = false;
            }
            used[abs(edges[i][0])] = true;
        }
        if ((int) edges[i].size() == 2) {
            if (sgn(edges[i][0]) == sgn(edges[i][1])) {
                var[i] = (sgn(edges[i][0]) == 1);
                used[abs(edges[i][0])] = used[abs(edges[i][1])] = true;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if ((int) edges[i].size() == 2 && sgn(edges[i][0]) != sgn(edges[i][1])) {
            int a = edges[i][0];
            int b = edges[i][1];
            if (a > b) {
                swap(a, b);
            }
            a = -a;
            graph[a].pb(b);
            edge[a].pb(i);
            in[a].pb(0);
            graph[b].pb(a);
            edge[b].pb(i);
            in[b].pb(1);
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            q.clear();
            was.clear();
            if (!dfs(i, -1)) {
                flag = false;
                break;
            } else {
                for (auto i : was) {
                    used[i] = false;
                }
                for (auto i : q) {
                    used[i] = true;
                }
                for (auto i : q) {
                    dfs2(i);
                }
            }
        }
    }
    if (!flag) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 1; i <= m; i++) {
            printf("%d", (int) var[i]);
        }
    }
    return 0;
}