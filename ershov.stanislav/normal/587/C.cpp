#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 1e5 + 100;

int n, m, q;
vector<int> tree[N];
int tin[N], tout[N], curt;
int par[19][N];
vector<int> cur;
vector<int> dp[19][N];

void dfs(int v, int curpar) {
    tin[v] = curt++;
    par[0][v] = curpar;
    for (int i = 0; i < sz(tree[v]); i++) {
        if (tree[v][i] != curpar) {
            dfs(tree[v][i], v);
        }
    }
    tout[v] = curt;
}

bool isanc(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

vector<int> join(const vector<int> & a, const vector<int> & b) {
    vector<int> ans;
    int i = 0, j = 0;
    for (; i < sz(a) && j < sz(b); ) {
        if (a[i] < b[j]) {
            ans.pb(a[i]);
            i++;
        } else {
            ans.pb(b[j]);
            j++;
        }
    }
    for (; i < sz(a); i++) {
        ans.pb(a[i]);
    }
    for (; j < sz(b); j++) {
        ans.pb(b[j]);
    }
    if (sz(ans) > 10) {
        ans.resize(10);
    }
    return ans;
}

int getlca(int a, int b) {
    for (int i = 18; i >= 0; i--) {
        if (!isanc(par[i][a], b)) {
            cur = join(cur, dp[i][a]);
            a = par[i][a];
        }
    }
    if (!isanc(a, b)) {
        cur = join(cur, dp[0][a]);
        a = par[0][a];
    }
    return a;
}

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        v--, u--;
        tree[v].pb(u);
        tree[u].pb(v);
    }
    dfs(0, 0);
    for (int i = 1; i < 19; i++) {
        for (int j = 0; j < n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
    for (int i = 1; i <= m; i++) {
        int c;
        scanf("%d", &c);
        dp[0][c - 1].pb(i);
    }
    for (int i = 0; i < n; i++) {
        sort(all(dp[0][i]));
        if (sz(dp[0][i]) > 10) {
            dp[0][i].resize(10);
        }
    }
    for (int i = 1; i < 19; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = join(dp[i - 1][j], dp[i - 1][par[i - 1][j]]);
        }
    }
    for (int i = 0; i < q; i++) {
        int v, u, a;
        scanf("%d%d%d", &v, &u, &a);
        u--, v--;
        cur.clear();
        getlca(v, u);
        int lca = getlca(u, v);
        cur = join(cur, dp[0][lca]);
        a = min(a, sz(cur));
        printf("%d", a);
        for (int i = 0; i < a; i++) {
            printf(" %d", cur[i]);
        }
        printf("\n");
    }
    return 0;
}