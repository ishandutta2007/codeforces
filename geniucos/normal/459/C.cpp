#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<string>
using namespace std;
int i,j,n,k,d,v[1009],a[1009][1009];
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
scanf("%d",&k);
scanf("%d",&d);
if(k==1&&n==1)
{
    for(i=1;i<=d;i++)
        printf("1\n");
    return 0;
}
if(k==1)
{
    printf("-1\n");
    return 0;
}
if(n<=k)
{
    for(i=1;i<=d;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",j);
        printf("\n");
    }
    return 0;
}
////n>k si k!=1
if(d==1)
{
    printf("-1\n");
    ////oricum o sa am doi intr-o masina intr-o zi
    return 0;
}
int p=1;
for(i=1;i<=d;i++)
{
    p=p*k;
    if(p>=n) break;
}
if(i>d)
{
    printf("-1\n");
    return 0;
}
for(j=1;j<=n;j++)
    v[j]=j-1;
for(i=1;i<=d;i++)
{
    for(j=1;j<=n;j++)
        a[i][j]=v[j]%k+1;
    for(j=1;j<=n;j++)
        v[j]/=k;
}
for(i=1;i<=d;i++)
{
    for(j=1;j<=n;j++)
        printf("%d ",a[i][j]);
    printf("\n");
}
return 0;
}