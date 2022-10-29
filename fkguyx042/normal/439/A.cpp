#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,v;
int a[100001];
int main()
{ scanf("%d%d",&n,&v);
  for (i=1;i<=n;i++)
    scanf("%d",&p),m+=p;
if (m+10*(n-1)>v) printf("-1\n");
else printf("%d\n",(v-m)/5);
return 0;
}