#include<bits/stdc++.h>
#define MN 200000
const double pi=acos(-1);
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,X,a[MN+5],N;
long long res[MN+5];
struct cp
{
	double r,u;
	cp(double _r=0,double _u=0):r(_r),u(_u){}
	cp operator + (const cp&y){return cp(r+y.r,u+y.u);}
	cp operator - (const cp&y){return cp(r-y.r,u-y.u);}
	cp operator * (const cp&y){return cp(r*y.r-u*y.u,r*y.u+u*y.r);}
	cp operator / (double y){return cp(r/y,u/y);}
}w[2][262145],A[262145],B[262145];
void FFT(cp*x,int r)
{
	for(int i=0,j=0;i<N;++i)
	{
		if(i>j) swap(x[i],x[j]);
		for(int k=N>>1;(j^=k)<k;k>>=1);	
	}
	for(int i=2;i<=N;i<<=1)for(int j=0;j<N;j+=i)for(int k=0;k<i>>1;++k)
	{
		cp t=x[j+k+(i>>1)]*w[r][N/i*k];
		x[j+k+(i>>1)]=x[j+k]-t;
		x[j+k]=x[j+k]+t;	
	}
	if(r)for(int i=0;i<N;++i) x[i]=x[i]/N;
}
void Solve(int l,int r)
{
	if(l==r) {++res[a[l]];return;}
	int mid=l+r>>1;
	Solve(l,mid);Solve(mid+1,r);
	for(N=1;N<=r-l+1;N<<=1);
	for(int i=0;i<=N;++i) w[0][i]=w[1][N-i]=cp(cos(2*i*pi/N),sin(2*i*pi/N)),A[i]=B[i]=cp(0,0);
	for(int i=mid,j=0;i>=l;--i) ++A[j+=a[i]].r;
	for(int i=mid+1,j=0;i<=r;++i) ++B[j+=a[i]].r;
	FFT(A,0);FFT(B,0);
	for(int i=0;i<N;++i) A[i]=A[i]*B[i];
	FFT(A,1);
	for(int i=0;i<N;++i) res[i]+=(long long)(A[i].r+0.5);
}
int main()
{
	n=read();X=read();
	for(int i=1;i<=n;++i) a[i]=read()<X;
	Solve(1,n);
	for(int i=0;i<=n;++i) printf("%lld ",res[i]);
	return 0;
}