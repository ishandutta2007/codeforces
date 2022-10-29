#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

#define N 300005

#define mk make_pair
#define se second

using namespace std;
priority_queue<pair<long long,int> >Q;
vector<int>v[N],sum[N];
long long dis[N],Short[N];
int i,j,m,n,p,k,fa[N],x,y,z,par[N],vis[N],tot;
struct Node{int x,y;long long val;}Bian[N];
inline bool cmp(Node a,Node b)
{
	 return a.val<b.val;
}
int get(int x) { return fa[x]==x?x:fa[x]=get(fa[x]); }
void kru()
{
	  long long ans=0;
	  sort(Bian+1,Bian+tot+1,cmp);
	  for (i=1;i<=n;++i) fa[i]=i;
	  for (i=1;i<=m;++i)
	  {
	  	 if (get(Bian[i].x)!=get(Bian[i].y)) 
		 ans+=Bian[i].val,fa[get(Bian[i].x)]=fa[get(Bian[i].y)];
	  }
	  printf("%I64d\n",ans+dis[1]);
}
void dij()
{
  memset(dis,60,sizeof(dis));
  for (i=1;i<=n;++i)
  {
  	  Short[i]=i;
  	  if (par[i]) dis[i]=0,Q.push(mk(0,i));
  }
  while (!Q.empty())
  {
  	  pair<long long,int> x=Q.top();
  	  Q.pop();
  	  if (vis[x.se]) continue;
  	  vis[x.se]=1;
  	  int id=x.se;
  	  for (i=0;i<v[id].size();++i)
  	      if (dis[id]+sum[id][i]<dis[v[id][i]])
  	      {
  	      	  int k=v[id][i];
  	      	  dis[k]=dis[id]+sum[id][i];
  	      	  Short[k]=Short[id];
  	      	  Q.push(mk(-dis[k],k));
  	      }
  }
}
int main()
{
	 scanf("%d%d",&n,&m);
	 for (i=1;i<=m;++i)
  {
	  scanf("%d%d%d",&x,&y,&z);
	  v[x].push_back(y);
	  v[y].push_back(x);
	  sum[x].push_back(z);
	  sum[y].push_back(z);
  }
  scanf("%d",&k);
  for (i=1;i<=k;++i)
  {
  	   scanf("%d",&x);
  	   par[x]=1;
  }
  dij();
  for (i=1;i<=n;++i)  
     for (j=0;j<(int)v[i].size();++j)
       if (i<v[i][j]&&Short[i]!=Short[v[i][j]])
       {
       	  Bian[++tot].x=Short[i];
       	  Bian[tot].y=Short[v[i][j]];
       	  Bian[tot].val=dis[i]+dis[v[i][j]]+sum[i][j];
       }
  kru();
}