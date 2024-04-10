#include<cstdio>
using namespace std;
int f[101];
int n,m,i,j,p,num,ans=1<<30;
int main()
{ scanf("%d",&n);
   for (i=1;i<=n;i++)
     scanf("%d",&f[i]);
   for (i=1;i<=n;i++)
     { num=15*f[i];
        for (j=1;j<=f[i];j++)
         { scanf("%d",&p); 
             num+=5*p;
             }
             if (ans>num)
         ans=num;
         }
     printf("%d\n",ans);
     return 0;
     }