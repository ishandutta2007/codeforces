#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,x,y;
int main()
{ int t; scanf("%d",&t);
  for (;t--;)
  { scanf("%d%d",&n,&p);
     for (i=1,x=1,y=2;i<=2*n+p;i++)
    {   printf("%d %d\n",x,y);
        y++;
         if (y>n) x++,y=x+1;
    }
}
}