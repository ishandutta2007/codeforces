#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100001];
int n,k,i,j,p,m,ans;
int main()
{ scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  for (i=1;i<=n&&a[i]<0&&k;i++)
  {  k--;
     a[i]=-a[i];
  }
  if (k) 
  {   if (k%2)
      {   sort(a+1,a+n+1);
           a[1]=-a[1];
           }
}
for (i=1;i<=n;i++) ans+=a[i];
printf("%d\n",ans);
return 0;
}