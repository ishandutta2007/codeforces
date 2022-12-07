#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[1000];
int nx[1001][8][1001];
int d[256];

const int INF = int(1e9);

inline void upd(int &x, int y) {
    x = min(x, y);
}

int pc[256];

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", a + i);
        --a[i];
    }
    memset(nx, -1, sizeof nx);
    forn(i, n + 1) {
        forn(j, 8) {
            nx[i][j][0] = i;
            int cnt = 0;
            for (int k = i; k < n; ++k) {
                if (a[k] == j) {
                    ++cnt;
                    nx[i][j][cnt] = k + 1;
                }
            }
        }
    }
    int lo = 0, hi = 1000, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        forn(i, 256) d[i] = INF;
        d[0] = 0;
        forn(i, 255) if (d[i] != INF) {
            forn(j, 8) if (!(i & (1 << j))) {
                if (nx[d[i]][j][mid] != -1) {
                    upd(d[i ^ (1 << j)], nx[d[i]][j][mid]);
                }
            }
        }
        if (d[255] != INF) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    int best = lo * 8;
    forn(i, 256) pc[i] = __builtin_popcount(i);
    forn(mask, 256) {
        forn(i, 256) d[i] = INF;
        d[0] = 0;
        forn(i, 255) if (d[i] != INF) {
            int cnt = lo;
            if (mask & (1 << pc[i])) {
                ++cnt;
            }
            forn(j, 8) if (!(i & (1 << j))) {
                if (nx[d[i]][j][cnt] != -1) {
                    upd(d[i ^ (1 << j)], nx[d[i]][j][cnt]);
                }
            }
        }
        if (d[255] != INF) {
            best = max(best, lo * 8 + pc[mask]);
        }
    }
    cout << best << endl;
    return 0;
}