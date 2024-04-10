#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,a,b,n;
int main()
{scanf("%d%d%d",&a,&b,&n);
  for (j=0,i=-1;j<10;j++)
   if ((a*10+j)%b==0) i=j;
if (i==-1) printf("-1\n");
else { printf("%d%d",a,i);
  for (i=1;i<n;i++) printf("0");
}
}