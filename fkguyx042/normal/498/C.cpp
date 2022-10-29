#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,st,ed,k1=1;
int sum[101][52],id[101][52],dis[5005],que[5005],fox[5005],a[101],tot,x,y;
struct Node{int ed,before,flow;}s[1000001];
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
{ scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++) 
  { scanf("%d",&a[i]);
  for (j=2;j*j<=a[i];j++)
   while (a[i]%j==0)
  {    a[i]/=j;
    sum[i][++sum[i][0]]=j;
    id[i][sum[i][0]]=++tot;
  } 
  if (a[i]>1) sum[i][++sum[i][0]]=a[i],id[i][sum[i][0]]=++tot;
  }
  for (i=1;i<=n;i++) sort(sum[i]+1,sum[i]+sum[i][0]+1);
  for (i=1;i<=m;i++)
{ scanf("%d%d",&x,&y);
  if (x%2==0) swap(x,y);
  int l=1,r=1;
 /* while (l<=sum[x][0]&&r<=sum[y][0])
{  if (sum[x][l]==sum[y][r]) add(id[x][l],id[y][r],1),l++,r++;
   else if (sum[x][l]<sum[y][r]) l++;
   else r++;
}*/
    for (j=1;j<=sum[x][0];j++)
      for (k=1;k<=sum[y][0];k++) if (sum[x][j]==sum[y][k]) add(id[x][j],id[y][k],1);
}
 st=tot+1; ed=st+1;
  for (i=1;i<=n;i++)
    if (i&1)
     for (j=1;j<=sum[i][0];j++) add(st,id[i][j],1);
    else 
     for (j=1;j<=sum[i][0];j++) add(id[i][j],ed,1);
  printf("%d\n",maxflow());
}