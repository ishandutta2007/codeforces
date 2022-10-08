#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int resp[32];
void query(int a, int b)
{
    int AND, OR;

    printf("and %d %d\n", a, b);
    fflush(stdout);
    scanf("%d", &AND);

    printf("or %d %d\n", a, b);
    fflush(stdout);
    scanf("%d", &OR);

    int i;

    for (i=0;i<30;i++)
    {
        if ( (AND & (1<<i)) > 0 )
            resp[i] = 1;
        else if ( (OR & (1<<i)) == 0 )
            resp[i] = 0;
        else
            resp[i] = -1;
    }
}

int responses[10111][32];
int firstNum[32];

int numBits[32];
int nums[10111];

int main()
{
    int i, j;
    int n, k;

    scanf("%d %d", &n, &k);

    memset(firstNum, -1, sizeof(firstNum));
    memset(nums, 0, sizeof(nums));

    for (i=2;i<=n;i++)
    {
        query(1, i);

        for (j=0;j<30;j++)
        {
            responses[i][j] = resp[j];

            if (resp[j] != -1)
                firstNum[j] = resp[j];
        }
    }

    query(2, 3);

    for (j=0;j<30;j++)
    {
        if (firstNum[j] == -1)
        {
            firstNum[j] = (resp[j] ^ 1);
        }

        nums[1] += firstNum[j] * (1<<j);
    }

    for (i=2;i<=n;i++)
    {
        for (j=0;j<30;j++)
        {
            if (responses[i][j] != -1)
                numBits[j] = responses[i][j];
            else
                numBits[j] = firstNum[j] ^ 1;

            nums[i] += numBits[j] * (1<<j);
        }
    }

    /*for (i=1;i<=n;i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");*/

    sort(nums+1,nums+1+n);

    printf("finish %d\n", nums[k]);

    fflush(stdout);

    return 0;
}