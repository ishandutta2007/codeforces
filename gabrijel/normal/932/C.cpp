#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i * a <= n; i++)
    {
        if ((n - i * a) % b == 0)
        {
            int poz = 1, pocpoz;
            for (int j = 0; j < i; j++)
            {
                pocpoz = poz;
                for (int k = 0; k < a - 1; k++)
                {
                    printf("%d ", poz + 1);
                    poz++;
                }
                poz++;
                printf("%d ", pocpoz);
            }
            for (int j = 0; j < (n - i * a) / b; j++)
            {
                pocpoz = poz;
                for (int k = 0; k < b - 1; k++)
                {
                    printf("%d ", poz + 1);
                    poz++;
                }
                poz++;
                printf("%d ", pocpoz);
            }
            return 0;
        }
    }
    printf("-1");
    return 0;
}