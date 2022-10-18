#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
double dp[10001][1001];
int main()
{
    cin>>n>>m;
    dp[1][1]=1.0000;
    for(int i=2;i<=10000;++i)
        for(int j=1;j<=n;++j)
        {
            dp[i][j]+=dp[i-1][j]*j*1.0/n;
            if(j^1)
                dp[i][j]+=dp[i-1][j-1]*(n-j+1)*1.0/n;
        }
    while(m--)
    {
        int p;
        cin>>p;
        for(int i=1;i<=10000;++i)
            if(dp[i][n]>=p/2000.0)
            {
                cout<<i<<'\n';
                break;
            }
    }
    return 0;
}