#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,k1;
long long vis[100001],fox[100001],ed[200001],before[200001],size[100001];
struct Node{long long x,y;}Tree[100001];
void add(int x,int y){ ed[++k1]=y; before[k1]=fox[x]; fox[x]=k1; }
void dfs(int x)
{  int i,j; vis[x]=1;
   for (i=fox[x];i;i=before[i])
    if (!vis[ed[i]])
    {  dfs(ed[i]);
       Tree[x].x=max(Tree[x].x,Tree[ed[i]].x);
       Tree[x].y=max(Tree[x].y,Tree[ed[i]].y);
   }
  int sum=size[x]-Tree[x].x+Tree[x].y;
  if (sum>0) Tree[x].x+=sum;
  if (sum<0) Tree[x].y-=sum;
}
int main()
{ scanf("%d",&n);
  for (i=1;i<n;i++)
  { int x,y; scanf("%d%d",&x,&y); add(x,y);add(y,x);}
  for (i=1;i<=n;i++) scanf("%I64d",&size[i]);
  dfs(1);
  printf("%I64d\n",Tree[1].x+Tree[1].y);
}