#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, p, k;
int a[1001], b[1001], c[1001];
int d[1001], e[1001][51], f[1001][51];
int nd[1001], ne[1001][51], nf[1001][51];

void readArr(int *a) {
    int cnt;
    scanf("%d", &cnt);
    forn(i, cnt) {
        int x;
        scanf("%d", &x), --x;
        a[x + 1] = 1;
    }
}

inline void upd(int &x, int y) {
    x = max(x, y);
}

int main() {
    scanf("%d%d%d", &n, &p, &k);
    readArr(a);
    readArr(b);
    forn(i, n + 1) {
        if (a[i] && b[i]) {
            c[i] = 1;
            a[i] = b[i] = 0;
        }
    }
    forn(i, n) {
        a[i + 1] += a[i];
        b[i + 1] += b[i];
        c[i + 1] += c[i];
    }
    p = min(p, (n + k - 1) / k * 2);
    forn(_, p) {
        memcpy(nd, d, sizeof d);
        memcpy(ne, e, sizeof e);
        memcpy(nf, f, sizeof f);

        int mx = 0;
        forn(i, n) {
            mx = max(mx, d[i]);
            int can = min(k, n - i);
            upd(ne[i][can], mx + a[i + can] - a[i] + c[i + can] - c[i]);
            upd(nf[i][can], mx + b[i + can] - b[i] + c[i + can] - c[i]);
            upd(nd[i + can], ne[i][can]);
            upd(nd[i + can], nf[i][can]);
        }
        forn(i, n) {
            int can = min(k, n - i);
            for (int j = 1; j <= can; ++j) {
                upd(nd[i + j], e[i][j] + b[i + j] - b[i]);
                upd(nd[i + j], f[i][j] + a[i + j] - a[i]);
                int can2 = min(j - 1, n - i - k);
                for (int p = (k == j); p <= can2; ++p) {
                    upd(nf[i + j][p + k - j], e[i][j] + b[i + p + k] - b[i + p] + c[i + p + k] - c[i + j]);
                    upd(ne[i + j][p + k - j], f[i][j] + a[i + p + k] - a[i + p] + c[i + p + k] - c[i + j]);
                    upd(nd[i + p + k], ne[i + j][p + k - j]);
                    upd(nd[i + p + k], nf[i + j][p + k - j]);
                }
            }
        }

        memcpy(d, nd, sizeof d);
        memcpy(e, ne, sizeof e);
        memcpy(f, nf, sizeof f);
    }
    int ans = 0;
    forn(i, n + 1) {
        ans = max(ans, d[i]);
        forn(j, k + 1) {
            ans = max(ans, e[i][j]);
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}