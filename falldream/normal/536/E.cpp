#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int f[MN+5],n,Q,head[MN+5],cnt=0,size[MN+5],mx[MN+5],top[MN+5],dfn[MN+5],p[MN+5],dn=0,dep[MN+5],fa[MN+5],Ans[MN+5];
struct data{
	int len,flag,l,r,ans;
	data(){}
	data(int k){len=1;flag=l=r=k;ans=0;}
	data(int _len,int _f,int _l,int _r,int _ans):len(_len),flag(_f),l(_l),r(_r),ans(_ans){}
	friend data operator + (const data&x,const data&y)
	{
		data c;
		c.len=x.len+y.len;c.ans=x.ans+y.ans;
		if(x.flag&y.flag) c.flag=1,c.l=c.r=c.len;
		else if(x.flag) c.flag=0,c.l=x.len+y.l,c.r=y.r; 
		else if(y.flag) c.flag=0,c.r=y.len+x.r,c.l=x.l;
		else c.flag=0,c.l=x.l,c.r=y.r,c.ans+=f[x.r+y.l];
		return c;
	}
};
struct Tree{int l,r;data x;}T[MN*4+5];
const data Nul=data(0,1,0,0,0);
struct ques{int x,y,w,id;}q[MN*2+5];
bool cmp(const ques&a,const ques&b){return a.w==b.w?a.id<b.id:a.w>b.w;}
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;	
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}
void Pre(int x,int f)
{
	fa[x]=f;size[x]=1;mx[x]=0;
	for(int i=head[x];i;i=e[i].next) if(e[i].to!=f)
		dep[e[i].to]=dep[x]+1,Pre(e[i].to,x),size[x]+=size[e[i].to],size[e[i].to]>size[mx[x]]?mx[x]=e[i].to:0;
}
void Dfs(int x,int tp)
{
	top[x]=tp;p[dfn[x]=++dn]=x;
	if(mx[x]) Dfs(mx[x],tp);
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa[x]&&e[i].to!=mx[x]) Dfs(e[i].to,e[i].to);
}
void Build(int x,int l,int r)
{
	if((T[x].l=l)==(T[x].r=r)) {T[x].x=data(0);return;}
	int mid=l+r>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
	T[x].x=T[x<<1].x+T[x<<1|1].x;
}
void Mod(int x,int k)
{
	if(T[x].l==T[x].r) T[x].x=data(1);
	else Mod(x<<1|(k>(T[x].l+T[x].r>>1)),k),T[x].x=T[x<<1].x+T[x<<1|1].x;	
}
data Query(int x,int l,int r)
{
	if(T[x].l==l&&T[x].r==r) return T[x].x;
	int mid=T[x].l+T[x].r>>1;
	if(r<=mid) return Query(x<<1,l,r);
	else if(l>mid) return Query(x<<1|1,l,r);
	else return Query(x<<1,l,mid)+Query(x<<1|1,mid+1,r); 
}
int main()
{
	n=read();Q=read();
	for(int i=1;i<n;++i) f[i]=read();
	for(int i=1;i<n;++i)
	{
		int x=read(),y=read(),w=read();
		ins(x,y);q[i]=(ques){x,y,w,0};	
	}
	for(int i=1;i<=Q;++i) 
	{
		int x=read(),y=read(),w=read();
		q[i+n-1]=(ques){x,y,w,i};	
	}
	sort(q+1,q+n+Q,cmp);Pre(1,0);Dfs(1,1);Build(1,1,n);
	for(int i=1;i<n+Q;++i)
		if(!q[i].id) Mod(1,max(dfn[q[i].x],dfn[q[i].y]));
		else 
		{
			data l=Nul,r=Nul;int x=q[i].x,y=q[i].y;
			while(top[x]!=top[y])
			{
				if(dep[top[x]]>dep[top[y]]) l=Query(1,dfn[top[x]],dfn[x])+l,x=fa[top[x]];
				else r=Query(1,dfn[top[y]],dfn[y])+r,y=fa[top[y]]; 
			}
			if(dfn[x]<dfn[y]) r=Query(1,dfn[x]+1,dfn[y])+r;
			if(dfn[x]>dfn[y]) l=Query(1,dfn[y]+1,dfn[x])+l;
			swap(l.l,l.r);data ans=l+r;
			Ans[q[i].id]=ans.ans+f[ans.l]+(ans.flag?0:f[ans.r]);
		}
	for(int i=1;i<=Q;++i) printf("%d\n",Ans[i]);
	return 0;
}