#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 200005
#define M 10
using namespace std;
char c[M];
int i,j,m,n,p,k,x[N],y[N],fa[M],f[M][M],lim,sum[M],big[M],g[M][M],tot,flag[N],h[M],w[M][M];
int fox[50],k1,st,ed,Str[M],Go[M][M],l,dis[50],Q[50],X[N],Y[N],fff[N];
struct Node{int ed,before,flow;}s[N];
const int inf=(int)1e9;
int power(int x,int y) 
{
      int sum=1;
      for (;y;y>>=1,x*=x) if (y&1) sum*=x;
      return sum;
}
int get(int x) { return fa[x]==x?x:fa[x]=get(fa[x]); }
void add(int x,int y,int flow)
{
       s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; s[k1].flow=flow;
       s[++k1].ed=x; s[k1].before=fox[y]; fox[y]=k1; s[k1].flow=0;
}
bool bfs()
{
     int i,j,l;
     memset(dis,-1,sizeof(dis));
     Q[Q[0]=1]=st; dis[st]=0;
     for (l=1;l<=Q[0];++l)
     {
          int p=Q[l];
          for(i=fox[p];i;i=s[i].before)
             if (s[i].flow&&dis[s[i].ed]==-1)
             {
                  dis[s[i].ed]=dis[p]+1;
                  Q[++Q[0]]=s[i].ed;
             }
     }
     return dis[ed]!=-1;    
}
int zyb(int x,int flow)
{
    int a,nowans=0,i;
    if (x==ed) return flow;
    for (i=fox[x];i&&flow;i=s[i].before)
       if (s[i].flow&&dis[x]+1==dis[s[i].ed])
         if (a=zyb(s[i].ed,min(flow,s[i].flow)))
         {
              nowans+=a;
              s[i].flow-=a;
              s[i^1].flow+=a;
              flow-=a;
         }
    if (!nowans) dis[x]=inf;
    return nowans;
}
int maxflow()
{
      int ans=0,j;
      while (bfs())
      {
             j=zyb(st,inf); 
             while (j) 
             ans+=j,j=zyb(st,inf);
      }
      return ans;
}
void work()
{
       int i,j,Sum=0; memset(fox,0,sizeof(fox)); k1=1;
       for (i=1;i<=k;++i) get(i);
       for (i=2;i<=k;++i) if (fa[i]!=fa[i-1]) return;
       tot=0; st=++tot; ed=++tot;
         for (i=1;i<=k;++i) h[i]=++tot,add(h[i],ed,sum[i]);
       for (i=1;i<=k;++i)
         for (j=i;j<=k;++j)
             if (f[i][j])
             {
                w[i][j]=++tot;
                add(st,w[i][j],f[i][j]);
                if (h[i]!=h[j])
                add(w[i][j],h[i],inf);
                add(w[i][j],h[j],inf);
                Sum+=f[i][j];
             }
      if (maxflow()!=Sum) return; 
      for (i=1;i<=k;++i) Str[i]=power(10,i-1)+1;
      for (i=1;i<=k;++i)
       for (j=i;j<=k;++j)
         if (f[i][j])
           for (l=fox[w[i][j]];l;l=s[l].before)
             if (s[l].ed==h[i]) Go[j][i]=inf-s[l].flow;
             else if (s[l].ed==h[j]) Go[i][j]=inf-s[l].flow;
      for (i=1;i<n;++i)
      {
             int ansx,ansy;
             if (g[x[i]][y[i]]) ansx=big[x[i]],ansy=big[y[i]],g[x[i]][y[i]]=0;
             else 
             { 
                  if (Go[x[i]][y[i]]) ansx=big[x[i]],ansy=Str[y[i]]++,Go[x[i]][y[i]]--;
                  else ansx=Str[x[i]]++,ansy=big[y[i]],Go[y[i]][x[i]]--;
             }
             if (flag[i]) swap(ansx,ansy);
             X[i]=ansx,Y[i]=ansy;
      }
      for (i=1;i<n;++i) printf("%d %d\n",X[i],Y[i]);
      exit(0);
}
void dfs(int x,int y)
{
     if (x>k) work();
     else  if (y>k) dfs(x+1,x+2);
     else 
     {          
            dfs(x,y+1);
            int z[M];
            memcpy(z,fa,sizeof(z));
            if (f[x][y]&&get(x)!=get(y))
            {
                 f[x][y]--;
                 g[x][y]=1;
                 fa[get(x)]=get(y);
                 dfs(x,y+1);
                 g[x][y]=0;
                 f[x][y]++;
                 --tot;
            }
            memcpy(fa,z,sizeof(z));
     }
} 	
int main()
{
     scanf("%d",&n); if (n==1) return 0;
     for (j=n;j;j/=10) k++;
     for (i=1;i<n;++i)
 {
       scanf("%s",c);
       x[i]=strlen(c); 
       scanf("%s",c);
       y[i]=strlen(c);
       if (x[i]>y[i]) flag[i]=1,swap(x[i],y[i]);
       f[x[i]][y[i]]++;
 }
 for (i=1;i<k;++i) sum[i]=9*power(10,i-1)-1;
 sum[k]=n-power(10,k-1);
 for (i=1;i<=k;++i) big[i]=power(10,i-1),fa[i]=i;
 dfs(1,2);
 puts("-1");
}