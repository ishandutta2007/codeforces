#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353,inv=(mod+1)>>1;
int n,m,u,v,w,a[100001],b[100001],c[100001],f[3][1<<17],g[1<<17],sum;
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
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
inline void fwt(int *f,bool tag)
{
    for(int i=2;i<=1<<m;i<<=1)
    {
        int len=i>>1;
        for(int j=0;j<1<<m;j+=i)
            for(int k=j;k<j+len;++k)
            {
                int x=f[k],y=f[k+len];
                if(tag)
                {
                    f[k]=x+y;
                    f[k+len]=x-y;
                }
                else
                {
                    f[k]=1ll*(x+y)%mod*inv%mod;
                    f[k+len]=1ll*(x-y+mod)%mod*inv%mod;
                }
            }
    }
}
int main()
{
    n=read(),m=read(),u=read(),v=read(),w=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read(),b[i]=read(),sum^=c[i]=read();
        a[i]^=c[i],b[i]^=c[i];
        ++f[0][a[i]];
        ++f[1][b[i]];
        ++f[2][a[i]^b[i]];
    }
    fwt(f[0],1);
    fwt(f[1],1);
    fwt(f[2],1);
    int A=((u+v)%mod+w)%mod,B=((u-v+mod)%mod+w)%mod,C=((-u+v+mod)%mod+w)%mod,D=((mod-(u+v)%mod)%mod+w)%mod;
    for(int i=0;i<1<<m;++i)
    {
        int cA=(n+f[0][i]+f[1][i]+f[2][i])/4,cB=(n+f[0][i])/2-cA,cC=(n+f[1][i])/2-cA,cD=(n+f[2][i])/2-cA;
        g[i]=1ll*pw(A,cA)*pw(B,cB)%mod*pw(C,cC)%mod*pw(D,cD)%mod;
    }
    fwt(g,0);
    for(int i=0;i<1<<m;++i)
        cout<<g[i^sum]<<" ";
    cout<<'\n';
    return 0;
}
/*
A=u+v+w
B=u-v+w
C=-u+v+w
D=-u-v+w
A+B+C+D=n
A+B-C-D=f0
A-B+C-D=f1
A-B-C+D=f2
A+B=(n+f0)/2
A+C=(n+f1)/2
A+D=(n+f2)/2
3A+B+C+D=(3n+f0+f1+f2)/2
A=(n+f0+f1+f2)/4
*/