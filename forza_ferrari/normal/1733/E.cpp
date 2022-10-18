#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int n=120;
int m,dp[121][121];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline int calc(int t,int x,int y)
{
    for(int i=0;i<=x;++i)
        for(int j=0;j<=y;++j)
            dp[i][j]=0;
    dp[0][0]=max(t-x-y+1,0ll);
    for(int i=0;i<=x;++i)
        for(int j=0;j<=y;++j)
        {
            if(j+1<=y)
                dp[i][j+1]+=(dp[i][j]+1)>>1;
            if(i+1<=x)
                dp[i+1][j]+=dp[i][j]>>1;
        }
    return dp[x][y];
}
signed main()
{
    m=read();
    while(m--)
    {
        int t=read(),x=read(),y=read();
        cout<<(calc(t,x,y)==calc(t-1,x,y)? "NO":"YES")<<'\n';
    }
    return 0;
}