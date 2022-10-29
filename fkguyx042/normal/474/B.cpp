#include<cstdio>
using namespace std;
int i,j,m,p,k,n,f[1000002],a[100001],q,x;
int main()
{ scanf("%d",&n); f[1]=1;
  for (i=1,p=1;i<=n;i++)
  { scanf("%d",&a[i]);
    p+=a[i]; f[p]=i+1;
  }
  scanf("%d",&q);
  for (i=2;i<=1000000;i++)
    if (!f[i]) f[i]=f[i-1];
  for (;q--;)
  { scanf("%d",&x); 
    printf("%d\n",f[x]);
}
}