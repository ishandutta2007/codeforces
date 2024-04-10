#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>

const int N = 1 << 6;

double p[N][N], win[2][N], score[2][N];

double solve(int i, int l, int r)
{
    if (r - l == 1) {
        win[i][l] = 1, score[i][l] = 0;
        return 0;
    }
    auto m = l + r >> 1;
    auto l_max = solve(i ^ 1, l, m);
    auto r_max = solve(i ^ 1, m, r);
    for (int j = l; j < r; ++ j) {
        win[i][j] = 0;
        for (int k = l; k < r; ++ k) {
            if ((j < m) != (k < m)) {
                win[i][j] += win[i ^ 1][j] * win[i ^ 1][k] * p[j][k];
            }
        }
        score[i][j] = win[i][j] * (m - l) + score[i ^ 1][j] + (j < m ? r_max : l_max);
    }
    return *std::max_element(score[i] + l, score[i] + r);
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("D.in", "r", stdin);
#endif
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < 1 << n; ++ i) {
            for (int j = 0, x; j < 1 << n; ++ j) {
                scanf("%d", &x);
                p[i][j] = x / 100.0;
            }
        }
        printf("%.9f\n", solve(0, 0, 1 << n));
    }
}