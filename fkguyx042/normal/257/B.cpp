#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
int main()
{ scanf("%d%d",&n,&m);
  if (n<m) swap(n,m);
  printf("%d %d\n",n-1,m);
}