#include <iostream>
#include <stdio.h>
using namespace std;

int t;
int n;
int a[200111];
int b[200111];
int g[200111];
int is1, is0;

void moveEm(int ind)
{
    is0 = max(is0, ind);
    is1 = max(is1, ind);

    while(is0 <= n && b[is0] != 0)
        is0++;
    while(is1 <= n && b[is1] != 1)
        is1++;
}

int tryMatch()
{
    int i, j;
    int ans = 0;

    //printf("\nTrying\n");

    for (i=1;i<=n;i++)
    {
        //printf("%d ", g[i]);
        b[i] = a[i];
    }

    /*
    printf("\nvs\n");
    for (i=1;i<=n;i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    */


    is0 = 1;
    is1 = 1;
    moveEm(1);

    for (i=1;i<=n;i++)
    {
        if (g[i] == 0)
        {
            if (is0 > n)
                return -1;

            //printf("Found 0 at %d\n", is0);

            ans += is0 - i;
            swap(b[i], b[is0]);

            moveEm(i + 1);
        }
        else
        {
            if (is1 > n)
                return -1;

            //printf("Found 1 at %d\n", is1);

            ans += is1 - i;
            swap(b[i], b[is1]);

            moveEm(i + 1);
        }
    }

    //printf("Result: %d\n", ans);

    return ans;
}

int main()
{
    //freopen("test.txt", "r", stdin);

    int i, j;
    int test;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        for (i=1;i<=n;i++)
        {
            scanf("%d", &a[i]);
            a[i] %= 2;
        }

        int ans = -1;

        for (i=1;i<=n;i++)
        {
            g[i] = i % 2;
        }

        int att = tryMatch();

        if (att != -1)
            ans = att;

        for (i=1;i<=n;i++)
        {
            g[i] = (i + 1) % 2;
        }

        att = tryMatch();

        if (ans == -1 || (att != -1 && att < ans))
        {
            ans = att;
        }

        printf("%d\n", ans);
    }

    return 0;
}