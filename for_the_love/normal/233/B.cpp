#include <cstdio>
#include <math.h>
long long sum(long long x)
{
        long long tmp=0;
        while (x)
        {
                tmp+=x%10; x=x/10;
        }
        return tmp;
}
int main()
{
        long long y,x,ans,n;
        scanf("%I64d",&n);
        y=sqrt(n);
        ans=-1;
        if (!n) ans=0;
        else
        for (x=y-100000;x<=y;x++)
        {
                if (x<=0) continue;
                if ((n%x==0)&&(n/x-x==sum(x)))
                {
                        ans=x; break;
                }
        }
        printf("%I64d\n",ans);
}