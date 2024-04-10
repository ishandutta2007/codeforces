#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9) + 123;

int n;
vector<int> g[300000];
int a[300000];

bool solve(int ans) {
    int bad = 0;
    forn(i, n) {
        bad += (a[i] + 2) > ans;
    }
    forn(v, n) {
        int cur = 0;
        if (a[v] + 2 > ans && a[v] <= ans) {
            ++cur;
        }
        for (int to : g[v]) {
            if (a[to] + 2 > ans && a[to] + 1 <= ans) {
                ++cur;
            }
        }
        if (cur == bad) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    int ans = -INF;
    forn(i, n) ans = max(ans, a[i] + 2);
    if (solve(ans - 2)) {
        cout << ans - 2 << endl;
    } else if (solve(ans - 1)) {
        cout << ans - 1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}