// Problem: F. Bingo
// Contest: Codeforces - Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
// URL: https://codeforces.com/contest/1530/problem/F
// Memory Limit: 512 MB
// Time Limit: 7000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//what the hell
//And in that light,I find deliverance.
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=31607;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}

void FWT_AND(int*F,int n)
{
	for(int w=2,j=1; w<=n; w<<=1,j<<=1)
		for(int i=0; i<n; i+=w)
			for(int k=0; k<j; ++k)
				((F[i+k]+=F[i+j+k])>=p)&&(F[i+k]-=p);
}
void FWT_IAND(int*F,int n)
{
	for(int w=2,j=1; w<=n; w<<=1,j<<=1)
		for(int i=0; i<n; i+=w)
			for(int k=0; k<j; ++k)
				((F[i+k]-=F[i+j+k])<0)&&(F[i+k]+=p);
}
int a[21][21],b[21][21];
int f[1<<21],g[1<<21];
int n,N;
void DFS(int C,int x,int y,int d)
{
	if(d==n){g[x]=y;return ;}
	DFS(C,x,(p+1-a[C][d])*y%p,d+1);
	DFS(C,x+(1<<d),a[C][d]*y%p,d+1);
}
signed main()
{
	int x=qp(10000,p-2);
	n=read(),N=1<<n;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j) a[i][j]=x*read()%p,b[i][j]=a[i][j];
	int ans=1;

	for(int i=0; i<n; ++i)
	{
		int tot=1;
		for(int j=0; j<n; ++j) tot=tot*a[i][j]%p;
		ans=ans*(p+1-tot)%p;
	}
	ans=(p+1-ans)%p;
#undef local
#ifdef local
	printf("%d\n",ans);
#endif
		
	for(int i=0; i<N; ++i) f[i]=1;
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<N; ++j) g[j]=1;
		DFS(i,0,1,0);
		g[N-1]=0;
		FWT_AND(g,N);
		for(int i=0; i<N; ++i) f[i]=f[i]*g[i]%p;
	}
	FWT_IAND(f,N);
	for(int j=1; j<N; ++j) ans=(ans+f[j])%p;

#ifdef local
	printf("%d\n",ans);
#endif
	
	for(int i=0; i<N; ++i) f[i]=1;
	for(int i=0; i<n; ++i) a[i][i]=1;
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<N; ++j) g[j]=1;
		DFS(i,0,1,0);
		g[N-1]=0;
		FWT_AND(g,N);
		for(int i=0; i<N; ++i) f[i]=f[i]*g[i]%p;
	}
	for(int i=0; i<n; ++i) a[i][i]=b[i][i];
	FWT_IAND(f,N);
	int K=1;
	for(int i=0; i<n; ++i) K=K*b[i][i]%p;
	ans=(ans+K*f[0])%p;
	
#ifdef local
	printf("%d\n",ans);
#endif
	
	for(int i=0; i<N; ++i) f[i]=1;
	for(int i=0; i<n; ++i) a[i][n-1-i]=1;
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<N; ++j) g[j]=1;
		DFS(i,0,1,0);
		g[N-1]=0;
		FWT_AND(g,N);
		for(int i=0; i<N; ++i) f[i]=f[i]*g[i]%p;
	}
	FWT_IAND(f,N);
	int K1=1;
	for(int i=0; i<n; ++i) K1=K1*b[i][n-1-i]%p;
	ans=(ans+K1*f[0])%p;
	
#ifdef local
	printf("%d\n",ans);
#endif

	for(int i=0; i<N; ++i) f[i]=1;
	for(int i=0; i<n; ++i) a[i][i]=1;
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<N; ++j) g[j]=1;
		DFS(i,0,1,0);
		g[N-1]=0;
		FWT_AND(g,N);
		for(int i=0; i<N; ++i) f[i]=f[i]*g[i]%p;
	}
	FWT_IAND(f,N);
	int K2=K*K1%p;
	//ans=(ans+p-K2)%p;
	if(n&1) K2=K2*qp(b[n/2][n/2],p-2)%p;
	ans=(ans+p-K2*f[0]%p)%p;
	
	printf("%d\n",ans);
	return 0;
}