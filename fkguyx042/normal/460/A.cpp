#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n;
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;;i++)
 {   n--;
    if (n<0) break;
    if (i%m==0) n++;
  }
 printf("%d\n",i-1);
 }