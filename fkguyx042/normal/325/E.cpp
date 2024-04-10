#include<cstdio>
using namespace std;
int vis[100005],Q[100005];
int i,j,m,n,p,k;
void dfs(int x)
{  vis[x]=1;
   if (!vis[(x*2)%n]) dfs((x*2)%n);
   if (!vis[(x*2+1)%n]) dfs((x*2+1)%n);
   Q[++Q[0]]=x;
}
int main()
{ scanf("%d",&n);
  if (n&1) printf("-1\n");
  else { 
       dfs(0);
        for (i=Q[0];i;i--) printf("%d ",Q[i]); printf("0");
}
}