// LUOGU_RID: 90802197
#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
const int xx=500005;
struct nod{int next,to;}e[xx<<1];
int cnt=1,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
struct node{int a[2][2];};
node f[xx],fa[xx],pre[xx],suf[xx]; 
int siz[xx];
ll ans=0;
void init(node &a)
{
	a.a[0][0]=1;
	a.a[1][1]=0;
	a.a[1][0]=0;
	a.a[0][1]=0;
}
void init1(node &a)
{
	a.a[0][0]=0;
	a.a[1][1]=0;
	a.a[1][0]=0;
	a.a[0][1]=1;
}
node merge(node a,node b)
{
	a.a[1][1]=(a.a[1][1]*b.a[0][1])+a.a[0][1]*b.a[1][1]+a.a[1][0]*b.a[0][0]+a.a[0][0]*b.a[1][0];
	a.a[1][0]=(a.a[1][0]*b.a[0][1])+a.a[0][0]*b.a[1][1];
	a.a[0][1]=(a.a[0][1]&b.a[0][1])|(a.a[0][0]&b.a[0][0]);
	a.a[0][0]&=b.a[0][1];
	return a;
}
node merge2(node a,node b)
{
	a.a[1][1]=(a.a[1][1]*b.a[0][0])+a.a[1][0]*b.a[0][1]+a.a[0][0]*b.a[1][1]+a.a[0][1]*b.a[1][0];
	a.a[1][0]=a.a[1][0]*b.a[0][0]+a.a[0][0]*b.a[1][0]; 
	a.a[0][1]=(a.a[0][1]&b.a[0][0])|(a.a[0][0]&b.a[0][1]);
	a.a[0][0]=a.a[0][0]&b.a[0][0];
	return a;
}
node upd(node a)
{
	a.a[1][1]+=a.a[0][0];
	return a;
}
void dp(int x,int y)
{
	siz[x]=1;
	init(f[x]);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dp(e[i].to,x);
		siz[x]+=siz[e[i].to];
		f[x]=merge(f[x],f[e[i].to]);
	}
	f[x]=upd(f[x]);
}
void hg(int x,int y)
{
	vector<int>v;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=y)v.push_back(e[i].to);
	node now;init(now);
	for(int i=0;i<v.size();i++)now=merge(now,f[v[i]]),pre[i]=now;
	init(now);
	for(int i=v.size()-1;i>=0;i--)now=merge(now,f[v[i]]),suf[i]=now;
	for(int i=0;i<v.size();i++)
	{
		if(i&&i!=v.size()-1)now=merge2(pre[i-1],suf[i+1]);
		else if(i)now=pre[i-1];
		else if(i!=v.size()-1)now=suf[i+1];
		else init(now);
		now=merge(now,fa[x]);
		now=upd(now);fa[v[i]]=now;
		if(now.a[0][1]&f[v[i]].a[0][1])ans+=1ll*(n-siz[v[i]])*(siz[v[i]]);
		else ans+=1ll*now.a[1][1]*f[v[i]].a[1][1];
	}
	for(auto it:v)hg(it,x);
}
int main(){
	n=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	dp(1,0);
	init1(fa[1]);
	hg(1,0);
	cout<<ans<<'\n';
	return 0;
}