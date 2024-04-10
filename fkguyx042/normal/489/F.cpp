#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,Mo,y,x,last,now;
char c[1001];
int size[501];
int f[2][501][501];
int main()
{ scanf("%d%d%d",&n,&m,&Mo);
  for (i=1;i<=m;i++) { 
  scanf("%s",&c);
  for (j=1;j<=n;j++)  size[j]+=c[j-1]-'0'; }
  for (i=1;i<=n;i++) if (size[i]>2) { printf("0\n"); return 0;  }
  else if (size[i]==1) x++; else if (size[i]==0) y++;
  f[0][y][x]=1;
  for (i=m+1;i<=n;i++)
{  last=now;
   now=last^1;
   memset(f[now],0,sizeof(f[now]));
   for (j=0;j<=n;j++)
     for (k=0;k<=n-j;k++)
        if (f[last][j][k])
       {    if (j>1) (f[now][j-2][k+2]+=1ll*f[last][j][k]*(j*(j-1)/2)%Mo)%=Mo;
            if (k>1) (f[now][j][k-2]+=1ll*f[last][j][k]*(k*(k-1)/2)%Mo)%=Mo;
            if (j&&k)(f[now][j-1][k]+=1ll*f[last][j][k]*j*k%Mo)%=Mo;
       }
}
     printf("%d\n",f[now][0][0]);
}