#include <stdio.h>

using namespace std;

const int mx = 1e5;
int n, a[mx + 1] = {0};

int main(void)
{
    int i, k;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &k);
        if ((i <= n / 2) && (k - i + 1 > 0))
            ++a[k - i + 1];
        if ((i > n / 2) && (k - n + i > 0))
            ++a[k - n + i];
    }
    int min = n;
    for (i = 1; i <= mx; ++i)
        if (n - a[i] < min)
            min = n - a[i];
    printf("%d", min);
    return 0;
}