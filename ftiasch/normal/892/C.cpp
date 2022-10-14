#include <algorithm>
#include <cstdio>

const int N = 2000;

int n, a[N];

int work()
{
    scanf("%d", &n);
    int ones = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
        ones += a[i] == 1;
    }
    if (ones > 0) {
        return n - ones;
    }
    int result = n;
    for (int i = 0; i < n; ++ i) {
        int g = 0;
        for (int j = i; j < n; ++ j) {
            g = std::__gcd(g, a[j]);
            if (g == 1) {
                result = std::min(j - i, result);
                break;
            }
        }
    }
    if (result == n) {
        return -1;
    }
    return result + n - 1;
}

int main()
{
    printf("%d\n", work());
}