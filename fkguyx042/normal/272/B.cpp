#include<cstdio>
#include<algorithm>
using namespace std;
int i,j,m,n,a[100001],p;
long long ans;
int Got(int x)
{ if (!x) return 0;
  if (x&1) return Got(x/2)+1;
  else return Got(x/2);
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&p),a[i]=Got(p);
  sort(a+1,a+n+1);
  for (i=1;i<=n;i=j)
 {   for (j=i+1;a[i]==a[j];j++);
     int x=j-i;
     ans+=1ll*x*(x-1)/2ll;
}
printf("%I64d\n",ans);
}