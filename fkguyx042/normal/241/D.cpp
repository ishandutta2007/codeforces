#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,N,x;
int f[32][32][50001],RT[40];
int y[101],ans[101];
void dfs(int x,int y,int z)
{  if (x==0) return;
  if (f[x][y][z]==32) dfs(x-1,y,z);
  else { ans[++ans[0]]=RT[f[x][y][z]];
         int i;
         for (i=0;i<p;i++)
         if (f[x][y][z]>=10)
        {   if ((i*100+f[x][y][z])%p==z&&f[x-1][y^f[x][y][z]][i]) { dfs(x-1,y^f[x][y][z],i); return; } }
        else {
        	   if ((i*10+f[x][y][z])%p==z
			   &&f[x-1][y^f[x][y][z]][i]) { dfs(x-1,y^f[x][y][z],i); return; }
           } 
}
}
int main()
{  scanf("%d%d",&n,&p);
  for (i=1;i<=n;i++) 
  { scanf("%d",&x);
   if (x<=31) y[++N]=x,RT[x]=i;
  }
  f[0][0][0]=1;
  for (i=1;i<=N;i++)
    for (j=0;j<32;j++)
      for (k=0;k<p;k++)
       { if (!f[i-1][j][k]) continue;
          if (y[i]>=10) f[i][j^y[i]][(k*100+y[i])%p]=y[i];
          else f[i][j^y[i]][(k*10+y[i])%p]=y[i];
          if (f[i][j][k]==0) f[i][j][k]=32;
       }
  dfs(N,0,0);
  if (!ans[0]) printf("No\n");
  else { printf("Yes\n");
         printf("%d\n",ans[0]);
         for (i=ans[0];i;i--) printf("%d ",ans[i]);
       }
}