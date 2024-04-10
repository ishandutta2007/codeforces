#include<bits/stdc++.h>
#define ll long long
#define dd double
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
const int xx=8e5+5;
struct node{int next,to;}e[xx<<1];
int cnt=1,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int n,m,uu[xx],vv[xx],fa[xx],cur[xx],vis[xx<<1];
int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
vector<int>lj;
void dfs(int x,int y)
{
	
	for(int i=cur[x];i;i=cur[x]=e[cur[x]].next)
	{
//		cout<<x<<" ttt "<<i<<"\n";
		if(vis[i])continue;
//		cur[x]=i;
//		cout<<x<<" sss "<<i<<"\n";
//		puts("SDasda");
		vis[i]=vis[i^1]=1;
		dfs(e[i].to,x);
	}
	lj.push_back(x);
//	if(x%100==0)cout<<x<<"sss \n";
}
signed main(){
//	freopen("a.in","r",stdin);
	n=read(),m=read();
	int k=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)uu[i]=read(),vv[i]=read();
	for(int i=1;i<=m;i++)
	{
		if(find(uu[i])==find(vv[i]))continue;
		fa[find(uu[i])]=find(vv[i]);
		int a=uu[i],b=vv[i];
		add(a,b),add(b,a);
		add(a,b),add(b,a);
//		cout<<a<<" sss "<<b<<"\n";
	}
	memcpy(cur,h,sizeof(h));
	dfs(1,0); 
//	puts("asdsad");
	int tt=ceil(1.0*(n+n)/k);
	for(int i=1;i<=k;i++)
	{
		if(lj.size()>tt)
		{
//			puts("SSS");
			cout<<tt<<" ";
			int o=tt;
			while(o--)cout<<*--lj.end()<<" ",lj.pop_back();
			puts("");
		}
		else if(!lj.size())cout<<1<<" "<<1<<"\n";
		else 
		{
			cout<<lj.size()<<" ";
			while(lj.size())cout<<*--lj.end()<<" ",lj.pop_back();
		}
	}
    return 0;
}