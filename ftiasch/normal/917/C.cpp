#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

const int K = 8;
const int Q = 25;
const int M = 70;
const int D = 30;

using LL = long long;

const LL INF = 1000000000000000000LL;

int x, k, n, q, c[K + 1], idx[1 << K];
LL dp[2][M], trans[D][M][M];
std::pair<int, int> s[Q + 1];

void update(LL& x, LL a)
{
    x = std::min(x, a);
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("C.in", "r", stdin);
#endif
    scanf("%d%d%d%d", &x, &k, &n, &q);
    for (int i = 1; i <= k; ++ i) {
        scanf("%d", c + i);
    }
    bool found = false;
    for (int i = 0; i < q; ++ i) {
        scanf("%d%d", &s[i].first, &s[i].second);
        found |= s[i].first == n - x + 1;
    }
    if (!found) {
        s[q ++] = {n - x + 1, 0};
    }
    std::sort(s, s + q);
    std::vector<int> msks;
    for (int msk = 0; msk < 1 << k; ++ msk) {
        if (__builtin_popcount(msk) == x) {
            idx[msk] = msks.size();
            msks.push_back(msk);
        }
    }
    int m = msks.size();
    for (int k = 0; k < D; ++ k) {
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < m; ++ j) {
                trans[k][i][j] = INF;
            }
        }
    }
    for (int i = 0; i < m; ++ i) {
        auto msk = msks[i];
        if (msk & 1) {
            for (int j = 1; j <= k; ++ j) {
                if (~msk >> j & 1) {
                    update(trans[0][idx[(msk | 1 << j) >> 1]][i], c[j]);
                }
            }
        } else {
            update(trans[0][idx[msk >> 1]][i], 0);
        }
    }
    for (int d = 1; d < D; ++ d) {
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < m; ++ j) {
                for (int k = 0; k < m; ++ k) {
                    update(trans[d][i][j], trans[d - 1][i][k] + trans[d - 1][k][j]);
                }
            }
        }
    }
    int now = 1;
    int cur = 0;
    for (int i = 0; i < m; ++ i) {
        dp[cur][i] = INF;
    }
    LL& tmp = dp[cur][idx[(1 << x) - 1]] = 0;
    for (int i = 0; i < q; ++ i) {
        if (s[i].first > n - x + 1) {
            tmp += s[i].second;
        }
    }
    for (int t = 0; t < q && s[t].first <= n - x + 1; ++ t) {
        int cnt = s[t].first - now;
        for (int d = D - 1; d >= 0; -- d) {
            if (cnt >> d & 1) {
                cur ^= 1;
                for (int i = 0; i < m; ++ i) {
                    LL& tmp = dp[cur][i] = INF;
                    for (int j = 0; j < m; ++ j) {
                        update(tmp, trans[d][i][j] + dp[cur ^ 1][j]);
                    }
                }
            }
        }
        for (int i = 0; i < m; ++ i) {
            if (dp[cur][i] < INF && (msks[i] & 1)) {
                dp[cur][i] += s[t].second;
            }
        }
        now = s[t].first;
    }
    printf("%lld\n", dp[cur][idx[(1 << x) - 1]]);
}