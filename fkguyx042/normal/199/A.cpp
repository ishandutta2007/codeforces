#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
long long f[61];
int main()
{ scanf("%d",&n);
  f[1]=f[2]=1;
  for (i=3;f[i-1]+f[i-2]<=n;i++)
    f[i]=f[i-1]+f[i-2];
  i--;
  for (j=0;j<=i;j++)
   for (k=0;k<=i;k++)
     for (p=0;p<=i;p++)
      if (f[j]+f[k]+f[p]==n)
      { printf("%I64d %I64d %I64d",f[j],f[k],f[p]); 
        return 0;}
   printf("I'm too stupid to solve this problem\n");
   return 0;
}