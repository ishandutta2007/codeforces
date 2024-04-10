#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int n;
int a[100000], b[100000];
int who[200005];
bool used[200005] = {};
vector<int> g[200005];
int mul;
int far[200005];
int tr[200005];

void dfs(int v) {
    ++mul;
    used[v] = true;
    for (int to : g[v]) {
        dfs(to);
    }
}

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d%d", a + i, b + i);
        --a[i];
        --b[i];
        g[b[i]].pb(a[i]);
    }
    memset(who, -1, sizeof who);
    forn(i, n) who[a[i]] = i;
    int ans = 1;
    forn(i, 2 * n) if (who[i] == -1) {
        mul = 0;
        dfs(i);
        ans = (LL)ans * mul % MOD;
    }
    memset(far, -1, sizeof far);
    forn(i, n) far[a[i]] = b[i];
    forn(_, 25) forn(i, 2 * n) {
        if (far[i] != -1) {
            far[i] = far[far[i]];
        }
    }
    forn(i, n) tr[a[i]] = b[i];
    forn(i, 2 * n) if (far[i] != -1 && !used[far[i]]) {
        int c = 0;
        for (int x = far[i]; !used[x]; x = tr[x]) {
            ++c;
            used[x] = true;
        }
        if (c > 1) {
            ans = 2ll * ans % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}