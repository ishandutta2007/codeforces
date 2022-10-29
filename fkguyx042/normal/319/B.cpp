#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,sum,r,ans;
int a[100001],Now,Q[100001],f[100001];
int main()
{scanf("%d",&n);
 for (i=1;i<=n;i++) scanf("%d",&a[i]);
 for (i=n;i;i--)
 {  int t=0; 
   while (r&&a[Q[r]]<a[i]) {t++; f[i]=t=max(t,f[Q[r]]); r--; }
    Q[++r]=i;
    ans=max(t,ans);
}
printf("%d\n",ans);
}