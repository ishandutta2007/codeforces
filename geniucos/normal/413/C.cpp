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
int Nr,maxi,i,j,n,m,nr,ap[109],v[109];
long long sum;
struct str
{
    int v,p;
}a[109];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
for(i=1;i<=n;i++)
    scanf("%d",&a[i].v);
for(i=1;i<=m;i++)
{
    scanf("%d",&j);
    a[j].p=1;
    v[++nr]=a[j].v;
    ap[nr]=1;
}
sum=0;
for(i=1;i<=n;i++)
    if(a[i].p==0) sum+=a[i].v;
sort(v+1,v+nr+1);
for(i=nr;i>=1;i--)
{
    if(v[i]<=sum) sum=1LL*sum*2;
    else sum+=v[i];
}
printf("%I64d\n",sum);
return 0;
}