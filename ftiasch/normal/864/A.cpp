#include <algorithm>
#include <cstdio>

const int N = 100;

int a[N];

int main()
{
#ifdef LOCAL_JUDGE
    freopen("A.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    std::sort(a, a + n);
    int n2 = n / 2;
    bool ok = a[n2 - 1] != a[n2];
    for (int i = 0; i < n2; ++ i) {
        ok &= a[i] == a[0];
        ok &= a[i + n2] == a[n2];
    }
    if (ok) {
        puts("Yes");
        printf("%d %d\n", a[n2 - 1], a[n2]);
    } else {
        puts("No");
    }
}