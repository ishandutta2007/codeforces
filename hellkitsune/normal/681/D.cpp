#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> g[100000];
int a[100000];
int indeg[100000] = {};
bool mark[100000];
int dep[100000];

bool dfs(int v, int lastMarked, int d) {
    dep[v] = d;
    if (mark[v]) lastMarked = v;
    for (int to : g[v]) {
        if (!dfs(to, lastMarked, d + 1)) return false;
    }
    if (lastMarked != a[v]) return false;
    return true;
}

inline bool cmp(const int &lhs, const int &rhs) {
    return dep[lhs] > dep[rhs];
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        ++indeg[to];
    }
    REP(i, n) scanf("%d", a + i), --a[i];
    REP(i, n) mark[a[i]] = true;
    REP(i, n) {
        if (indeg[i] == 0 && !dfs(i, -1, 0)) {
            cout << -1 << endl;
            return 0;
        }
    }
    vector<int> ans;
    REP(i, n) if (mark[i]) {
        ans.pb(i);
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n", (int)ans.size());
    for (int x : ans) {
        printf("%d\n", x + 1);
    }
    return 0;
}