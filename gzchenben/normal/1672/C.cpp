#include <cstdio>
#include <cstring>
using namespace std;
int n, t, a[200005];
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
        int fir = 0, lst = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == a[i - 1])
            {
                if (fir == 0)
                    fir = i;
                lst = i;
            }
        }
        if (fir == lst)
            printf("0\n");
        else if (fir == lst - 1)
            printf("1\n");
        else
            printf("%d\n", lst - fir - 1);
    }
}