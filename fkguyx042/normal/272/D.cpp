#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int x,i,j,m,n,p,k,ans,tot,Mo;
int a[100001],b[100001],Q[200001];
void Do(int j)
{  while (j%2==0&&x>0) 
   {  x--;
       j/=2;
   }
   ans=1ll*ans*j%Mo;
}
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]),Q[++tot]=a[i];
  for (i=1;i<=n;i++) scanf("%d",&b[i]),Q[++tot]=b[i];
  for (i=1;i<=n;i++) if (a[i]==b[i]) x++;
  scanf("%d",&Mo);
  ans=1;
  sort(Q+1,Q+tot+1);
  for (i=1;i<=tot;i++)
    if (Q[i]!=Q[i-1])
    {   for (j=2;j<=k;j++)
           Do(j);
       k=1;
    }
    else k++;
   for (j=2;j<=k;j++)
      Do(j);
printf("%d\n",ans);
}