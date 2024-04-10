#include <stdio.h>
#include <stdlib.h>

using namespace std;

int cmp(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;
    if (*x < *y)
        return -1;
    if (*x == *y)
        return 0;
    return 1;
}

int main()
{
    int n, i, t;
    long long k, z;
    int a[100001];
    scanf("%d%I64d", &n, &k);
    for (i = 0; i < n; i++)
        scanf("%d", a+i);
    qsort(a, n, sizeof(int), cmp);
    a[n] = 1000000001;
    t = 0;
    for (i = 1; i <= n; i++)
        if (a[i] != a[t])
        {
            z = i - t;
            if (z * n < k)
                k -= z * n;
            else
            {
                printf("%d %d", a[t], a[((k - 1) / z) % n]);
                return 0;
            }
            t = i;
        }
    return 0;
}