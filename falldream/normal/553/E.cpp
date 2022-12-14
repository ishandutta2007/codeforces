#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath> 
#define MN 65536
const double pi=acos(-1);
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int p[105][20005],suf[105][20005],n,m,t,fine,X[105],Y[105],W[105],d[55][55],F[55],N;
double P[20005][105],f[20005][55];
struct cp
{
	double r,u;	
	cp(double _r=0,double _u=0):r(_r),u(_u){}
	cp operator + (const cp&b){return cp(r+b.r,u+b.u);}
	cp operator - (const cp&b){return cp(r-b.r,u-b.u);}
	cp operator * (const cp&b){return cp(r*b.r-u*b.u,r*b.u+u*b.r);}
	cp operator / (double b){return cp(r/b,u/b);}
}a[MN+5],b[MN+5],w[2][MN+5];

void init_eps(int N){for(int i=0;i<=N;++i) w[0][i]=w[1][N-i]=cp(cos(2*pi/N*i),sin(2*pi/N*i));}
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
	if(r)for(int i=0;i<N;++i)x[i]=x[i]/N;
}

void Solve(int l,int r)
{
	if(l==r) 
	{
		for(int i=1;i<=m;++i)
		{
			P[l][i]+=(double)suf[i][l]*F[Y[i]]/1e5+W[i];
	//		printf("P[%d][%d]=%.10lf\n",l,i,P[l][i]);
			f[l][X[i]]=min(f[l][X[i]],P[l][i]);	
		}
	//	for(int i=1;i<=n;++i) printf("f[%d][%d]=%.10lf\n",l,i,f[l][i]);
		return;
	}
	int mid=l+r>>1;Solve(l,mid);
	for(N=1;N<=r-l;N<<=1);init_eps(N);
	for(int i=1;i<=m;++i)
	{
		memset(a,0,sizeof(cp)*(N+2));
		memset(b,0,sizeof(cp)*(N+2));
		for(int j=1;j<=r-l;++j) b[j]=cp((double)p[i][j]/100000,0);
		for(int j=l;j<=mid;++j) a[j-l]=cp(f[j][Y[i]],0);
	//	for(int j=0;j<N;++j) printf("%.10lf ",a[j].r);cout<<endl;
	//	for(int j=0;j<N;++j) printf("%.10lf ",b[j].r);cout<<endl;
		FFT(a,0);FFT(b,0);
		for(int j=0;j<N;++j) a[j]=a[j]*b[j];
		FFT(a,1);
	//	for(int j=0;j<N;++j) printf("%.10lf ",a[j].r);cout<<endl;
		for(int j=mid+1;j<=r;++j) P[j][i]+=a[j-l].r;//printf("solve %d %d %d id=%d ->%d:%.10lf\n",l,mid,r,i,j,a[j-l].r);
	}
	Solve(mid+1,r);	
}

int main()
{
	n=read();m=read();t=read();fine=read();
	memset(d,40,sizeof(d));
	for(int i=1;i<=t+1;++i) for(int j=1;j<=n;++j) f[i][j]=j==n?0:1e18;
	for(int i=1;i<=n;++i) d[i][i]=0; 
	for(int i=1;i<=m;++i)
	{
		X[i]=read();Y[i]=read();W[i]=read();
		d[X[i]][Y[i]]=min(d[X[i]][Y[i]],W[i]);
		for(int j=1;j<=t;++j) p[i][j]=read();
		for(int j=t;j>=1;--j) suf[i][j]=suf[i][j+1]+p[i][j];
	}
	for(int k=1;k<=n;++k) for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
		if(d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j];
	for(int i=1;i<=n;++i) F[i]=d[i][n]+fine;
	Solve(1,t+1);
	printf("%.10lf\n",f[t+1][1]);
	return 0;
}