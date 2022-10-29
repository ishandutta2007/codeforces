#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,a[500001];
int main()
{ scanf("%d",&n);
 for (i=1;i<=n;i++) scanf("%d",&a[i]);
 sort(a+1,a+n+1);
 if (a[1]==a[n]) printf("%d %I64d\n",0,1ll*n*(n-1)/2ll);
 else {  for (i=2;i<=n&&a[i]==a[i-1];i++); i--;
         for (j=n-1;j>=1&&a[j]==a[j+1];j--);
         printf("%d %I64d\n",a[n]-a[1],1ll*i*(n-j));
}
}