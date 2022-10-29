#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int x[100001],y[100001];
int i,j,m,n,p,k;
int main()
  {  scanf("%d",&n);
   for (i=1;i<=n;i++)
   { scanf("%d",&p);
     x[p]++;
     scanf("%d",&y[i]);
  }
  for (i=1;i<=n;i++)
  printf("%d %d\n",n-1+x[y[i]],2*n-2-(n-1+x[y[i]]));
return 0;
}