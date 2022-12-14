#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 262144
#define mod 998244353
const int Inv2=499122177;
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int w[2][MN+5],m,C[MN+5],N,Rev[MN+5],B[MN+5],A[MN+5],Ans[MN+5];

inline int pow(int x,int k)
{
    int sum=1;
    for(;k;k>>=1,x=1LL*x*x%mod)
        if(k&1) sum=1LL*sum*x%mod;
    return sum;
}
int last=0;
void NTT(int*x,int N,int r)
{
    if(last!=N)
    {
        w[0][0]=w[1][last=N]=1,w[0][1]=w[1][N-1]=pow(3,(mod-1)/N);
        for(int i=2;i<=N;++i) w[0][i]=w[1][N-i]=1LL*w[0][i-1]*w[0][1]%mod;
    }
    for(int i=0,j=0;i<N;++i)
    {
        if(i>j) swap(x[i],x[j]);
        for(int l=N>>1;(j^=l)<l;l>>=1);
    }
    for(int i=2;i<=N;i<<=1)for(int j=0;j<N;j+=i)for(int k=0;k<i>>1;++k)
    {
        int t=1LL*x[j+k+(i>>1)]*w[r][N/i*k]%mod;
        x[j+k+(i>>1)]=(x[j+k]-t+mod)%mod;
        x[j+k]=(x[j+k]+t)%mod;
    }
    if(r)for(int i=0,inv=pow(N,mod-2);i<N;++i) x[i]=1LL*x[i]*inv%mod;
}

void GetInv(int*a,int*b,int N)
{
    if(N==1){b[0]=pow(a[0],mod-2);return;}GetInv(a,b,N>>1);
    for(int i=0;i<N;++i)A[i]=a[i],A[i+N]=0;
    NTT(b,N<<1,0);NTT(A,N<<1,0);
    for(int i=0;i<N<<1;++i) b[i]=(2LL*b[i]-1LL*A[i]*b[i]%mod*b[i]%mod+mod)%mod;
    NTT(b,N<<1,1);for(int i=N;i<N<<1;++i) b[i]=0;
}

void GetSqr(int*a,int*b,int N)
{
    if(N==1){b[0]=1;return;}GetSqr(a,b,N>>1);
    memset(Rev,0,sizeof(int)*(N+2));GetInv(b,Rev,N);
    for(int i=0;i<N;++i) A[i]=a[i],A[i+N]=0;
    NTT(Rev,N<<1,0);NTT(A,N<<1,0);NTT(b,N<<1,0);
    for(int i=0;i<N<<1;++i) b[i]=1LL*(b[i]+1LL*A[i]*Rev[i]%mod)*Inv2%mod;
    NTT(b,N<<1,1);for(int i=N;i<N<<1;++i) b[i]=0;
}

int main()
{
    int n=read();m=read();C[0]=1;
    for(int i=1,j;i<=n;++i) j=read(),j<=m?(C[j]=mod-4):0;
    for(N=1;N<=m;N<<=1);
    GetSqr(C,B,N);(++B[0])%=mod;GetInv(B,Ans,N);
    for(int i=1;i<=m;++i) printf("%d\n",Ans[i]*2%mod);
    return 0;
}