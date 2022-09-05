#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, SZ = 2100;
int n, m, tot, bel[maxn], a[maxn], b[maxn];
int cnt[maxn], buc[maxn], ans[maxn];
vector<array<int, 5>> Q;
vector<array<int, 3>> M;
bitset<maxn> S;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), bel[i] = (i - 1) / SZ + 1;
    }
    copy(a + 1, a + n + 1, b + 1);
    for (int i = 1, op, x, y, z; i <= m; i++) {
        scanf("%d %d %d", &op, &x, &y);
        if (op == 1) {
            scanf("%d", &z), ans[i] = INT_MAX;
            Q.push_back({x, y, (int)M.size(), z, i});
        } else {
            M.push_back({x, y, b[x]});
            ans[i] = -1, b[x] = y;
        }
    }
    sort(Q.begin(), Q.end(), [&](array<int, 5> x, array<int, 5> y) {
        return make_tuple(bel[x[0]], bel[x[1]], x[2]) < make_tuple(bel[y[0]], bel[y[1]], y[2]);
    });
    int l = 1, r = 0, t = 0;
    auto ins = [&](int x, int coef) {
        if (!--buc[cnt[x]]) S.reset(cnt[x]);
        cnt[x] += coef;
        if (!buc[cnt[x]]++) S.set(cnt[x]);
    };
    auto modify = [&](int p, int v) {
        if (p >= l && p <= r) ins(a[p], -1);
        a[p] = v;
        if (p >= l && p <= r) ins(a[p], 1);
    };
    vector<array<int, 2>> V;
    for (auto &p : Q) {
        while (l > p[0]) ins(a[--l], 1);
        while (r < p[1]) ins(a[++r], 1);
        while (l < p[0]) ins(a[l++], -1);
        while (r > p[1]) ins(a[r--], -1);
        while (t < p[2]) modify(M[t][0], M[t][1]), t++;
        while (t > p[2]) t--, modify(M[t][0], M[t][2]);
        V.clear();
        for (int i = S._Find_next(0); i <= n; i = S._Find_next(i)) {
            V.push_back({i, buc[i]});
        }
        for (int i = 0, j = -1, s = 0; i < V.size(); s -= V[i++][1]) {
            while (j + 1 < V.size() && s < p[3]) s += V[++j][1];
            if (s < p[3]) break;
            ans[p[4]] = min(ans[p[4]], V[j][0] - V[i][0]);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (~ans[i]) printf("%d\n", ans[i] == INT_MAX ? -1 : ans[i]);
    }
    return 0;
}