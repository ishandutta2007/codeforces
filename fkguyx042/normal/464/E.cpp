#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>

#define ls tree[t].l
#define rs tree[t].r
#define Ls tree[t1].l
#define Rs tree[t1].r
#define mid ((l+r)>>1)

#define seed 23333
#define mo 998244353
#define Mo 1000000007
#define N 100050
#define M 43000005

using namespace std;
struct Tre{short int add;int l,r,hash;}tree[M];
int i,j,m,n,p,k,Q[N*100],root[N],ans,x,y,z,T,S,k1,fox[N],pre[N],vis[N],tot,Hash[N+10],R,Pow[N];
struct Node{int ed,before,cost;}s[N*2];
void add(int x,int y,int z)
{
	s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; s[k1].cost=z;
}
struct Nc{int sum,ch;
};
void down(int t,int len)
{
	   if (!t) return;
	  if (tree[t].add==-1) return;
	  if (!ls) ls=++tot; if (!rs) rs=++tot;
	  tree[ls].add=tree[rs].add=tree[t].add;
	  tree[ls].hash=tree[t].add*Hash[len-(len>>1)];
	  tree[rs].hash=tree[t].add*Hash[len>>1];
	  tree[t].add=-1;
}
bool Find(int l,int r,int t,int t1)
{
	 if (l==r) return tree[t].hash<tree[t1].hash;
	 else 
	 {
	 	  down(t,r-l+1); down(t1,r-l+1);
	 	  if (tree[rs].hash!=tree[Rs].hash) return Find(mid+1,r,rs,Rs);
	 	  else return Find(l,mid,ls,Ls);
	 }
}
bool compare(int x,int y)
{
	  return Find(0,N,x,y);
}
int LeftMost(int ll,int rr,int l,int r,int t)
{
     if (tree[t].hash==Hash[r-l+1]) return 0;
     if (l==r) { R=l; return 1; }
     down(t,r-l+1);
     if (ll<=l&&r<=rr) return LeftMost(ll,rr,l,mid,ls)||LeftMost(ll,rr,mid+1,r,rs);
    if (ll<=mid&&LeftMost(ll,rr,l,mid,ls)) return 1;
     if (rr>mid&&LeftMost(ll,rr,mid+1,r,rs)) return 1;
     return 0;
}
void update(int ll,int rr,int c,int l,int r,int t)
{
	 if (ll<=l&&r<=rr)
	 {
	 	 ls=rs=0;
	 	 tree[t].hash=c*Hash[r-l+1];
	 }
	 else 
	 { 
	      down(t,r-l+1);
	 	 if (ll<=mid)
	 	 {
	 	 	  if (ls)
	 	 	  tree[++tot]=tree[ls];
	 	 	  else ++tot;
	 	 	  ls=tot;
	 	 	  update(ll,rr,c,l,mid,ls);
	 	 }
	 	 if (rr>mid)
	 	 {
	 	 	   if (rs)
	 	 	  tree[++tot]=tree[rs];
	 	 	  else ++tot;
	 	 	  rs=tot;
	 	 	  update(ll,rr,c,mid+1,r,rs);
	     }
	     int len=r-l+1;
	     tree[t].hash=(tree[ls].hash+1ll*tree[rs].hash*Pow[len-(len>>1)]%mo)%mo;
	}
}
void make_change(int Rt,int x)
{
	  LeftMost(x,N,0,N,Rt);
	  if (R!=x) update(x,R-1,0,0,N,Rt);
	  update(R,R,1,0,N,Rt);
}
bool change(int x,int y,int c)
{
	   root[y]=++tot;
	   tree[tot]=tree[root[x]];
	   make_change(tot,c);
	   return 1;
}
bool check(int x,int y,int c)
{
	  int i;
	  if (!root[y]) return change(x,y,c);
	  int Root=++tot; tree[Root]=tree[root[x]];
	  make_change(Root,c);
	  if (compare(Root,root[y])) 
	  {
	  	  for(i=Root;i<=tot;++i) tree[i].l=tree[i].r=0,tree[i].add=-1,tree[i].hash=0;
	  	  tot=Root-1;
          return change(x,y,c);
      }
      for(i=Root;i<=tot;++i) tree[i].l=tree[i].r=0,tree[i].add=-1,tree[i].hash=0;
      tot=Root-1;
	  return 0;
}
priority_queue<Nc>Que;
inline int operator <(Nc a,Nc b) {
	  return !compare(a.ch,b.ch);
}
void spfa()
{
	  Nc Rec; Rec.sum=S; Rec.ch=root[S];
	  Que.push(Rec);
	  root[S]=++tot;
	  int l;
	 while (!Que.empty())
	  {
	  	  Rec=Que.top(); Que.pop(); p=Rec.sum;
	  	  if (p==T) vis[p]=1;
	  	  if (vis[p]) continue;
	  	  vis[p]=1;
	  	  for (i=fox[p];i;i=s[i].before)
	  	    if (check(p,s[i].ed,s[i].cost))
	  	    {
	  	    	  pre[s[i].ed]=p;
	  	    	  Rec.sum=s[i].ed;
	  	    	  Rec.ch=root[s[i].ed];
	  	    	  Que.push(Rec);
	  	    }
	  }
}
void Prt(int l,int r,int t)
{
	 if (l==r) ans=(ans*2+tree[t].hash)%Mo;
	 else 
	 {
	 	  down(t,r-l+1);
	 	  Prt(mid+1,r,rs);
	 	  Prt(l,mid,ls);
	 }
}
int main()
{
	 scanf("%d%d",&n,&m);
	 for (i=1;i<M;++i) tree[i].add=-1;
	 Pow[0]=1;
	 for (i=1;i<N;++i) Pow[i]=1ll*Pow[i-1]*seed%mo;
	 for (i=1;i<N+10;++i) Hash[i]=(1ll*Hash[i-1]*seed%mo+1)%mo;
	 for (;m--;)
	 {
	 	  scanf("%d%d%d",&x,&y,&z);
	 	  add(x,y,z);
	 	  add(y,x,z);
	 }
	 scanf("%d%d",&S,&T);
	 spfa();
	 Prt(0,N,root[T]);
	 if (!vis[T]) printf("-1\n");
	else 
	{
	 printf("%d\n",ans);
	 Q[0]=0;
	 for (i=T;i;i=pre[i]) Q[++Q[0]]=i;
	 printf("%d\n",Q[0]);
	 for (i=Q[0];i;--i) printf("%d ",Q[i]);
     }
}