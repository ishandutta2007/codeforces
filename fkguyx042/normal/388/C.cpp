#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,Ans,ans,a[101],sky[101];
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++)
{ scanf("%d",&m);
   k=m/2;
   for (j=1;j<=m;j++)
   { scanf("%d",&a[j]);
     if (j<=k) Ans+=a[j];
     else ans+=a[j];
   }
   if (m&1) ans-=a[k+1],sky[++sky[0]]=a[k+1];
}
sort(sky+1,sky+sky[0]+1);
for (i=sky[0];i;i--)
 if ((sky[0]-i+1)&1) Ans+=sky[i];
 else ans+=sky[i];
 printf("%d %d\n",Ans,ans);
}