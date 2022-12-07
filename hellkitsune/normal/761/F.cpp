#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;
LL cnt[26][1005][1005] = {};
int c[1005][1005] = {};
LL d[1005][1005] = {};
int a[1005][1005];
char s[1005];

void p(int (&c)[1005][1005]) {
    forn(i, n) {
        c[i + 1][0] += c[i][0];
    }
    forn(i, m) {
        c[0][i + 1] += c[0][i];
    }
    forn(i, n) forn(j, m) {
        c[i + 1][j + 1] += c[i][j + 1] + c[i + 1][j] - c[i][j];
    }
}

void p(LL (&c)[1005][1005]) {
    forn(i, n) {
        c[i + 1][0] += c[i][0];
    }
    forn(i, m) {
        c[0][i + 1] += c[0][i];
    }
    forn(i, n) forn(j, m) {
        c[i + 1][j + 1] += c[i][j + 1] + c[i + 1][j] - c[i][j];
    }
}


int q(int (&c)[1005][1005], int i, int j, int ii, int jj) {
    return c[ii + 1][jj + 1] - c[ii + 1][j] - c[i][jj + 1] + c[i][j];
}

LL q(LL (&c)[1005][1005], int i, int j, int ii, int jj) {
    return c[ii + 1][jj + 1] - c[ii + 1][j] - c[i][jj + 1] + c[i][j];
}

int x[300005], y[300005], xx[300005], yy[300005], ind[300005];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    forn(i, n) {
        scanf("%s", s);
        forn(j, m) {
            a[i][j] = int(s[j] - 'a');
        }
    }
    forn(i, k) {
        int x, y, xx, yy;
        char cc;
        scanf("%d%d%d%d %c", &x, &y, &xx, &yy, &cc);
        --x, --y, --xx, --yy;
        ::x[i] = x;
        ::y[i] = y;
        ::xx[i] = xx;
        ::yy[i] = yy;
        int ind = int(cc - 'a');
        ::ind[i] = ind;
        ++cnt[ind][x][y];
        --cnt[ind][xx + 1][y];
        --cnt[ind][x][yy + 1];
        ++cnt[ind][xx + 1][yy + 1];

        ++c[x][y];
        --c[xx + 1][y];
        --c[x][yy + 1];
        ++c[xx + 1][yy + 1];
    }
    forn(i, 26) {
        p(cnt[i]);
    }
    p(c);
    forn(i, n) forn(j, m) {
        cnt[a[i][j]][i][j] += k - c[i][j];
    }

    forn(i, n) forn(j, m) {
        LL res = 0;
        forn(k, 26) {
            res += cnt[k][i][j] * abs(k - a[i][j]);
        }
        d[i + 1][j + 1] = res;
    }

    p(d);

    forn(z, 26) {
        for (int i = n; i > 0; --i) {
            for (int j = m; j > 0; --j) {
                cnt[z][i][j] = cnt[z][i - 1][j - 1];
            }
        }
        forn(i, n + 1) {
            cnt[z][i][0] = 0;
        }
        forn(i, m + 1) {
            cnt[z][0][i] = 0;
        }
    }

    forn(i, 26) {
        p(cnt[i]);
    }

    LL all = q(d, 0, 0, n - 1, m - 1);
    LL ans = LL(4e18);
    forn(i, k) {
        int x = ::x[i];
        int y = ::y[i];
        int xx = ::xx[i];
        int yy = ::yy[i];
        int ind = ::ind[i];
        LL res = all - q(d, x, y, xx, yy);
        forn(j, 26) {
            res += (LL)q(cnt[j], x, y, xx, yy) * abs(j - ind);
        }
        ans = min(ans, res);
    }

    cout << ans << endl;
    return 0;
}