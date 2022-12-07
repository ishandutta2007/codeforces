#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
vector<int> g[200005];
int c[200005], sz[200005];
bool has[200005] = {};

void dfs(int v, int par) {
    sz[v] = has[v];
    for (int to : g[v]) if (to != par) {
        dfs(to, v);
        sz[v] += sz[to];
    }
}

vector<int> all[200005];
int cnt[200005] = {};
int cur = 0;

struct Cmp {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (cnt[lhs] != cnt[rhs]) return cnt[lhs] > cnt[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> se;

void dfs2(int v, int par) {
    if (has[v]) {
        all[cur].pb(v);
        ++cnt[cur];
    }
    for (int to : g[v]) if (to != par) {
        dfs2(to, v);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    k *= 2;
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to);
        --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    forn(i, k) {
        scanf("%d", c + i);
        --c[i];
        has[c[i]] = true;
    }
    dfs(0, -1);
    int szv = sz[0];
    int v = 0;
    int par = -1;
    while (true) {
        bool done = true;
        for (int to : g[v]) if (to != par && sz[to] * 2 > szv) {
            par = v;
            v = to;
            done = false;
            break;
        }
        if (done) {
            break;
        }
    }
    cout << 1 << endl;
    cout << v + 1 << endl;
    for (int to : g[v]) {
        dfs2(to, v);
        if (to == par && has[v]) {
            all[cur].pb(v);
            ++cnt[cur];
        }
        if (cnt[cur] != 0) {
            ++cur;
        }
    }
    if (par == -1 && has[v]) {
        all[cur].pb(v);
        ++cnt[cur];
        ++cur;
    }
    forn(i, cur) {
        se.insert(i);
    }
    while (!se.empty()) {
        assert(int(se.size()) >= 2);
        int a = *se.begin();
        se.erase(se.begin());
        int b = *se.begin();
        se.erase(se.begin());
        printf("%d %d %d\n", all[a].back() + 1, all[b].back() + 1, v + 1);
        all[a].pop_back();
        all[b].pop_back();
        --cnt[a];
        --cnt[b];
        if (cnt[a]) {
            se.insert(a);
        }
        if (cnt[b]) {
            se.insert(b);
        }
    }
    return 0;
}