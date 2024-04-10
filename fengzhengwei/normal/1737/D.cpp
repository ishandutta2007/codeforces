#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
namespace ppprrr{const int xx=2,mod=2;ll ksm(ll a,ll b){ll ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod,b>>=1;}return ans;}

ll jiec[xx],ni[xx];
ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
void pre()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
}
	
int prim[xx],mn[xx],Cnt;
void pre(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!mn[i])mn[i]=i,prim[++Cnt]=i;
		for(int j=1;j<=Cnt;j++)
		{
			if(prim[j]*i>n)break;
			mn[i*prim[j]]=prim[j];
			if(i%prim[j]==0)break;
		}
	}
}


int lb(int x){return x&-x;}
ll sum[xx];
void Add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}
ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}

struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}


}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
//co 
const int xx=1e6+5,mod=998244353;
//mod1e9+7998 
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
struct pr{int x,y;};
int n,m,k,b[xx];
char s[xx];
ll a[505][505];
ll f[505][505];
int g[505][505];
ll dp[505];
queue<pair<int,int> >q;
void upd(int a,int b,int c,int d)
{
	if(f[c][d]>f[a][b]+1)
	{
		f[c][d]=f[a][b]+1;
		q.push({c,d});
	}
}
int main(){
	int T=read();
	while(T--)
	{
		n=read(),m=read();
//		memset(dp,0x3f,sizeof(dp));
		memset(a,0x3f,sizeof(a));
		memset(f,0x3f,sizeof(f));
//		memset(g,0x3f,sizeof(g));
		vector<int>lsh;
		for(int i=1;i<=m;i++)
		{
			int x=read(),y=read();
			ll z=read();
			a[x][y]=a[y][x]=min(a[x][y],z);
//			g[x][y]=g[y][x]=1;
		}
//		lsh.push_back(a[0][0]);
//		sort(lsh.begin(),lsh.end());
//		lsh.resize(unique(lsh.begin(),lsh.end())-lsh.begin());
		f[1][n]=1;
		f[n][1]=1;
		q.push({1,n});
		q.push({n,1});
		while(!q.empty())
		{
			int x=q.front().first,y=q.front().second;
			q.pop();
//			upd(x,y,x,x);
//			upd(x,y,y,y);
			for(int i=1;i<=n;i++)
				if(a[x][i]<=1e9)upd(x,y,i,y);
			for(int i=1;i<=n;i++)
				if(a[y][i]<=1e9)upd(x,y,x,i);
			if(x==y)
			{
				for(int i=1;i<=n;i++)upd(x,y,i,y);
				for(int i=1;i<=n;i++)upd(x,y,x,y);
//				
			}
		}
		ll ans=1e18;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
//				cerr<<i<<" "<<j<<" "<<f[i][j]<<"@\n";
				if(a[i][j]<=1e9)ans=min(ans,a[i][j]*f[i][j]);
			}
		}
		cout<<ans<<"\n";
//		for(int i=1;i<=n;i++)f[i][i]=g[i][i]=0;
//		for(int k=1;k<=n;k++)
//		{
//			for(int i=1;i<=n;i++)
//			{
//				for(int j=1;j<=n;j++)
//				{
//					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
//				}
//			}
//		}
//		dp[1]=0;
//		vector<int>vis(n+2);
//		for(int i=1;i<=n;i++)
//		{
//			int id=0;
//			for(int j=1;j<=n;j++)
//				if(!vis[j]&&(!id||dp[j]<dp[id]))id=j;
//			for(int j=1;j<=n;j++)
//			{
//				if(a[id][j]<=1e9)
//				{
//					for(int k=1;k<=n;k++)
//						dp[k]=min(dp[k],a[id][j]*(g[j][k]+1));
//				}
//			}
//		}
//		cout<<dp[n]<<"\n";
	}
	pc('1',1);
	return 0;
}