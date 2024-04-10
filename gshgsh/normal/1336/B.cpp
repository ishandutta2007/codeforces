#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,M,K,a[MAXN],b[MAXN],c[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void solve(int N,int M,int K,int*a,int*b,int*c,ll&ans)
{
	For(i,1,N)
	{
		int x=lower_bound(b+1,b+M+1,a[i])-b;
		if(x<=M)
		{
			int y=lower_bound(c+1,c+K+1,a[i]+b[x]>>1)-c;
			if(y<=K)ans=min(ans,1ll*(a[i]-b[x])*(a[i]-b[x])+1ll*(a[i]-c[y])*(a[i]-c[y])+1ll*(b[x]-c[y])*(b[x]-c[y]));
			if(y>1){y--;ans=min(ans,1ll*(a[i]-b[x])*(a[i]-b[x])+1ll*(a[i]-c[y])*(a[i]-c[y])+1ll*(b[x]-c[y])*(b[x]-c[y]));}
			y=lower_bound(c+1,c+K+1,a[i]+b[x]+1>>1)-c;
			if(y<=K)ans=min(ans,1ll*(a[i]-b[x])*(a[i]-b[x])+1ll*(a[i]-c[y])*(a[i]-c[y])+1ll*(b[x]-c[y])*(b[x]-c[y]));
			if(y>1){y--;ans=min(ans,1ll*(a[i]-b[x])*(a[i]-b[x])+1ll*(a[i]-c[y])*(a[i]-c[y])+1ll*(b[x]-c[y])*(b[x]-c[y]));}
		}
		if(x>1)
		{
			x--;
			int y=lower_bound(c+1,c+K+1,a[i]+b[x]>>1)-c;
			if(y<=K)ans=min(ans,1ll*(a[i]-b[x])*(a[i]-b[x])+1ll*(a[i]-c[y])*(a[i]-c[y])+1ll*(b[x]-c[y])*(b[x]-c[y]));
			if(y>1){y--;ans=min(ans,1ll*(a[i]-b[x])*(a[i]-b[x])+1ll*(a[i]-c[y])*(a[i]-c[y])+1ll*(b[x]-c[y])*(b[x]-c[y]));}
			y=lower_bound(c+1,c+K+1,a[i]+b[x]+1>>1)-c;
			if(y<=K)ans=min(ans,1ll*(a[i]-b[x])*(a[i]-b[x])+1ll*(a[i]-c[y])*(a[i]-c[y])+1ll*(b[x]-c[y])*(b[x]-c[y]));
			if(y>1){y--;ans=min(ans,1ll*(a[i]-b[x])*(a[i]-b[x])+1ll*(a[i]-c[y])*(a[i]-c[y])+1ll*(b[x]-c[y])*(b[x]-c[y]));}
		}
	}
}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get(),K=get();For(i,1,N)a[i]=get();For(i,1,M)b[i]=get();For(i,1,K)c[i]=get();sort(a+1,a+N+1);sort(b+1,b+M+1);sort(c+1,c+K+1);
		ll ans=8e18;solve(N,M,K,a,b,c,ans);solve(N,K,M,a,c,b,ans);solve(M,N,K,b,a,c,ans);solve(M,K,N,b,c,a,ans);solve(K,N,M,c,a,b,ans);solve(K,M,N,c,b,a,ans);cout<<ans<<'\n';
	}
	return 0;
}