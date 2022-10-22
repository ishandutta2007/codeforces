// Problem: CF773F Test Data Generation
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF773F
// Memory Limit: 250 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const long double pi=acos(-1);
struct cp
{
    long double r,i;
    cp operator+(const cp &x)const{return (cp){x.r+r,x.i+i};}
    cp operator-(const cp &x)const{return (cp){r-x.r,i-x.i};}
    cp operator*(const cp &x)const{return (cp){r*x.r-i*x.i,r*x.i+i*x.r};}
}A[600003],B[600003];
int rev[6000003],N=1;
void init()
{
    int d=N>>1;
    rev[0]=0,rev[1]=N>>1;
    for(int i=2; i<N; i<<=1)
    {
        d>>=1;
        for(int j=0; j<i; ++j) rev[i+j]=rev[j]|d;
    }
    return ;
}
void FFT(cp* F,int op)
{
    for(int i=0; i<N; ++i) if(rev[i]>i) swap(F[i],F[rev[i]]);
    for(int len=2,M=1; len<=N; len<<=1,M<<=1)
    {
        cp w=(cp){cos(pi/M*op),sin(pi/M*op)};
        //omega(m,1)
        for(int l=0,r=len-1; l<N; l+=len,r+=len)
        {
            cp w0=(cp){1,0};
            for(int i=l; i<l+M; ++i)
            {
                cp x=F[i],y=w0*F[i+M];
                F[i]=x+y,F[i+M]=x-y,w0=w0*w;
            }
        }
    }
}
signed MTT(int n,int p,ll* F,ll* G,ll* ans)
{
    N=1;for(;N<=(n<<1);N<<=1);
    for(int i=0; i<N; ++i) A[i]=B[i]=(cp){0.0,0.0};
    for(int i=0; i<=n; ++i) A[i].r=F[i];
    for(int i=0; i<=n; ++i) B[i].r=G[i];
    init();
    FFT(A,1),FFT(B,1);
    for(int i=0; i<N; ++i) A[i]=A[i]*B[i];
    FFT(A,-1);
    for(int i=0; i<=n; ++i) ans[i]=(ll)(A[i].r/N+0.5);
    return 0;
}
ll F[30003],G[30003],sum[30003];
ll tf[30003],tg[30003];
signed main()
{
	int N=read(),A=read()>>1,p=read();
	ll ans=0;
	for(int i=0; i<=N; ++i) F[i]=G[i]=0;
	F[0]=1;
	int M=1;
	for(;(M<<1)<=A;M<<=1)M<<=1;
	for(int cur=0;M;M>>=1)
	{
		if(cur)
		{
			for(int i=0; i<=N; ++i) sum[i]=(F[i]+G[i])%p;
			F[0]=0;
			MTT(N,p,sum,F,tg),
			MTT(N,p,sum,G,tf);
			F[0]=1;
			for(int i=0; i<=N; ++i) F[i]=(F[i]+tf[i])%p;
			for(int i=0; i<=N; ++i) G[i]=(G[i]+tg[i])%p;
		}
		else
		{
			for(int i=0; i<=N; ++i) sum[i]=(F[i]+G[i])%p;
			F[0]=0;
			MTT(N,p,sum,F,tf),
			MTT(N,p,sum,G,tg);
			F[0]=1;
			for(int i=0; i<=N; ++i) F[i]=(F[i]+tf[i])%p;
			for(int i=0; i<=N; ++i) G[i]=(G[i]+tg[i])%p;
		}
		cur=0;
		if(M&A)
		{
			for(int i=N; i>=1; --i) F[i]=(F[i]+F[i-1]+G[i-1])%p;
			cur=1;
		}	
		for(int i=1; i<=N; i+=2) ans=(ans+F[i])%p;
	}
	printf("%lld\n",ans);
	return 0;
}