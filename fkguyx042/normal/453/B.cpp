#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,Rt,a[101],Cost,Ans[101];
const int prime[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int f[101][65536];
int G[101][65536],Now[101][65536],tot;
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]); 
   tot=1<<16;
  memset(f,60,sizeof(f)); f[0][0]=0;
  for (i=1;i<=n;i++)
      for (j=1;j<min(59,2*a[i]);j++)
    {  Rt=0; Cost=abs(a[i]-j);
         for (k=0;k<16&&prime[k]<=j;k++)
           if (j%prime[k]==0)
              Rt|=1<<k;
          for (k=0;k<tot;k++)
            if ((Rt&k)==0)
            {    p=Rt|k;
               if (f[i][p]>f[i-1][k]+Cost)
                { f[i][p]=f[i-1][k]+Cost;
                  G[i][p]=k;
                  Now[i][p]=j;
             }
    }
}
p=0;
for (i=1;i<tot;i++)
  if (f[n][i]<f[n][p]) p=i;
for (i=n;i;i--)
{  Ans[i]=Now[i][p];
   p=G[i][p];
}
for (i=1;i<=n;i++)
{ printf("%d",Ans[i]);
  if (i==n) printf("\n"); else printf(" "); }
}