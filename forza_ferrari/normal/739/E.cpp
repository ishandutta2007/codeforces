#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps=1e-10;
int n,a,b,cnt[2001][2];
double dp[2001],p[2001],u[2001],ans[2];
inline void solve(double va,double vb)
{
    for(int i=1;i<=n;++i)
    {
        dp[i]=dp[i-1];
        cnt[i][0]=cnt[i-1][0];
        cnt[i][1]=cnt[i-1][1];
        if(dp[i]+eps<dp[i-1]-va+p[i])
        {
            dp[i]=dp[i-1]-va+p[i];
            cnt[i][0]=cnt[i-1][0]+1;
            cnt[i][1]=cnt[i-1][1];
        }
        if(dp[i]+eps<dp[i-1]-vb+u[i])
        {
            dp[i]=dp[i-1]-vb+u[i];
            cnt[i][0]=cnt[i-1][0];
            cnt[i][1]=cnt[i-1][1]+1;
        }
        if(dp[i]+eps<dp[i-1]-va-vb+p[i]+u[i]-p[i]*u[i])
        {
            dp[i]=dp[i-1]-va-vb+p[i]+u[i]-p[i]*u[i];
            cnt[i][0]=cnt[i-1][0]+1;
            cnt[i][1]=cnt[i-1][1]+1;
        }
    }
}
inline double check(double va)
{
    double l=0.0000,r=1.0000,mid,res=-1e9;
    for(int i=1;i<=50;++i)
    {
        mid=(l+r)/2;
        solve(va,mid);
        if(cnt[n][1]<=b)
            res=r=mid;
        else
            l=mid;
    }
    return res;
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;++i)
        scanf("%lf",&p[i]);
    for(int i=1;i<=n;++i)
        scanf("%lf",&u[i]);
    double l=0.0000,r=1.0000,mid;
    for(int i=1;i<=50;++i)
    {
        mid=(l+r)/2;
        ans[1]=check(mid);
        if(cnt[n][0]<=a)
            ans[0]=r=mid;
        else
            l=mid;
    }
    solve(ans[0],ans[1]);
    printf("%.5lf\n",dp[n]+ans[0]*a+ans[1]*b);
    return 0;
}