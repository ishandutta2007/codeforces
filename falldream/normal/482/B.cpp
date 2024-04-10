#include<iostream>
#include<cstdio>
#define N 131072
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,T[N*2+5],L[N+5],R[N+5],X[N+5];
void Modify(int l,int r,int x)
{
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) T[l+1]|=x;
		if( r&1) T[r-1]|=x; 
	}
}
int Query(int l,int r)
{
	int res=(1<<30)-1;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) res&=T[l+1];
		if( r&1) res&=T[r-1]; 
	}
	return res;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		L[i]=read();R[i]=read();X[i]=read();
		Modify(L[i],R[i],X[i]);
	} 
	for(int i=1;i<=n;++i) for(int j=i+N;j>>=1;) T[i+N]|=T[j];
	for(int i=N;i;--i) T[i]=T[i<<1]&T[i<<1|1];
	for(int i=1;i<=m;++i)
		if(Query(L[i],R[i])!=X[i]) return 0*puts("NO");
	puts("YES");
	for(int i=1;i<=n;++i) printf("%d ",T[i+N]);
	return 0;
}