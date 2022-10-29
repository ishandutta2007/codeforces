#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,x,y,k1,Ans[100001],Got[100001],X[2];
struct Node{int ed,before;}s[1000001];
int vis[100001],fox[200001];
int a[100001];
int b[100001];
void add(int x,int y)
{ s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1;}
void dfs(int x,int dep)
{  int z=y; vis[x]=1;
   if ((a[x]^X[dep&1])!=b[x])
   {  X[dep&1]^=1;
      Ans[++Ans[0]]=x;
      Got[x]=1;
   }
   int i;
   for (i=fox[x];i;i=s[i].before)
    if (!vis[s[i].ed]) dfs(s[i].ed,dep+1);
   if (Got[x]) X[dep&1]^=1;
}
int main()
{ scanf("%d",&n);
  for (i=1;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (i=1;i<=n;i++) scanf("%d",&b[i]);
  dfs(1,0);
  sort(Ans+1,Ans+Ans[0]+1);
  printf("%d\n",Ans[0]);
  for (i=1;i<=Ans[0];i++) printf("%d\n",Ans[i]);
}