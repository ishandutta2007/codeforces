#include <stdio.h>

using namespace std;

const int maxn = 1000000, mask = (1 << 22) - 1;

int n, i, j, a[maxn], r = -1, t;
int ans[mask + 1], q[mask + 1], qans[mask + 1];
bool ex[mask + 1];

int main(void)
{
    scanf("%d", &n);
    for (i = 0; i <= mask; i++)
    {
        ans[i] = -1;
        ex[i] = false;
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        if (!ex[a[i]])
        {
            ex[a[i]] = true;
            q[++r] = mask & (~a[i]);
            qans[r] = a[i];
            ans[q[r]] = a[i];
        }
    }
    ans[0] = 1;
    for (i = 0; i <= r; ++i)
    {
        for (j = 1; j <= q[i]; j <<= 1)
            if ((q[i] & j) && (ans[q[i] ^ j] == -1))
            {
                q[++r] = q[i] ^ j;
                ans[q[r]] = qans[r] = qans[i];
            }
    }
    for (i = 0; i < n; i++)
        printf("%d ", ans[a[i]]);
    return 0;
}