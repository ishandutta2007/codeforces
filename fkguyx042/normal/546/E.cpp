#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=(int)1e9;
int i,j,m,n,p,k,a[105],b[105],st,ed,x,y; 
int Cost[105][105],dis[233],que[233],fox[233],k1=1,X,Y;
struct Node{int ed,before,flow;}s[1000005];
inline int bfs()
 { int i,j,p,k,l,r;
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
 {  int i,p;
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
{ int i,j;
  int ans=0;
    while (bfs())
    { j=dfs(st,(int)1e9);  while (j) ans+=j,j=dfs(st,(int)1e9); }
  return ans;
}
int main()
{
    scanf("%d%d",&n,&m); st=2*n+1; ed=st+1;
    for (i=1;i<=n;++i) scanf("%d",&a[i]),add(st,i,a[i]),X+=a[i];
    for (i=1;i<=n;++i) scanf("%d",&b[i]),add(i+n,ed,b[i]),Y+=b[i];
    for (;m--;)
  {
         scanf("%d%d",&x,&y);
         add(x,y+n,INF);
         add(y,x+n,INF);
  }
  for (i=1;i<=n;++i) add(i,i+n,INF);
  if (X!=Y||maxflow()!=Y)  printf("NO\n");
  else 
  {
        printf("YES\n");
        for (i=1;i<=n;++i)
            for (j=fox[i];j;j=s[j].before)
             if (s[j].ed<=2*n) Cost[i][s[j].ed-n]=INF-s[j].flow;
        for (i=1;i<=n;++i)
        {
         for (j=1;j<=n;++j) printf("%d ",Cost[i][j]);
         puts("");
        }
  }
}