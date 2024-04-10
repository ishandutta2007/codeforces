#include <algorithm>
#include <cstdio>

const int N = 100000;

int n, w, a[N << 1];

int main()
{
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n << 1; ++ i) {
        scanf("%d", a + i);
    }
    std::sort(a, a + (n << 1));
    double x = w;
    x = std::min(x, (double)a[0] * 3 * n);
    x = std::min(x, (double)a[n] * 3 * n / 2);
    printf("%.10f\n", x);
    return 0;
}