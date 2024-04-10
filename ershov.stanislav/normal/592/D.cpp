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

const int N = 5e5 + 100;

vector<int> tree[N];
int n, m;
bool good[N];
int deep[N], cnt[N];
int deepest[N];
int ans;
pair<int, int> mxdist;

void dfs1(int v, int par) {
    deep[v] = -1;
    if (good[v]) {
        deep[v] = 0;
        deepest[v] = v;
    }
    cnt[v]++;
    for (int i = 0; i < sz(tree[v]); i++) {
        if (tree[v][i] == par) {
            continue;
        }
        dfs1(tree[v][i], v);
        cnt[v] += cnt[tree[v][i]];
        if (deep[tree[v][i]] != -1) {
            int cur = deep[tree[v][i]] + 1;
            if (deep[v] < cur) {
                deep[v] = cur;
                deepest[v] = deepest[tree[v][i]];
            }
        }
    }
}

void dfs2(int v, int par, bool flag = false) {
    if (good[v]) {
        flag = true;
    }
    int c = 0;
    for (int i = 0; i < sz(tree[v]); i++) {
        if (tree[v][i] == par) {
            continue;
        }
        if (deep[tree[v][i]] != -1) {
            c++;
        }
    }
    if (!flag && c <= 1) {
        ans--;
    } else {
        flag = true;
    }
    for (int i = 0; i < sz(tree[v]); i++) {
        if (tree[v][i] == par) {
            continue;
        }
        if (deep[tree[v][i]] != -1) {
            dfs2(tree[v][i], v, flag);
        } else {
            ans -= cnt[tree[v][i]];
        }
    }
}

void dfs3(int v, int par, int curmx = -1) {
    pair<int, int> mx1 = mp(-1, 0), mx2 = mp(-1, 0);
    for (int i = 0; i < sz(tree[v]); i++) {
        if (tree[v][i] == par) {
            continue;
        }
        if (deep[tree[v][i]] != -1) {
            pair<int, int> cur = mp(deep[tree[v][i]] + 1, tree[v][i]);
            mx1 = max(mx1, cur);
            if (mx1 > mx2) {
                swap(mx1, mx2);
            }
        }
    }
    if (good[v]) {
        curmx = max(curmx, 0);
    }
    if (good[v] && mp(max(curmx, deep[v]), -v) > mxdist) {
        mxdist = mp(max(curmx, deep[v]), -v);
    }
    for (int i = 0; i < sz(tree[v]); i++) {
        if (tree[v][i] == par) {
            continue;
        } else {
            int cur = max(curmx, mx2.fs);
            if (mx2.sc == tree[v][i]) {
                cur = max(curmx, mx1.fs);
            }
            if (cur > -1) {
                cur++;
            }
            dfs3(tree[v][i], v, cur);
        }
    }
}

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    mxdist.sc = -INF;
    for (int i = 0; i < m; i++) {
        int v;
        scanf("%d", &v);
        good[v] = true;
        mxdist.sc = max(mxdist.sc, -v);
    }
    dfs1(1, -1);
    ans = n;
    dfs2(1, -1);
    ans--;
    ans *= 2;
    if (m > 1) {
        mxdist = mp(0, 0);
        dfs3(1, -1);
        ans -= mxdist.fs;
    }
    cout << -mxdist.sc << endl << ans << endl;
    return 0;
}