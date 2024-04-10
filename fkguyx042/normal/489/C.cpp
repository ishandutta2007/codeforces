#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,x,y;
int main()
{ scanf("%d%d",&x,&y);
  if (y==0&&x==1)  {printf("0 0\n"); return 0; }
  if (y==0||y>9*x)   { printf("-1 -1\n"); return 0; }
   int sum=y;
  for (i=1;i<=x;i++)
 {  for (j=(i==1)?1:0;j<=9;j++)
      if (9*(x-i)>=sum-j) { printf("%d",j); sum-=j; break; }
 }
 printf(" ");
 for (i=1;i<=x;i++)
 {  for (j=9;j>=0;j--)
    if (y>=j) { printf("%d",j); y-=j; break; }
  }
 printf("\n");
}