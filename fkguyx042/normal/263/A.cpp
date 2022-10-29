#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int x,y;
int main()
{  for (i=1;i<=5;i++)
    for (j=1;j<=5;j++)
    { scanf("%d",&p);
       if (p==1) x=i,y=j;
  }
  printf("%d\n",abs(x-3)+abs(y-3));
}