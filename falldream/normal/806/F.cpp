#include<bits/stdc++.h>
using namespace std;
#define MN 65536
const double pi=acos(-1);
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,mod,ans=1,N,A[2][MN+5];
struct cp
{
    double r,u;
    cp(double _r=0,double _u=0):r(_r),u(_u){}
    cp operator + (const cp&y){return cp(r+y.r,u+y.u);}
    cp operator - (const cp&y){return cp(r-y.r,u-y.u);}
    cp operator * (const cp&y){return cp(r*y.r-u*y.u,r*y.u+u*y.r);}
    cp operator / (double y){return cp(r/y,u/y);}
}w[2][MN+5],a[MN+5],b[MN+5],c[MN+5];
void FFT(cp*x,int r)
{
    for(int i=0,j=0;i<N;++i)
    {
        if(i>j) swap(x[i],x[j]);
        for(int k=N>>1;(j^=k)<k;k>>=1);
    }
    for(int i=2;i<=N;i<<=1) for(int j=0;j<N;j+=i) for(int k=0;k<i>>1;++k)
    {
        cp t=x[j+k+(i>>1)]*w[r][N/i*k];
        x[j+k+(i>>1)]=x[j+k]-t;
        x[j+k]=x[j+k]+t;
    }
    if(r)for(int i=0;i<N;++i) x[i]=x[i]/N;
}
void Solve(int l)
{
    if(l==1) return;Solve(l>>1);int bit=(l>>1)&1;
    for(int i=0;i<N;++i) a[i]=cp(A[0][i]+A[1][i],0),b[i]=cp(A[bit][i],0),c[i]=cp(A[bit^1][i],0);
    FFT(a,0);FFT(b,0);FFT(c,0);
    for(int i=0;i<N;++i) b[i]=b[i]*a[i],c[i]=c[i]*a[i];
    FFT(b,1);FFT(c,1);
    for(int i=1;i<=n;++i)
    {
        int w[2]={A[0][i],A[1][i]};
        A[0][i]=(A[0][i]+(long long)(b[i].r+0.5)+w[bit])%mod,
        A[1][i]=(A[1][i]+(long long)(c[i].r+0.5)+w[bit^1])%mod;
    }
    if(l&1) for(int i=n;i;--i) A[1][i]=(A[1][i]+A[0][i-1]+A[1][i-1]+(i==1))%mod;
    for(int i=1;i<=n;i+=2) ans=(ans+A[1][i])%mod;
}
int main()
{
	n=read();m=read();mod=read();if(m==1) return 0*puts("0");
    for(N=1;N<=n;N<<=1);N<<=1;
    for(int i=0;i<=N;++i) w[0][i]=w[1][N-i]=cp(cos(2*pi*i/N),sin(2*pi*i/N));
    A[1][1]=1;Solve(m>>1);
    cout<<ans;
    return 0;
}