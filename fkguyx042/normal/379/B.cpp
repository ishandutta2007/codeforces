#include<cstdio>
using namespace std;
int i,j,m,n,p,k,a[301];
int ans[10000001];
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (i=1;i<=n;i++)
  {    for (j=1;j<=a[i];j++) {
        if (i==1)
        {  ans[++ans[0]]=2;
           ans[++ans[0]]=1;
        }
        else { ans[++ans[0]]=1;
           ans[++ans[0]]=2;
        }
        ans[0]++;
     }
     ans[++ans[0]]=2;
  }
 // printf("%d\n",ans[0]-1);
  for (i=1;i<ans[0];i++)
   if (ans[i]==1) printf("L");
   else if (ans[i]==2) printf("R");
   else printf("P");
}