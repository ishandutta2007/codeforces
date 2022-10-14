#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 200000;

int x[N], xx[N + 2];

bool check(int n, int k, int a, int m)
{
    memcpy(xx + 1, x, sizeof(*x) * m);
    xx[0] = -1;
    xx[m + 1] = n;
    std::sort(xx, xx + m + 2);
    int result = 0;
    for (int i = 1; i <= m + 1; ++ i) {
        int l = xx[i] - xx[i - 1] - 1;
        if (l >= a) {
            result += (l + 1) / (a + 1);
        }
    }
    return result >= k;
}

int main()
{
    int n, k, a, m;
    scanf("%d%d%d%d", &n, &k, &a, &m);
    for (int i = 0; i < m; ++ i) {
        scanf("%d", x + i);
        x[i] --;
    }
    int low  = 0;
    int high = m;
    while (low < high) {
        int middle = low + high + 1 >> 1;
        if (check(n, k, a, middle)) {
            low = middle;
        } else {
            high = middle - 1;
        }
    }
    printf("%d\n", low == m ? -1 : low + 1);
    return 0;
}