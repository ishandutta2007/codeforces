#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char str[100111];
int n;

bool overflow[100111];

int arr[100111];

bool Try(bool of)
{
    int i;
    int val;
    int rem,sum;

    memset(overflow,false,sizeof(overflow));
    overflow[n+1]=false;

    if (!of)
    {
        overflow[1]=false;
        overflow[n]=false;
    }

    if (of)
    {
        if (str[1]!='1')
        return false;

        for (i=1;i<n;i++)
        {
            str[i]=str[i+1];
        }
        n--;

        overflow[1]=true;
        overflow[n]=true;
    }

    for (i=1;i<=n/2;i++)
    {
        if (str[i]!=str[n-i+1])
        {
            overflow[i+1]=!overflow[n-i+2];
            overflow[n-i]=overflow[i+1];

            if (str[i]=='0' && str[n-i+1]=='9')
            {
                overflow[n-i+1]=false;
            }

            if (str[i]=='9' && str[n-i+1]=='0')
            {
                overflow[n-i+1]=true;
            }
        }
        else
        {
            overflow[i+1]=overflow[n-i+2];
            overflow[n-i]=overflow[i+1];
        }
    }

    for (i=1;i<=n/2;i++)
    {
        if (str[i]=='9' && str[n-i+1]=='0')
        {
            overflow[i]=false;
        }
    }

    if (n%2==1)
    {
        val=str[(n+1)/2]-'0';
        if (overflow[(n+1)/2])
        val+=10;
        if (overflow[(n+1)/2+1])
        val--;

        if (val<0 || val%2==1)
        return false;
    }

    for (i=1;i<=(n+1)/2;i++)
    {
        val=str[i]-'0';
        if (overflow[i])
        val+=10;
        if (overflow[i+1])
        val--;

        if (val<0)
        return false;

        arr[i]=val/2;
        arr[n-i+1]=val-arr[i];

        if (arr[i]>9 || arr[n-i+1]>9)
        return false;
    }

    rem=0;
    sum=0;
    for (i=n;i>=1;i--)
    {
        sum=arr[i]+arr[n-i+1]+rem;
        rem=sum/10;
        sum%=10;

        if (sum!=str[i]-'0')
        return false;
    }

    if (!of && rem!=0)
    {
        return false;
    }

    if (of && rem!=1)
    return false;

    if (arr[1]!=0)
    {
        for (i=1;i<=n;i++)
        {
            printf("%d",arr[i]);
        }
        printf("\n");
    }
    else if (arr[n]!=0)
    {
        for (i=n;i>=1;i--)
        {
            printf("%d",arr[i]);
        }
        printf("\n");
    }
    else
    {
        return false;
    }


    return true;
}

int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);

    if (!Try(false))
    {
        if (!Try(true))
        {
            printf("0\n");
        }
    }

    return 0;
}