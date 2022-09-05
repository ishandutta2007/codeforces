#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn], cnt[maxn], fa[maxn], p[maxn], q[maxn];
vector<int> pos[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unite(int x, int y) {
    fa[find(x)] = find(y);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(cnt + 1, cnt + n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pos[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            cnt[a[i]]++, pos[a[i]].push_back(i);
        }
        int odd = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] % 2) odd++;
        }
        if (odd > 1) { puts("NO"); continue; }
        if (n % 2 == 1 && cnt[a[(n + 1) / 2]] == 1) { puts("NO"); continue; }
        iota(fa + 1, fa + n + 1, 1);
        int l = 1, r = n;
        for (int t : {0, 1}) {
            for (int i = 1; i <= n; i++) if (pos[i].size() % 2 == t) {
                for (int j : pos[i]) {
                    (l <= n - r + 1 ? p[l++] : p[r--]) = j;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            q[p[i]] = i, unite(i, p[i]);
        }
        auto swap = [&](int i, int j) {
            std::swap(q[p[i]], q[p[j]]), std::swap(p[i], p[j]);
        };
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < pos[i].size(); j++) {
                int x = pos[i][j], y = pos[i][j - 1];
                if (find(x) ^ find(y)) swap(q[x], q[y]), unite(x, y);
            }
        }
        for (int i = 1, lst = 0; i <= n; i++) if (pos[i].size() > 1) {
            if (lst && find(pos[lst][0]) ^ find(pos[i][0])) {
                int x = pos[lst][0];
                if (2 * x - 1 == n) x = pos[lst][1];
                int u = q[x], v = n - u + 1;
                swap(u, v);
                int y = pos[i][0];
                if (2 * y - 1 == n) y = pos[i][1];
                int a = q[y], b = n - a + 1;
                swap(u, a), swap(v, b);
                unite(pos[lst][0], pos[i][0]);
            }
            lst = i;
        }
        puts("YES");
        for (int i = 1; i <= n; i++) {
            printf("%d ", p[i]);
        }
        putchar('\n');
    }
    return 0;
}