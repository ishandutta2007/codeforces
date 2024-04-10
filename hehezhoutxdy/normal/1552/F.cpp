// Problem: F. Telepanting
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
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
int tree[1000003],f[1000003];
int n=read();
void add(int x,int k)
{
	while(x<=n) tree[x]=(tree[x]+k)%p,x+=x&(-x);
	return ;
}
int find(int x)
{
	int res=0;
	while(x) res=(res+tree[x])%p,x-=x&(-x);
	return res;
}
int sum(int l,int r)
{
	if(l>r) return 0;
	return (p+find(r)-find(l-1))%p;
}
int a[1000003],b[1000003],c[1000003],op[1000003];
signed main()
{
	
	for(int i=1; i<=n; ++i) a[i]=read(),c[i]=read(),op[i]=read();
	for(int i=1; i<=n; ++i) b[i]=lower_bound(a+1,a+n+1,c[i])-a,c[i]=a[b[i]]-c[i];
	a[n+1]=a[n]+1;
	//for(int i=1; i<=n; ++i) printf("%lld %lld\n",b[i],c[i]);
	for(int i=1; i<=n; ++i) 
		f[i]=(a[i+1]-a[i]+c[i]+sum(b[i],i-1))%p,
		add(i,f[i]);
	int ans=a[1];
	for(int i=1; i<=n; ++i)
	{
		if(op[i]==0) ans=(ans+a[i+1]-a[i])%p;
		else ans=(ans+f[i])%p;
	}
	printf("%lld\n",ans);
	return 0;
}