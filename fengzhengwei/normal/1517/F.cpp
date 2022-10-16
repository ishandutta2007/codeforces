#include<bits/stdc++.h>
#define ll long long 
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
	wt(x),pc(op,0);
}
const int xx=315;
int n;
struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}
const int mod=998244353;
int md[xx];
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
ll ans[xx];
//dlt 
//dlt=xx 
ll f[xx][xx<<1];
ll g[xx<<1];
int dep[xx],to;
void ad(ll &a,ll b){a+=b,a%=mod;}
void dfs(int x,int y)
{
	dep[x]=dep[y]+1,md[x]=dep[x];
	f[x][xx+0]=1;
	//0-1 
	f[x][xx-to-1]=1;
//	cout<<f[x][xx-to-1]<<" "<<x<<" "<<xx+-to-1<<" "<<to<<"\n";
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		memset(g,0,sizeof(g));
		vector<int>usa,usb;
		for(int j=xx-to-1;j<=xx+md[x]-dep[x];j++)if(f[x][j])usa.push_back(j);
		for(int j=xx-to-1;j<=xx+md[e[i].to]-dep[e[i].to];j++)if(f[e[i].to][j])usb.push_back(j);
		for(auto a:usa)
		{
			for(auto b:usb)
			{
				if(a>=xx&&b>=xx)
					ad(g[max(a,b+1)],f[x][a]*f[e[i].to][b]);
				if(a<xx&&b<xx)
					ad(g[min(a,(b+1))],f[x][a]*f[e[i].to][b]);
				if(a<xx&&b>=xx)
				{
					if(-(a-xx+1)>=b-xx+1)ad(g[a],f[x][a]*f[e[i].to][b]);
					else ad(g[b+1],f[x][a]*f[e[i].to][b]);
				}
				if(a>=xx&&b<xx)
				{
					if(-(b-xx+2)>=a-xx)ad(g[b+1],f[x][a]*f[e[i].to][b]);
					else ad(g[a],f[x][a]*f[e[i].to][b]);
				}
			}
		}
		md[x]=max(md[x],md[e[i].to]);
		for(int j=xx-to-1;j<=xx+md[x]-dep[x];j++)f[x][j]=g[j];
	}
}
int main(){
	n=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	//ddd+1 
//	d[0]=ksm(2,n);
	for(int d=0;d<=n;d++)
	{
		memset(f,0,sizeof(f));
		to=d+1,dfs(1,0);
		for(int i=-1;i>=-to-1;i--)ans[d]+=f[1][i+xx];
//		,cerr<<i<<" "<<i+xx<<" "<<d<<" ss "<<to<<" "<<ans[d]<<"!!\n";
		ans[d]%=mod;
	}
	ll res=ksm(2,n)*n;
//	for(int d=n-1;d>=0;d--)cout<<ans[d]<<"!!\n";
	for(int d=n-1;d>=0;d--)
		res-=ans[d];
//		res+=(ans[i+1]-ans[i])*(i+1),res%=mod,res+=mod,res%=mod;
	res--;
	res%=mod,res+=mod,res%=mod;
	cout<<res*ksm(ksm(2,n),mod-2)%mod<<"\n";
	pc('1',1);
	return 0;
}