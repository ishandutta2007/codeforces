#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a[100000][10];
int n, m, q, nn;
int ans[1 << 18], dif[1 << 18], col[1 << 18][20], le[1 << 18], ri[1 << 18];
const int off = 1 << 17;

int par[40], ra[40];

void dsuInit(int n) {
    forn(i, n) par[i] = i, ra[i] = 1;
}

inline int dsuParent(int v) {
    if (v == par[v]) return v;
    return par[v] = dsuParent(par[v]);
}

bool dsuMerge(int u, int v) {
    u = dsuParent(u);
    v = dsuParent(v);
    if (u == v) return false;
    if (ra[u] < ra[v]) swap(u, v);
    par[v] = u;
    ra[u] += ra[v];
    return true;
}

int b[20], c[20];
int ma[40];
void stMerge(int l, int r, int res) {
    forn(i, nn) {
        b[i] = col[l][i];
        c[i] = col[r][i] + dif[l];
    }
    dsuInit(dif[l] + dif[r]);
    ans[res] = ans[l] + ans[r];
    forn(i, n) {
        if (a[ri[l]][i] == a[le[r]][i]) {
            ans[res] -= dsuMerge(b[n + i], c[i]);
        }
    }
    memset(ma, -1, sizeof ma);
    dif[res] = 0;
    forn(i, n) {
        int cur = dsuParent(b[i]);
        if (ma[cur] == -1) {
            ma[cur] = dif[res]++;
        }
        col[res][i] = ma[cur];
    }
    forn(i, n) {
        int cur = dsuParent(c[n + i]);
        if (ma[cur] == -1) {
            ma[cur] = dif[res]++;
        }
        col[res][n + i] = ma[cur];
    }
    le[res] = le[l];
    ri[res] = ri[r];
}

void stBuild() {
    forn(i, m) {
        int cnt = 1;
        col[off + i][0] = 0;
        for (int j = 1; j < n; ++j) {
            if (a[i][j] == a[i][j - 1]) {
                col[off + i][j] = col[off + i][j - 1];
            } else {
                col[off + i][j] = cnt++;
            }
        }
        forn(j, n) {
            col[off + i][n + j] = col[off + i][j];
        }
        le[off + i] = ri[off + i] = i;
        ans[off + i] = dif[off + i] = cnt;
    }
    for (int i = off - 1; i >= 1; --i) {
        stMerge(2 * i, 2 * i + 1, i);
    }
}

bool flag;

void stGet(int v, int L, int R, int l, int r) {
    if (l > r) return;
    if (L == l && R == r) {
        if (flag) {
            stMerge(0, v, 0);
        } else {
            ans[0] = ans[v];
            dif[0] = dif[v];
            le[0] = le[v];
            ri[0] = ri[v];
            forn(i, nn) {
                col[0][i] = col[v][i];
            }
            flag = true;
        }
        return;
    }
    int mid = (L + R) >> 1;
    stGet(2 * v, L, mid, l, min(r, mid));
    stGet(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
}

const int DEBUG = 0;
mt19937 mt(123);

int main() {
//    freopen("input.txt", "r", stdin);
    if (DEBUG) {
        n = 10, m = 100000, q = 100000;
        forn(i, n) forn(j, m) {
            a[j][i] = mt() % 1000000;
        }
    } else {
        scanf("%d%d%d", &n, &m, &q);
        forn(i, n) forn(j, m) {
            scanf("%d", a[j] + i);
        }
    }
    nn = 2 * n;
    stBuild();
    forn(i, q) {
        int from, to;
        if (DEBUG) {
            from = mt() % m;
            to = mt() % m;
            if (from > to) {
                swap(from, to);
            }
        } else {
            scanf("%d%d", &from, &to);
            --from, --to;
        }
        flag = false;
        stGet(1, 0, off - 1, from, to);
        assert(flag);
        printf("%d\n", ans[0]);
    }
    return 0;
}