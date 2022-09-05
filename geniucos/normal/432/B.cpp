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
int i,n,a,b,x[100009],y[100009],apx[100009],apy[100009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    scanf("%d",&x[i]);
    scanf("%d",&y[i]);
    apx[x[i]]++;
    apy[y[i]]++;
}
for(i=1;i<=n;i++)
{
    a=n-1;
    b=n-1;
    a+=apx[y[i]];
    b-=apx[y[i]];
    printf("%d %d\n",a,b);
}
return 0;
}