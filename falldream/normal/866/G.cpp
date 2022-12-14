#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define MN 8200
#define MM 32767
#define mod 1000000007
const double pi=acos(-1);
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}
int pow(int x,int k)
{
	int sum=1;
	for(;k;k>>=1,x=1LL*x*x%mod)
		if(k&1) sum=1LL*sum*x%mod;
	return sum; 
}	
namespace Poly 
{
	#define MX 512
	struct cp
	{
		double r,u;
		cp(double _r=0,double _u=0):r(_r),u(_u){}
		friend cp operator + (const cp&x,const cp&y){return cp(x.r+y.r,x.u+y.u);}
		friend cp operator - (const cp&x,const cp&y){return cp(x.r-y.r,x.u-y.u);}
		friend cp operator * (const cp&x,const cp&y){return cp(x.r*y.r-x.u*y.u,x.r*y.u+x.u*y.r);} 
		cp operator / (double y){return cp(r/y,u/y);}
	}w[10][2][MX+5],a[MX+5],b[MX+5],c[MX+5],d[MX+5],e[MX+5];int N,P,nl,Rev[MX+5],C[MX+5],D[MX+5],E[MX+5];
	inline long long R(double x){return (long long)(x+0.5)%mod;}
	void FFT(cp*x,int r)
	{
		for(int i=0,j=0;i<N;++i)
		{
			if(i>j) swap(x[i],x[j]);
			for(int k=N>>1;(j^=k)<k;k>>=1);
		}
		for(int i=2;i<=N;i<<=1)for(int j=0;j<N;j+=i)for(int k=0;k<i>>1;++k)
		{
			cp t=x[j+k+(i>>1)]*w[P][r][N/i*k];
			x[j+k+(i>>1)]=x[j+k]-t;
			x[j+k]=x[j+k]+t;
		}
		if(r)for(int i=0;i<N;++i)x[i]=x[i]/N;
	}
	void Reverse(int*x,int n){for(int i=0;i<n-1-i;++i)swap(x[i],x[n-1-i]);}
	void mul(int len,int*A,int*B)
	{
		for(N=1,P=0;N<len;N<<=1,++P);N<<=1;++P;
		memset(a,0,sizeof(cp)*(N+5));memset(b,0,sizeof(cp)*(N+5));
		memset(c,0,sizeof(cp)*(N+5));memset(d,0,sizeof(cp)*(N+5));
		for(int i=0;i<len;++i) a[i]=cp(A[i]&MM,0),b[i]=cp(B[i]&MM,0),c[i]=cp(A[i]>>15,0),d[i]=cp(B[i]>>15,0);
		FFT(a,0);FFT(b,0);FFT(c,0);FFT(d,0);
		for(int i=0;i<N;++i) e[i]=a[i]*d[i]+b[i]*c[i],a[i]=a[i]*b[i],c[i]=c[i]*d[i];
		FFT(a,1);FFT(c,1);FFT(e,1);
		for(int i=0;i<N;++i) A[i]=((1LL<<30)*R(c[i].r)%mod+R(a[i].r)+(1LL<<15)*R(e[i].r)%mod+mod)%mod;
	}
	void GetInv(int*A,int*B,int n)
	{
		/*
		B(x)-B'(x) = 0 mod n/2
		B^2 -2BB' + B'2^2 = 0 mod n
		B - 2B' + AB'^2 = 0
		B = 2B' - AB'^2 
		*/
		if(n==1){B[0]=pow(A[0],mod-2);B[1]=0;return;}GetInv(A,B,n>>1);
		for(int i=0;i<n;++i) C[i]=A[i],D[i]=B[i];
		mul(n>>1,B,B);mul(n,C,B);
		for(int i=0;i<n;++i) B[i]=(2LL*D[i]-C[i]+mod)%mod,B[i+n]=0;
	}
	void Mul(int len,int*A,int*B,int*S)
	{
		mul(len,A,B);if(2*len-2<len) return;
		/*
		A=SB+R
		A(1/x) = S(1/x) * B(1/x) + R(1/x)
		x^2*len-2 * A(1/x) = x^2len-2 * S(1/x) * len B(1/x) + x^n * R(1/x)
		RA = RS*RB + x^n-m+1 RR
		A->2*len-2 B->len-1  len-2
		*/	
		for(nl=1;nl<len;nl<<=1);
		for(int i=0;i<len;++i) E[i]=A[len*2-2-i];
		for(int i=len-1;i<=len*2;++i) E[i]=Rev[i]=0;
		mul(len-1,E,Rev);Reverse(E,len-1);
		E[len]=E[len-1]=0;mul(len+1,E,S);
		for(int i=0;i<len;++i) A[i]=(A[i]-E[i]+mod)%mod,A[i+len]=0;
	}
	void init()
	{
		for(int i=1,j=2;i<=9;++i,j<<=1)
			for(int k=0;k<=j;++k) w[i][0][k]=w[i][1][j-k]=cp(cos(2*k*pi/j),sin(2*k*pi/j));	
	}
}
int n,m,p[20],f[MN+5],c[MN+5],A[31][MN*2+5],B[MN*2+5],CC[MN*2+5],P[MN*2+5],G[MN*2+5];
long long ts;
int main()
{
	n=read();m=read();scanf("%lld",&ts);f[0]=1;int mx=0,nl=1;Poly::init();
	for(int i=1;i<=n;++i) p[i]=read();
	for(int i=1;i<=m;++i) mx=max(mx,c[i]=read());
	for(int i=1;i<=m;++i) (CC[mx-c[i]]+=mod-1)%=mod;++CC[mx];
	for(;nl<mx;nl<<=1);
	Poly::Reverse(CC,mx+1);
	Poly::GetInv(CC,Poly::Rev,nl); 
	Poly::Reverse(CC,mx+1);
	for(int i=1;i<=mx;++i)
		for(int j=1;j<=m;++j) if(i>=c[j]) R(f[i],f[i-c[j]]);
	if(mx==1) A[0][0]=mod-CC[0]; else A[0][1]=1;	
	for(int i=1;i<=30;++i) memcpy(A[i],A[i-1],sizeof(A[i])),Poly::Mul(mx,A[i],A[i],CC);
	for(int t=1;t<=n;++t)
	{
		memset(B,0,sizeof(B));B[0]=1;
		for(int k=p[t],j=0;k;++j,k>>=1) if(k&1) Poly::Mul(mx,B,A[j],CC);
		for(int i=0;i<mx;++i) R(P[i],B[i]);
	}
	int ans=0;memset(B,0,sizeof(B));B[0]=1;
	for(;ts;ts>>=1,Poly::Mul(mx,P,P,CC))if(ts&1)Poly::Mul(mx,B,P,CC);
	for(int i=0;i<mx;++i) R(ans,1LL*B[i]*f[i]%mod);
	printf("%d\n",(ans%mod+mod)%mod); 
	return 0;
}