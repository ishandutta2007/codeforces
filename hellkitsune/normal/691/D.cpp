#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int p[1000000];
vector<int> g[1000000];
bool used[1000000] = {};
vector<int> all;

void dfs(int v) {
    used[v] = true;
    all.pb(v);
    for (int to : g[v]) if (!used[to]) {
        dfs(to);
    }
}

int a[1000000], cnt;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", p + i), --p[i];
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    REP(i, n) if (!used[i]) {
        all.clear();
        dfs(i);
        sort(all.begin(), all.end());
        cnt = 0;
        for (int x : all) {
            a[cnt++] = p[x];
        }
        sort(a, a + cnt);
        reverse(a, a + cnt);
        cnt = 0;
        for (int x : all) {
            p[x] = a[cnt++];
        }
    }
    REP(i, n) printf("%d ", p[i] + 1);
    printf("\n");
    return 0;
}