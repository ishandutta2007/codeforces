#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,flag;
int a[101][101];
int main()
{ scanf("%d",&n);
 for (i=1;i<=n;i++)
 { scanf("%d",&k);
   for (j=1;j<=k;j++) scanf("%d",&p),a[i][p]++;
 }
 for (i=1;i<=n;i++)
 { flag=1;
       for (j=1;j<=n;j++)
    if (i!=j)
    { flag=0;
      for (k=1;k<=100;k++)
       if ((a[j][k]>0&&a[i][k]==0))
       {   flag=1;
           break;
       }
       if (!flag) break;
    }
    if (flag) printf("YES\n");
    else printf("NO\n");
}
}