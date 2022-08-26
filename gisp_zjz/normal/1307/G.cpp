#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

inline char nc(){
  static char buf[100000],*p1=buf,*p2=buf;
  return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline void read(int &x){
  char c=nc(),b=1;
  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;
  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;
}

const int N=55;
const int M=2505;

struct edge{
  int u,v,w,f; int next;
}G[M<<1];
int head[N],inum=1;
inline void add(int u,int v,int w,int f,int p){
  G[p].u=u; G[p].v=v; G[p].w=w; G[p].f=f; G[p].next=head[u]; head[u]=p;
}
inline void link(int u,int v,int w,int f){
  add(u,v,w,f,++inum); add(v,u,-w,0,++inum);
}
#define oo 1<<29
int n,m,P;
int S,T,Mincost;
int Q[N*M],l,r;
int dis[N],pre[N],ins[N];
#define V G[p].v
inline bool SPFA(){
  for (int i=1;i<=n;i++) dis[i]=oo,pre[i]=0,ins[i]=0;
  l=r=-1; Q[++r]=S,dis[S]=0,ins[S]=1;
  while (l<r){
    int u=Q[++l]; ins[u]=0;
    for (int p=head[u];p;p=G[p].next)
      if (G[p].f && dis[V]>dis[u]+G[p].w){
    dis[V]=dis[u]+G[p].w; pre[V]=p;
    if (!ins[V]) Q[++r]=V,ins[V]=1;
      }
  }
  if (dis[T]==oo) return 0;
  Mincost+=dis[T];
  for (int p=pre[T];p;p=pre[G[p].u])
    G[p].f--,G[p^1].f++;
  return 1;
}
int _,Qry[123456];
double Ans[123456];
int main(){
  int u,v,c,d;
  //freopen("input.txt","r",stdin);
  //freopen("t.out","w",stdout);
  read(n); read(m); S=1; T=n;
  for (int i=1;i<=m;i++)
    read(u),read(v),read(d),c=1,link(u,v,d,c);
  read(_);
  for (int i=0;i<_;i++) read(Qry[i]);
  //for (int i=0;i<_;i++) printf("%d\n",Qry[i]);
  double ans=1e20; int m=0;
  for (int i=0;i<_;i++) Ans[i]=1e20;
  while (SPFA()){
    m++;
    for (int i=0;i<_;i++) Ans[i]=min(Ans[i],((double)(Mincost+Qry[i]))/m);
    ans=min(ans,(double)(Mincost+P)/m);
  }
  for (int i=0;i<_;i++) printf("%.10f\n",Ans[i]);
  return 0;
}