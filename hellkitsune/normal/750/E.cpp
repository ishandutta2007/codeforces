#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = 1 << 20;

int tmp[5][5];

void matMul(int (&a)[5][5], int (&b)[5][5], int (&c)[5][5]) {
    forn(i, 5) forn(j, 5) {
        c[i][j] = INF;
        forn(k, 5) {
            c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
        }
    }
}

void matMul(int (&a)[5][5], int (&b)[5][5]) {
    forn(i, 5) forn(j, 5) {
        tmp[i][j] = INF;
        forn(k, 5) {
            tmp[i][j] = min(tmp[i][j], a[i][k] + b[k][j]);
        }
    }
    forn(i, 5) forn(j, 5) {
        a[i][j] = tmp[i][j];
    }
}

int n, q;
const int off = 1 << 18;
int st[1 << 19][5][5];
int mat[10][5][5];

int res[5][5];

char s[200005];
int a[200005];
int from[200005], to[200005], ord[200005];
int ans[200005];

void stBuild() {
    forn(i, n) {
        int (&c)[5][5] = st[off + i];
        int (&b)[5][5] = mat[a[i]];
        forn(j, 5) forn(k, 5) {
            c[j][k] = b[j][k];
        }
    }
    for (int i = off - 1; i >= 1; --i) {
        matMul(st[2 * i], st[2 * i + 1], st[i]);
    }
}



void stGet(int v, int L, int R, int l, int r) {
    if (L == l && R == r) {
        matMul(res, st[v]);
        return;
    }
    int mid = (L + R) >> 1;
    if (l <= mid) stGet(2 * v, L, mid, l, min(r, mid));
    if (r > mid) stGet(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
}

void stGet(int l, int r) {
    forn(i, 5) forn(j, 5) {
        res[i][j] = INF;
        if (i == j) {
            res[i][j] = 0;
        }
    }
    stGet(1, 0, off - 1, l, r);
}

inline bool cmp(const int &lhs, const int &rhs) {
    if (from[lhs] != from[rhs]) return from[lhs] < from[rhs];
    return to[lhs] < to[rhs];
}

int solve(int from, int to) {
    stGet(from, to);
    if (res[0][4] == INF) {
        return -1;
    }
    return res[0][4];
}

mt19937 mt(123);

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    scanf("%s", s);
    forn(i, q) {
        scanf("%d%d", from + i, to + i);
        --from[i];
        --to[i];
    }

//    n = 200000, q = 200000;
//    forn(i, n) {
//        a[i] = mt() % 10;
//    }
//    forn(i, q) {
//        from[i] = mt() % (n / 10);
//        to[i] = n - 1 - (mt() % (n / 10));
//        if (from[i] > to[i]) {
//            swap(from[i], to[i]);
//        }
//    }
    forn(i, n) {
        a[i] = int(s[i] - '0');
    }
    forn(k, 10) forn(i, 5) forn(j, 5) {
        mat[k][i][j] = INF;
        if (i == j) {
            mat[k][i][j] = 0;
        }
    }
    mat[2][0][0] = 1;
    mat[2][0][1] = 0;
    mat[0][1][1] = 1;
    mat[0][1][2] = 0;
    mat[1][2][2] = 1;
    mat[1][2][3] = 0;
    mat[6][3][3] = 1;
    mat[6][4][4] = 1;
    mat[7][3][3] = 1;
    mat[7][3][4] = 0;
    stBuild();
    forn(i, q) {
        ord[i] = i;
    }
    sort(ord, ord + q, cmp);
    for (int beg = 0; beg < q; ) {
        int end = beg + 1;
        while (end < q && from[ord[beg]] == from[ord[end]] && to[ord[beg]] == to[ord[end]]) {
            ++end;
        }
        int cur = solve(from[ord[beg]], to[ord[beg]]);
        for (int i = beg; i < end; ++i) {
            ans[ord[i]] = cur;
        }
        beg = end;
    }
    forn(i, q) {
        printf("%d\n", ans[i]);
    }
    return 0;
}