#include<bits/stdc++.h>
#define MN 1000000
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
bool b[MN+5];
int Q,last[MN+5],s[MN/5+5],num,p[MN*2+5],inv[MN*2+5],a[65],c[65],ans,f[8][8],sum[25];
inline int C(int n,int m){return m>n||m<0?0:1LL*p[n]*inv[m]%mod*inv[n-m]%mod;}
inline int S(int n,int m){return m?C(n+m-1,m-1):(n?0:1);}
int main()
{
    p[0]=p[1]=inv[0]=inv[1]=sum[0]=1;
    for(int i=2;i<=MN;++i)
    {
        if(!b[i]) s[++num]=i,last[i]=i;
        for(int j=1;s[j]*i<=MN;++j)
        {
            b[s[j]*i]=1;last[s[j]*i]=s[j];
            if(i%s[j]==0) break;
        }
    }
    for(int i=2;i<=MN*2;++i) p[i]=1LL*p[i-1]*i%mod,inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
    for(int i=2;i<=MN*2;++i) inv[i]=1LL*inv[i-1]*inv[i]%mod;
    for(Q=read();Q--;)
    {
        int m=read(),n=read();num=ans=0;
        while(n>1)
        {
            ++num;c[num]=0;a[num]=last[n];
            for(int t=last[n];n%t==0;n/=t) ++c[num];
        }
        for(int i=1;i<=20;++i) sum[i]=(sum[i-1]+S(i,m))%mod;
        memset(f,0,sizeof(f));f[0][0]=1;
        for(int i=1;i<=num;++i) for(int j=0;j<i;++j)
        {
            f[i][j]=(f[i][j]+1LL*f[i-1][j]*S(c[i],m))%mod;
            f[i][j+1]=(f[i][j+1]+1LL*f[i-1][j]*sum[c[i]-1])%mod;
        }
        for(int i=0;i<=num;++i) ans=(ans+1LL*(1<<i)*f[num][i])%mod;
        printf("%d\n",ans);
    }
    return 0;
}