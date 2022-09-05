#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int D,tip[5009],L[5009],R[5009],mx[5009],n,m,i,j,fx[5009],ap[5009],lim[5009],a[5009][5009];
char sir[100009];
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
int mod(int x)
{
    if(x<0) return -x;
    return x;
}
int det(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return mod(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
for(i=1;i<=n;i++)
    lim[i]=1000000000;
for(i=1;i<=m;i++)
{
    scanf("%d",&tip[i]);
    for(j=1;j<=n;j++)
        a[i][j]=a[i-1][j];
    if(tip[i]==1)
    {
        scanf("%d",&L[i]);
        scanf("%d",&R[i]);
        scanf("%d",&D);
        for(j=L[i];j<=R[i];j++)
            a[i][j]=a[i-1][j]+D;
    }
    else
    {
        scanf("%d",&L[i]);
        scanf("%d",&R[i]);
        scanf("%d",&mx[i]);
        for(j=L[i];j<=R[i];j++)
            lim[j]=min(lim[j],mx[i]-a[i][j]);
    }
}
for(i=1;i<=m;i++)
if(tip[i]==2)
{
    for(j=L[i];j<=R[i];j++)
        if(lim[j]>=mx[i]-a[i][j]&&(ap[j]==0||(ap[j]==1&&fx[j]==mx[i]-a[i][j])))
        {
            ap[j]=1;
            fx[j]=mx[i]-a[i][j];
            break;
        }
    if(j>R[i])
    {
        printf("NO\n");
        return 0;
    }
}
printf("YES\n");
for(i=1;i<=n;i++)
{
    if(ap[i]==1) printf("%d ",fx[i]);
    else printf("%d ",lim[i]);
}
return 0;
}