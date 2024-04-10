#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 305
#define M 2000005

using namespace std;

const int INF=(int)1e9;

int i,j,m,n,p,k,x,k1=1,fox[N],que[N],dis[N],a[N][N],vis[N],match[N];
int st,ed,ans;

struct Node{int ed,before,flow;}s[M];

int get(int x)
{
	  int i;
	  for (i=1;i<=n;++i)
	    if (a[x][i]&&vis[i]!=p)
	    {
	    	    vis[i]=p;
	    	    if (!match[i]||get(match[i])) 
	    	    {
	    	    	 match[i]=x;
	    	    	 return true;
	    	    }
	    }
	    return false;
}
inline int bfs()
 { int i,p,l,r;
   memset(dis,-1,sizeof(dis));
    l=r=1;
    dis[st]=0;
   que[1]=st;
   while (l<=r)
    { p=que[l];
      for (i=fox[p];i;i=s[i].before)
        if (s[i].flow>0)
        if (dis[s[i].ed]==-1)
         { 
           que[++r]=s[i].ed;
           dis[s[i].ed]=dis[p]+1;
           }
    l++;
}
 if (dis[ed]==-1) return 0;
 return 1;
}
void add(int p1,int p2,int p3) {s[++k1].ed=p2; s[k1].flow=p3; s[k1].before=fox[p1]; fox[p1]=k1;
  s[++k1].ed=p1; s[k1].flow=0; s[k1].before=fox[p2]; fox[p2]=k1; }
int dfs(int num,int flow)
 {  int i;
    int a,nowans=0;
   if (num==ed) return flow;
     for (i=fox[num];i&&flow;i=s[i].before)
       if (s[i].flow>0&&dis[s[i].ed]==dis[num]+1)
        if(a=dfs(s[i].ed,min(s[i].flow,flow)))
         { s[i].flow-=a;
           s[i^1].flow+=a;
           flow-=a;nowans+=a;
           }if (!nowans) dis[num]=(int)1e9;
   return nowans;
}
int maxflow()
{ int j;
  int ans=0;
    while (bfs())
    { j=dfs(st,(int)1e9);  while (j) ans+=j,j=dfs(st,(int)1e9); }
  return ans;
}
int main()
{
	 scanf("%d",&n);
	st=n+1; ed=st+1;
	 for (i=1;i<=n;++i)
  { 
     scanf("%d",&k);
     for (;k--;)
     {
     	 scanf("%d",&x);
    	 a[i][x]=1;
     }
  }
     for (i=1;i<=n;++i)
  {
      ++p;
      get(i);
  }
    for (i=1;i<=n;++i)
    {
    	   scanf("%d",&x); x=-x;
    	   if (x>0) ans-=x,add(st,i,x);
    	   else add(i,ed,-x);
    	   for (j=1;j<=n;++j) 
    	     if (match[j]!=i&&a[i][j]) add(i,match[j],INF);
    }
   ans+=maxflow();
   printf("%d\n",ans); 
}