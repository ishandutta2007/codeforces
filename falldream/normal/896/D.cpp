#include<iostream>
#include<cstdio>
#define MN 100000
#define pa pair<int,int>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,l,r,mod,P[100],V[100],res[100],num=0,f[MN+5],g[MN+5],Mod;
inline int pow(int x,int k,int M)
{
	int sum=1;	
	for(;k;k>>=1,x=1LL*x*x%M) if(k&1) sum=1LL*sum*x%M;
	return sum;
}
inline int C(int n,int m,int p,int v)
{
	if(m<0||n<m) return 0;
	return 1LL*f[n]*pow(f[m],Mod/p*(p-1)-1,Mod)%Mod*pow(f[n-m],Mod/p*(p-1)-1,Mod)%Mod*pow(p,g[n]-g[m]-g[n-m],Mod)%Mod;
}
void Solve(int p,int v)
{
	++num;P[num]=p;V[num]=v;f[0]=1;Mod=pow(p,v,mod+1);
	for(int i=1;i<=n;++i) 
	{
		f[i]=f[i-1];g[i]=g[i-1];int t=i;
		while(t%p==0) t/=p,++g[i];
		f[i]=1LL*f[i]*t%Mod;
	}
	for(int i=0;i<=n;++i)
	{
		int R=r,L=l;
		if((R&1)!=(i&1)) --R;
		if((L&1)!=(i&1)) ++L;
		int Mx=min(i,R);if(Mx<L) continue;
		res[num]=(res[num]+1LL*C(n,i,p,v)*(C(i,(i-L)/2,p,v)+Mod-C(i,(i-Mx)/2-1,p,v)))%Mod;
	}
}
int main()
{
	n=read();mod=read();l=read();r=read();	
	if(mod==1) return 0*puts("0");
	int t=mod;
	for(int i=2;i<=100000;++i) if(t%i==0)
	{
		int v=0;
		while(t%i==0) t/=i,++v;
		Solve(i,v);
	}
	if(t>1) Solve(t,1);int ans=0;
	for(int i=1,M;i<=num;++i) M=pow(P[i],V[i],mod+1),ans=(ans+1LL*res[i]*(mod/M)%mod*pow(mod/M,M/P[i]*(P[i]-1)-1,M))%mod; 
	printf("%d\n",ans);
	return 0;
}