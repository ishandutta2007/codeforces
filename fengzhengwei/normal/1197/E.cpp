#include<bits/stdc++.h>
#define ll long long
#define dd double
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
const int xx=8e5+5;
struct no{int next,to,v;}e[xx<<1];
int cnt,h[xx],d[xx];
void add(int x,int y,int z){d[y]++;cnt++;e[cnt]={h[x],y,z};h[x]=cnt;}
int n,tt,f[xx],g[xx];
struct nod
{
	int x,v;
	bool operator<(const nod&w)const{return v==w.v?x>w.x:v>w.v;}
};
priority_queue<nod>q;
int vis[xx];
const int mod=1e9+7;
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
struct nd{int in,out,id;bool operator<(const nd&w)const{return out<w.out;};}E[xx];
int sum[xx],I[xx];
int main(){
	n=read();
	for(int i=1;i<=n;i++)E[i].out=read(),E[i].in=read();
	memset(f,0x3f,sizeof(f));
	int mx=0;
	sort(E+1,E+n+1);
	for(int i=1;i<=n;i++)E[i].id=++tt;
	for(int i=1;i<=n;i++)mx=max(mx,E[i].in);
	++tt,f[tt]=0,g[tt]=1;
	for(int i=1;i<=n;i++)if(E[i].out>mx)add(tt,E[i].id,0);
	int s=tt;
	for(int i=1;i<=n;i++)
	{
		sum[i]=++tt;
		if(i!=1)add(sum[i],sum[i-1],0);
		add(sum[i],E[i].id,-E[i].out);
	}
	for(int i=1;i<=n;i++)
	{
		int id=upper_bound(E+1,E+n+1,(nd){0,E[i].in,0})-E-1;
		if(id)add(E[i].id,sum[id],E[i].in);
	}
	queue<int>Q;
	for(int i=1;i<=tt;i++)if(!d[i])Q.push(i);
	int TT=0;
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		I[++TT]=x;
		for(int i=h[x];i;i=e[i].next)
			if(!(--d[e[i].to]))Q.push(e[i].to);
	}
	for(int j=1;j<=TT;j++)
	{
		///fn 
		int x=I[j];
		for(int i=h[x];i;i=e[i].next)
		{
			if(f[e[i].to]>f[x]+e[i].v)f[e[i].to]=f[x]+e[i].v,g[e[i].to]=0;
			if(f[e[i].to]==f[x]+e[i].v)ad(g[e[i].to],g[x]),q.push({e[i].to,f[e[i].to]});
		}
	}
	int mn=2147483647,fn=0;
	for(int i=1;i<=n;i++)
	{
		if(mn>f[E[i].id]+E[i].in)mn=f[E[i].id]+E[i].in,fn=0;
		if(mn==f[E[i].id]+E[i].in)ad(fn,g[E[i].id]);
	}
	cout<<fn<<"\n";
//	<<" "<<mn<<"\n";
	pc('1',1);
	return 0;
}