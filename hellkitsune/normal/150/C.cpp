#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct Node {
    double tot, best, pref, suf;
};

const int off = 1 << 18;

int n, m, c;
int x[150000], p[150000];
Node st[1 << 19], cur, tmp;
bool flag;

void stMerge(Node &v, Node &l, Node &r) {
    v.tot = l.tot + r.tot;
    v.pref = max(l.pref, l.tot + r.pref);
    v.suf = max(r.suf, r.tot + l.suf);
    v.best = max(max(l.best, r.best), l.suf + r.pref);
}

void stBuild() {
    REP(i, n - 1) {
        Node &v = st[off + i];
        v.tot = x[i + 1] - x[i] - 0.02 * p[i] * c;
        v.best = v.suf = v.pref = max(v.tot, 0.0);
    }
    for (int i = off - 1; i >= 1; --i) {
        stMerge(st[i], st[i << 1], st[(i << 1) | 1]);
    }
}

void stGet(int v, int L, int R, int l, int r) {
    if (l == L && r == R) {
        if (flag) {
            cur = st[v];
            flag = false;
        } else {
            tmp = cur;
            stMerge(cur, tmp, st[v]);
        }
        return;
    }
    int mid = (L + R) >> 1;
    if (l <= mid) stGet(v << 1, L, mid, l, min(r, mid));
    if (r > mid) stGet((v << 1) | 1, mid + 1, R, max(l, mid + 1), r);
}

int main() {
    scanf("%d%d%d", &n, &m, &c);
    REP(i, n) scanf("%d", x + i);
    REP(i, n - 1) scanf("%d", p + i);
    stBuild();

    double ans = 0;
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, to -= 2;
        flag = true;
        stGet(1, 0, off - 1, from, to);
        ans += cur.best;
    }
    printf("%.12f\n", 0.5 * ans);
    return 0;
}