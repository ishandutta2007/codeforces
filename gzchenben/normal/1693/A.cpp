#include <cstdio>
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
        int lst = n + 1;
        for (int i = n; i >= 1; i--)
        {
            if (a[i] == 0)
                lst = i;
            else
                break;
        }
        n = lst - 1;
        long long Now = 0;
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            Now += a[i];
            if (Now <= 0 && i != n)
                flag = false;
            if (i == n && Now != 0)
                flag = false;
        }
        printf(flag ? "yes\n" : "no\n");
    }
}