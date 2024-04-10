#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[1<<15],dp[16][16][1<<15],d[21];
pair<int,int> pre[16][16][1<<15];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<=n;++i)
            for(int j=0;j<=n;++j)
                for(int s=0;s<1<<n;++s)
                {
                    dp[i][j][s]=1e9;
                    pre[i][j][s].first=pre[i][j][s].second=0;
                }
        for(int s=0;s<1<<n;++s)
            a[s]=0;
        for(int i=0;i<n;++i)
        {
            cin>>a[1<<i];
            d[i+1]=0;
        }
        for(int i=0;i<n;++i)
            for(int s=0;s<1<<n;++s)
                if(s>>i&1)
                    a[s]+=a[s^(1<<i)];
        dp[0][0][0]=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<=n;++j)
                for(int s=0;s<1<<n;++s)
                    if(dp[i][j][s]<1e9)
                    {
                        int tmp=((1<<n)-1)^s;
                        for(int t=tmp;t;t=tmp&(t-1))
                            if(a[t]>dp[i][j][s]&&(t>>j)&&a[t]<dp[i+1][j+__builtin_ctz(t>>j)+1][s|t])
                            {
                                dp[i+1][j+__builtin_ctz(t>>j)+1][s|t]=a[t];
                                pre[i+1][j+__builtin_ctz(t>>j)+1][s|t]={j,s};
                            }
                    }
        bool flag=0;
        for(int i=n;i>=1;--i)
        {
            for(int j=1;j<=n;++j)
                if(dp[i][j][(1<<n)-1]<1e9)
                {
                    flag=1;
                    cout<<n-i<<'\n';
                    int pos=j,s=(1<<n)-1;
                    for(int k=i;k>=1;--k)
                    {
                        int t=s^pre[k][pos][s].second;
                        for(int p=1;p<=n;++p)
                            if(p!=pos&&(t>>(p-1)&1))
                            {
                                cout<<p-d[p]<<" "<<pos-d[pos]<<'\n';
                                for(int q=p+1;q<=n;++q)
                                    ++d[q];
                            }
                        t=pre[k][pos][s].second;
                        pos=pre[k][pos][s].first;
                        s=t;
                    }
                    break;
                }
            if(flag)
                break;
        }
    }
    return 0;
}