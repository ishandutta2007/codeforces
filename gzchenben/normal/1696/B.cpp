#include <cstdio>
#include <algorithm>
using namespace std;
int n, t, a[200005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] != 0)
                flag = false;
        }
        if (flag)
        {
            printf("0\n");
            continue;
        }
        int fir = 0, lst = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != 0 && !fir)
                fir = i;
            if (a[i] != 0)
                lst = i;
        }
        flag = true;
        for (int i = fir; i <= lst; i++)
        {
            if (a[i] == 0)
                flag = false;
        }
        if (flag)
            printf("1\n");
        else
            printf("2\n");
    }
}