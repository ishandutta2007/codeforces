#include<cstdio>
#include<algorithm>
using namespace std;
int a[3001],i,j,m,n,p,k,num,ans;
int main()
 { scanf("%d%d",&n,&m);
   for (i=1;i<=m;i++)
      scanf("%d",&a[i]);
   sort(a+1,a+m+1);
 if (a[1]==1||a[m]==n) printf("NO\n");
 else {  for (i=1;i<=m-2;i++)
                 if (a[i]+1==a[i+1]&&a[i+1]+1==a[i+2])
                   {printf("NO\n");
                     return 0;
                     }
          printf("YES\n");
          }
 return 0;
}