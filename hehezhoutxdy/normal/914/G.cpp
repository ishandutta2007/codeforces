// Problem: G. Sum the Fibonacci
// Contest: Codeforces - Codecraft-18 and Codeforces Round #458 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/problemset/problem/914/G
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
void FWT_OR(int*F,int n)
{
	for(int w=2,j=1; w<=n; w<<=1,j<<=1)
		for(int i=0; i<n; i+=w)
			for(int k=0; k<j; ++k)
				((F[i+j+k]+=F[i+k])>=p)&&(F[i+j+k]-=p);
}
void FWT_IOR(int*F,int n)
{
	for(int w=2,j=1; w<=n; w<<=1,j<<=1)
		for(int i=0; i<n; i+=w)
			for(int k=0; k<j; ++k)
				((F[i+j+k]-=F[i+k])<0)&&(F[i+j+k]+=p);
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
void FWT_XOR(int*F,int n)
{
	for(int w=2,j=1; w<=n; w<<=1,j<<=1)
		for(int i=0; i<n; i+=w)
			for(int k=0,A,B; k<j; ++k)
				A=F[i+k],B=F[i+j+k],((F[i+k]=A+B)>=p)&&(F[i+k]-=p),((F[i+j+k]=A-B)<0)&&(F[i+j+k]+=p);
}
const int P=(p+1)>>1;
void FWT_IXOR(int*F,int n)
{
	for(int w=2,j=1; w<=n; w<<=1,j<<=1)
		for(int i=0; i<n; i+=w)
			for(int k=0,A,B; k<j; ++k)
				A=1ll*P*F[i+k]%p,B=1ll*P*F[i+j+k]%p,((F[i+k]=A+B)>=p)&&(F[i+k]-=p),((F[i+j+k]=A-B)<0)&&(F[i+j+k]+=p);
}
int a[1<<17],b[1<<17],c[1<<17],f[1<<17],A[18][1<<17],F[18][1<<17];
const int N=1<<17;
signed main()
{
	f[0]=0,f[1]=1;
	for(int i=2; i<N; ++i) f[i]=(f[i-2]+f[i-1])%p;
	for(int T=read(); T--;) ++a[read()];
	memcpy(b,a,sizeof(a)),memcpy(c,a,sizeof(a));
	for(int i=0; i<N; ++i) A[__builtin_popcount(i)][i]=a[i];
	for(int i=0; i<=17; ++i) FWT_OR(A[i],N);
	for(int i=0; i<=17; ++i)
		for(int j=0; i+j<=17; ++j)
			for(int k=0; k<N; ++k)
				F[i+j][k]=(1ll*A[i][k]*A[j][k]+F[i+j][k])%p;
	for(int i=0; i<=17; ++i) FWT_IOR(F[i],N);
	for(int i=0; i<N; ++i) a[i]=F[__builtin_popcount(i)][i];
	FWT_XOR(b,N);
	for(int i=0; i<N; ++i) b[i]=1ll*b[i]*b[i]%p;
	FWT_IXOR(b,N);
	for(int i=0; i<N; ++i) a[i]=1ll*f[i]*a[i]%p;
	for(int i=0; i<N; ++i) b[i]=1ll*f[i]*b[i]%p;
	for(int i=0; i<N; ++i) c[i]=1ll*f[i]*c[i]%p;
	FWT_AND(a,N),FWT_AND(b,N),FWT_AND(c,N);
	for(int i=0; i<N; ++i) a[i]=1ll*a[i]*b[i]%p*c[i]%p;
	int ans=0;
	FWT_IAND(a,N);
	for(int i=0; i<17; ++i) ans=(ans+a[1<<i])%p;
	printf("%d\n",ans);
	return 0;
}