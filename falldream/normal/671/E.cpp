#include<iostream>
#include<cstdio>
#define MD 17
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
#define pa pair<long long,int>
int n,w[MN+5],g[MN+5],head[MN+5],q[MN+5],top=0,cnt=0,K,ans=0;
struct edge{int to,next;}e[MN+5];long long p[MN+5],p2[MN+5];
inline void ins(int f,int t){e[++cnt]=(edge){t,head[f]};head[f]=cnt;}
struct Tree{int l,r;long long maxp,mina,pval;int aid;pa j;}T[MN*4+5];

inline void Mark(int x,long long p){T[x].pval+=p;T[x].maxp+=p;T[x].j.first+=p;}
void pushdown(int x){Mark(x<<1,T[x].pval);Mark(x<<1|1,T[x].pval);T[x].pval=0;}

pa GetJ(int x,long long P)
{
	if(T[x].l==T[x].r) return make_pair(P+T[x].mina,T[x].l);
	int L=x<<1,R=x<<1|1;if(T[x].pval) pushdown(x);
	long long q=T[L].maxp;
	if(P>q) return min(make_pair(T[L].mina+P,T[L].aid),GetJ(x<<1|1,P));
	else return min(T[x].j,GetJ(x<<1,P));
}

void update(int x)
{
	int L=x<<1,R=x<<1|1;
	T[x].maxp=max(T[L].maxp,T[R].maxp);
	if(T[L].mina<T[R].mina) T[x].mina=T[L].mina,T[x].aid=T[L].aid;
	else T[x].mina=T[R].mina,T[x].aid=T[R].aid;
	T[x].j=GetJ(R,T[L].maxp);
}

void Build(int x,int l,int r)
{
	if((T[x].l=l)==(T[x].r=r))
	{
		T[x].maxp=p2[l];T[x].mina=-p2[l];
		T[x].aid=l;T[x].pval=0;T[x].j=make_pair(T[x].maxp+T[x].mina,l);
		return;	
	}
	int mid=l+r>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
	update(x);
}

void Modify(int x,int l,int r,long long v)
{
	if(T[x].l==l&&T[x].r==r){Mark(x,v);return;}
	int mid=T[x].l+T[x].r>>1;if(T[x].pval) pushdown(x);
	if(r<=mid) Modify(x<<1,l,r,v);
	else if(l>mid) Modify(x<<1|1,l,r,v);
	else Modify(x<<1,l,mid,v),Modify(x<<1|1,mid+1,r,v);
	update(x);
}

int Bs(int x,int l,int r,long long P)
{
	if(T[x].mina+P>K) return 0;
	if(l==r) return l;
	int mid=l+r>>1;if(T[x].pval) pushdown(x);
	return (T[x<<1|1].mina+P<=K)?Bs(x<<1|1,mid+1,r,P):Bs(x<<1,l,mid,P);
}

int Query(int x,long long P)
{
	if(T[x].l==T[x].r) return (P+T[x].mina)<=K?T[x].l:0;
	int L=x<<1,R=x<<1|1;if(T[x].pval) pushdown(x);
	long long q=T[L].maxp;
	if(P<=q) return T[x].j.first<=K?Query(R,q):Query(L,P);
	else return max(Query(R,P),Bs(L,T[x].l,T[x].l+T[x].r>>1,P));
}

int fa[MN+5];
void Solve(int x)
{
	q[++top]=x;int Rt=n;	
	if(x>1) Modify(1,1,x-1,-1e17);
	int l=1,r=top-1,mid;
	while(l<=r)
	{
		mid=l+r>>1;	
		if(p[x]-p[q[mid]]>K) Rt=q[mid]-1,l=mid+1;
		else r=mid-1;
	}
	if(fa[x]) Modify(1,fa[x]-1,n,p[x]-p[fa[x]]);
    if(Rt<n) Modify(1,Rt+1,n, 1e17);
	ans=max(ans,Query(1,-1e18)-x+1);
    if(Rt<n) Modify(1,Rt+1,n,-1e17);
	if(x>1) Modify(1,1,x-1, 1e17);
	for(int i=head[x];i;i=e[i].next) fa[e[i].to]=x,Solve(e[i].to);
	if(fa[x]) Modify(1,fa[x]-1,n,p[fa[x]]-p[x]);	
	--top;
}

int main()
{
	n=read();K=read();
	for(int i=1;i<n;++i) w[i]=read();
	for(int i=1;i<=n;++i) g[i]=read();
	for(int i=2;i<=n;++i) p[i]=p[i-1]+g[i-1]-w[i-1];
	for(int i=2;i<=n;++i) p2[i]=p2[i-1]+g[i]-w[i-1];
	for(int i=n;i;--i)
	{
		while(top&&p[q[top]]>=p[i]) --top;
		if(top) ins(q[top],i);
		q[++top]=i;
	}
	Build(1,1,n);
	for(int i=n;i;--i) if(!fa[i]) top=0,Solve(i);
	printf("%d\n",ans);
	return 0;
}
/*
cf671e 
i,j
max p2[k] [i,j) - p2[j] +cost[j] <=k

aj = cost[j]-p2[j] 
[i,j) max(p2) + aj 
segmenttree-> min(a) and who , maxp , pval , the j 
Query -> if p <= q  ->  no influence -> right ok?right:left
	   if p > q   ->  L is p , bs(left) + right 
update -> right -> p > q ? L is p , min(left->a + p)  + right
			 p <= q ? (right->j) + left
*/