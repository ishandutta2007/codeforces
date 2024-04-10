#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,ans;
int a[2001];
int main()
{ scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  for (i=n;i>0;)
  {   ans+=(a[i]-1)*2;
     i-=k;
  }
 printf("%d\n",ans);
}