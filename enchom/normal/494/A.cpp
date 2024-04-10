#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char str[200001];
int n;
int sum=0;

int main()
{
    int i;
    int lastplace=-1;
    int cansub;
    int newtry;

    scanf("%s",str+1);
    n=strlen(str+1);

    for (i=n;i>=1;i--)
    {
        if (str[i]=='#')
        {
            lastplace=i;
            break;
        }
    }

    for (i=1;i<=lastplace;i++)
    {
        if (str[i]=='(')
        {
            sum++;
        }
        else if (str[i]==')')
        {
            sum--;
        }
        else
        {
            sum--;
        }

        if (sum<0)
        {
            printf("-1\n");
            return 0;
        }
    }

    cansub=sum;

    for (i=lastplace+1;i<=n;i++)
    {
        if (str[i]=='(')
        {
            sum++;
        }
        else if (str[i]==')')
        {
            sum--;
        }

        if (sum<0)
        {
            printf("-1\n");
            return 0;
        }
    }

    if (sum>cansub)
    {
        printf("-1\n");
        return 0;
    }

    newtry=cansub-sum;

    for (i=lastplace+1;i<=n;i++)
    {
        if (str[i]=='(')
        newtry++;
        else if (str[i]==')')
        newtry--;

        if (newtry<0)
        {
            printf("-1\n");
            return 0;
        }
    }

    for (i=1;i<lastplace;i++)
    {
        if (str[i]=='#')
        {
            printf("1\n");
        }
    }

    printf("%d\n",sum+1);

    return 0;
}