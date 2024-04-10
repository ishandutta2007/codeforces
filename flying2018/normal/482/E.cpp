#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define ll long long
using namespace std;
ll siz[N],sum[N],ans[N],sa[N],s1[N],s2[N];
int fa[N],ch[N][2],val[N];
bool not_root(int u){return ch[fa[u]][0]==u || ch[fa[u]][1]==u;}
void update(int u)
{
	sum[u]=siz[u]+sum[ch[u][0]]+sum[ch[u][1]];
	sa[u]=sa[ch[u][0]]+sa[ch[u][1]]+val[u]*siz[u];
	ans[u]=ans[ch[u][0]]+ans[ch[u][1]]+s1[u];
	ans[u]+=val[u]*(siz[u]*siz[u]-s2[u])+2*val[u]*siz[u]*sum[ch[u][1]];
	ans[u]+=2*sa[ch[u][0]]*(sum[u]-sum[ch[u][0]]);
}
void rotate(int u)
{
	int f=fa[u],ff=fa[f];
	int k=ch[f][1]==u,v=ch[u][!k];
	if(not_root(f)) ch[ff][ch[ff][1]==f]=u;
	ch[u][!k]=f;
	ch[f][k]=v;
	if(v) fa[v]=f;
	fa[f]=u;
	fa[u]=ff;
	update(f),update(u);
}
void splay(int u)
{
	while(not_root(u))
	{
		int f=fa[u],ff=fa[f];
		if(not_root(f)) rotate((ch[ff][1]==f)^(ch[f][1]==u)?u:f);
		rotate(u);
	}
	update(u);
}
void inc(int x,int y){siz[x]+=sum[y]; s2[x]+=sum[y]*sum[y]; s1[x]+=ans[y];}
void dec(int x,int y){siz[x]-=sum[y]; s2[x]-=sum[y]*sum[y]; s1[x]-=ans[y];}
void access(int x)
{
	for(int y=0;x;y=x,x=fa[x])
	{
		splay(x);
		inc(x,ch[x][1]);
		ch[x][1]=y;
		dec(x,ch[x][1]);
		update(x);
	}
}
void make_root(int x){access(x);splay(x);}
void link(int x,int y)
{
	make_root(y),make_root(x);
	fa[y]=x;
	inc(x,y);
	update(x);
	return;
}
void cut(int x,int y)
{
	make_root(x),splay(y);
	dec(x,y);
	fa[y]=0;
	update(x);
	return;
}
bool is_fa(int x,int y)
{
	make_root(y),splay(x);
	return not_root(y);
}
int n;
int tfa[N];
ll res=0;
void print_ans(){make_root(1),printf("%.10f\n",ans[1]*1.0/n/n);}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++) scanf("%d",&tfa[i]);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]),ans[i]=sa[i]=val[i],siz[i]=sum[i]=1;
	for(int i=2;i<=n;i++) link(tfa[i],i);
	int m;
	scanf("%d",&m);
	while(m --> 0)
	{
		print_ans();
		char opt[3];
		int x,y;
		scanf("%s%d%d",opt,&x,&y);
		if(opt[0]=='P')
		{
			if(tfa[y]==x || tfa[x]==y) continue;
			if(is_fa(x,y)) swap(x,y);
			cut(tfa[x],x);
			tfa[x]=y;
			link(y,x);
		}
		else
		{
			make_root(x);
			val[x]=y;
			update(x);
		}
	}
	print_ans();
	return 0;
}