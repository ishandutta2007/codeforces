#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
#define pi pair<int,int>
#define pii pair<pi,int>
#define piii pair<pii,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int n,q,t,m,p,fa[200010][25],h[200010],r[200010],e[200010],f[200010],u[200010],v[200010],w[200010],x[400010];
vi a[200010],b[200010],d;
pii g[200010];
bool o[200010];
set<piii> F;
inline void dfs(int i)
{
    int j;
    r[i]=++p;
    for(j=1;j<=20;j++)
      fa[i][j]=fa[fa[i][j-1]][j-1];
    for(auto j:a[i])
      if(j!=fa[i][0])
        {
         fa[j][0]=i;
         h[j]=h[i]+1;
         dfs(j);
        }
}
inline int lca(int i,int j)
{
    int k;
    if(h[i]<h[j])
      swap(i,j);
    if(h[i]>h[j])
      for(k=20;k>=0;k--)
        if(h[i]-h[j]>=(1<<k))
          i=fa[i][k];
    if(i==j)
      return i;
    for(k=20;k>=0;k--)
      if(fa[i][k]!=fa[j][k])
        i=fa[i][k],j=fa[j][k];
    return fa[i][0];
}
inline bool cmp(int i,int j)
{
    return r[i]<r[j];
}
inline void add(int i,int j)
{
    b[i].pb(j);
    b[j].pb(i);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	  {
	   scanf("%d%d",&j,&k);
	   a[j].pb(k);
	   a[k].pb(j);
      }
    h[1]=1;
    dfs(1);
    scanf("%d",&q);
    while(q--)
      {
       scanf("%d%d",&t,&m);
       p=1;
       x[1]=1;
       for(i=1;i<=t;i++)
         scanf("%d%d",&u[i],&v[i]),x[++p]=u[i];
       for(i=1;i<=m;i++)
         scanf("%d",&w[i]),x[++p]=w[i];
       sort(x+1,x+p+1,cmp);
       k=1;
       e[1]=1;
       d.pb(1);
       for(i=2;i<=p;i++)
         {
          if(x[i]==e[k])
            continue;
          j=lca(x[i],e[k]);
          while(k>1 && h[e[k-1]]>=h[j])
            {
             add(e[k],e[k-1]);
             k--;
            }
          if(e[k]!=j)
            {
             add(e[k],j);
             e[k]=j;
             d.pb(j);
            }
          e[++k]=x[i];
          d.pb(x[i]);
         }
       for(;k>1;k--)
         add(e[k],e[k-1]);
       for(auto i:d)
         f[i]=0,g[i]=mp(mp((int)1e9,0),0);
       for(i=1;i<=t;i++)
         f[u[i]]=i,g[u[i]]=mp(mp(0,i),0);
       for(auto i:d)
         F.insert(mp(g[i],i));
       while(!F.empty())
         {
          i=(*F.begin()).se;
          pii x=(*F.begin()).fi;
          F.erase(*F.begin());
          f[i]=x.fi.se;
          for(auto j:b[i])
            if(!f[j])
            {
             pii y=x;
             k=abs(h[i]-h[j])+x.se;
             if(k<=0)
               y.se=k;
             else
               {
                y.fi.fi+=(k-1)/v[f[i]]+1;
                y.se=k-((k-1)/v[f[i]]+1)*v[f[i]];
               }
             if(y<g[j])
               {
                F.erase(mp(g[j],j));
                g[j]=y;
                F.insert(mp(g[j],j));
               }
            }
         }
       for(i=1;i<=m;i++)
         printf("%d ",f[w[i]]);
       printf("\n");
       for(auto i:d)
         b[i].clear();
       d.clear();
      }
	return 0;
}