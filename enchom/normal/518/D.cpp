#include <iostream>
#include <stdio.h>
using namespace std;
typedef long double Double;

int n,t;
Double p;

Double F[2011][2011];

int main()
{
    int i,j;
    Double Ans=0.0;

    cin>>n;
    cin>>p;
    cin>>t;

    F[0][0]=1.0;
    for (i=1;i<=n;i++)
    {
        F[i][0]=0.0;
    }

    for (i=1;i<=t;i++)
    {
        F[0][i]=F[0][i-1]*(1.0-p);
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=t;j++)
        {
            ///i people inside at second j
            if (i!=n)
            F[i][j]=F[i][j-1]*(1.0-p) + F[i-1][j-1]*p;
            else
            F[i][j]=F[i][j-1]+F[i-1][j-1]*p;

            //cout<<"F["<<i<<"]["<<j<<"]="<<F[i][j]<<endl;
        }
    }

    for (i=1;i<=n;i++)
    {
        Ans=Ans+F[i][t]*(Double)i;
    }

    printf("%.7f\n",(double)Ans);

    return 0;
}