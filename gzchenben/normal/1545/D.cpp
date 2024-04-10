#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
long long a[1005][1005],sum[1005],sumsqr[1005],dif[1005],difsqr[1005];
int DeltaX,WrongTime;
int main()
{
    scanf("%d%d",&k,&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            scanf("%lld",&a[i][j]);
            sum[i]+=a[i][j];
            sumsqr[i]+=a[i][j]*a[i][j];
        }
        dif[i-1]=sum[i]-sum[i-1];
        difsqr[i-1]=sumsqr[i]-sumsqr[i-1];
    }
    // for(int i=1;i<=n;i++)
    // {
    //     printf("i=%d sum=%lld sqr=%lld dif1=%lld dif2=%lld\n",i-1,sum[i-1],sumsqr[i],dif[i],difsqr[i]);
    // }
    if(dif[1]!=dif[2] && dif[1]!=dif[5])
    {
        if(dif[2]==dif[5]) WrongTime=1;
        else WrongTime=2;
        DeltaX=dif[5];
    }
    else
    {
        for(int i=2;i<=n-1;i++)
        {
            if(dif[i]!=dif[i-1]) 
            {
                WrongTime=i+1;
                break;
            }
        }
        DeltaX=dif[1];
    }
    long long Sum,SumSqr;
    if(WrongTime>=4)
    {
        Sum=sum[WrongTime-1]+DeltaX;
        SumSqr=sumsqr[WrongTime-1]+(2*difsqr[WrongTime-2]-difsqr[WrongTime-3]);
    }
    else
    {
        Sum=sum[WrongTime+1]-DeltaX;
        SumSqr=sumsqr[WrongTime+1]-(2*difsqr[WrongTime+1]-difsqr[WrongTime+2]);
    }
//    printf("Sum=%lld SumSqr=%lld\n",Sum,SumSqr);
    long long XplusY,XminusY;
    XminusY=Sum-sum[WrongTime];
    XplusY=(SumSqr-sumsqr[WrongTime])/XminusY;
    printf("%d %lld\n",WrongTime-1,(XplusY+XminusY)/2);
}