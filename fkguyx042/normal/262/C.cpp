#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int k,i,j,m,n,p,ans;
int a[100001];
int main()
{ scanf("%d",&n); k=1000000;
  for (i=1;i<=n;i++)
   {scanf("%d",&p); k=min(p,k); }
  scanf("%d",&m);
  for (i=1;i<=m;i++)
  scanf("%d",&a[i]);
 sort(a+1,a+m+1);
 for (i=m;i>0;i-=2)
 {   for (p=1;p<=k;p++)
     { ans+=a[i--]; if(i==0) break; }
}
printf("%d\n",ans);
return 0;
}