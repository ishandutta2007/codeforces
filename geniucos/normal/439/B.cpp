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
int i,n,x,a[100009];
long long sol;
int mod(int x)
{
    if(x<0) return -x;
    return x;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&x);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
sort(a+1,a+n+1);
for(i=1;i<=n;i++)
{
    sol+=1LL*a[i]*x;
    if(x>1) x--;
}
printf("%I64d\n",sol);
return 0;
}