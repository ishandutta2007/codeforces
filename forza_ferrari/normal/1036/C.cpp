#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long t,n,l,r,p[21],dp[21][2][4];
inline long long solve(long long maxn)
{
    memset(dp,0,sizeof dp);
    dp[n+1][1][0]=1;
    for(int i=n;i>=0;--i)
        for(int tag=0;tag<=1;++tag)
            for(int j=0;j<=3;++j)
            {
                int num=maxn/p[i]%10;
                if(tag)
                {
                    if(j>=(bool)num)
                        dp[i][1][j]+=dp[i+1][1][j-(bool)num];
                    for(int k=0;k<num;++k)
                        if(j>=(bool)k)
                            dp[i][0][j]+=dp[i+1][1][j-(bool)k];
                }
                else
                    for(int k=0;k<=9;++k)
                        if(j>=(bool)k)
                            dp[i][0][j]+=dp[i+1][0][j-(bool)k];
            }
    long long ans=0;
    for(int i=0;i<=1;++i)
        for(int j=0;j<=3;++j)
            ans+=dp[0][i][j];
    return ans;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        p[0]=1;
        for(int i=1;;++i)
        {
            p[i]=p[i-1]*10;
            if(r/p[i]<10)
            {
                n=i;
                break;
            }
        }
        while(r/p[n]==0)
            --n;
        cout<<solve(r)-solve(l-1)<<'\n';
    }
    return 0;
}