#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define MN 524288
const double pi=acos(-1);
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char s[MN+5],S[MN+5];
int n,m,K,p[4][MN+5],N,flag[MN+5];
struct cp
{
	double r,u;	
	cp(double _r=0,double _u=0):r(_r),u(_u){}
	cp operator + (const cp&b){return cp(r+b.r,u+b.u);}
	cp operator - (const cp&b){return cp(r-b.r,u-b.u);}
	cp operator * (const cp&b){return cp(r*b.r-u*b.u,r*b.u+u*b.r);}
	cp operator / (double b){return cp(r/b,u/b);}
}A[MN+5],B[MN+5],w[2][MN+5];
void FFT(cp*x,int r)
{
	for(int i=0,j=0;i<N;++i)
	{
		if(i>j) swap(x[i],x[j]);
		for(int k=N>>1;(j^=k)<k;k>>=1);
	}
	for(int i=2;i<=N;i<<=1)for(int j=0;j<N;j+=i)for(int k=0;k<i>>1;++k)
	{
		cp t=w[r][N/i*k]*x[j+k+(i>>1)];
		x[j+k+(i>>1)]=x[j+k]-t;
		x[j+k]=x[j+k]+t;	
	}
	if(r) for(int i=0;i<N;++i) x[i]=x[i]/N;
}
inline int Get(char s)
{
	if(s=='A') return 0;
	if(s=='C') return 1;
	if(s=='G') return 2;
	if(s=='T') return 3;	
}
int main()
{
	n=read();m=read();K=read();
	scanf("%s",s+1);scanf("%s",S+1);
	for(int i=1;i<=n;++i)
	{
		++p[Get(s[i])][max(1,i-K)];
		--p[Get(s[i])][i+K+1];	
	}
	for(N=1;N<=n;N<<=1);N<<=1;
	for(int i=0;i<=N;++i) w[0][i]=w[1][N-i]=cp(cos(2*pi/N*i),sin(2*pi/N*i));
	for(int i=0;i<4;++i)
	{
		for(int j=1;j<=n;++j) p[i][j]+=p[i][j-1];
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		for(int j=1;j<=n;++j) A[j]=cp(!p[i][j],0);
		for(int j=0;j<m;++j) B[j]=cp(Get(S[m-j])==i,0);
		FFT(A,0);FFT(B,0);
		for(int j=0;j<N;++j) A[j]=A[j]*B[j];
		FFT(A,1);
		for(int j=m;j<=n;++j) flag[j]|=int(A[j].r+0.5);
	}
	int ans=0;
	for(int j=m;j<=n;++j) ans+=!flag[j];
	printf("%d\n",ans);
	return 0;
}