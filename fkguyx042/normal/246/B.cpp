#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,i,sum,a[100001];
int main()
{ scanf("%d",&n); 
   for (i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
   if (!(sum%n)) printf("%d\n",n); else printf("%d\n",n-1);
}