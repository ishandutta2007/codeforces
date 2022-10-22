#include <cstdio>
#include <algorithm>
using namespace std;
int n, t, a[100005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        if (n % 2 == 1)
        {
            printf("NO\n");
            continue;
        }
        sort(a + 1, a + n + 1);
        int cnt1 = 0, cnt2 = 0;
        for (int i = n / 2; i >= 1; i--)
        {
            if (a[i] == a[i + 1])
                cnt1++;
            else break;
        }
        for (int i = n / 2 + 1; i <= n; i++)
        {
            if (a[i] == a[i - 1])
                cnt2++;
            else break;
        }
        if (cnt1 + cnt2 >= n / 2)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for (int i = 1; i <= n / 2; i++)
        {
            printf("%d %d ", a[i], a[i + n / 2]);
        }
        printf("\n");
    }
}