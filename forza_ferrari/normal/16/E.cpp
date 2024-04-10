#include<iostream>
#include<cstdio>
using namespace std;
int n;
double a[21][21],dp[1<<18];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>a[i][j];
    dp[(1<<n)-1]=1.0000;
    for(int s=(1<<n)-1;s;--s)
    {
        int cnt=__builtin_popcount(s);
        double val=1.0/(cnt*(cnt-1)/2);
        for(int i=1;i<n;++i)
            if(s&(1<<(i-1)))
                for(int j=i+1;j<=n;++j)
                    if(s&(1<<(j-1)))
                    {
                        dp[s^(1<<(i-1))]+=dp[s]*val*a[j][i];
                        dp[s^(1<<(j-1))]+=dp[s]*val*a[i][j];
                    }
    }
    for(int i=1;i<=n;++i)
        cout<<dp[1<<(i-1)]<<" ";
    cout<<'\n';
    return 0;
}