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
int n,s,d,i,a[1009];
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
scanf("%d",&d);
for(i=1;i<=n;i++)
{
    scanf("%d",&a[i]);
    s+=a[i];
}
s+=10*(n-1);
if(s>d) printf("-1\n");
else printf("%d\n",2*(n-1)+(d-s)/5);
return 0;
}