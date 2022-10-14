#include <cstdio>
#include <vector>

int main()
{
    int a, b, f_, k;
    scanf("%d%d%d%d", &a, &b, &f_, &k);
    long long f = f_;
    long long x = a;
    std::vector<long long> p { 0LL, f };
    for (int i = 1; i < k; ++ i) {
        f = 2 * x - f;
        p.push_back(f);
        x += a;
    }
    p.push_back(x);
    std::vector<int> dp(p.size());
    for (int i = p.size() - 2, j = (int)p.size() - 1; i >= 0; -- i) {
        while (p[j] - p[i] > b) {
            j --;
        }
        if (i == j) {
            puts("-1");
            return 0;
        }
        dp[i] = dp[j] + 1;
    }
    printf("%d\n", dp[0] - 1);
}