#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,dp[32][21][21][21][21][2][2],x[11],y[11];
inline void work(int now,int a,int b,int c,int d,int e,int f,int state)
{
    int val=dp[now][a][b][c][d][e][f];
    bool flag=(m>>now)&1;
    for(register int i=1;i<=n;++i)
        if(state&(1ll<<(i-1)))
        {
            x[i]>0? a+=x[i]:b-=x[i];
            y[i]>0? c+=y[i]:d-=y[i];
        }
    if((a&1)^(b&1))
        return;
    if((c&1)^(d&1))
        return;
    if((a&1)&&!flag)
        e=1;
    if(!(a&1)&&flag)
        e=0;
    if((c&1)&&!flag)
        f=1;
    if(!(c&1)&&flag)
        f=0;
    a>>=1;
    b>>=1;
    c>>=1;
    d>>=1;
    dp[now+1][a][b][c][d][e][f]=(dp[now+1][a][b][c][d][e][f]+val)%mod;
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(register int i=1;i<=n;++i)
        scanf("%lld%lld",&x[i],&y[i]);
    dp[0][0][0][0][0][0][0]=1;
    for(register int i=0;i<=30;++i)
        for(register int a=0;a<=4*n;++a)
            for(register int b=0;b<=4*n;++b)
                for(register int c=0;c<=4*n;++c)
                    for(register int d=0;d<=4*n;++d)
                        for(register int e=0;e<=1;++e)
                            for(register int f=0;f<=1;++f)
                                if(dp[i][a][b][c][d][e][f])
                                    for(register int state=0;state<1<<n;++state)
                                        work(i,a,b,c,d,e,f,state);
    printf("%lld\n",(dp[31][0][0][0][0][0][0]-1+mod)%mod);
    return 0;
}