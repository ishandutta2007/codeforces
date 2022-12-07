#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
PII a[3001];
int can[3001];
int res[3001];

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i].first), a[i].second = i;
    sort(a, a + n, greater<PII>());
    a[n] = mp(0, -1);
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        int need = (i + 1) / 2 * 2 + i;
        if (need > n) {
            break;
        }
        mx = max(mx, a[i - 1].first - a[i].first);
    }
    can[0] = -1;
    for (int i = 1; i <= n; ++i) {
        int need = (i + 1) / 2 * 2 + i;
        if (need > n) {
            for (int j = i; j <= n; ++j) {
                can[j] = can[j - 1];
            }
            break;
        }
        can[i] = can[i - 1];
        if (a[i - 1].first - a[i].first == mx) {
            can[i] = i;
        }
    }
    PII best = mp(-1, -1);
    int bestI = -1;
    int bestJ = -1;
    int bestK = -1;
    for (int j = 2; j <= n; ++j) {
        for (int k = 1; j + k <= n; ++k) {
            int mn = 1;
            mn = max(mn, (k + 1) / 2);
            mn = max(mn, (j + 2) / 3);
            mn = max(mn, j - 2 * k);
            int mx = n;
            mx = min(mx, 2 * j / 3);
            mx = min(mx, j - (k + 1) / 2);
            mx = min(mx, 2 * k);
            if (mx > 0 && can[mx] >= mn) {
                PII cur = mp(a[j - 1].first - a[j].first, a[j + k - 1].first - a[j + k].first);
                if (cur > best) {
                    best = cur;
                    bestI = can[mx];
                    bestJ = j;
                    bestK = j + k;
                }
            }
        }
    }
    memset(res, -1, sizeof res);
    for (int i = 0; i < bestI; ++i) {
        res[a[i].second] = 1;
    }
    for (int i = bestI; i < bestJ; ++i) {
        res[a[i].second] = 2;
    }
    for (int i = bestJ; i < bestK; ++i) {
        res[a[i].second] = 3;
    }
    forn(i, n) printf("%d ", res[i]);
    puts("");
    return 0;
}