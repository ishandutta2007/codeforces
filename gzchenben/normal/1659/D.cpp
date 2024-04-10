// C i
// Ai*(i-1) + f(5,A,5) + f(6,A,5) + ... + f(n,A,5);
#include <cstdio>
using namespace std;
int n, t, c[200005], lst[200005], a[200005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        bool flag = true;
        for (int i = 1; i <= n; i++)
            a[i] = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &c[i]);
            if (flag && c[i] != 0)
            {
                flag = false;
            }
            if (flag)
            {
                a[i] = 0;
                lst[i] = i;
            }
            else
            {
                c[i] -= a[i] * (i - 1);
                lst[i] = i + c[i];
                a[lst[i]] = 0;
            }
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}