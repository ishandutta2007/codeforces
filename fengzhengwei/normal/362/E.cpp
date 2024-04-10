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
const int xx=1e5+5;
struct node{int next,to,v;ll s;}e[xx<<1];
int cnt=1,h[xx],cur[xx];ll d[xx];int v[xx],ts[xx],now,s,t,tt;
void add(int x,int y,int a,int b){cnt++;e[cnt]={h[x],y,a,b};h[x]=cnt;}
void ad(int x,int y,int a,int b){add(x,y,a,b),add(y,x,0,-b);}
void spfa()
{
	for(int i=1;i<=tt;i++)v[i]=0,d[i]=1e18,cur[i]=h[i];
	queue<int>q;d[t]=0,v[t]=1,q.push(t);
	while(!q.empty())
	{
		int x=q.front();q.pop();v[x]=0;
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i^1].v&&d[e[i].to]>d[x]+e[i^1].s)
			{
				d[e[i].to]=d[x]+e[i^1].s;
				if(!v[e[i].to])v[e[i].to]=1,q.push(e[i].to);
			}
		}
	}
}
ll cost;
int n,m,k;
int nans=0;
int dfs(int x,int mx)
{
	if(x==t)
	{
//		cout<<d[s]<<" "<<mx<<"!!\n";
		if(cost+mx*d[s]<=k)cost+=mx*d[s],nans+=mx;
		else nans+=(k-cost)/d[s],cout<<nans<<"\n",exit(0);
		return mx;
	}
	int res=mx;v[x]=1,ts[x]=now;
	for(int &i=cur[x];i;i=e[i].next)
	{
		if(e[i].v&&!v[e[i].to]&&d[e[i].to]+e[i].s==d[x])
		{
			int a=dfs(e[i].to,min(res,e[i].v));
			res-=a,e[i].v-=a,e[i^1].v+=a;
			if(!res)return v[x]=0,mx-res;
		}
	}
	return v[x]=0,mx-res;
}
bool cd()
{
	ll mn=1e18;
	for(int x=1;x<=tt;x++)
	{
		if(ts[x]!=now)continue;
		for(int i=h[x];i;i=e[i].next)if(e[i].v&&ts[e[i].to]!=now)mn=min(mn,d[e[i].to]+e[i].s-d[x]);
	}
	if(mn==1e18)return 0;
	for(int i=1;i<=tt;i++)
	{
		cur[i]=h[i];
		if(ts[i]==now)d[i]+=mn;
	}
	return 1;
}
int go()
{
	spfa();
	int ans=0;
	++now,ans+=dfs(s,1e9);
	while(cd())++now,ans+=dfs(s,1e9);
	return ans;
}
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int t=read();
			if(t)ad(i,j,t,0),ad(i,j,1e9,1);
		}
	}
	s=1,t=n,tt=n;
	go();
	puts("0");// 
//	cout<<go()<<"\n";
	pc('1',1);
	return 0;
}