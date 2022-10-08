#include <iostream>
#include <stdio.h>
using namespace std;

const int INF = 1000000000;

int t;
int n;
char a[100111];
char b[100111];

int main()
{
    int i, j;
    int test;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);
        scanf("%s", a + 1);
        scanf("%s", b + 1);

        int c[2][2] = {{0, 0}, {0, 0}};

        for (i=1;i<=n;i++)
        {
            c[ a[i] - '0' ][ b[i] - '0' ]++;
        }

        int ans = INF;
        /// Base case
        if (c[1][0] == c[0][1])
        {
            //printf("Base %d\n", c[0][1]);
            ans = c[0][1] * 2;
        }

        //printf("c11 = %d\n", c[1][1]);

        for (i=1;i<=n;i++)
        {
            if (a[i] == '1')
            {
                int v01 = c[1][1];
                int v10 = c[0][0];

                if (b[i] == '1')
                    v01--;
                else
                    v10++;

                if (v01 == v10)
                {
                    //printf("Flipping %d gives %d\n", i, v01 + 1);
                    ans = min(ans, v01 * 2 + 1);
                }
            }
        }

        if (ans == INF)
            ans = -1;

        printf("%d\n", ans);
    }

    return 0;
}