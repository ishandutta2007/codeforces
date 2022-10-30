#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

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

int n, m;

vector<int> g[111111];
vector<int> edge[111111];
vector<int> d;
int cur[111111];
vector<int> ans;
bool used[1111111];

void dfs(int v) {
//    cout << v << endl;
    for (; cur[v] < sz(g[v]); ) {
        if (!used[edge[v][cur[v]]]) {
            used[edge[v][cur[v]]] = true;
            cur[v]++;
            dfs(g[v][cur[v] - 1]);
        } else {
            cur[v]++;
        }
    }
    ans.pb(v);
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].pb(y);
        g[y].pb(x);
        edge[x].pb(i);
        edge[y].pb(i);
    }
    for (int i = 1; i <= n; i++) {
        if (sz(g[i]) & 1) {
            d.pb(i);
        }
    }
    int last = m;
    for (int i = 0; i < sz(d); i += 2) {
        g[d[i]].pb(d[i + 1]);
        g[d[i + 1]].pb(d[i]);
        edge[d[i]].pb(last);
        edge[d[i + 1]].pb(last);
        last++;
        m++;
    }
    if (m & 1) {
        g[1].pb(1);
        g[1].pb(1);
        edge[1].pb(last);
        edge[1].pb(last);
        last++;
        m++;
    }
    dfs(1);
    printf("%d\n", ans.size() - 1);
    for (int i = 0; i < sz(ans) - 1; i++) {
        if (i & 1) {
            printf("%d %d\n", ans[i], ans[i + 1]);
        } else {
            printf("%d %d\n", ans[i + 1], ans[i]);
        }
    }
    return 0;
}