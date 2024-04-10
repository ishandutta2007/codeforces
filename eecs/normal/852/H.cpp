#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 210;
int n, K, id[maxn * 2];
ll ans, f[maxn][maxn][55];
array<int, 2> a[maxn];
double ang[maxn], foo[maxn * 2];
deque<int> Q;

int main() {
    scanf("%d %d", &n, &K), K--;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    sort(a + 1, a + n + 1, greater<>());
    auto cross = [&](array<int, 2> p, array<int, 2> q, array<int, 2> r) {
        return 1LL * (q[0] - p[0]) * (r[1] - q[1]) - 1LL * (r[0] - q[0]) * (q[1] - p[1]);
    };
    for (int s = 3; s <= n; s++) {
        sort(a + 1, a + s, [&](array<int, 2> p, array<int, 2> q) {
            return atan2(p[1] - a[s][1], p[0] - a[s][0]) < atan2(q[1] - a[s][1], q[0] - a[s][0]);
        });
        memset(f, -0x3f, sizeof(f));
        for (int i = 1; i < s; i++) {
            for (int j = 1; j < i; j++) {
                bool flag = 1;
                ll area = abs(cross(a[s], a[i], a[j]));
                for (int k = j + 1; k < i && flag; k++) {
                    flag &= abs(cross(a[s], a[j], a[k])) + abs(cross(a[s], a[k], a[i])) + abs(cross(a[j], a[k], a[i])) > area;
                }
                if (!flag) { memset(f[i][j], -0x3f, sizeof(f[i][j])); continue; }
                f[i][j][2] = 0;
                for (int k = 2; k <= K; k++) f[i][j][k] += area;
                ans = max(ans, f[i][j][K]);
            }
            int tot = 0;
            for (int j = 1; j < s; j++) if (i ^ j) {
                ang[j] = atan2(a[j][1] - a[i][1], a[j][0] - a[i][0]), id[++tot] = j;
            }
            sort(id + 1, id + tot + 1, [&](int x, int y) { return ang[x] < ang[y]; });
            copy(id + 1, id + tot + 1, id + tot + 1);
            for (int i = 1; i <= 2 * tot; i++) {
                foo[i] = ang[id[i]] + (i > tot ? 2 * M_PI : 0);
            }
            for (int k = 2; k < K; k++) {
                Q.clear();
                for (int p = tot, q = 0; p <= 2 * tot; p++) if (id[p] > i) {
                    while (foo[q + 1] < foo[p] - M_PI) {
                        if (id[++q] < i) {
                            while (!Q.empty() && f[i][id[Q.back()]][k] <= f[i][id[q]][k]) Q.pop_back();
                            Q.push_back(q);
                        }
                    }
                    while (!Q.empty() && Q.front() <= p - tot) Q.pop_front();
                    if (!Q.empty()) f[id[p]][i][k + 1] = f[i][id[Q.front()]][k];
                }
            }
        }
    }
    printf("%lld.%d0\n", ans / 2, ans % 2 ? 5 : 0);
    return 0;
}