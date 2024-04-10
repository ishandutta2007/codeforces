#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int T,n;
const int xx=2e5+5;
struct node{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
ll f[xx],a[xx];
int dep[xx],F[xx];
vector<int>v[xx];
void dfs(int x,int y)
{
	dep[x]=dep[y]+1,F[x]=y;
	v[dep[x]].push_back(x);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
	}
}
signed main(){
	T=read();
	while(T--)
	{
		memset(e,0,sizeof(e[0])*(cnt+1));
		n=read();
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=2;i<=n;i++)add(read(),i);
		for(int i=2;i<=n;i++)a[i]=read();
		dfs(1,0);
		memset(f,0,sizeof(f));
		ll ans=0;
		for(int i=2;i<=n;i++)
		{
			ll mx=-1e18,mn=1e18;
			for(auto it:v[i])mx=max(mx,a[it]),mn=min(mn,a[it]);
			for(auto it:v[i])f[it]=f[F[it]]+max(mx-a[it],a[it]-mn);
			mx=-1e18;
			for(auto it:v[i])mx=max(mx,f[F[it]]-a[it]);
			for(auto it:v[i])f[it]=max(f[it],a[it]+mx);
			mx=-1e18;
			for(auto it:v[i])mx=max(mx,f[F[it]]+a[it]);
			for(auto it:v[i])f[it]=max(f[it],-a[it]+mx);
		}
		for(int i=1;i<=n;i++)ans=max(ans,f[i]);
		cout<<ans<<"\n";
	}
    return 0;
}