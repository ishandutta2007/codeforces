#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,l,a[100001],b[100001],Q[100001],sum;
int main()
{scanf("%d",&n);
 for (i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]),sum+=a[i];
 for (i=0;i<n;i++) if (a[i]==1) Q[++Q[0]]=i;
 printf("%d\n",sum/2);
 for (l=1;l<=Q[0];l++)
 {  p=Q[l];
   if (a[p]==0) continue;
   printf("%d %d\n",p,b[p]);
   b[b[p]]^=p;
   a[b[p]]--;
   if (a[b[p]]==1) Q[++Q[0]]=b[p];
 }
}