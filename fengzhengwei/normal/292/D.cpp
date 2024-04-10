#include<bits/stdc++.h>
#define ll long long
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
int n,m;
const int xx=20005;
struct node{int next,to,v;}e[xx];
int cnt=1,h[xx],fa[xx],vis[xx];
void add(int x,int y,int z)
{
	cnt++;e[cnt].next=h[x];
	h[x]=cnt;e[cnt].to=y,e[cnt].v=z;
}
void clear()
{
	memset(h,0,sizeof(h[0])*(n+1));
	memset(e,0,sizeof(e[0])*(cnt+1));
	memset(vis,0,sizeof(vis[0])*(cnt+1));
	cnt=1;
}
vector<int>use;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int uu[xx],vv[xx];
void rebuild()
{
	clear();
	for(auto it:use)add(uu[it],vv[it],it),add(vv[it],uu[it],it);
}
struct qqq{int l,id;};
vector<qqq>qu[xx];
int stk[xx],ans[xx],top,vs,op;
void dfs(int x,int y)
{
//	cout<<x<<" "<<h[x]<<"ttt \n";
	if(x==op){vs=1;return;}
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		if(vis[i])continue;
		stk[++top]=i;dfs(e[i].to,x);
		if(vs)return;
		top--;
	}
}
signed main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)uu[i]=read(),vv[i]=read();
	for(int i=1;i<=m;i++)uu[i+m]=uu[i],vv[i+m]=vv[i];
	int q=read();
	for(int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		qu[l-1+m].push_back((qqq){r+1,i});
	}
	for(int i=1;i<=m+m;i++)
	{
		if(find(uu[i])!=find(vv[i]))use.push_back(i),fa[find(uu[i])]=find(vv[i]),add(uu[i],vv[i],i),add(vv[i],uu[i],i);
		else 
		{
			op=vv[i];
			vs=top=0;dfs(uu[i],0);
			int mn=m+m+1,mnid=-1;
//			cout<<i<<" "<<top<<" "<<vs<<"\n";
//			puts("SSSS");
			for(int j=1;j<=top;j++)mn=min(mn,e[stk[j]].v);
			for(int j=1;j<=top;j++)if(mn==e[stk[j]].v)mnid=stk[j];
			vis[mnid]=vis[mnid^1]=1;
			add(uu[i],vv[i],i);
			add(vv[i],uu[i],i);
			for(vector<int>::iterator it=use.begin();it!=use.end();it++)if(*it==mn){use.erase(it);break;}
			use.push_back(i);
			if(i%10==0)
			rebuild();// 
		}
		for(auto it:qu[i])ans[it.id]=use.end()-lower_bound(use.begin(),use.end(),it.l);
//		puts("!!!!!");
//		cout<<i<<"\n";
//		for(auto it:use)
//		{
//			cout<<it<<"\n";
//		}
//		puts("ed");
	}
	for(int i=1;i<=q;i++)cout<<n-ans[i]<<"\n";
	return 0;
}