#include <cstdio>
using namespace std;
int n, m, t, a[55], b[55];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            char tmp;
            scanf(" %c", &tmp);
            a[i] = tmp - '0';
        }
        bool flag1 = true, flag2 = true;
        for (int i = 1; i <= m; i++)
        {
            char tmp;
            scanf(" %c", &tmp);
            b[i] = tmp - '0';
            if (i != 1 && a[n - (m - i)] != b[i])
                flag1 = false;
        }

        for (int i = 1; i <= n - m + 1; i++)
        {
            if (a[i] == b[1])
                flag2 = false;
        }
        printf((flag1 && !flag2) ? "Yes\n" : "No\n");
    }
}