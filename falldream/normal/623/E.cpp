#include<iostream>
#include<cstdio>
#include<cmath>
#define MN 65536
#define mod 1000000007
const double pi=acos(-1);
using namespace std;
long long n;
int N,k,p[MN+5],inv[MN+5],A[MN+5],B[MN+5];
struct cp
{
	double r,u;
	cp(double _r=0,double _u=0):r(_r),u(_u){}
	cp operator + (const cp&b){return cp(r+b.r,u+b.u);}
	cp operator - (const cp&b){return cp(r-b.r,u-b.u);}
	cp operator * (const cp&b){return cp(r*b.r-u*b.u,r*b.u+u*b.r);}
	cp operator / (int t){return cp(r/t,u/t);}
}a[MN+5],b[MN+5],c[MN+5],d[MN+5],w[2][MN+5];
inline int C(int n,int m){return 1LL*p[n]*inv[m]%mod*inv[n-m]%mod;}
inline int pow(int x,int k)
{
	int sum=1;
	for(;k;k>>=1,x=1LL*x*x%mod) if(k&1) sum=1LL*sum*x%mod;
	return sum;
}	

void FFT(cp*a,int r)
{
	for(int i=0,j=0;i<N;++i)
	{
		if(i>j) swap(a[i],a[j]);
		for(int k=N>>1;(j^=k)<k;k>>=1);	
	}
	for(int i=2;i<=N;i<<=1)for(int j=0;j<N;j+=i)for(int k=0;k<i>>1;++k)
	{
		cp t=a[j+k+(i>>1)]*w[r][N/i*k];
		a[j+k+(i>>1)]=a[j+k]-t;
		a[j+k]=a[j+k]+t;
	}
	if(r) for(int i=0;i<N;++i) a[i]=a[i]/N;
}
long long R(double t){return (long long)(t+0.5);}
void Mul(int*A,int*B,int L)
{
	int t=pow(2,L);
	for(int i=0,j=1;i<N;++i) 
	{
		int pt=1LL*A[i]*j%mod;j=1LL*j*t%mod; 
		a[i]=cp(pt>>15,0);b[i]=cp(B[i]>>15,0);
		c[i]=cp(pt&32767,0);d[i]=cp(B[i]&32767,0);
	}
	FFT(a,0);FFT(b,0);FFT(c,0);FFT(d,0);
	for(int i=0;i<N;++i) 
	{
		cp t=c[i];
		c[i]=a[i]*d[i]+b[i]*c[i];
		d[i]=t*d[i];
		a[i]=a[i]*b[i];
	}
	FFT(a,1);FFT(c,1);FFT(d,1);
	for(int i=0;i<=k;++i) A[i]=(((R(a[i].r)%mod)<<30)%mod+((R(c[i].r)%mod)<<15)%mod+R(d[i].r))%mod;
}

int main()
{
	cin>>n>>k;if(n>k) return 0*puts("0");
	for(N=1;N<=k;N<<=1);N<<=1;
	for(int i=0;i<=N;++i) w[0][i]=w[1][N-i]=cp(cos(2*pi/N*i),sin(2*pi/N*i));
	p[0]=p[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=k;++i) p[i]=1LL*p[i-1]*i%mod,inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=k;++i) inv[i]=1LL*inv[i-1]*inv[i]%mod;
	B[0]=1;
	for(int i=1;i<=k;++i) A[i]=inv[i]%mod;
	for(int len=1;n;n>>=1,Mul(A,A,len),len<<=1) if(n&1) Mul(B,A,len);
	int ans=0;
	for(int i=1;i<=k;++i) ans=(ans+1LL*C(k,i)*B[i]%mod*p[i])%mod;
	printf("%d\n",ans);
	return 0;
}