#include <algorithm>
#include <cstdio>
#include <climits>

const int N = 100000;

int x[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", x + i);
    }
    for (int i = 0; i < n; ++ i) {
        int min = INT_MAX;
        if (i) {
            min = std::min(min, x[i] - x[i - 1]);
        }
        if (i + 1 < n) {
            min = std::min(min, x[i + 1] - x[i]);
        }
        int max = std::max(x[i] - x[0], x[n - 1] - x[i]);
        printf("%d %d\n", min, max);
    }
    return 0;
}