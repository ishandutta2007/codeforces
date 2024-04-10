#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int i,xi,p,n,ap[309];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&p);
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    scanf("%d",&xi);
    ap[xi%p]++;
    if(ap[xi%p]>1) break;
}
if(i<=n) printf("%d\n",i);
else printf("-1\n");
return 0;
}