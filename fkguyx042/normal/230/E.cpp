#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long i,j,m,n,p,k;
long long g[1000001];
int main()
 {scanf("%I64d%I64d",&n,&m);
 for (i=1;i<=m;i++)
  { scanf("%I64d%I64d",&p,&k); g[p]++; g[k]++;}
 for (i=1;i<=n;i++)
   j+=g[i]*(n-g[i]-1);
   j=(long long)n*(n-1)*(n-2)/6-j/2;
  printf("%I64d\n",j);
return 0;
}