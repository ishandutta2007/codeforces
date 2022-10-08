#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int t;
int n, k;
int counts[31];
char str[100111];
int letters[100111];

int main()
{
    //freopen("test.txt", "r", stdin);
    int test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d", &n, &k);

        scanf("%s", str);

        int capped = n / k;

        memset(counts, 0, sizeof(counts));
        for (i=0;i<n;i++)
        {
            counts[ str[i] - 'a' ]++;
        }

        for (i=1;i<=k;i++)
        {
            letters[i] = 0;
        }

        for (i=0;i<25;i++)
        {
            for (j=1;j<=k;j++)
            {
                if (letters[j] == i && counts[i] > 0 && letters[j] < capped)
                {
                    letters[j]++;
                    counts[i]--;
                }
            }
        }

        for (i=1;i<=k;i++)
        {
            printf("%c", letters[i] + 'a');
        }
        printf("\n");
    }

    return 0;
}