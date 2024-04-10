#include<bits/stdc++.h>
#define ll long long
//#define int long long
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
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=6e5+5,yy=2e5+5,mod=998244353;// 
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
//ll jiec[xx];
//ll ni[xx];
//ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
//void pr()
//{
//	jiec[0]=1;
//	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
//	ni[xx-1]=ksm(jiec[xx-1],mod-2);
//	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
//}
int T,n,m,k,x,y,z;
struct node{int next,to,v;}e[xx];
int cnt=1,h[xx];
void add(int x,int y){cnt++;e[cnt]={h[x],y,0};h[x]=cnt;}
int col[xx];
char s[xx];
//, 
int ans[xx],id[xx],q[xx],L,R;
void fl(int x)
{
	if(ans[x]==0)q[++R]=x;
	ans[x]=1;
}
int tt;
int sum[xx],f[xx];
void dfs(int x,int y)
{
	f[x]=y;
	sum[x]=col[x];
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		sum[x]+=sum[e[i].to];
	}
}
void down(int x,int y)
{
	id[x]++,fl(x);
	if(id[x]>=5)return;//4 ()
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		if(e[i].v)continue;
		e[i].v=1;
		down(e[i].to,x);
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)col[i]=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	L=1,R=0; 
	for(int i=1;i<=n;i++)
	{
		if(col[i]==1)
		{
			tt++;
			fl(i);
			for(int j=h[i];j;j=e[j].next)fl(e[j].to);
		}
	}
	dfs(1,0);
	while(L<=R)
	{
		int x=q[L++];
		// 
		// 
		if(f[x])
		{
			if(sum[x]>=2)
			{
				down(f[x],x);
			}
		}
		for(int i=h[x];i;i=e[i].next)
		{
			if(tt-sum[e[i].to]>=2&&e[i].to!=f[x])down(e[i].to,x);
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	puts("");
	pc('1',1);
	return 0;
}