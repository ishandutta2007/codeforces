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
int n,i,j,ap,k;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&k);
for(i=1;i<=n;i++)
{
    scanf("%d",&j);
    if(j+k<=5) ap++;
}
printf("%d\n",ap/3);
return 0;
}