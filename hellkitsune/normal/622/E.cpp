#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> g[500000];
vector<int> a;
int dep[500000];

void dfs(int v, int p) {
    if (p == -1) dep[v] = 0;
    else dep[v] = dep[p] + 1;
    bool leaf = true;
    for (int to : g[v]) if (to != p) {
        leaf = false;
        dfs(to, v);
    }
    if (leaf) a.pb(dep[v]);
}

int main() {
    scanf("%d", &n);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    int ans = 0;
    dep[0] = 0;
    for (int v : g[0]) {
        a.clear();
        dfs(v, 0);
        sort(a.begin(), a.end());
        //for (int x : a) printf("%d ", x);
        //cout << endl;
        for (int i = 1; i < (int)a.size(); ++i) {
            a[i] = max(a[i], a[i - 1] + 1);
        }
        ans = max(ans, a.back());
    }
    printf("%d\n", ans);
    return 0;
}