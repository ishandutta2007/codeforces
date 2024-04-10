#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
const int G=3,mod=998244353;
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
const int invG=pw(G,mod-2);
int n,m,p[100001],A[200001<<1],B[200001<<1],tr[200001<<1],fac[200001<<1],inv[200001<<1],g[200001<<1];
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
inline void NTT(int *f,bool flag,int n)
{
    for(register int i=0;i<n;++i)
        if(i<tr[i])
            swap(f[i],f[tr[i]]);
    for(register int p=2;p<=n;p<<=1)
    {
        int len=p>>1,tg=pw(flag? G:invG,(mod-1)/p);
        for(register int k=0;k<n;k+=p)
        {
            int buf=1;
            for(register int l=k;l<k+len;++l)
            {
                int tt=buf*f[l+len]%mod;
                f[l+len]=(f[l]+mod-tt)%mod;
                f[l]=(f[l]+tt)%mod;
                buf=buf*tg%mod;
            }
        }
    }
    if(!flag)
    {
        int Inv=pw(n,mod-2);
        for(register int i=0;i<n;++i)
            f[i]=f[i]*Inv%mod;
    }
}
inline void solve(int *A,int *B,int n)
{
    int N;
    for(N=n<<1,n=1;n<=N;n<<=1);
    for(register int i=0;i<n;++i)
        tr[i]=(tr[i>>1]>>1)|((i&1)? n>>1:0);
    NTT(A,1,n);
    NTT(B,1,n);
    for(register int i=0;i<n;++i)
        A[i]=A[i]*B[i]%mod;
    NTT(A,0,n);
    N>>=1;
    for(register int i=N;i<n;++i)
        A[i]=B[i]=0;
}
signed main()
{
    n=read()+1,m=read()%(mod-1);
    fac[0]=inv[0]=1;
    for(register int i=0;i<n;++i)
    {
        p[i]=read();
        if(i)
        {
            fac[i]=fac[i-1]*i%mod;
            inv[i]=pw(fac[i],mod-2);
        }
    }
    for(register int i=0;i<n;++i)
    {
        A[n-i-1]=fac[i]*p[i]%mod;
        B[i]=inv[i];
    }
    solve(A,B,n);
    for(register int i=0;i<n;++i)
        g[i]=inv[i]*A[n-i-1]%mod*pw(pw(i+1,m),mod-2)%mod;
    for(register int i=0;i<n;++i)
    {
        A[n-i-1]=fac[i]*g[i]%mod;
        B[i]=i&1? mod-inv[i]:inv[i];
    }
    solve(A,B,n);
    for(register int i=0;i<n;++i)
        printf("%lld ",A[n-i-1]*inv[i]%mod);
    puts("");
    return 0;
}