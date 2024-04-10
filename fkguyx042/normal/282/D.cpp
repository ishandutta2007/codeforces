#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int i,j,m,n,p,k,x,y;
int a[4];
int main()
{scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  if (n==1)
   printf(a[1]!=0?"BitLGM":"BitAryo");
   if (n==3)
   printf(((a[1]^a[2]^a[3])!=0)?"BitLGM":"BitAryo");
   if (n==2)
   {   if (a[1]>a[2]) swap(a[1],a[2]);
   x=a[1];y=a[2];
      k=y-x;
       if (x==(int)((y-x)*((1+sqrt(5.0))/2.0))) 
         printf("BitAryo\n");
         else printf("BitLGM\n");
}
}