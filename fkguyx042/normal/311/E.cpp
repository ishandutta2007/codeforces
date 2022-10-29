#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=(int)1e9;
int i,j,m,n,p,k,g,st,ed,sum,Rp,ans,k1=1;
struct Node{int ed,before,flow;}s[1000001];
int from[20001],dis[20001],que[20001],fox[20001];
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
{ scanf("%d%d%d",&n,&m,&g);
  st=n+m+1; ed=st+1;
  for (i=1;i<=n;i++) scanf("%d",&from[i]);
  for (i=1;i<=n;i++) {scanf("%d",&k); if (!from[i]) add(st,i,k); else add(i,ed,k); }
  for (i=1;i<=m;i++)
  { scanf("%d%d%d",&Rp,&sum,&k); ans+=sum;
     for (j=1;j<=k;j++) {
     scanf("%d",&p);
     if (Rp==0) 
	 add(i+n,p,INF); else add(p,i+n,INF); }
     scanf("%d",&p);
     if (Rp==0) add(st,i+n,sum+p*g);
     else add(i+n,ed,sum+p*g);
}
printf("%d\n",ans-maxflow());
}