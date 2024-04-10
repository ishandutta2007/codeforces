#include<cstdio>
#include<algorithm>
using namespace std;
int f[100000];
int f1[8];
int n,m,i,j,p;
int main()
{scanf("%d",&n);
for (i=1;i<=n;i++)
{scanf("%d",&f[i]);
  f1[f[i]]++;}
  if (f1[5]>0||f1[7]>0||f1[2]<f1[4]||(f1[2]+f1[3])!=(f1[4]+f1[6])||f1[1]!=(f1[2]+f1[3])) printf("-1\n");
  else { for (i=1;i<=f1[4];i++)
          printf("1 2 4\n");
            f1[2]-=f1[4];
          for (i=1;i<=f1[2];i++)
            printf("1 2 6\n");
          for (j=1;j<=f1[3];j++)
           printf("1 3 6\n");
}
return 0;
}