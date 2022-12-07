#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int col[200000];
vector<int> g[200000];
vector<int> ans;

void dfs(int v, int par) {
    col[v] ^= 1;
    ans.pb(v);
    for (int to : g[v]) if (to != par) {
        dfs(to, v);
        col[v] ^= 1;
        ans.pb(v);
        if (col[to] != 1) {
            col[to] ^= 1;
            col[v] ^= 1;
            ans.pb(to);
            ans.pb(v);
        }
    }
}

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", col + i);
        if (col[i] == -1) {
            col[i] = 0;
        }
    }
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    col[0] ^= 1;
    dfs(0, -1);
    if (col[0] != 1) {
        int to = g[0][0];
        col[to] ^= 1;
        col[0] ^= 1;
        col[to] ^= 1;
        ans.pb(to);
        ans.pb(0);
        ans.pb(to);
    }
    forn(i, n) assert(col[i] == 1);
    bool firstTime = true;
    for (int x : ans) {
        if (!firstTime) {
            printf(" ");
        }
        firstTime = false;
        printf("%d", x + 1);
    }
    printf("\n");
    return 0;
}