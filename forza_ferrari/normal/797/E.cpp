#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,block,dp[100001][401],a[100001];
int main()
{
    cin>>n;
    block=sqrt(n);
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=n;i;--i)
        for(int j=1;j<=block;++j)
            dp[i][j]=(i+a[i]+j>n? 0:dp[i+a[i]+j][j])+1;
    cin>>m;
    while(m--)
    {
        int p,k;
        cin>>p>>k;
        if(k<=block)
            cout<<dp[p][k]<<endl;
        else
        {
            int ans=0;
            while(p<=n)
            {
                ++ans;
                p+=a[p]+k;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}