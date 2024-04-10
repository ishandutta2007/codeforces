#include<iostream>
#include<cstdio>
#define mod 1000000007
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int p[MN+5],v[MN+5],Q,head[MN+5],cnt,tot=1,size[MN+5],mx[MN+5];
int son[MN+5],dep[MN+5],fa[MN+5],top[MN+5],nl[MN+5],nr[MN+5],dn,inv[MN+5];
struct edge{int to,next;}e[MN+5];
inline void ins(int f,int t){e[++cnt]=(edge){t,head[f]};head[f]=cnt;}
void Pre(int x)
{
	size[x]=1;mx[x]=0;
	for(int i=head[x];i;i=e[i].next)
	{
		dep[e[i].to]=dep[x]+1;fa[e[i].to]=x;
		Pre(e[i].to);
		size[x]+=size[e[i].to];
		if(size[e[i].to]>size[mx[x]]) mx[x]=e[i].to;	
	}
}
void Dfs(int x,int tp)
{
	top[x]=tp;nl[x]=++dn;
	if(mx[x]) Dfs(mx[x],tp);
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=mx[x]) Dfs(e[i].to,e[i].to);
	nr[x]=dn;
}
bool flag=0;
struct Seg
{
	struct Tree{int l,r,x,val,tag;}T[MN*4+5];
	void Build(int x,int l,int r)
	{
		if((T[x].l=l)==(T[x].r=r)){T[x].x=flag;return;}
		int mid=l+r>>1;
		Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
		T[x].x=(T[x<<1].x+T[x<<1|1].x)%mod;
	}
	inline void Mark(int x,int v)
	{
		if(!T[x].tag) T[x].tag=T[x].val=1;
		T[x].val=1LL*T[x].val*v%mod;
		T[x].x=1LL*T[x].x*v%mod;
	}
	inline void pushdown(int x){Mark(x<<1,T[x].val);Mark(x<<1|1,T[x].val);T[x].tag=0;}
	void Modify(int x,int k,int v)
	{
	//	cout<<"MOdify"<<x<<" "<<k<<" "<<v<<endl;
		if(T[x].l==T[x].r){T[x].x=v;return;}	
		int mid=T[x].l+T[x].r>>1;if(T[x].tag) pushdown(x);
		Modify(x<<1|(k>mid),k,v);
		T[x].x=(T[x<<1].x+T[x<<1|1].x)%mod; 
	}
	void Modify(int x,int l,int r,int v)
	{
		//cout<<"Modify*"<<l<<" "<<r<<" "<<v<<endl; 
		if(T[x].l==l&&T[x].r==r) {Mark(x,v);return;}
		int mid=T[x].l+T[x].r>>1;if(T[x].tag) pushdown(x);
		if(r<=mid) Modify(x<<1,l,r,v);
		else if(l>mid) Modify(x<<1|1,l,r,v);
		else Modify(x<<1,l,mid,v),Modify(x<<1|1,mid+1,r,v);
		T[x].x=(T[x<<1].x+T[x<<1|1].x)%mod;	
	}
	int Query(int x,int l,int r)
	{
		if(T[x].l==l&&r==T[x].r) return T[x].x;	
		int mid=T[x].l+T[x].r>>1;if(T[x].tag) pushdown(x);
		if(r<=mid) return Query(x<<1,l,r);
		else if(l>mid) return Query(x<<1|1,l,r);
		else return (Query(x<<1,l,mid)+Query(x<<1|1,mid+1,r))%mod;
	}
}s,S;
int pow(int x,int k)
{
	int sum=1;
	for(;k;k>>=1,x=1LL*x*x%mod)
		if(k&1) sum=1LL*sum*x%mod;
	return sum;	
}
int main()
{
	v[0]=read();Q=read();inv[0]=inv[1]=1;
	for(int i=2;i<=MN;++i) inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=Q;++i)
		if(read()==1) p[i]=read(),v[i]=read(),ins(p[i],++tot),p[i]=tot;
		else v[i]=read();
	Pre(1);Dfs(1,1);s.Build(1,1,tot);flag=1;S.Build(1,1,tot);
	s.Modify(son[1]=1,1,v[0]);
	for(int i=1;i<=Q;++i)
		if(!p[i]) 
		{
			int x=v[i]==1?1:S.Query(1,nl[fa[v[i]]],nl[fa[v[i]]]);
			printf("%d\n",1LL*pow(x,mod-2)*s.Query(1,nl[v[i]],nr[v[i]])%mod);
		}
		else 
		{
		//	cout<<p[i]<<" "<<son[fa[p[i]]]<<endl;
			int k=1LL*inv[son[fa[p[i]]]]*(son[fa[p[i]]]+1)%mod;++son[fa[p[i]]];
			s.Modify(1,nl[fa[p[i]]],nr[fa[p[i]]],k);	
			S.Modify(1,nl[fa[p[i]]],nr[fa[p[i]]],k);
		//	cout<<S.Query(1,nl[fa[p[i]]],nl[fa[p[i]]])<<endl;
			s.Modify(1,nl[p[i]],1LL*v[i]*S.Query(1,nl[fa[p[i]]],nl[fa[p[i]]])%mod);son[p[i]]=1;
		}
	return 0;
}