#include<bits/stdc++.h>
#define ll long long
#define LL __int128
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
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
	pc(x%10+'0',0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=3005,mod=1e9+7;
int n,m;
struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
int siz[xx],f[xx][xx];
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
void dfs(int x,int y)
{
	siz[x]=1;
	for(int i=1;i<=3001;i++)f[x][i]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x),siz[x]+=siz[e[i].to];
		for(int j=1;j<=3001;j++)f[x][j]=1ll*f[x][j]*f[e[i].to][j]%mod;
	}
//	if(x!=1)
	for(int i=1;i<=3001;i++)ad(f[x][i],f[x][i-1]);
}
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
struct Pr{int x,y;};
ll solve(vector<Pr>&v,int n,int m)
{
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ll res=1,re=1;
		for(int j=0;j<n;j++)
		{
			if(i==j)continue;
			res*=(m-v[j].x+mod),res%=mod;
			re*=(v[i].x-v[j].x+mod),re%=mod;
		}
		res*=ksm(re,mod-2),res%=mod;
		res*=v[i].y,res%=mod;
		ans+=res,ans%=mod;
	}
	return ans;
}
vector<Pr>v;
signed main(){
	n=read(),m=read();
	for(int i=2;i<=n;i++)add(read(),i);
	dfs(1,0);
	//n+1 
	for(int i=1;i<=n+1;i++)
		v.push_back({i,f[1][i]});
//	for(int i=1;i<=100;i++)cout<<f[1][i]<<" "<<solve(v,v.size(),i)<<"\n";
	cout<<solve(v,v.size(),m)<<"\n";
	pc('1',1);
	return 0;
}