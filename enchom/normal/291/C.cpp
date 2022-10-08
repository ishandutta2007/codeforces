#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long Int;

char str[101];
Int Nums[100001][33];
Int SubnetMask[33];
Int networks[100001];
Int n;
Int PowerOf2[51];

Int global;

void PrintMask()
{
    Int i;
    Int total=0;
    Int thepower=0;

    total=0;
    thepower=0;
    for (i=8;i>=1;i--)
    {
        total=total+(PowerOf2[thepower]*SubnetMask[i]);
        thepower++;
    }
    printf("%I64d.",total);
    //////////////////////////////////////////////////////
    total=0;
    thepower=0;
    for (i=16;i>=9;i--)
    {
        total=total+(PowerOf2[thepower]*SubnetMask[i]);
        thepower++;
    }
    printf("%I64d.",total);
    //////////////////////////////////////////////////////
    total=0;
    thepower=0;
    for (i=24;i>=17;i--)
    {
        total=total+(PowerOf2[thepower]*SubnetMask[i]);
        thepower++;
    }
    printf("%I64d.",total);
    /////////////////////////////////////////////////////
    total=0;
    thepower=0;
    for (i=32;i>=25;i--)
    {
        total=total+(PowerOf2[thepower]*SubnetMask[i]);
        thepower++;
    }
    printf("%I64d\n",total);

    return;
}

Int GetNetwork(Int amask[])
{
    Int i;
    Int total=0;
    Int thepower=0;

    for (i=32;i>=1;i--)
    {
        total=total+(amask[i]*PowerOf2[thepower]);
        thepower++;
    }

    return total;
}

Int Different()
{
    Int myresult[33];
    Int i,j;
    Int ctr=1;

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=32;j++)
        {
            myresult[j]=SubnetMask[j]&Nums[i][j];
        }

        networks[i]=GetNetwork(myresult);
    }

    sort(networks+1,networks+1+n);

    for (i=2;i<=n;i++)
    {
        if (networks[i]!=networks[i-1])
        {
            ctr++;
        }
    }

    return ctr;
}

Int INT(char ch)
{
    return (Int)ch - (Int)'0';
}

void Add(Int num,Int k,Int s,Int e)
{
    Int i;

    for (i=e;i>=s;i--)
    {
        Nums[k][i]=num%2;
        num=num/2;
    }

    return;
}

void Create32BitNum(Int k)
{
    Int L=strlen(str);
    Int uk;
    Int num=0;
    Int ctr=0;

    uk=0;

    while(uk<L)
    {
        if (str[uk]=='.')
        {
            ctr++;
            Add(num,k,8*ctr-7,8*ctr);
            num=0;
        }
        else
        {
            num=num*10 + INT(str[uk]);
        }

        uk++;
    }

    Add(num,k,25,32);

    return;
}

int main()
{
    Int k;
    Int ctr;
    Int i,j;

    scanf("%I64d %I64d",&n,&k);

    PowerOf2[0]=1;
    for (i=1;i<=50;i++)
    {
        PowerOf2[i]=PowerOf2[i-1]*2;
    }

    for (i=1;i<=n;i++)
    {
        scanf("%s",str);
        Create32BitNum(i);
    }

    for (i=1;i<=32;i++)
    {
        SubnetMask[i]=0;
    }

    for (i=1;i<=31;i++)
    {
        SubnetMask[i]=1;

        global=i;

        ctr=Different();

        if (ctr==k)
        {
            PrintMask();
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}