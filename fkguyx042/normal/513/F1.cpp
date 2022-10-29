#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int xi[4]={0,0,-1,1};
const int yi[4]={-1,1,0,0};
int i,j,m,n,p,k,tot,id[33][33],st,ed,male,famale,x,y,z,id_[33][33];
int fox[3005],que[3005],dis[3005],k1=1,Dis[33][33],Vis[33][33];
struct Queue{int x,y;}Q[5555];
char c[33][33];
struct Time{int x,y,t;}M[1000];
Time F[1000];
struct Node{int ed,before,flow;}s[200001];
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
void bfs(int x,int y){
	 int l=1,r=1,i,j,X,Y;
	Q[1].x=x; Q[1].y=y;
	memset(Dis,60,sizeof(Dis));
	Dis[x][y]=0;
	for (;l<=r;l++)
 {    X=Q[l].x; Y=Q[l].y;
    for (i=0;i<4;i++)
     if (X+xi[i]>0&&Y+yi[i]>0&&X+xi[i]<=n&&Y+yi[i]<=m&&Dis[X+xi[i]][Y+yi[i]]>(int)1e9&&c[X+xi[i]][Y+yi[i]-1]!='#')
     {  Dis[X+xi[i]][Y+yi[i]]=Dis[X][Y]+1;
        Q[++r].x=X+xi[i]; Q[r].y=Y+yi[i];
     }
}
}
bool check(long long x)
{    int i,j,p,k;
     memset(fox,0,sizeof(fox)); k1=1;
     for (i=1;i<=male;i++) add(st,i,1);
     for (i=1;i<=famale;i++) add(male+i,ed,1);
     for (i=1;i<=male;i++)
    { bfs(M[i].x,M[i].y);
       for (j=1;j<=n;j++)
         for (k=1;k<=m;k++)
          if (Dis[j][k]<10000&&(long long)1ll*Dis[j][k]*M[i].t<=x) add(i,id[j][k],1);
    }
     for (i=1;i<=famale;i++)
    {  bfs(F[i].x,F[i].y);
       for (j=1;j<=n;j++)
         for (k=1;k<=m;k++)
        if (Dis[j][k]<10000&&(long long)1ll*Dis[j][k]*F[i].t<=x) add(id_[j][k],i+male,1);
    }
    for (i=1;i<=n;i++) for (j=1;j<=m;j++) add(id[i][j],id_[i][j],1);
     if (maxflow()==male) return 1;
     return 0;
}
int main()
{ scanf("%d%d%d%d",&n,&m,&male,&famale);
  if (abs(male-famale)!=1) { printf("-1\n"); return 0; }
  for (i=1;i<=n;i++) scanf("%s",&c[i]);
  tot=2*max(male,famale);
  for (i=1;i<=n;i++)
   for (j=1;j<=m;j++)
     id[i][j]=++tot;
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      id_[i][j]=++tot;
    st=tot+1;ed=st+1;
   scanf("%d%d%d",&x,&y,&z);
   for (i=1;i<=male;i++) scanf("%d%d%d",&M[i].x,&M[i].y,&M[i].t);
   for (i=1;i<=famale;i++) scanf("%d%d%d",&F[i].x,&F[i].y,&F[i].t);
   if (male<famale) male++,M[male].x=x,M[male].y=y,M[male].t=z;
   else famale++,F[famale].x=x,F[famale].y=y,F[famale].t=z;
 long long l=0,r=(long long)1e15,mid=0;
 for (;(l+r)>>1!=mid;)
 {  
   mid=(l+r)>>1;
   if (check(mid)) r=mid; else l=mid;
}
if (r==(long long)1e15) printf("-1\n");
else printf("%I64d\n",r);
}