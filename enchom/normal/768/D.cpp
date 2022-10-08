#include <iostream>
#include <stdio.h>
using namespace std;
typedef long double Double;

Double F[2][1111];
Double WinChance[100111];
int k,q;
int DAYS;
Double EPS=0.0000001;
Double Wanted;

int main()
{
    int i,j;
    int cur,op;
    int p;
    int n;
    int l,r,mid,best;

    scanf("%d %d",&k,&q);

    F[0][0]=1.0;
    for (i=1;i<=k;i++)
    {
        F[0][i]=0.0;
    }

    for (i=1;;i++)
    {
        cur=i%2;
        op=cur^1;

        F[cur][0]=0.0;
        for (j=1;j<=k;j++)
        {
            F[cur][j]=F[op][j]*( (Double)j/(Double)k )+F[op][j-1]*( (Double)(k-j+1)/(Double)k );
        }

        WinChance[i]=F[cur][k];

        n=i;

        if (F[cur][k]>0.5)
        break;
    }

    for (i=1;i<=q;i++)
    {
        scanf("%d",&p);

        Wanted=((Double)p-EPS)/2000.0;

        l=1;
        r=n;

        while(l<=r)
        {
            mid=(l+r)/2;

            if (WinChance[mid]>Wanted)
            {
                best=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        printf("%d\n",best);
    }

    return 0;
}