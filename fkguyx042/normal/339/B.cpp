#include<cstdio>
#include<algorithm>
using namespace std;
int a[100001];
long long i,j,m,n,ans;
int main()
  { scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
     scanf("%d",&a[i]);
     a[0]=1;
   for (i=1;i<=m;i++)
     if (a[i]<a[i-1])
       ans+=a[i]+n-a[i-1];
       else ans+=a[i]-a[i-1];
   printf("%I64d\n",ans);
   return 0;
}