#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char num[100001];
int L;
int ctr=0;

bool Check(int k)
{
    int i;

    for (i=1;i<=k/2;i++)
    {
        if (num[i]>num[i+k/2])
        return true;
        else if (num[i]<num[i+k/2])
        return false;
    }

    return true;
}

void Solve(int k)
{
    int i;

    for (i=k;i>=(k+1)/2+1;i--)
    {
        if (num[i]!='0')
        {
            if (k%2==0 && i==k/2+1)
            {
                if (Check(k))
                {
                    ctr++;
                    Solve(i-1);
                    return;
                }
            }
            else
            {
                ctr++;
                Solve(i-1);
                return;
            }
        }
    }

    ctr++;

    return;
}

int main()
{
    scanf("%s",num+1);
    L=strlen(num+1);

    Solve(L);

    printf("%d\n",ctr);

    return 0;
}