#include <iostream>
#include <stdio.h>
using namespace std;
#define INF 999999999

int n;
int arr[5011];
int F[5011][5011];
int premaxs[5011][5011];
int psum[5011];

inline int Sum(int L,int R)
{
    return psum[R]-psum[L-1];
}

inline int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int main()
{
    int i,j,in;
    int ans;
    int uk;

    scanf("%d",&n);

    psum[0]=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        psum[i]=psum[i-1]+arr[i];
    }

    for (i=1;i<=n;i++)
    {
        premaxs[i+1][i]=-INF;
    }

    F[1][1]=1;
    premaxs[1][1]=1;

    for (j=2;j<=n;j++)
    {
        uk=j;
        for (i=j;i>=1;i--)
        {
            while(uk>=i)
            uk--;

            while(uk>1 && Sum(uk-1,i-1)<=Sum(i,j))
            uk--;

            F[i][j]=-INF;

            if (Sum(uk,i-1)<=Sum(i,j))
            {
                F[i][j]=premaxs[uk][i-1]+1;
            }

            if (i==1)
            F[i][j]=1;

            premaxs[i][j]=MAX(premaxs[i+1][j],F[i][j]);
        }
    }

    ans=F[1][n];
    for (i=2;i<=n;i++)
    {
        ans=MAX(ans,F[i][n]);
    }

    printf("%d\n",n-ans);

    return 0;
}