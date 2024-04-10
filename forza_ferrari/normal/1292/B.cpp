#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long x[101],y[101],a[2],b[2],sx,sy,t,ans,cnt,sum,T;
inline long long calc(long long x1,long long y_1,long long x2,long long y2)
{
    return llabs(x1-x2)+llabs(y_1-y2);
}
int main()
{
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&x[0],&y[0],&a[0],&a[1],&b[0],&b[1],&sx,&sy,&T);
    for(;;)
    {
        ++cnt;
        x[cnt]=x[cnt-1]*a[0]+b[0];
        y[cnt]=y[cnt-1]*a[1]+b[1];
        if(x[cnt]>sx&&y[cnt]>sy&&calc(sx,sy,x[cnt],y[cnt])>T)
            break;
    }
    for(register int i=0;i<=cnt;++i)
    {
        sum=0;
        t=T;
        if(calc(sx,sy,x[i],y[i])<=t)
        {
            t-=calc(sx,sy,x[i],y[i]);
            ++sum;
        }
        else
            continue;
        for(register int j=i;j;--j)
            if(calc(x[j],y[j],x[j-1],y[j-1])<=t)
            {
                t-=calc(x[j],y[j],x[j-1],y[j-1]);
                ++sum;
            }
            else
                break;
        for(register int j=1;j<=cnt;++j)
            if(calc(x[j],y[j],x[j-1],y[j-1])<=t)
            {
                t-=calc(x[j],y[j],x[j-1],y[j-1]);
                sum+=j>i;
            }
            else
                break;
        ans=max(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}