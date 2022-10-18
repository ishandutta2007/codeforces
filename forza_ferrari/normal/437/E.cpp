#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=1000000007;
int n,dp[201][201];
long long sum;
struct cp
{
    int x,y;
}a[201];
inline long long cross(cp x,cp y,cp O={0,0})
{
    return 1ll*(x.x-O.x)*(y.y-O.y)-1ll*(x.y-O.y)*(y.x-O.x);
}
inline bool check(cp x,cp y,cp O)
{
    return cross(x,y,O)>0;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].x>>a[i].y;
        sum+=cross(a[i-1],a[i]);
    }
    sum+=cross(a[n],a[1]);
    if(sum<0)
        reverse(a+1,a+n+1);
    for(int i=1;i<n;++i)
        dp[i][i+1]=1;
    for(int len=3;len<=n;++len)
        for(int i=1,j=len;j<=n;++i,++j)
            for(int k=i+1;k<j;++k)
                if(check(a[k],a[j],a[i]))
                    dp[i][j]=(dp[i][j]+1ll*dp[i][k]*dp[k][j]%mod)%mod;
    cout<<dp[1][n]<<'\n';
    return 0;
}