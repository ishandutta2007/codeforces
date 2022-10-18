#include<iostream>
#include<cstdio>
using namespace std;
unsigned long long m,k,dp[71][71][2];
inline unsigned long long check(unsigned long long n)
{
    for(register int i=0;i<=64;++i)
        for(register int j=0;j<=64;++j)
            dp[i][j][0]=dp[i][j][1]=0;
    dp[64][0][1]=1;
    for(register int i=63;~i;--i)
        for(register int j=0;j<64-i;++j)
            if(n&(1ull<<i))
            {
                dp[i][j+1][1]+=dp[i+1][j][1];
                dp[i][j+1][0]+=dp[i+1][j][0];
                dp[i][j][0]+=dp[i+1][j][1]+dp[i+1][j][0];
            }
            else
            {
                dp[i][j][1]+=dp[i+1][j][1];
                dp[i][j+1][0]+=dp[i+1][j][0];
                dp[i][j][0]+=dp[i+1][j][0];
            }
    return dp[0][k][0]+dp[0][k][1];
}
int main()
{
    cin>>m>>k;
    unsigned long long l=1,r=1e18,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        unsigned long long val=check(mid<<1)-check(mid);
        if(val==m)
        {
            cout<<mid<<endl;
            return 0;
        }
        if(val<m)
            l=mid+1;
        if(val>m)
            r=mid-1;
    }
    return 0;
}