#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char num[1000111];
char rem[1000111];
int n,m;
int L;

int ctr[11];

int DigCtr(int k)
{
    if (k==0)
    return 1;

    int ctr=0;

    while(k>0)
    {
        ctr++;
        k/=10;
    }

    return ctr;
}

char answer[1000111];
int aL=0;

char otherans[1000111];
int oL=0;

int main()
{
    int i,j;
    int rL;
    int total=0;
    bool appendfirst=false;
    bool needswap;

    scanf("%s",num+1);
    n=strlen(num+1);

    scanf("%s",rem+1);
    m=strlen(rem+1);

    for (i=1;i<=n;i++)
    {
        ctr[ num[i]-'0' ]++;
    }

    for (L=1;L<=n;L++)
    {
        if (DigCtr(L)+L==n)
        break;
    }

    if (DigCtr(L)+m==n)
    {
        for (i=1;i<=m;i++)
        {
            printf("%c",rem[i]);
        }
        printf("\n");

        return 0;
    }

    rL=L;

    while(rL>0)
    {
        ctr[rL%10]--;
        rL/=10;
    }

    for (i=1;i<=m;i++)
    {
        ctr[ rem[i]-'0' ]--;
    }

    for (i=2;i<=m;i++)
    {
        if (rem[i]<rem[1])
        {
            appendfirst=true;
            break;
        }
        else if (rem[i]>rem[1])
        {
            appendfirst=false;
            break;
        }
    }

    if (rem[1]!='0')
    {
        for (i=1;i<=m;i++)
        {
            oL++;
            otherans[oL]=rem[i]-'0';
        }

        for (i=0;i<=9;i++)
        {
            for (j=1;j<=ctr[i];j++)
            {
                oL++;
                otherans[oL]=i;
            }
        }
    }

    for (i=1;i<=9;i++)
    {
        if (ctr[i]>0)
        {
            aL++;
            answer[aL]=i;
            ctr[i]--;

            break;
        }
    }

    if (i==10)
    {
        for (i=1;i<=oL;i++)
        {
            printf("%d",otherans[i]);
        }
        printf("\n");

        return 0;
    }

    for (i=0;i<=9;i++)
    {
        if (appendfirst && i==rem[1]-'0')
        {
            for (j=1;j<=m;j++)
            {
                aL++;
                answer[aL]=rem[j]-'0';
            }
        }

        for (j=1;j<=ctr[i];j++)
        {
            aL++;
            answer[aL]=i;
        }

        if (!appendfirst && i==rem[1]-'0')
        {
            for (j=1;j<=m;j++)
            {
                aL++;
                answer[aL]=rem[j]-'0';
            }
        }
    }

    if (aL>0 && oL>0)
    {
        needswap=false;

        for (i=1;i<=aL;i++)
        {
            if (answer[i]<otherans[i])
            break;
            else if (answer[i]>otherans[i])
            {
                needswap=true;
                break;
            }
        }

        if (needswap)
        {
            for (i=1;i<=aL;i++)
            {
                answer[i]=otherans[i];
            }
        }
    }

    for (i=1;i<=aL;i++)
    {
        printf("%d",answer[i]);
    }
    printf("\n");

    return 0;
}