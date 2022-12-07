#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef long double Double;
typedef pair<Double, Double> P;

int n, q;
int a[100000], b[100000];
P st[1 << 18];
const int off = 1 << 17;

P merge(P p1, P p2) {
    return mp(p1.first * p2.first / (1 - p1.second * (1 - p2.first)),
        p2.second + (1 - p2.second) * p1.second * p2.first / (1 - p1.second * (1 - p2.first)));
}

void stBuild() {
    forn(i, n) {
        st[off + i] = mp((Double)a[i] / b[i], (Double)a[i] / b[i]);
    }
    for (int i = n; i < off; ++i) {
        st[off + i] = mp(1, 1);
    }
    for (int i = off - 1; i >= 1; --i) {
        if (2 * i == off) {
            --i;
            ++i;
        }
        st[i] = merge(st[2 * i], st[2 * i + 1]);
    }
}

void stUpdate(int pos, Double val) {
    st[off + pos] = mp(val, val);
    for (pos = (off + pos) >> 1; pos >= 1; pos >>= 1) {
        st[pos] = merge(st[2 * pos], st[2 * pos + 1]);
    }
}

P res;
bool firstTime = true;

void stGet(int v, int L, int R, int l, int r) {
    if (l > r) return;
    if (l == L && r == R) {
        if (firstTime) {
            res = st[v];
            firstTime = false;
        } else {
            res = merge(res, st[v]);
        }
        return;
    }
    int mid = (L + R) >> 1;
    stGet(2 * v, L, mid, l, min(r, mid));
    stGet(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    forn(i, n) {
        scanf("%d%d", a + i, b + i);
    }
    stBuild();
//    forn(i, n) cerr << st[off + i].first << ' ' << st[off + i].second << ", ";
//    cerr << endl;
    forn(i, q) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            int ind, a, b;
            scanf("%d%d%d", &ind, &a, &b), --ind;
            stUpdate(ind, (Double)a / b);
        } else if (qt == 2) {
            int from, to;
            scanf("%d%d", &from, &to), --from, --to;
            firstTime = true;
            stGet(1, 0, off - 1, from, to);
            printf("%.15f\n", (double)res.first);
        }
    }
    return 0;
}