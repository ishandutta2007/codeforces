#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,d,a[10001];
int main()
{ scanf("%d%d%d",&n,&d,&k);
  for (i=1;i<n;i++)
  { if (d>0) a[i]=k;
    else a[i]=1;
    d=a[i]-d;
  }
  a[n]=d;
  if (a[n]<1||a[n]>k) printf("-1\n");
  else for (i=1;i<=n;i++) printf("%d ",a[i]); 
}