#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,x,Last;
int a[7];
int main()
{ scanf("%d",&n);
  scanf("%d",&x);
  Last=7-x;
  for (i=1;i<=n;i++)
  { memset(a,0,sizeof(a));
    scanf("%d%d",&p,&k);
    a[p]=a[k]=a[7-k]=a[7-p]=1;
    for (j=1;j<=6;j++)
     if (!a[j]) break;
     if (j==Last||7-j==Last)
     Last=Last;
     else { printf("NO\n"); return 0;}
}
printf("YES\n");
}