#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1e9 + 7;

int n;
int x[5000], y[5000];
vector<int> d[10001];
int c[5000], col[5000] = {};
vector<int> cm[5000];
int ccnt;

bool dsuMerge(int u, int v) {
    bool sw = col[u] == col[v];
    u = c[u];
    v = c[v];
    if (u == v) return !sw;
    if (cm[u].size() < cm[v].size()) swap(u, v);
    for (int x : cm[v]) {
        cm[u].pb(x);
        c[x] = u;
        if (sw) col[x] ^= 1;
    }
    cm[v].clear();
    --ccnt;
    return true;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", x + i, y + i);
    REP(i, n) c[i] = i, cm[i].pb(i);
    REP(i, n) for (int j = i + 1; j < n; ++j) {
        int dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        d[dist].pb((i << 13) | j);
    }
    ccnt = n;
    int ans = 10000, ansCnt = n;
    for (int i = 10000; i > 0; --i) {
        bool ok = true;
        for (int x : d[i]) {
            int u = x >> 13;
            int v = x & 8191;
            if (!dsuMerge(u, v)) {
                ok = false;
                break;
            }
        }
        if (!ok) break;
        ans = i - 1;
        ansCnt = ccnt;
    }
    int ans2 = 1;
    REP(i, ansCnt) {
        ans2 <<= 1;
        if (ans2 >= MOD) ans2 -= MOD;
    }
    printf("%d\n%d\n", ans, ans2);
    return 0;
}