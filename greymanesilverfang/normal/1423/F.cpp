#include <cstdio>

int solve()
{
    int n, k; scanf("%d%d", &n, &k);
    int sum = 0, mod = 0;
    for (int i = 1; i <= k; ++i)
    {
        int a, b; scanf("%d%d", &a, &b);
        sum = sum + b;
        if (sum > n)
            return -1;
        mod = (mod + 1LL * a * b) % n;
    }
    return sum < n ? 1 : mod == (n % 2 ? 0 : n / 2) ? 1 : -1;
}

int main()
{
    printf("%d\n", solve());
}