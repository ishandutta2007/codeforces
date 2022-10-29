#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int i,j,m,n,p,k,x,y,k1,A[100001];
struct Node{int ed,before,cost;}s[500001];
map<int,int>mp[100001];
int Que[10000001],vis[100001],dis[100001],fox[100001];
void spfa()
{ int i,j,l=1,r=0,p,cost;
  Que[++r]=1;
  memset(dis,60,sizeof(dis));
  dis[1]=0;
  if (mp[1][0]) dis[1]=mp[1][0];
  vis[1]=1;
  for (;l<=r;l++)
  {   p=Que[l];
      if (mp[p][dis[p]]) cost=mp[p][dis[p]];  else cost=dis[p];
     for (i=fox[p];i;i=s[i].before)
       if (cost+s[i].cost<dis[s[i].ed])
         {  dis[s[i].ed]=cost+s[i].cost;
            if (!vis[s[i].ed]) Que[++r]=s[i].ed,vis[s[i].ed]=1;
        }
    vis[p]=0;
  }
}
void add(int x,int y,int cost) {s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1; s[k1].cost=cost; }
int main()
{scanf("%d%d",&n,&m);
 for (i=1;i<=m;i++)
 scanf("%d%d%d",&x,&y,&p),add(x,y,p),add(y,x,p);
 for (i=1;i<=n;i++)
 { scanf("%d",&A[0]);
   for (j=1;j<=A[0];j++) scanf("%d",&A[j]);
   for (j=A[0];j;j--)
    if (j==A[0]||A[j]!=A[j+1]-1) mp[i][A[j]]=A[j]+1;
    else mp[i][A[j]]=mp[i][A[j+1]];
 }
 spfa();
 if (dis[n]>1000100000) printf("-1\n");
 else printf("%d\n",dis[n]);
}