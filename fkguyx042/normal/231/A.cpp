#include<cstdio>
#include<algorithm>
using namespace std;
int x,y,z,ans,n,i;
int main()
{ scanf("%d",&n);
  for (i=1;i<=n;i++)
  { scanf("%d%d%d",&x,&y,&z);
    if (x+y+z>=2) ans++;
 }
 printf("%d\n",ans);
}