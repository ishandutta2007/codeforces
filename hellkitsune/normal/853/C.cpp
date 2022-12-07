#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, q;
int row[200000], col[200000];
int l[200000], r[200000], u[200000], d[200000];
LL ans[200000];
int mnmx[800000], from[800000], to[800000], bound[800000], cnt = 0;

int fen[200000];

void fenInc(int pos) {
    for (; pos < n; pos |= pos + 1) {
        ++fen[pos];
    }
}

int fenGet(int pos) {
    int res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res += fen[pos];
    }
    return res;
}

inline bool cmp(const int &lhs, const int &rhs) {
    return bound[lhs] < bound[rhs];
}

int ord[400000], c;

int main() {
    scanf("%d%d", &n, &q);
    forn(i, n) scanf("%d", row + i), --row[i];
    forn(i, n) col[row[i]] = i;
    forn(i, q) {
        scanf("%d%d%d%d", l + i, u + i, r + i, d + i);
        --l[i], --u[i], --r[i], --d[i];
        ans[i] = (LL)l[i] * (l[i] - 1) / 2;
        ans[i] += (LL)(n - 1 - r[i]) * (n - 2 - r[i]) / 2;
        ans[i] += (LL)u[i] * (u[i] - 1) / 2;
        ans[i] += (LL)(n - 1 - d[i]) * (n - 2 - d[i]) / 2;
        mnmx[cnt] = 0, from[cnt] = 0, to[cnt] = u[i], bound[cnt] = l[i] - 1;
        ++cnt;
        mnmx[cnt] = 1, from[cnt] = 0, to[cnt] = u[i], bound[cnt] = r[i] + 1;
        ++cnt;
        mnmx[cnt] = 0, from[cnt] = d[i] + 1, to[cnt] = n, bound[cnt] = l[i] - 1;
        ++cnt;
        mnmx[cnt] = 1, from[cnt] = d[i] + 1, to[cnt] = n, bound[cnt] = r[i] + 1;
        ++cnt;
    }
    c = 0;
    forn(i, cnt) if (mnmx[i] == 0) {
        ord[c++] = i;
    }
    sort(ord, ord + c, cmp);
    int ind = 0;
    forn(ii, c) {
        int i = ord[ii];
        while (ind < n && bound[i] >= ind) {
            fenInc(row[ind]);
            ++ind;
        }
        int res = fenGet(to[i] - 1) - fenGet(from[i] - 1);
        ans[i / 4] -= (LL)res * (res - 1) / 2;
    }

    memset(fen, 0, sizeof fen);
    c = 0;
    forn(i, cnt) if (mnmx[i] == 1) {
        ord[c++] = i;
    }
    sort(ord, ord + c, cmp);
    reverse(ord, ord + c);
    ind = n - 1;
    forn(ii, c) {
        int i = ord[ii];
        while (ind >= 0 && bound[i] <= ind) {
            fenInc(row[ind]);
            --ind;
        }
        int res = fenGet(to[i] - 1) - fenGet(from[i] - 1);
        ans[i / 4] -= (LL)res * (res - 1) / 2;
    }
    LL tot = (LL)n * (n - 1) / 2;
    forn(i, q) printf("%I64d\n", tot - ans[i]);
    return 0;
}