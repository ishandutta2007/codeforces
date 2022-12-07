#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int d[1 << 16][137];
const int INF = int(1e9);

int n;
char c[16];
int r[16], b[16];

void upd(int &x, int y) {
    x = max(x, y);
}

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf(" %c%d%d", c + i, r + i, b + i);
    }
    forn(i, 1 << 16) forn(j, 137) {
        d[i][j] = -INF;
    }
    d[0][0] = 0;
    forn(mask, (1 << n) - 1) {
        int cr = 0;
        int cb = 0;
        forn(i, n) if (mask & (1 << i)) {
            if (c[i] == 'R') {
                ++cr;
            } else {
                ++cb;
            }
        }
        forn(j, 137) {
            if (d[mask][j] == INF) {
                continue;
            }
            forn(k, n) if (!(mask & (1 << k))) {
                int nmask = mask | (1 << k);
                upd(d[nmask][j + min(cr, r[k])], d[mask][j] + min(cb, b[k]));
            }
        }
    }
    int rr = 0, bb = 0;
    forn(i, n) {
        rr += r[i];
        bb += b[i];
    }
    int ans = INF;
    int all = (1 << n) - 1;
    forn(i, 137) {
        ans = min(ans, max(rr - i, bb - d[all][i]));
    }
    ans += n;
    cout << ans << endl;
    return 0;
}