#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n;
int main()
{ scanf("%d%d",&n,&m);
  j=min(n,m);
  if (j%2) printf("Akshat\n"); else printf("Malvika\n");
}