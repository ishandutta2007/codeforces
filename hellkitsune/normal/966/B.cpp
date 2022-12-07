#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, x, y;
PII p[300000];
int a[300000];

int main() {
    scanf("%d%d%d", &n, &x, &y);
    forn(i, n) scanf("%d", a + i);
    forn(i, n) p[i] = mp(a[i], i + 1);
    sort(p, p + n, greater<PII>());
    forn(i, n) a[i] = p[i].first;
    int bestX = 0;
    while (bestX < n && (LL)a[bestX] * (bestX + 1) < x) {
        ++bestX;
    }
    int bestY = 0;
    while (bestY < n && (LL)a[bestY] * (bestY + 1) < y) {
        ++bestY;
    }
    if (bestX == n || bestY == n) {
        cout << "No" << endl;
        return 0;
    }
    ++bestX, ++bestY;
    forn(i, n) {
        int can = i + 1;
        int need = (x + a[i] - 1) / a[i];
        if (need + bestY <= can) {
            printf("Yes\n%d %d\n", need, bestY);
            forn(i, need) {
                printf("%d ", p[bestY + i].second);
            }
            puts("");
            forn(i, bestY) {
                printf("%d ", p[i].second);
            }
            puts("");
            return 0;
        }
    }
    forn(i, n) {
        int can = i + 1;
        int need = (y + a[i] - 1) / a[i];
        if (need + bestX <= can) {
            printf("Yes\n%d %d\n", bestX, need);
            forn(i, bestX) {
                printf("%d ", p[i].second);
            }
            puts("");
            forn(i, need) {
                printf("%d ", p[bestX + i].second);
            }
            puts("");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}