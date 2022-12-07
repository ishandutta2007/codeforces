#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int N = 200015;

int n, k, s, t;
int c[N], v[N];
int g[N], sum[N];

const int INF = int(1e9) + 123;

int main() {
    scanf("%d%d%d%d", &n, &k, &s, &t);
    forn(i, n) {
        scanf("%d%d", c + i, v + i);
    }
    forn(i, k) {
        scanf("%d", g + i);
    }
    g[k++] = 0;
    g[k++] = s;
    sort(g, g + k);
    for (int i = k - 1; i > 0; --i) {
        g[i] -= g[i - 1];
    }
    forn(i, k - 1) {
        g[i] = g[i + 1];
    }
    --k;
    sort(g, g + k);
    sum[0] = 0;
    forn(i, k) {
        sum[i + 1] = sum[i] + g[i];
    }
    int ans = INF;
    forn(i, n) {
        if (g[k - 1] > v[i]) {
            continue;
        }
        int ind = lower_bound(g, g + k, v[i] / 2 + 1) - g;
        LL curT = sum[ind];
        //3 * g[ind] - v[i]
        //(v[i] - g[ind]) + (g[ind] - v[i] + g[ind]) * 2
        curT += 3ll * (sum[k] - sum[ind]) - (k - ind) * 1ll * v[i];
        if (curT <= t) {
            ans = min(ans, c[i]);
        }
        //cerr << curT << ' ';
    }
   // cerr << endl;
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}