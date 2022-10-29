#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,ans;
int a[10001];
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (i=1;i<=n;i++) 
    for (j=i+1;j<=n;j++)
      if (a[i]>a[j]) ans++;
  printf("%.6lf\n",ans&1?(double)(ans*2-1):(double)(ans*2));
}