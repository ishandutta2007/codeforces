// Problem: C. Tyler and Strings
// Contest: Codeforces Round #775 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/contest/1648/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int c[200003],b[200003];
int fac[200003],ifac[200003];
const int N=200000;
int tree[200003],val[200003];
void setval(int x,int k)
{
	int K=k;
	k=(k+p-val[x])%p,val[x]=K;
	while(x<=N) tree[x]=(tree[x]+k)%p,x+=x&(-x);
	return ;
}
int find(int x)
{
	int res=0;
	while(x) res=(res+tree[x])%p,x-=x&(-x);
	return res;
}
signed main()
{
	int n=read(),m=read();
	fac[0]=ifac[0]=1;
	for(int i=1; i<=N; ++i) 
		fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	for(int i=1; i<=n; ++i) ++c[read()];
	for(int i=1; i<=m; ++i) b[i]=read();
	int S=fac[n];
	for(int i=1; i<=N; ++i) S=S*ifac[c[i]]%p; 
	for(int i=1; i<=N; ++i) if(c[i]) 
		setval(i,fac[c[i]]*ifac[c[i]-1]%p);
	int ans=0;
	for(int i=1; i<=m; ++i)
	{
		S=S*ifac[n+1-i]%p*fac[n-i]%p;
		ans=(ans+S*find(b[i]-1)%p)%p;
		if(!c[b[i]]) break;
		S=S*fac[c[b[i]]]%p*ifac[c[b[i]]-1]%p,--c[b[i]];
		if(c[b[i]]) 
			setval(b[i],fac[c[b[i]]]*ifac[c[b[i]]-1]%p);
		else setval(b[i],0);
		// printf("%lld\n",ans);
		if(i==n&&n<m)
		{
			ans=(ans+1)%p;
			break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}/////////////////////////////////////