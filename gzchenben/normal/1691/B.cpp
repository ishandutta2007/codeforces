#include <cstdio>
#include <algorithm>
using namespace std;
int n, t, a[100005], ans[100005];
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
        a[n+1] = 0;
        bool flag = true;
        int lst = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == a[i + 1])
                continue;
            if (i - lst == 1)
            {
                flag = false;
                break;
            }
            ans[i] = lst + 1;
            for (int j = lst + 1; j < i; j++)
            {
                ans[j] = j + 1;
            }
            lst = i;
        }
        if (!flag)
            printf("-1\n");
        else
        {
            for (int i = 1; i <= n; i++)
                printf("%d ", ans[i]);
            printf("\n");
        }
    }
}