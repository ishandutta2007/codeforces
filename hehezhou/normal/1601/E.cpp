#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
int a[300010];
int qwq[1200010];
inline void build(int x, int l, int r) {
    if (l == r) {
        qwq[x] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    qwq[x] = min(qwq[x << 1], qwq[x << 1 | 1]);
}
inline int query(int x, int l, int r, int L, int R) {
    if (l > R || L > r) return 0x3f3f3f3f;
    if (L <= l && r <= R) return qwq[x];
    int mid = l + r >> 1;
    return min(query(x << 1, l, mid, L, R), query(x << 1 | 1, mid + 1, r, L, R));
}
struct qnode {
    int l, r, id, qwq;
};
vector < qnode > q[300010];
ll ans[300010];
int nxt[300010], top;
pair < int, int > sta[300010];
int f[300010][20];
ll g[300010][20];
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        q[l % k].push_back({l, r, i, a[l]});
    }
    for (int i = 0; i < k; i++) {
        int cnt = 0;
        for (int j = 0; j * k + i - k + 1 <= n; j++) {
            a[j] = query(1, 1, n, j * k + i - k + 1, j * k + i);
            cnt = j;
        }
        sort(q[i].begin(), q[i].end(), [](qnode a, qnode b) {
            return a.l > b.l;
        });
        sta[top = 1] = {-1, cnt + 1};
        int pos = 0;
        for (int j = cnt; j >= 0; j--) {
            while (pos < q[i].size() && q[i][pos].l / k == j) {
                q[i][pos].l = (q[i][pos].l - i) / k;
                q[i][pos].r = (q[i][pos].r - i) / k + 1;
                while (sta[top].first >= q[i][pos].qwq) top--;
                ans[q[i][pos].id] += 1ll * q[i][pos].qwq * (min(sta[top].second, q[i][pos].r) - q[i][pos].l);
                q[i][pos].l = sta[top].second;
                pos++;
            }
            while (sta[top].first >= a[j]) top--;
            nxt[j] = sta[top].second;
            sta[++top] = {a[j], j};
        }
        f[cnt + 1][0] = cnt + 1;
        for (int i = 0; i <= cnt; i++) f[i][0] = nxt[i], g[i][0] = 1ll * (nxt[i] - i) * a[i];
        for (int d = 1; d < 20; d++) {
            for (int i = 0; i <= cnt + 1; i++) {
                f[i][d] = f[f[i][d - 1]][d - 1];
                g[i][d] = g[i][d - 1] + g[f[i][d - 1]][d - 1];
            }
        }
        // cerr << i << endl;
        // for (int j = 0; j <= cnt; j++) cerr << a[j] << " \n"[j == cnt];
        // for (int j = 0; j <= cnt; j++) cerr << f[j][0] << " \n"[j == cnt];
        // for (int j = 0; j <= cnt; j++) cerr << g[j][0] << " \n"[j == cnt];
        for (auto t : q[i]) {
            int l = t.l, r = t.r;
            // cerr << l << ' ' << r << ' ' << t.id << endl;
            ll ans = 0;
            for (int d = 20; d --> 0; ) if (f[l][d] < r) ans += g[l][d], l = f[l][d];
            if (l < r) ans += 1ll * (r - l) * a[l];
            ::ans[t.id] += ans;
        }
    }
    for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
}