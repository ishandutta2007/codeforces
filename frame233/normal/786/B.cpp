#include<cstdio>
#include<cstring>
#include<queue>
typedef long long ll;
const int N=150005;
const ll inf=4557430888798830399ll;
typedef const int& ct;
typedef const ll& cll;
struct edge{
	int v,nxt;
	ll w;
}c[N<<5];
struct node{
	int u;
	ll d;
	inline bool operator < (const node &b)const{return d>b.d;}
};
std::priority_queue<node> q;
int front[N<<3],cnt;
ll d[N<<3];
int node_cnt,ls[N<<3],rs[N<<3];
inline void add(ct u,ct v,cll w){c[++cnt]=(edge){v,front[u],w},front[u]=cnt;}
inline void add_e(ct u,ct v)
{
	c[++cnt]=(edge){v,front[u],0},front[u]=cnt;
	c[++cnt]=(edge){u,front[v],0},front[v]=cnt;
}
struct seg_tr1{
	int rt,n;
	int build(ct l,ct r)
	{
		if(l==r) return add_e(l,++node_cnt),node_cnt;
		int now=++node_cnt,mid=(l+r)>>1;
		ls[now]=build(l,mid),rs[now]=build(mid+1,r);
		return add(now,ls[now],0),add(now,rs[now],0),now;
	}
	void link(ct L,ct R,ct l,ct r,ct cur,ct x,cll w)
	{
		if(L<=l&&r<=R) return add(x,cur,w);
		int mid=(l+r)>>1;
		if(L<=mid) link(L,R,l,mid,ls[cur],x,w);
		if(R>mid) link(L,R,mid+1,r,rs[cur],x,w);
	}
	inline void init(int x){rt=build(1,x);}
}tr1;
struct seg_tr2{
	int rt,n;
	int build(ct l,ct r)
	{
		if(l==r) return add_e(l,++node_cnt),node_cnt;
		int now=++node_cnt,mid=(l+r)>>1;
		ls[now]=build(l,mid),rs[now]=build(mid+1,r);
		return add(ls[now],now,0),add(rs[now],now,0),now;
	}
	void link(ct L,ct R,ct l,ct r,ct cur,ct x,cll w)
	{
		if(L<=l&&r<=R) return add(cur,x,w);
		int mid=(l+r)>>1;
		if(L<=mid) link(L,R,l,mid,ls[cur],x,w);
		if(R>mid) link(L,R,mid+1,r,rs[cur],x,w);
	}
	inline void init(int x){rt=build(1,n=x);}
}tr2;
void dij(int s)
{
	memset(d,63,sizeof(d));
	d[s]=0,q.push((node){s,0});
	node x;
	while(!q.empty())
	{
		x=q.top();
		q.pop();
		if(x.d!=d[x.u]) continue;
		for(int i=front[x.u];i;i=c[i].nxt)
		{
			if(d[c[i].v]>d[x.u]+c[i].w)
			{
				d[c[i].v]=d[x.u]+c[i].w;
				q.push((node){c[i].v,d[c[i].v]});
			}
		}
	}
}
int main()
{
	int n,q,s,opt,u,v,l,r;
	ll w;
	scanf("%d %d %d",&n,&q,&s);
	node_cnt=n;
	tr1.init(n);
	tr2.init(n);
	for(int i=1;i<=q;++i)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d %d %lld",&u,&v,&w);
			add(u,v,w);
		}
		else if(opt==2)
		{
			scanf("%d %d %d %lld",&u,&l,&r,&w);
			tr1.link(l,r,1,n,tr1.rt,u,w);
		}
		else
		{
			scanf("%d %d %d %lld",&v,&l,&r,&w);
			tr2.link(l,r,1,n,tr2.rt,v,w);
		}
	}
	dij(s);
	for(int i=1;i<=n;++i) printf("%lld ",d[i]<inf?d[i]:-1);
	return 0;
}
//clx ak ioi