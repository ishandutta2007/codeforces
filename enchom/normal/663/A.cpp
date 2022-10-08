#include <iostream>
#include <stdio.h>
using namespace std;

int n=0;
bool positive[100111];

char s[3];
int totalpos=0;
int totalneg=0;
int vals[100111];

int main()
{
    int i;
    bool pos=true;
    int result;
    int sum=0;

    s[0]=0;
    while(s[0]!='=')
    {
        scanf("%s",s);

        if (s[0]=='-')
        {
            pos=false;
        }
        else if (s[0]=='+')
        {
            pos=true;
        }
        else if (s[0]=='?')
        {
            n++;
            positive[n]=pos;

            if (pos)
            totalpos++;
            else
            totalneg++;
        }
    }

    scanf("%d",&result);

    sum=0;
    for (i=1;i<=n;i++)
    {
        if (positive[i])
        {
            sum++;
            vals[i]=1;
        }
        else
        {
            sum-=result;
            vals[i]=result;
        }

    }

    for (i=1;i<=n;i++)
    {
        if (sum==result)
        break;

        if (positive[i])
        {
            if (sum-vals[i]+result<=result)
            {
                sum-=vals[i];
                vals[i]=result;
                sum+=vals[i];
            }
            else
            {
                while(sum<result)
                {
                    vals[i]++;
                    sum++;
                }
            }
        }
        else
        {
            if (sum+vals[i]-1<=result)
            {
                sum+=vals[i]-1;
                vals[i]=1;
            }
            else
            {
                while(sum<result)
                {
                    sum++;
                    vals[i]--;
                }
            }
        }
    }

    if (sum!=result)
    {
        printf("Impossible\n");
        return 0;
    }

    printf("Possible\n");

    for (i=1;i<=n;i++)
    {
        if (i!=1)
        {
            if (positive[i])
            printf(" + %d",vals[i]);
            else
            printf(" - %d",vals[i]);
        }
        else
        {
            printf("%d",vals[i]);
        }
    }

    printf(" = %d\n",result);

    return 0;
}