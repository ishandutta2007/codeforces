#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int n;
char s[500111];
int L;

bool seen[256];

int main()
{
    int i, j;

    scanf("%d", &n);

    for (i=1;i<=n;i++)
    {
        memset(seen, false, sizeof(seen));

        scanf("%s", s+1);
        L = strlen(s+1);

        int cutoff = L;
        for (j=L;j>=1;j--)
        {
            if (!seen[ s[j] ])
            {
                cutoff = j;
                seen[ s[j] ] = true;
            }
        }

        for (j=cutoff;j<=L;j++)
        {
            printf("%c", s[j]);
        }
        printf("\n");
    }

    return 0;
}