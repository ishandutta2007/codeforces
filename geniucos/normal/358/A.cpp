#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n,i,j,sol,x[1009];
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
int ap(int x,int x1,int x2)
{
    return(x>=x1&&x<=x2);
}
int inter(int x1,int y1,int x2,int y2)
{
    if(x1<x2&&x2<y1&&y1<y2) return 1;
    if(x2<x1&&x1<y2&&y2<y1) return 1;
    return 0;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&x[i]);
for(i=1;i<n;i++)
    for(j=i+1;j<n;j++)
        if(inter(min(x[i],x[i+1]),max(x[i],x[i+1]),min(x[j],x[j+1]),max(x[j],x[j+1])))
        {
            printf("yes\n");
            return 0;
        }
printf("no\n");
return 0;
}