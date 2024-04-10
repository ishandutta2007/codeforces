#include<bits/stdc++.h>
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
const int xx=3e5+5;
int a[xx];
struct node
{
	int next,to;
}e[xx<<1];
int cnt;
int h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int cst;
int in[xx],out[xx],dfx[xx<<1],size[xx],son[xx],dep[xx],f[xx],top[xx];
void dfs(int x,int y)
{
	dfx[++cst]=x;
	in[x]=cst;
	size[x]=1;
	dep[x]=dep[y]+1;
	f[x]=y;
	int maxx=-1;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		size[x]+=size[e[i].to];
		if(size[e[i].to]>maxx)maxx=size[e[i].to],son[x]=e[i].to;
	}
	dfx[++cst]=x;
	out[x]=cst;
}
void dfs2(int x,int y)
{
	top[x]=y;
	if(!son[x])return;
	dfs2(son[x],y);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==f[x]||e[i].to==son[x])continue;
		dfs2(e[i].to,e[i].to);
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
int B;
int bel(int x){return (x-1)/B+1;}
int rs(int x){return min(n,bel(x)*B);}
int ls(int x){return (bel(x)-1)*B+1;}
struct nod
{
	int l,r,lca,x,y,id;
	bool operator<(const nod&w)const{return bel(l)==bel(w.l)?bel(l)&1?r<w.r:r>w.r:l<w.l;}
}q[xx];
int b[xx];
int t[xx],res[xx];
void add(int x)// 
{
	if(!x)return;
//	cout<<x<<" ss "<<a[dfx[x]]<<"\n";
	b[bel(a[dfx[x]])]-=t[a[dfx[x]]];
	t[a[dfx[x]]]^=1;
	b[bel(a[dfx[x]])]+=t[a[dfx[x]]];
}
int main(){
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a);
	}
	B=sqrt(n+n);
	dfs(1,0);
	dfs2(1,1);
	for(int i=1;i<=m;i++)
	{
		int a,b,c,d;
		a=read();b=read();
		c=read();d=read();
//		cout<<in[a]<<" "<<in[b]<<" "<<out[a]<<" "<<out[b]<<"\n";
		q[i].id=i;q[i].x=c;q[i].y=d;
		if(dep[a]>dep[b])swap(a,b);
		if(in[a]<=in[b]&&out[b]<=out[a])q[i].l=in[a],q[i].r=in[b];
		else 
		{
			if(in[a]>in[b])swap(a,b);
//			puts("qweqwewqeqwe");
			q[i].lca=lca(a,b);q[i].l=in[a]+1,q[i].r=in[b];
		}
	}
	sort(q+1,q+m+1);////////////////
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		while(r<q[i].r)add(++r);
		while(l>q[i].l)add(--l);
		while(r>q[i].r)add(r--);
		while(l<q[i].l)add(l++);
		add(in[q[i].lca]);
//		puts("qweqeqeqwe");
		int vis=0;
		if(bel(q[i].x)==bel(q[i].y))
		{
			for(int j=q[i].x;j<=q[i].y;j++)if(t[j])res[q[i].id]=j,vis=1;
		}
		else 
		{
//			cout<<bel(q[i].x)<<" aaa "<<bel(q[i].y)<<"\n";
//			puts("QWWQQQQQQQQQ");
			if(!vis)for(int j=q[i].x;j<=rs(q[i].x);j++)if(t[j])res[q[i].id]=j,vis=1;
			if(!vis)for(int j=ls(q[i].y);j<=q[i].y;j++)if(t[j])res[q[i].id]=j,vis=1;
			if(!vis)
			for(int j=bel(q[i].x)+1;j<=bel(q[i].y)-1;j++)
			if(b[j])
			{
				for(int s=(j-1)*B+1;;s++)
				{
					if(t[s])
					{
						res[q[i].id]=s,vis=1;
						break;
					}
				}
				break;
			}
		}
		if(!vis)res[q[i].id]=-1;
//		cout<<q[i].l<<" "<<q[i].r<<" "<<q[i].lca<<" "<<q[i].x<<" "<<q[i].y<<"\n";
//		puts("");
		add(in[q[i].lca]);
	}
	for(int i=1;i<=m;i++)cout<<res[i]<<"\n";
	return 0;
}