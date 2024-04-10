#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

#define ALL(v) (v).begin(), (v).end()

const int N = 31;
const int B = 1000000;
const int INV_B = 616898040;
const int MOD = 998244353;

int inv[N], n, m, a[N], values[N * N], size[N * N], sum[N * N], coef[N * N][N];

int find(int a)
{
    return std::find(values, values + (n * m + 1), a) - values;
}

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main()
{
    inv[1] = 1;
    for (int i = 2; i < N; ++ i) {
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
#ifdef LOCAL_JUDGE
    freopen("H.in", "r", stdin);
#endif
    scanf("%d", &n);
    std::vector<int> fractions { 0 };
    for (int i = 0; i < n; ++ i) {
        double x;
        scanf("%lf", &x);
        a[i] = (int)(x * B + 0.5);
        fractions.push_back(a[i] % B);
    }
    std::sort(ALL(fractions));
    fractions.erase(std::unique(ALL(fractions)), fractions.end());
    m = fractions.size();
    for (int i = n * m; i >= 0; -- i) {
        values[i] = (i / m) * B + fractions[i % m];
        if (i < n * m) {
            size[i] = 1LL * (values[i + 1] - values[i]) * INV_B % MOD;
        }
    }
    for (int i = std::min(find(a[0]), m) - 1; i >= 0; -- i) {
        sum[i] = size[i];
        coef[i][1] = 1;
    }
    for (int i = 1; i < n; ++ i) {
        int cut = find(a[i]);
        for (int j = n * m - 1; j >= 0; -- j) {
            if (j < cut) {
                for (int k = j - 1; k >= 0 && k >= j - m; -- k) {
                    update(coef[j][0], sum[k]);
                }
                if (j >= m) {
                    for (int k = 0; k <= n; ++ k) {
                        update(coef[j][k], MOD - coef[j - m][k]);
                    }
                }
                for (int k = n - 1; k >= 0; -- k) {
                    coef[j][k + 1] = 1LL * coef[j][k] * inv[k + 1] % MOD;
                }
                coef[j][0] = 0;
                sum[j] = 0;
                for (int k = n; k >= 0; -- k) {
                    sum[j] = (1LL * sum[j] * size[j] + coef[j][k]) % MOD;
                }
            } else {
                sum[j] = 0;
                memset(coef[j], 0, sizeof(coef[j]));
            }
        }
    }
    int result = 0;
    for (int j = 0; j < n * m; ++ j) {
        update(result, sum[j]);
    }
    printf("%d\n", result);
}