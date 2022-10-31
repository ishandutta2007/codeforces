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
#define rank _rank

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

const int MOD = 1e9 + 7;

const int N = 1e5 + 100;

int n, k;
int t, t_in[N], t_out[N];
vector<int> tree[N];
vector<int> to[N];
int par[20][N];
int up[N], down[N];
int pw2[3000000];

void dfs1(int v, int p) {
    par[0][v] = p;
    t_in[v] = t++;
    for (auto i : tree[v]) {
        if (i != p) {
            dfs1(i, v);
        }
    }
    t_out[v] = t;
}

bool is_anc(int a, int b) {
    return t_in[a] <= t_in[b] && t_out[a] >= t_out[b];
}

int get_lca(int a, int b) {
    for (int i = 19; i >= 0; i--) {
        if (!is_anc(par[i][a], b)) {
            a = par[i][a];
        }
    }
    if (!is_anc(a, b)) {
        a = par[0][a];
    }
    return a;
}

int ans = 0;

pair<int, int> dfs2(int v, int p) {
    pair<int, int> res = mp(0, 0);
    for (int ii = 0; ii < (int) tree[v].size(); ii++) {
        int i = tree[v][ii];
        if (i != p) {
            pair<int, int> add = dfs2(i, v);
            res.fs += add.fs;
            res.sc += add.sc;
            if (to[v][ii] == 1) {
                ans = (ans + pw2[add.fs] - 1) % MOD;
            }
            if (to[v][ii] == -1) {
                ans = (ans + pw2[add.sc] - 1) % MOD;
            }
        }
    }
    res.fs += up[v];
    res.sc += down[v];
    return res;
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    pw2[0] = 1;
    for (int i = 1; i < 3e6; i++) {
        pw2[i] = pw2[i - 1] * 2 % MOD;
    }
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int x;
        scanf("%d", &x);
        tree[a].pb(b);
        tree[b].pb(a);
        to[a].pb(x);
        to[b].pb(-x);
    }
    dfs1(1, 1);
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
    scanf("%d", &k);
    int pre = 1;
    for (int i = 0; i < k; i++) {
        int now;
        scanf("%d", &now);
        int lca = get_lca(pre, now);
        up[pre]++;
        up[lca]--;
        down[lca]--;
        down[now]++;
        pre = now;
    }
    dfs2(1, 1);
    cout << ans << endl;
    return 0;
}