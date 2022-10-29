#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>

#define se second
#define fi first
#define mk make_pair

#define N 100005
#define M 20

using namespace std;
set<pair<int,int> >str;
int st[N],fa[N][M],i,j,m,n,p,k,ans,x,y,sum,tot,deep[N];
vector<int>v[N];
void get(int x)
{
      int i;
      for (i=1;i<M;++i) fa[x][i]=fa[fa[x][i-1]][i-1];
}
void dfs(int x)
{
       int i,p;
       st[x]=++tot;
       get(x);
       for (i=0;i<(int)v[x].size();++i)
         if (fa[x][0]!=v[x][i])
         {
           fa[p=v[x][i]][0]=x;
           deep[p]=deep[x]+1;
           dfs(p);
         }
}
int getfa(int x,int y)
{
    if (deep[x]<deep[y]) swap(x,y);
    int i,j,k;
    for (i=M-1,k=deep[x]-deep[y];i>=0;--i)
      if (k&(1<<i)) x=fa[x][i];
    if (x==y) return x;
    for (i=M-1;i>=0;--i)
      if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
void Jia(int x,int y,int z)
{
       int F=getfa(x,y);
       sum+=z*(deep[x]+deep[y]-2*deep[F]);
}
void insert(int x)
{
     if (!str.size()) ;
     else if  (str.size()==1)
     {
              pair<int,int> y=*str.begin();
              Jia(x,y.se,2);
     }
     else if (st[(*str.begin()).se]>st[x])
     { 
                int ax=(*str.begin()).se,ay=(*--str.end()).se;
                Jia(ax,ay,-1);
                Jia(x,ax,1);
                Jia(x,ay,1);
     }
     else if (st[(*--str.end()).se]<st[x])
     {
            int ax=(*str.begin()).se,ay=(*--str.end()).se;
            Jia(ax,ay,-1);
            Jia(x,ax,1);
            Jia(x,ay,1);
     }
     else 
     {
            set<pair<int,int> >::iterator it=str.lower_bound(mk(st[x],x));
            int ax=(*it).se; --it; int ay=(*it).se;
            Jia(ax,ay,-1);
            Jia(x,ax,1);
            Jia(x,ay,1);
     }
     str.insert(mk(st[x],x));
}
void del(int x)
{
       if (str.size()==1) ;
       else 
       {
             int ax,ay;
            set<pair<int,int> >::iterator it=str.lower_bound(mk(st[x],x));
            if (it==str.begin()) ax=(*--str.end()).se; else 
            --it,ax=(*it).se,++it;
            if (it==--str.end()) ay=(*str.begin()).se; else 
            ++it,ay=(*it).se,--it;
            Jia(ax,x,-1); Jia(ay,x,-1); Jia(ax,ay,1);
       }
       str.erase(mk(st[x],x));
}
int main()
{
     scanf("%d%d",&n,&k);--k; k*=2; 
     for (i=1;i<n;++i) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
     dfs(1);
     int l=1; 
     for (i=1;i<=n;++i)
     {
         for (;l<=n&&sum<=k;)
         {
               insert(l); ++l;
         }
         if (l>n&&sum<=k) ans=max(ans,l-i);
         else 
         ans=max(ans,l-i-1);
         del(i);
     }
     printf("%d\n",ans);
}