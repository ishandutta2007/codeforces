#include <algorithm>
#include <cstdio>

const int N = 22;

int a[N], b[N], order[N];

bool by_a(int i, int j)
{
    return a[i] < a[j];
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
        order[i] = i;
    }
    std::sort(order, order + n, by_a);
    for (int i = 0; i < n; ++ i) {
        b[order[(i + 1) % n]] = a[order[i]];
    }
    for (int i = 0; i < n; ++ i) {
        printf("%d%c", b[i], " \n"[i == n - 1]);
    }

}