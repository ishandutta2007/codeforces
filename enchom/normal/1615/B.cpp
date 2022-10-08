#include <iostream>
#include <stdio.h>
using namespace std;

int toremove[19][200111];

int main()
{
    int i, j;

    for (i=0;i<=18;i++)
    {
        toremove[i][0] = 1;
        for (j=1;j<=200000;j++)
        {
            toremove[i][j] = toremove[i][j-1];
            if ( (j & (1 << i)) == 0 )
                toremove[i][j]++;
        }
    }

    int n, l, r;

    scanf("%d", &n);

    for (i=1;i<=n;i++)
    {
        int ans;
        scanf("%d %d", &l, &r);

        ans = r - l;

        for (j=0;j<=18;j++)
        {
            ans = min(ans, toremove[j][r] - toremove[j][l - 1]);
        }

        printf("%d\n", ans);
    }

    return 0;
}