#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a[1000][1000];
int r[1000][1000], c[1000][1000];
int b[1000][1000];
int st[1 << 11][10][1 << 10];
const int off = 1 << 10;
int p[1005];

void stInit() {
    int cur = 0;
    forn(i, 1005) {
        while ((2 << cur) < i) {
            ++cur;
        }
        p[i] = cur;
    }
}

void stBuild(int v, int l, int r) {
    int (&st)[10][1 << 10] = ::st[v];
    forn(i, n) {
        st[0][i] = 0;
        for (int j = l; j <= r; ++j) {
            st[0][i] = max(st[0][i], b[i][j]);
        }
    }
    forn(i, 9) forn(j, n - (2 << i) + 1) {
        st[i + 1][j] = max(st[i][j], st[i][j + (1 << i)]);
    }
    if (l != r) {
        int mid = (l + r) >> 1;
        stBuild(2 * v, l, mid);
        stBuild(2 * v + 1, mid + 1, r);
    }
}

void stBuild() {
    stInit();
    stBuild(1, 0, m - 1);
}

int stGet(int v, int y, int yy) {
    int sz = p[yy - y + 1];
    int (&st)[10][1 << 10] = ::st[v];
    return max(st[sz][y], st[sz][yy - (1 << sz) + 1]);
}

int stGet(int v, int L, int R, int x, int xx, int y, int yy) {
    if (x > xx) return 0;
    if (x == L && xx == R) {
        return stGet(v, y, yy);
    }
    int mid = (L + R) >> 1;
    return max(stGet(2 * v, L, mid, x, min(xx, mid), y, yy),
        stGet(2 * v + 1, mid + 1, R, max(x, mid + 1), xx, y, yy));
}

int ans[1000005];

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) forn(j, m) scanf("%d", a[i] + j);
    forn(i, n) {
        r[i][m - 1] = a[i][m - 1];
        for (int j = m - 2; j >= 0; --j) {
            if (a[i][j] == 0) {
                r[i][j] = 0;
            } else {
                r[i][j] = 1 + r[i][j + 1];
            }
        }
    }
    forn(j, m) {
        c[n - 1][j] = a[n - 1][j];
        for (int i = n - 2; i >= 0; --i) {
            if (a[i][j] == 0) {
                c[i][j] = 0;
            } else {
                c[i][j] = 1 + c[i + 1][j];
            }
        }
    }
    forn(i, n) b[i][m - 1] = a[i][m - 1];
    forn(i, m) b[n - 1][i] = a[n - 1][i];
    for (int i = n - 2; i >= 0; --i) {
        for (int j = m - 2; j >= 0; --j) {
            b[i][j] = min(min(r[i][j], c[i][j]), b[i + 1][j + 1] + 1);
        }
    }
    stBuild();
    int qq;
    scanf("%d", &qq);
    forn(q, qq) {
        int y, x, yy, xx;
        scanf("%d%d%d%d", &y, &x, &yy, &xx), --y, --x, --yy, --xx;
        int lo = 0, hi = min(xx - x + 1, yy - y + 1), mid;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (stGet(1, 0, m - 1, x, xx - mid + 1, y, yy - mid + 1) < mid) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        ans[q] = lo;
    }
    forn(i, qq) printf("%d\n", ans[i]);
    return 0;
}