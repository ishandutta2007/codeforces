#include<cstdio>
using namespace std;
int a[5],i,ans;
int main()
{  for (i=0;i<5;i++) scanf("%d",&a[i]),ans+=a[i];
if (ans%5) printf("-1\n");
else printf("%d\n",ans==0?-1:ans/5);
}