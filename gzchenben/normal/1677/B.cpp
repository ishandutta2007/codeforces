#include <cstdio>
using namespace std;
int n, m, t, a[1000005], ansR[1000005], ansC[1000005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n * m; i++)
        {
            char tmp;
            scanf(" %c", &tmp);
            a[i] = tmp - '0';
            ansC[i] = ansR[i] = 0;
        }
        int Now = 0;
        for (int i = 1; i <= n * m; i++)
        {
            Now += a[i];
            if (i > m)
                Now -= a[i - m];
            ansR[i] = (Now ? 1 : 0);
        }
        for (int i = m + 1; i <= n * m; i++)
        {
            ansR[i] += ansR[i - m];
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[j * m + i])
                {
                    ansC[j * m + i] = 1;
                    break;
                }
            }
        }
        for (int i = 1; i <= n * m; i++)
        {
            ansC[i] += ansC[i - 1];
            printf("%d ", ansR[i] + ansC[i]);
        }
        printf("\n");
    }
}