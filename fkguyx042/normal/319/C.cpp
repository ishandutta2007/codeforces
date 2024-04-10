#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,l,r,Q[100001];
long long a[100001],b[100001],f[100001];
long double up(int x,int y) { return (long double)(f[x]-f[y]); }
long double down(int x,int y) { return (long double)(b[y]-b[x]); }
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%I64d",&a[i]);
  for (i=1;i<=n;i++) scanf("%I64d",&b[i]);
  f[1]=0;
  l=r=1; Q[1]=1;
  for (i=2;i<=n;i++)
  {  while (l<r&&up(Q[l+1],Q[l])<=a[i]*down(Q[l+1],Q[l])) l++;
     f[i]=f[Q[l]]+a[i]*b[Q[l]];
     while (l<r&&up(Q[r],Q[r-1])/down(Q[r],Q[r-1])>up(i,Q[r])/down(i,Q[r])) r--;
     Q[++r]=i;
}
printf("%I64d\n",f[n]);
}