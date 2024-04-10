#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define int long long 
#define dd double
#define LL __int128
#define ull unsigned ll 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=1e5+5,mod=1e9+7;
struct nod
{
	int next,to;
}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
int n,f[xx][2];
void dfs(int x,int y)
{
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=y)dfs(e[i].to,x),f[e[i].to][0]++;
	f[x][1]=1;
	int tt=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		++tt;
		int g[2]={0,0};
		g[0]=(1ll*f[x][0]*f[e[i].to][0]+1ll*f[x][1]*f[e[i].to][1])%mod;
		g[1]=(1ll*f[x][0]*f[e[i].to][1]+1ll*f[x][1]*f[e[i].to][0])%mod;
		f[x][0]=g[0],f[x][1]=g[1];
	}
//	cerr<<f[x][0]<<" "<<f[x][1]<<"!\n";
//	cerr<<x<<" "<<f[x][0]<<" "<<f[x][1]<<" "<<f[4][0]<<"!\n";
	if(tt)
	{
		// 
		f[x][0]=2*f[x][0]%mod,f[x][1]=2*f[x][1]%mod;
		ll sm=1;
		for(int i=h[x];i;i=e[i].next)
			if(e[i].to!=y)sm=1ll*sm*f[e[i].to][0]%mod;
		f[x][1]=(f[x][1]-sm+mod)%mod;
		// 
//		if((tt&1))
//		{
			ll t[2]={1,0};
			for(int i=h[x];i;i=e[i].next)
			{
				if(e[i].to!=y)
				{
					ll g[2]={t[0]+t[1]*f[e[i].to][1],t[1]+t[0]*f[e[i].to][1]};
					t[0]=g[0]%mod;
					t[1]=g[1]%mod;
//					sm=1ll*sm*(f[e[i].to][1]+1);
				}
				
			}
//			--sm;//   0   
			f[x][0]=(f[x][0]-t[1]+mod)%mod;
//		}
		f[x][0]%=mod,f[x][1]%=mod;
	}
//	cerr<<x<<" "<<f[x][0]<<" "<<f[x][1]<<"!\n";
}
mt19937 G(218);
int main(){
//	freopen("a.in","r",stdin);
	n=read();
//	n=8;
//	for(int i=2,f;i<=n;i++)cerr<<(G()%(i-1))+1<<"\n";
	for(int i=2,f;i<=n;i++)add(f=/*G()%(i-1)+1*/read(),i),add(i,f);
	dfs(1,0);
	cout<<(f[1][0]+f[1][1])%mod<<"\n";
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}