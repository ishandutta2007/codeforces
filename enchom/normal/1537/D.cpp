#include <stdio.h>
using namespace std;

bool win[1011];

int main()
{
    int i, j;
    int t, n;

    scanf("%d", &t);

    for (i=1;i<=t;i++)
    {
        scanf("%d", &n);

        if (n % 2 == 1)
            printf("Bob\n");
        else
        {
            int p2 = 0;
            while(n % 2 == 0)
            {
                n /= 2;
                p2++;
            }

            if (n != 1)
                printf("Alice\n");
            else
            {
                if (p2 % 2 == 1)
                    printf("Bob\n");
                else
                    printf("Alice\n");
            }
        }
    }

    /*for (i=1;i<=10000;i++)
    {
        win[i] = false;
        for (j=2;j<i;j++)
        {
            if (i % j == 0 && !win[i - j])
                win[i] = true;
        }

        if (!win[i] && i % 2 == 0)
            printf("%d\n", i);
    }*/
}