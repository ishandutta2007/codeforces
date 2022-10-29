#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 15
#define M 100005
using namespace std;
const int INF=(int)1e9;
const int x[4]={0,0,-1,1};
const int y[4]={1,-1,0,0};
char c[N][N],S[N][N];
int i,j,sx,sy,st,ed,n,t,tot,id[N][N],dis[N][N],vis[N][N],que[M],fox[N*N*2],dist[N*N*2];
int k1=1;
struct Bian{int ed,before,flow;}s[M];
int Dis[N][N];
struct Node{int x,y;}Q[100005];
inline int bfs()
 { int i,p,l,r;
   memset(dist,-1,sizeof(dist));
    l=r=1;
    dist[st]=0;
   que[1]=st;
   while (l<=r)
    { p=que[l];
      for (i=fox[p];i;i=s[i].before)
        if (s[i].flow>0)
        if (dist[s[i].ed]==-1)
         { 
           que[++r]=s[i].ed;
           dist[s[i].ed]=dist[p]+1;
           }
    l++;
}
 if (dist[ed]==-1) return 0;
 return 1;
}
void add(int p1,int p2,int p3) {s[++k1].ed=p2; s[k1].flow=p3; s[k1].before=fox[p1]; fox[p1]=k1;
  s[++k1].ed=p1; s[k1].flow=0; s[k1].before=fox[p2]; fox[p2]=k1; }
int dfs(int num,int flow)
 {  int i;
    int a,nowans=0;
   if (num==ed) return flow;
     for (i=fox[num];i&&flow;i=s[i].before)
       if (s[i].flow>0&&dist[s[i].ed]==dist[num]+1)
        if(a=dfs(s[i].ed,min(s[i].flow,flow)))
         { s[i].flow-=a;
           s[i^1].flow+=a;
           flow-=a;nowans+=a;
           }if (!nowans) dist[num]=(int)1e9;
   return nowans;
}
int maxflow()
{ int j;
  int ans=0;
    while (bfs())
    { j=dfs(st,(int)1e9);  while (j) ans+=j,j=dfs(st,(int)1e9); }
  return ans;
}
bool check(int x,int y)
{
	  if (x<0||y<0||x>=n||y>=n||vis[x][y]||c[x][y]<'0'||c[x][y]>'9') return 0;
	  return 1;
}
void Bfs()
{
	  int i,l=1,r=0;
	  memset(dis,60,sizeof(dis)); dis[sx][sy]=0;
	  Q[++r].x=sx;Q[r].y=sy; vis[sx][sy]=1;
	   for (;l<=r;++l)
	  {
	  	  int ax=Q[l].x,ay=Q[l].y;
	  	  for (i=0;i<4;++i)
	  	    if (check(ax+x[i],ay+y[i]))
	  	   {  
	  	          dis[ax+x[i]][ay+y[i]]=dis[ax][ay]+1;
	  	          vis[ax+x[i]][ay+y[i]]=1;
	  	          Q[++r].x=ax+x[i]; Q[r].y=ay+y[i];
	  	   }
	  }
}
void Find(int tx,int ty,int idx)
{
	 int i,l=1,r=0,j;
	 Q[++r].x=tx; Q[r].y=ty;
	 memset(vis,0,sizeof(vis));
	 memset(Dis,60,sizeof(Dis));
	 vis[tx][ty]=1; Dis[tx][ty]=0;
	 for (;l<=r;++l)
	 {
	 	  int ax=Q[l].x,ay=Q[l].y;
	 	  for (i=0;i<4;++i)
	 	    if (check(ax+x[i],ay+y[i]))
	 	    {
	 	    	  Dis[ax+x[i]][ay+y[i]]=Dis[ax][ay]+1;
	 	    	  vis[ax+x[i]][ay+y[i]]=1;
	 	    	  if (Dis[ax+x[i]][ay+y[i]]<dis[ax+x[i]][ay+y[i]]) Q[++r].x=ax+x[i],Q[r].y=ay+y[i];
	 	    }
	 }
	 for (i=0;i<n;++i)
	   for (j=0;j<n;++j)
	     if (Dis[i][j]<=t&&S[i][j]>'0'&&S[i][j]<='9'&&Dis[i][j]<=dis[i][j]) 
	     add(idx,id[i][j]+tot,INF);
}
int main()
{
	 scanf("%d%d",&n,&t);
	 for (i=0;i<n;++i) scanf("%s",c[i]);
	 for (i=0;i<n;++i) scanf("%s",S[i]);
	 for (sx=0;sx<n;++sx)
	 {
	   for (sy=0;sy<n;++sy)
	       if (c[sx][sy]=='Z') break;
	   if (sy!=n) break;
      }
      for (i=0;i<n;++i)
         for (j=0;j<n;++j) id[i][j]=++tot;
      st=2*tot+1; ed=st+1;
      Bfs();
      for (i=0;i<n;++i)
         for (j=0;j<n;++j)
            if (c[i][j]>'0'&&c[i][j]<='9')
            {
            	  add(st,id[i][j],c[i][j]-'0');
            	  Find(i,j,id[i][j]);
            }
     for (i=0;i<n;++i)
       for (j=0;j<n;++j)
         if (S[i][j]>'0'&&S[i][j]<='9') add(id[i][j]+tot,ed,S[i][j]-'0');
     printf("%d\n",maxflow());
}