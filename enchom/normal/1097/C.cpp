#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n;
char seq[500111];

int corrects = 0;
int seconds[500111];
int firsts[500111];

int MIN(int a,int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    int i,j;
    int ans = 0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%s",seq+1);
        int L = strlen(seq+1);

        int sum = 0;
        int smallest = 0;
        for (j=1;j<=L;j++)
        {
            if (seq[j] == '(')
                sum++;
            else
                sum--;

            if (sum < smallest)
                smallest = sum;
        }

        if (sum == 0 && smallest == 0) ///Correct
        {
            corrects++;
        }
        else if (sum < 0)
        {
            if (smallest == sum)
            {
                seconds[-sum]++;
            }
        }
        else if (sum > 0)
        {
            if (smallest == 0)
            {
                firsts[sum]++;
            }
        }
    }

    ans = corrects / 2;

    for (i=1;i<=500000;i++)
    {
        ans += MIN(firsts[i], seconds[i]);
    }

    printf("%d\n",ans);
}