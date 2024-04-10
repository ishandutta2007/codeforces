#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

const Int INF=1000000000000000000LL;
int arr[300111];
int n,k;
int len1=0,len2=0;
int ctr1=0,ctr2=0;

Int F[5011][5011];

inline Int MIN(Int a,Int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int main()
{
    int i,j;
    int c;
    int begg,endd;

    scanf("%d %d",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }

    sort(arr+1,arr+1+n);

    for (i=1;i<=k;i++)
    {
        c=0;
        for (j=i;j<=n;j+=k)
        {
            c++;
        }

        if (len1==0)
        {
            len1=c;
            ctr1++;
        }
        else
        {
            if (len1==c)
            ctr1++;
            else
            {
                len2=c;
                ctr2++;
            }
        }
    }

    for (i=ctr1;i>=0;i--)
    {
        for (j=ctr2;j>=0;j--)
        {
            begg=i*len1+j*len2+1;

            if (begg>n)
            {
                F[i][j]=0;
                continue;
            }

            F[i][j]=INF;

            if (i<ctr1) ///Use first
            {
                endd=(i+1)*len1+j*len2;
                F[i][j]=F[i+1][j]+(Int)(arr[endd]-arr[begg]);
            }

            if (j<ctr2) ///Use second
            {
                endd=i*len1+(j+1)*len2;
                F[i][j]=MIN(F[i][j], F[i][j+1]+(Int)(arr[endd]-arr[begg]) );
            }
        }
    }

    printf("%lld\n",F[0][0]);

    return 0;
}