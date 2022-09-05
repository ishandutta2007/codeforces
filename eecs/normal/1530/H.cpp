#include <bits/stdc++.h>
using namespace std;

const int maxn = 15010, L = 555;
int T, n, a[maxn], f[maxn][L], g[maxn][L];

struct BIT {
    vector<int> a;
    BIT() : a(n, -1) {}

    void add(int p, int v) {
        for (int i = p + 1; i <= n; i += i & -i) a[i - 1] = max(a[i - 1], v);
    }
    int query(int p) {
        int s = -1;
        for (int i = p; i; i -= i & -i) s = max(s, a[i - 1]);
        return s;
    }
};

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]), a[i]--;
        }
        reverse(a, a + n);
        int ans = 1;
        for (int t : {0, 1}) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < L; j++) f[i][j] = -1, g[i][j] = n;
            }
            auto t1 = vector<BIT>(L, BIT());
            auto t2 = t1, t3 = t1, t4 = t1;
            if (!t) {
                t1[1].add(a[0], a[0]);
                t2[1].add(n - a[0] - 1, n - a[0] - 1);
                f[0][1] = g[0][1] = a[0];
            }
            for (int i = 1; i < n; i++) {
                if (t) {
                    f[i][2] = g[i][2] = a[i];
                    t1[2].add(a[i], a[i]), t2[2].add(n - a[i] - 1, n - a[i] - 1);
                }
                for (int j = 2; j < L; j++) {
                    int x = i - j + 1;
                    if (x >= 0 && g[x][j - 1] < n) t3[j - 1].add(g[x][j - 1], a[x]);
                    if (x >= 0 && ~f[x][j - 1]) t4[j - 1].add(n - f[x][j - 1] - 1, n - a[x] - 1);
                    f[i][j] = max(t1[j - 1].query(a[i]), t3[j - 1].query(a[i]));
                    g[i][j] = n - max(t2[j - 1].query(n - a[i] - 1), t4[j - 1].query(n - a[i] - 1)) - 1;
                    if (~f[i][j] || g[i][j] < n) ans = max(ans, j - t);
                }
                for (int j = 2; j < L; j++) {
                    if (~f[i][j]) t1[j].add(a[i], f[i][j]);
                    if (g[i][j] < n) t2[j].add(n - a[i] - 1, n - g[i][j] - 1);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}