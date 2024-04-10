#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int i,j,m,n,p,k,r,l,ans;
int a[500001];
int main() 
 { scanf("%d",&n);
   for (i=1;i<=n;i++) scanf("%d",&a[i]);
   sort(a+1,a+n+1);
   r=n;
   l=n/2;
   ans=n;
   while (l)
    {  if (a[r]>=2*a[l]) { ans--; r--;}
       l--;
}
printf("%d\n",ans);
return 0;
}