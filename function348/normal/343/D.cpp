#include<cstdio>
#include<iostream>
using namespace std;
const int N=500010;
struct Edge {int y,ne;};
int n,num,m;
int fa[N],s[N],son[N],dfn[N],top[N];
Edge e[N*2];int last[N];
int tag[N*4];
void add(int x,int y) { e[++num]=(Edge){y,last[x]};last[x]=num;}
void dfs1(int i)
{
    s[i]=1;son[i]=0;
    for (int j=last[i];j;j=e[j].ne)
    if (e[j].y!=fa[i])
    {
        fa[e[j].y]=i;
        dfs1(e[j].y);
        s[i]+=s[e[j].y];
        if (s[e[j].y]>s[son[i]])son[i]=e[j].y;
    }
}
void dfs2(int i,int tp)
{
    dfn[i]=++num;top[i]=tp;
    if (son[i]) dfs2(son[i],tp);
    for (int j=last[i];j;j=e[j].ne)
    if (e[j].y!=fa[i]&&e[j].y!=son[i]) dfs2(e[j].y,e[j].y);
}
void build(int i,int l,int r)
{
	if (l==r)
	{
		tag[i]=0;
		return;
	}
	tag[i]=-1;
	int mid=(l+r)>>1;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
}
void change(int i,int l,int r,int ll,int rr,int d)
{
    if (ll<=l&&r<=rr) 
    {
        tag[i]=d;return;
    }
    int mid=(l+r)>>1;
	if (tag[i]!=-1) tag[i*2]=tag[i*2+1]=tag[i],tag[i]=-1;
    if (ll<=mid) change(i*2,l,mid,ll,rr,d);
    if (rr> mid) change(i*2+1,mid+1,r,ll,rr,d);
}
int ask(int i,int l,int r,int k)
{
    if (tag[i]!=-1) return tag[i];
    int mid=(l+r)>>1;
	if (k<=mid) return ask(i*2,l,mid,k);
    if (k> mid) return ask(i*2+1,mid+1,r,k);
}
void modify(int i)
{
    int f=top[i];
    while (i)
    {
        change(1,1,n,dfn[f],dfn[i],0);
        i=fa[f];f=top[i];
    }
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	num=0;
	dfs1(1);
	dfs2(1,1);
	scanf("%d",&m);
	while (m--)
	{
		int kd,x;
		scanf("%d%d",&kd,&x);
		if (kd==1) change(1,1,n,dfn[x],dfn[x]+s[x]-1,1);
		if (kd==2) modify(x);
		if (kd==3) printf("%d\n",ask(1,1,n,dfn[x]));
	}
	return 0;
}