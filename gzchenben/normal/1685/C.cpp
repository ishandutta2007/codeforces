#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, t, a[200005], F[200005];
char ch[200005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++)
        {
            scanf(" %c", &ch[i]);
            a[i] = (ch[i] == '(' ? 1 : -1);
            F[i] = F[i - 1] + a[i];
        }
        int pos1 = 1, pos2 = 2 * n, Maxn1 = 0, Maxn2 = 0;
        while (F[pos1] >= 0 && pos1 <= 2 * n)
        {
            if (F[pos1] >= F[Maxn1])
                Maxn1 = pos1;
            pos1++;
        }
        if (pos1 == 2 * n + 1)
        {
            printf("0\n");
            continue;
        }
        while (F[pos2] >= 0 && pos2 >= 1)
        {
            if (F[pos2] >= F[Maxn2])
                Maxn2 = pos2;
            pos2--;
        }
        reverse(a + Maxn1 + 1, a + Maxn2 + 1);
        bool flag = false;
        for (int i = 1; i <= 2 * n; i++)
        {
            F[i] = F[i - 1] + a[i];
            if (F[i] < 0)
                flag = true;
        }
        if (!flag)
        {
            printf("1\n%d %d\n", Maxn1 + 1, Maxn2);
            continue;
        }
        reverse(a + Maxn1 + 1, a + Maxn2 + 1);
        int maxn = 0;
        for (int i = 1; i <= 2 * n; i++)
        {
            F[i] = F[i - 1] + a[i];
            if (F[i] > F[maxn])
                maxn = i;
        }
        printf("2\n%d %d\n%d %d\n", 1, maxn, maxn + 1, 2 * n);
    }
}