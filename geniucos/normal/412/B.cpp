#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int n,m,i,a[1009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
sort(a+1,a+n+1);
printf("%d\n",a[n-m+1]);
return 0;
}