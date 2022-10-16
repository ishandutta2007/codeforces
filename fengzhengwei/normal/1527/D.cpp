#include<bits/stdc++.h>
#define ll long long
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
	((op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf));
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(c,0);
}
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
int dfx[xx],size[xx],f[xx],cst;

void dfs(int x,int y)
{
	size[x]=1;dfx[x]=++cst;f[x]=y;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
	}
}
int cvt[xx<<2];
void cv(int k,int a){cvt[k]=a;}
void pd(int k)
{
	if(cvt[k]!=-1)
	{
		cv(k<<1,cvt[k]);
		cv(k<<1|1,cvt[k]);
		cvt[k]=-1;
	}
}
void cov(int k,int l,int r,int x,int y,int z)
{
	if(x<=l&&r<=y)return cv(k,z);
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)cov(k<<1,l,mid,x,y,z);
	if(mid<y)cov(k<<1|1,mid+1,r,x,y,z);
}
int ask(int k,int l,int r,int x)
{
	if(l==r)return cvt[k];
	pd(k);
	int mid=l+r>>1;
	if(x<=mid)return ask(k<<1,l,mid,x);
	return ask(k<<1|1,mid+1,r,x);
}
ll ans[xx];
bool check(int a,int b){return dfx[a]<=dfx[b]&&dfx[a]+size[a]>=dfx[b]+size[b];}
signed main(){
	int T=read();
	while(T--)
	{
		cst=0;
		int n=read();
		memset(e,0,sizeof(e[0])*(cnt+1));
		memset(h,0,sizeof(h[0])*(n+1));
		cnt=0;
		for(int i=1;i<n;i++)
		{
			int a=read(),b=read();
			add(a,b),add(b,a);
		}
		cov(1,1,n,1,n,0);
		dfs(0,0);
		ll rem=1ll*n*(n-1)/2;
		ll ida=0,sza=0,idb=0,szb=0;
		int x=1;
		while(f[x])x=f[x];
		cov(1,1,n,dfx[x],dfx[x]+size[x]-1,n+1);
		ida=0,sza=n-size[x];
		idb=1,szb=size[1];
		for(int i=0;i<=n;i++)ans[i]=0;
		cov(1,1,n,dfx[1],dfx[1]+size[1]-1,1);
		for(int i=h[0];i;i=e[i].next)
		{
			x=e[i].to;
			ans[0]+=1ll*size[e[i].to]*(size[e[i].to]-1)/2;
		}
		rem-=ans[0];
		ans[1]=rem-sza*szb;
		rem=sza*szb;
		for(int i=2;i<n;i++)
		{
			int op=ask(1,1,n,dfx[i]);
			if(op==ida)
			{
				ida=i,sza=size[i];
				cov(1,1,n,dfx[i],dfx[i]+size[i]-1,i);
				ans[i]=rem-sza*szb;
				rem=sza*szb;
			}
			else if(op==idb)
			{
				idb=i,szb=size[i];
				cov(1,1,n,dfx[i],dfx[i]+size[i]-1,i);
				ans[i]=rem-sza*szb;
				rem=sza*szb;
			}
			else if(check(i,ida)||check(i,idb))
			{
				
			}
			else 
			{
				ans[i]=rem,rem=0;
				break;
			}
		}
		ans[n]=rem;
		for(int i=0;i<=n;i++)cout<<ans[i]<<" ";
		puts("");
	}
	pc('-',1);
	return 0;
}