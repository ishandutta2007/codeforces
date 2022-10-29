#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long i,j,m,n,p,k,x,y,d;
int main()
{ scanf("%I64d%I64d",&p,&d);
  x=p; j=1;
  for (i=9;i<=p;i=i*10+9)
  {    j*=10;
      y=p%j;
        if (y==i) x=p;
        else 
       if (y+1<=d) x=(p/j-1)*j+i;
  }
  printf("%I64d\n",x);
}