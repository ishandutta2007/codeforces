#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 150001
int N,M,L,a[MAXN],b[MAXN],t[MAXN],q[MAXN];ll f[MAXN],g[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),M=get(),L=get();For(i,1,M)a[i]=get(),b[i]=get(),t[i]=get();For(i,1,N)f[i]=b[1]-abs(a[1]-i);
	For(j,2,M)
	{
		For(i,1,N)g[i]=f[i];int lim=min(N-1ll,1ll*L*(t[j]-t[j-1])),l=1,r=0,y=1;
		For(i,1,N)
		{
			while(l<=r&&q[l]<i-lim)l++;while(y<=min(i+lim,N)){while(l<=r&&g[q[r]]<g[y])r--;q[++r]=y++;}
			f[i]=g[q[l]]+b[j]-abs(a[j]-i);
		}
	}
	ll ans=f[1];For(i,2,N)ans=max(ans,f[i]);cout<<ans<<'\n';return 0;
}