#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,n,m,p,k,l,r,K;
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
  {  scanf("%d",&p);
     if (p==-1) k++; else j++;
}
for (i=1;i<=m;i++)
 { scanf("%d%d",&l,&r);
    if ((r-l+1)%2==0)
{   K=(r-l+1);
  if (j>=K/2&&k>=K/2) printf("1\n"); else printf("0\n");
}
else printf("0\n");
}
}