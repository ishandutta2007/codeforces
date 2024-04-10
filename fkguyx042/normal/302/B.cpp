#include<cstdio>
#include<algorithm>
using namespace std;
int i,j,m,n,p,k;
int c[100001],t[100001];
int main()
{ scanf("%d%d",&n,&m);
  k=1;
  int last=0;
  for (i=1;i<=n;i++) scanf("%d%d",&c[i],&t[i]);
  for (i=1;i<=m;i++)
  {  scanf("%d",&p);
    while (p>last) last+=c[k]*t[k],k++;
    printf("%d\n",k-1); }
}