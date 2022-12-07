#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100000], dep[100000];
vector<int> g[100000];
int cnt[10000001] = {};

void dfs(int v, int d) {
    dep[v] = d;
    for (int to : g[v]) {
        dfs(to, d + 1);
    }
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n - 1) {
        int p;
        scanf("%d", &p), --p;
        g[p].pb(i + 1);
    }
    dfs(0, 0);
    int mx = 0;
    forn(i, n) mx = max(mx, dep[i]);
    mx %= 2;
    int xo = 0;
    int dif = 0;
    forn(i, n) if (dep[i] % 2 == mx) {
        xo ^= a[i];
    } else {
        ++cnt[a[i]];
        ++dif;
    }
    LL ans = 0;
    if (xo == 0) {
        ans = (LL)dif * (dif - 1) / 2;
        ans += (LL)(n - dif) * (n - dif - 1) / 2;
    }
    forn(i, n) if (dep[i] % 2 == mx) {
        int need = xo ^ a[i];
        if (need <= 10000000) {
            ans += cnt[need];
        }
    }
    cout << ans << endl;
    return 0;
}