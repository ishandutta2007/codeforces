#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, cnt[maxn];
long long ans, cnt_all[maxn];
vector<array<int, 2>> V[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1, c; j <= m; j++) {
            scanf("%d", &c), V[c].push_back({i, j});
        }
    }
    vector<vector<int>> s0(n + 1, vector<int>(m + 1, 0));
    vector<vector<long long>> s1(n + 1, vector<long long>(m + 1, 0));
    auto ins = [&](int i, int p, int coef) {
        cnt[i] += coef, cnt_all[i] += p * coef;
        int x = p;
        for (; p <= m; p += p & -p) {
            s0[i][p] += coef, s1[i][p] += x * coef;
        }
    };
    auto query = [&](int i, int p) {
        long long res0 = 0, res1 = 0;
        for (; p; p -= p & -p) {
            res0 += s0[i][p], res1 += s1[i][p];
        }
        return make_pair(res0, res1);
    };
    for (int i = 1; i <= 100000; i++) {
        for (auto &p : V[i]) {
            for (int j = 1; j <= p[0]; j++) {
                int all = cnt[j];
                ans += all * (p[0] - j);
                auto q = query(j, p[1]);
                ans += 1LL * q.first * p[1] - q.second;
                ans += cnt_all[j] - q.second - 1LL * (all - q.first) * p[1];
            }
            ins(p[0], p[1], 1);
        }
        for (auto &p : V[i]) {
            ins(p[0], p[1], -1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}