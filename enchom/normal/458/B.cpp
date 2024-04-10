#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int n,m;
int a[100001];
int b[100001];

Int MIN(Int a,Int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int main()
{
    int i,j;
    Int suma=0,sumb=0;
    int maxnuma=-1,maxnumb=-1;
    int ida,idb;
    Int ans1=0,ans2=0;

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);

        if (maxnuma<a[i])
        {
            maxnuma=a[i];
            ida=i;
        }

        suma+=(Int)a[i];
    }

    for (i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);

        if (maxnumb<b[i])
        {
            maxnumb=b[i];
            idb=i;
        }

        sumb+=(Int)b[i];
    }

    ///Pick A side
    for (i=1;i<=n;i++)
    {
        if (i==ida)
        ans1+=sumb;
        else
        ans1+=MIN(sumb,a[i]);
    }

    ///Pick B side
    for (i=1;i<=m;i++)
    {
        if (i==idb)
        ans2+=suma;
        else
        ans2+=MIN(suma,b[i]);
    }

    printf("%I64d\n",MIN(ans1,ans2));

    return 0;
}