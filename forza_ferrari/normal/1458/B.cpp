#include<iostream>
#include<cstdio>
using namespace std;
int n,a[101],b[101],dp[2][101][40001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i]>>b[i];
        a[i]<<=1;
        b[i]<<=1;
    }
    int now=0;
    for(int i=0;i<=n;++i)
        for(int j=0;j<=400*n;++j)
            dp[0][i][j]=-1e9;
    dp[0][0][200*n]=0;
    for(int i=1;i<=n;++i)
    {
        //cout<<i<<'\n';
        now^=1;
        for(int j=0;j<=n;++j)
            for(int k=0;k<=400*n;++k)
                dp[now][j][k]=-1e9;
        for(int j=0;j<i;++j)
            for(int k=0;k<=400*n;++k)
                if(dp[now^1][j][k]>=0)
                {
                    if(k>=200*n)
                    {
                        dp[now][j][k+b[i]]=max(dp[now][j][k+b[i]],dp[now^1][j][k]);
                        if(k-((a[i]-b[i])<<1)>=200*n)
                            dp[now][j+1][k-((a[i]-b[i])<<1)]=max(dp[now][j+1][k-((a[i]-b[i])<<1)],dp[now^1][j][k]+a[i]);
                        else
                            dp[now][j+1][200*n-(a[i]-b[i]-((k-200*n)>>1))]=max(dp[now][j+1][200*n-(a[i]-b[i]-((k-200*n)>>1))],dp[now^1][j][k]+b[i]+((k-200*n)>>1));
                    }
                    else
                    {
                        if(k+(b[i]>>1)<200*n)
                            dp[now][j][k+(b[i]>>1)]=max(dp[now][j][k+(b[i]>>1)],dp[now^1][j][k]+(b[i]>>1));
                        else
                            dp[now][j][200*n+(b[i]-((200*n-k)<<1))]=max(dp[now][j][200*n+(b[i]-((200*n-k)<<1))],dp[now^1][j][k]+200*n-k);
                        dp[now][j+1][k-(a[i]-b[i])]=max(dp[now][j+1][k-(a[i]-b[i])],dp[now^1][j][k]+b[i]);
                    }
                }
    }
    for(int i=1;i<=n;++i)
    {
        int ans=-1e9;
        for(int j=0;j<=400*n;++j)
            ans=max(ans,dp[now][i][j]);
        printf("%.1lf ",ans*0.5);
    }
    cout<<'\n';
    return 0;
}