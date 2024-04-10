#include <cstdio>

/*
 * NOTE:
 * ans = prod{a_i} - sum_{x_1 + x_2 + ... + x_n = k} prod{(a_i - x_i) / x_i!} * k! / n^k
 *
 * sum_x (a - x) / x! = (a - x) * e^x
 * => prod{(a - x) * e^x} = (sum_{i = 0}^n c_i x^i) e^{nx}
 */
const int N = 5000;
const int MOD = (int)1e9 + 7;

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int pow(int a, int n)
{
    int result = 1;
    while (n) {
        if (n & 1) {
            result = 1LL * result * a % MOD;
        }
        a = 1LL * a * a % MOD;
        n >>= 1;
    }
    return result;
}

int n, k, coef[N + 1];


int main()
{
#ifdef LOCAL_JUDGE
    freopen("E.in", "r", stdin);
#endif
    scanf("%d%d", &n, &k);
    coef[0] = 1;
    int pd = 1;
    for (int i = 0, a; i < n; ++ i) {
        scanf("%d", &a);
        pd = 1LL * pd * a % MOD;
        for (int j = i + 1; j >= 1; -- j) {
            coef[j] = ((MOD - 1LL) * coef[j - 1] + 1LL * a * coef[j]) % MOD;
        }
        coef[0] = 1LL * a * coef[0] % MOD;
    }
    int fact = 1;
    int norm = pow(pow(n, MOD - 2), k);
    int result = 0;
    for (int i = 0; i <= n && i <= k; ++ i) {
        // k - i
        // (n x)^{k - i} / (k - i)!
        update(result, 1LL * coef[i] * fact % MOD * pow(n, k - i) % MOD);
        fact = 1LL * fact * (k - i) % MOD;
    }
    result = 1LL * result * norm % MOD;
    update(pd, MOD - result);
    printf("%d\n", pd);
}